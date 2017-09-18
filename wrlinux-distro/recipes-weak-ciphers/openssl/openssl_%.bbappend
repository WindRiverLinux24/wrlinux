#
# Copyright (C) 2017 Wind River Systems, Inc.
#

WEAKCIPHERS = "${@bb.utils.contains('DISTRO_FEATURES', 'openssl-no-weak-ciphers', 'no-des no-ec no-ecdh no-ecdsa no-md2 no-mdc2', '', d)}"
EXTRA_OECONF_append_class-target = " ${WEAKCIPHERS}"
EXTRA_OECONF_append_class-nativesdk = " ${WEAKCIPHERS}"
