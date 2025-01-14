#
# Add a few "redhat" modules to pam.  Some have been accepted upstream and
# are part of the distribution, but not the three we add here.
#

FILESEXTRAPATHS:prepend := "${THISDIR}/libpam:"

SRC_URI += "https://src.fedoraproject.org/repo/pkgs/pam/pam-redhat-1.1.5.tar.xz/sha512/b93b80e9aa0dd8b38045b2a8cc36006b1b651a2724e64fcd9ed87af1fc36008acf9e62e2950097bebfccd657a064b748311f4b9c826f76d7b8c4299feb070bb8/pam-redhat-1.1.5.tar.xz;name=redhat \
            file://pam-1.0.90-redhat-modules.patch \
            ${@bb.utils.contains('PACKAGECONFIG', 'faillock', 'file://pam_faillock_add_uid.patch', '', d)} \
           "

SRC_URI[redhat.sha256sum] = "0fb422bdc4889e0f1d28144d95268266ad3953dcd64ab90f5efb0f2caa2e06cf"

EXTRA_OEMAKE:append = " LOCKDIR=${localstatedir}/run/console"

# If necessary, move pam-redhat modules to where they will be built.
# We create a local function and use sh.
#
do_lcl_rh_move () {
	SAVED_PWD=`pwd`; cd ${S}
	if [ ! -e modules/pam_console ] ; then
		mv ${WORKDIR}/pam-redhat-1.1.5/* modules
	fi
	cd ${SAVED_PWD}
}

# Now, we define our own do_patch.  We rely on the fact
# that the default do_patch just invokes patch_do_patch.
#
python do_patch () {
    bb.build.exec_func('do_lcl_rh_move', d)
    bb.build.exec_func('patch_do_patch', d)
}

do_install:append() {
    if ${@bb.utils.contains('PACKAGECONFIG', 'faillock', 'true', 'false', d)}; then
        sed -i '/end of pam-auth-update config/i \
# faillock is required to reset the fail count on success\
account    required            pam_faillock.so' \
            ${D}${sysconfdir}/pam.d/common-account
        sed -i '/pam_unix.so/i \
auth    required    pam_faillock.so preauth deny=5 even_deny_root unlock_time=60' \
            ${D}${sysconfdir}/pam.d/common-auth
        sed -i '/pam_unix.so/a \
auth    [default=die]    pam_faillock.so authfail deny=5 even_deny_root unlock_time=60 \
auth    sufficient       pam_faillock.so authsucc deny=5 even_deny_root unlock_time=60' \
            ${D}${sysconfdir}/pam.d/common-auth
    fi

    if ${@bb.utils.contains('DISTRO_FEATURES','sysvinit','false','true',d)}; then
        install -d ${D}${sysconfdir}/tmpfiles.d
        echo "d /run/console 0755 root root - -" >>  ${D}${sysconfdir}/tmpfiles.d/pam.conf
        if ${@bb.utils.contains('PACKAGECONFIG', 'faillock', 'true', 'false', d)}; then
            echo "d /run/faillock 0755 root root - -" >>  ${D}${sysconfdir}/tmpfiles.d/pam.conf
        fi
    else
        echo "d root root 0755 /var/run/console none" >> ${D}${sysconfdir}/default/volatiles/99_pam
        if ${@bb.utils.contains('PACKAGECONFIG', 'faillock', 'true', 'false', d)}; then
            echo "d root root 0755 /var/run/faillock none" >> ${D}${sysconfdir}/default/volatiles/99_pam
        fi
    fi
}

PACKAGECONFIG[faillock] = ",,,"
RDEPENDS:${PN}-runtime += "${@bb.utils.contains('PACKAGECONFIG', 'faillock', 'pam-plugin-faillock', '', d)}"
