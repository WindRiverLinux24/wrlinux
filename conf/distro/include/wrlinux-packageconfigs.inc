# PACKAGECONFIG settings of recipes for WRLinux

# Workaround for nmap possibly requiring python-pygtk which is not available
PACKAGECONFIG_remove_pn-nmap = "zenmap"

# we usually use gnutls as the default PACKAGECONFIG of wpa-supplicant, but its sub-packege gnutls-openssl
# is GPLv3, so need this check to switch to openssl if GLPv3 is blacklisted.
PACKAGECONFIG_pn-wpa-supplicant ?= "${@bb.utils.contains('INCOMPATIBLE_LICENSE', 'GPLv3', 'openssl', 'gnutls', d)}"

PACKAGECONFIG_pn-sysstat ?= "${@bb.utils.filter('DISTRO_FEATURES', 'systemd', d)} lm-sensors cron"

PACKAGECONFIG_append_pn-mesa-demos = "${@bb.utils.contains('DISTRO_FEATURES', 'weston-demo', ' wayland ', ' ', d)}"