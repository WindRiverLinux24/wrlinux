#
# Copyright (C) 2020 Wind River Systems, Inc.
#
DESCRIPTION = "Provides container base app sdk for Wind River Linux Assembly Tool."

LICENSE = "MIT"

# Control the installed packages strictly
WRTEMPLATE_IMAGE = "0"

NO_RECOMMENDATIONS = "1"

SDKIMAGE_LINGUAS = ""

# Implementation of Full Image generator with Application SDK
TOOLCHAIN_HOST_TASK:append = " \
    nativesdk-wic \
    nativesdk-genimage \
    nativesdk-bootfs \
    nativesdk-appsdk \
"
TOOLCHAIN_TARGET_TASK:append = " \
    qemuwrapper-cross \
"

TOOLCHAIN_TARGET_TASK:append:x86-64 = " \
    syslinux-misc \
    syslinux-isolinux \
    syslinux-pxelinux \
"
POPULATE_SDK_PRE_TARGET_COMMAND += "copy_pkgdata_to_sdk;"
copy_pkgdata_to_sdk() {
    install -d ${SDK_OUTPUT}${SDKPATHNATIVE}${datadir}/pkgdata
    if [ -e ${DEPLOY_DIR}/${IMAGE_PKGTYPE}/.pkgdata.tar.bz2 -a -e ${DEPLOY_DIR}/${IMAGE_PKGTYPE}/.pkgdata.tar.bz2.sha256sum ]; then
        cp ${DEPLOY_DIR}/${IMAGE_PKGTYPE}/.pkgdata.tar.bz2 \
            ${SDK_OUTPUT}${SDKPATHNATIVE}${datadir}/pkgdata/pkgdata.tar.bz2
        cp ${DEPLOY_DIR}/${IMAGE_PKGTYPE}/.pkgdata.tar.bz2.sha256sum \
            ${SDK_OUTPUT}${SDKPATHNATIVE}${datadir}/pkgdata/pkgdata.tar.bz2.sha256sum
    fi

    if [ ! -e ${SDK_OUTPUT}${SDKPATHNATIVE}${datadir}/pkgdata/pkgdata.tar.bz2 ]; then
        copy_pkgdata ${SDK_OUTPUT}${SDKPATHNATIVE}${datadir}/pkgdata
    fi
}

copy_pkgdata() {
    dest=$1
    install -d $dest
    tar cfj $dest/pkgdata.tar.bz2 -C ${TMPDIR}/pkgdata ${MACHINE}
    (
        cd $dest;
        sha256sum pkgdata.tar.bz2 > pkgdata.tar.bz2.sha256sum
    )
}

do_copy_pkgdata_to_deploy_repo() {
    for class in ${PACKAGE_CLASSES}; do
        class=`echo $class | sed -e 's/package_//'`
        deploydir=${DEPLOY_DIR}/$class
        copy_pkgdata $deploydir
        mv $deploydir/pkgdata.tar.bz2 $deploydir/.pkgdata.tar.bz2
        mv $deploydir/pkgdata.tar.bz2.sha256sum $deploydir/.pkgdata.tar.bz2.sha256sum
    done
}
addtask copy_pkgdata_to_deploy_repo

POPULATE_SDK_PRE_TARGET_COMMAND += "copy_ostree_initramfs_to_sdk;"
copy_ostree_initramfs_to_sdk() {
    install -d ${SDK_OUTPUT}${SDKPATHNATIVE}${datadir}/genimage/data/initramfs
    if [ -L ${DEPLOY_DIR_IMAGE}/${INITRAMFS_IMAGE}-${MACHINE}.${INITRAMFS_FSTYPES} ];then
        cp -f ${DEPLOY_DIR_IMAGE}/${INITRAMFS_IMAGE}-${MACHINE}.${INITRAMFS_FSTYPES} \
            ${SDK_OUTPUT}${SDKPATHNATIVE}${datadir}/genimage/data/initramfs/
    fi
}

IMAGE_CLASSES += "qemuboot"
do_populate_sdk:prepend() {
    localdata = bb.data.createCopy(d)
    if localdata.getVar('MACHINE') == 'bcm-2xxx-rpi4':
        localdata.appendVar('QB_OPT_APPEND', ' -bios @DEPLOYDIR@/qemu-u-boot-bcm-2xxx-rpi4.bin')
    localdata.setVar('QB_MEM', '-m 512')

    bb.build.exec_func('do_write_qemuboot_conf', localdata)

    d.setVar('PACKAGE_INSTALL', 'packagegroup-base')
}


