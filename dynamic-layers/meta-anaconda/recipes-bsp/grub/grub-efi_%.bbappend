FILESEXTRAPATHS:prepend:anaconda := "${THISDIR}/files:"

PXE_UEFI_GRUB_CONF ?= "grub.cfg"
PXE_UEFI_GRUB_IMAGE ?= "bootx64-pxe.efi"
INSTALLER_INITRAMFS_IMAGE ?= "wrlinux-image-installer-initramfs-${MACHINE}.rootfs.${INITRAMFS_FSTYPES}"

SRC_URI:append:anaconda = " file://grub.cfg \
"

do_mkpxeimage() {
    :
}

do_mkpxeimage:class-target:anaconda() {
    cd ${B}
    install -d boot/grub
    if [ -e ${PXE_UEFI_GRUB_CONF} ]; then
        # Use customer's
        install -m 755 ${PXE_UEFI_GRUB_CONF} boot/grub/grub.cfg
    else
        install -m 755 ${WORKDIR}/grub.cfg boot/grub/grub.cfg
        # Use default
        sed -i -e "s/@MACHINE@/${MACHINE}/g" \
               -e "s#@APPEND@#${APPEND}#g" \
               -e "s/@INITRAMFS_FSTYPES@/${INITRAMFS_FSTYPES}/g" \
               -e "s/@KERNEL_IMAGETYPE@/${KERNEL_IMAGETYPE}/g" boot/grub/grub.cfg
    fi
    cp ${DEPLOY_DIR_IMAGE}/${KERNEL_IMAGETYPE} .
    cp ${DEPLOY_DIR_IMAGE}/${INSTALLER_INITRAMFS_IMAGE} .

    grub-mkstandalone -d ./grub-core --modules="${GRUB_BUILDIN}" \
       -O ${GRUB_TARGET}-efi -o ./${PXE_UEFI_GRUB_IMAGE} \
       boot/grub/grub.cfg \
       ${KERNEL_IMAGETYPE} \
       ${INSTALLER_INITRAMFS_IMAGE}

    install -m 644 ${PXE_UEFI_GRUB_IMAGE} ${DEPLOY_DIR_IMAGE}
    rm ${KERNEL_IMAGETYPE} ${INSTALLER_INITRAMFS_IMAGE}
}

do_deploy:append:class-target:anaconda() {
        # Install the modules to deploy, and efi_populate will
        # copy them to grub-efi's search path later
        make -C grub-core install DESTDIR=${DEPLOYDIR} pkglibdir=""
}


addtask do_mkpxeimage after do_install