POPULATE_SDK_PRE_TARGET_COMMAND += "copy_qemu_data;"
copy_qemu_data() {
    install -d ${SDK_OUTPUT}${SDKPATHNATIVE}${datadir}/qemu_data
    if [ -e ${DEPLOY_DIR_IMAGE}/qemu-u-boot-bcm-2xxx-rpi4.bin ]; then
        cp -f ${DEPLOY_DIR_IMAGE}/qemu-u-boot-bcm-2xxx-rpi4.bin ${SDK_OUTPUT}${SDKPATHNATIVE}${datadir}/qemu_data/
    fi
    if [ -e ${DEPLOY_DIR_IMAGE}/ovmf.qcow2 ]; then
        cp -f ${DEPLOY_DIR_IMAGE}/ovmf.qcow2 ${SDK_OUTPUT}${SDKPATHNATIVE}${datadir}/qemu_data/
    fi
    if [ -e ${DEPLOY_DIR_IMAGE}/ovmf.vars.qcow2 ]; then
        cp -f ${DEPLOY_DIR_IMAGE}/ovmf.vars.qcow2 ${SDK_OUTPUT}${SDKPATHNATIVE}${datadir}/qemu_data/
    fi

    sed -e '/^staging_bindir_native =/d' \
        -e '/^staging_dir_host =/d' \
        -e '/^staging_dir_native = /d' \
        -e '/^kernel_imagetype =/d' \
        -e 's/^deploy_dir_image =.*$/deploy_dir_image = @DEPLOYDIR@/' \
        -e 's/^image_link_name =.*$/image_link_name = @IMAGE_LINK_NAME@/' \
        -e 's/^image_name =.*$/image_name = @IMAGE_NAME@/' \
        -e 's/^qb_default_fstype =.*$/qb_default_fstype = wic/' \
            ${IMGDEPLOYDIR}/container-base-${MACHINE}.qemuboot.conf > \
                ${SDK_OUTPUT}${SDKPATHNATIVE}${datadir}/qemu_data/qemuboot.conf.in
}

POPULATE_SDK_PRE_TARGET_COMMAND += "copy_bootfile;"
copy_bootfile() {
	if [ -n "${BOOTFILES_DIR_NAME}" -a -d "${DEPLOY_DIR_IMAGE}/${BOOTFILES_DIR_NAME}" ]; then
	    install -d ${SDK_OUTPUT}${SDKPATHNATIVE}${datadir}/bootfiles
		cp -rf ${DEPLOY_DIR_IMAGE}/${BOOTFILES_DIR_NAME} ${SDK_OUTPUT}${SDKPATHNATIVE}${datadir}/bootfiles/
	fi
}

# Make sure code changes can result in rebuild
do_populate_sdk[vardeps] += "extract_pkgdata_postinst"
SDK_POST_INSTALL_COMMAND += "${extract_pkgdata_postinst}"
extract_pkgdata_postinst() {
    cd $target_sdk_dir/sysroots/${SDK_SYS}${datadir}/pkgdata/;
    mkdir $target_sdk_dir/sysroots/pkgdata;
    tar xf pkgdata.tar.bz2 -C $target_sdk_dir/sysroots/pkgdata;
}

IMAGE_INSTALL = "\
    base-files \
    base-passwd \
    ${VIRTUAL-RUNTIME_update-alternatives} \
    openssh \
    ca-certificates \
    packagegroup-base \
    "

# - The ostree are not needed for container image.
# - No docker or k8s by default
IMAGE_INSTALL:remove = "\
    ostree ostree-upgrade-mgr \
    kubernetes \
    docker \
    ${@bb.utils.contains('PACKAGE_CLASSES','package_deb','containerd-opencontainers','virtual-containerd',d)} \
    python3-docker-compose \
"

# Only need tar.bz2 for container image
IMAGE_FSTYPES:remove = " \
    live wic wic.bmap otaimg \
"

# No bsp packages for container
python () {
    d.setVar('WRTEMPLATE_CONF_WRIMAGE_MACH', 'wrlnoimage_mach.inc')

    machine = d.getVar('MACHINE')
    if machine == 'intel-x86-64':
        d.appendVarFlag('do_populate_sdk', 'depends', ' ovmf:do_deploy')
    elif machine == 'bcm-2xxx-rpi4':
        d.appendVarFlag('do_populate_sdk', 'depends', ' rpi-bootfiles:do_deploy u-boot:do_deploy')

}

IMAGE_FEATURES += "package-management"

inherit wrlinux-image features_check
REQUIRED_DISTRO_FEATURES = "ostree lat"

# Make sure the existence of ostree initramfs image
do_populate_sdk[depends] += "initramfs-ostree-image:do_image_complete"

deltask do_populate_sdk_ext
