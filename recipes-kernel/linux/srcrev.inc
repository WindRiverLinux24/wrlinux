#
# This file is generated based on:
#     linux-yocto-6.6
#     yocto-kernel-cache
#
# Any manual changes will be overwritten.
#
# This will cause SRCREV_machine:kb-<KBRANCH> take priority over SRCREV_machine:<machine>
MACHINEOVERRIDES .= ":kb-${@oe.utils.conditional('PREFERRED_PROVIDER_virtual/kernel', 'linux-yocto-dev', 'dev-', '', d)}${@d.getVar('KBRANCH', True).replace("/", "-")}"

# linux-yocto-6.6 entries

# linux-yocto-6.6 branch entries
SRCREV_machine:kb-master ?= "402cc2d98840bdcdf6c2a4ec171bb30ea003300e"
LINUX_VERSION:kb-master = "6.5.5"
SRCREV_machine:kb-v6.6-base ?= "a3463f08104612fc979c41fa54733e925205d3d7"
LINUX_VERSION:kb-v6.6-base = "6.6.29"
SRCREV_machine:kb-v6.6-standard-arm-versatile-926ejs ?= "45982c347ee123883a88f220d1d9a740e2c2b959"
LINUX_VERSION:kb-v6.6-standard-arm-versatile-926ejs = "6.6.29"
SRCREV_machine:kb-v6.6-standard-base ?= "6655dc03f5de7bb734da3ec8eb97f9be281dfbdb"
LINUX_VERSION:kb-v6.6-standard-base = "6.6.29"
SRCREV_machine:kb-v6.6-standard-bcm-2xxx-rpi ?= "6655dc03f5de7bb734da3ec8eb97f9be281dfbdb"
LINUX_VERSION:kb-v6.6-standard-bcm-2xxx-rpi = "6.6.29"
SRCREV_machine:kb-v6.6-standard-beaglebone ?= "6655dc03f5de7bb734da3ec8eb97f9be281dfbdb"
LINUX_VERSION:kb-v6.6-standard-beaglebone = "6.6.29"
SRCREV_machine:kb-v6.6-standard-edgerouter ?= "6655dc03f5de7bb734da3ec8eb97f9be281dfbdb"
LINUX_VERSION:kb-v6.6-standard-edgerouter = "6.6.29"
SRCREV_machine:kb-v6.6-standard-fsl-mpc8315e-rdb ?= "1f39da279a1542a4aceb5ddf6306f1b469c84f29"
LINUX_VERSION:kb-v6.6-standard-fsl-mpc8315e-rdb = "6.6.29"
SRCREV_machine:kb-v6.6-standard-mti-malta32 ?= "738f344ef6da38ebf6fcca87b701281c930b16e4"
LINUX_VERSION:kb-v6.6-standard-mti-malta32 = "6.6.29"
SRCREV_machine:kb-v6.6-standard-mti-malta64 ?= "7f4b889b7acb9fe36e290bf40c2e9b6cec523f6d"
LINUX_VERSION:kb-v6.6-standard-mti-malta64 = "6.6.29"
SRCREV_machine:kb-v6.6-standard-nxp-ls20xx ?= "6655dc03f5de7bb734da3ec8eb97f9be281dfbdb"
LINUX_VERSION:kb-v6.6-standard-nxp-ls20xx = "6.6.29"
SRCREV_machine:kb-v6.6-standard-nxp-sdk-6.6-nxp-soc ?= "a5bbf7a57836c8bde9e3279ad25d64c29ca07656"
LINUX_VERSION:kb-v6.6-standard-nxp-sdk-6.6-nxp-soc = "6.6.29"
SRCREV_machine:kb-v6.6-standard-preempt-rt-arm-versatile-926ejs ?= "68e2072d8a0a0d328d491dc918b1ea352c5ea37d"
LINUX_VERSION:kb-v6.6-standard-preempt-rt-arm-versatile-926ejs = "6.6.29"
SRCREV_machine:kb-v6.6-standard-preempt-rt-base ?= "99d3632c1cf7688066e57aea89f9adfe8d1a5ca5"
LINUX_VERSION:kb-v6.6-standard-preempt-rt-base = "6.6.29"
SRCREV_machine:kb-v6.6-standard-preempt-rt-bcm-2xxx-rpi ?= "fb51f76153150c04b0cd902dc8e36a11c1cbaa8d"
LINUX_VERSION:kb-v6.6-standard-preempt-rt-bcm-2xxx-rpi = "6.6.29"
SRCREV_machine:kb-v6.6-standard-preempt-rt-nxp-sdk-6.6-nxp-soc ?= "7ea9a24dd7547b2942f94e3f38d662d9a70b3a20"
LINUX_VERSION:kb-v6.6-standard-preempt-rt-nxp-sdk-6.6-nxp-soc = "6.6.29"
SRCREV_machine:kb-v6.6-standard-preempt-rt-x86 ?= "fdb6b710f42a6b2d32e5380324aa6550efd787f6"
LINUX_VERSION:kb-v6.6-standard-preempt-rt-x86 = "6.6.29"
SRCREV_machine:kb-v6.6-standard-qemuarm64 ?= "6655dc03f5de7bb734da3ec8eb97f9be281dfbdb"
LINUX_VERSION:kb-v6.6-standard-qemuarm64 = "6.6.29"
SRCREV_machine:kb-v6.6-standard-qemuppc ?= "6655dc03f5de7bb734da3ec8eb97f9be281dfbdb"
LINUX_VERSION:kb-v6.6-standard-qemuppc = "6.6.29"
SRCREV_machine:kb-v6.6-standard-ti-am335x ?= "6655dc03f5de7bb734da3ec8eb97f9be281dfbdb"
LINUX_VERSION:kb-v6.6-standard-ti-am335x = "6.6.29"
SRCREV_machine:kb-v6.6-standard-tiny-arm-versatile-926ejs ?= "68d6d6e19cb656b06b2106df4a99c7dd5b1885b2"
LINUX_VERSION:kb-v6.6-standard-tiny-arm-versatile-926ejs = "6.6.29"
SRCREV_machine:kb-v6.6-standard-tiny-base ?= "6655dc03f5de7bb734da3ec8eb97f9be281dfbdb"
LINUX_VERSION:kb-v6.6-standard-tiny-base = "6.6.29"
SRCREV_machine:kb-v6.6-standard-tiny-common-pc ?= "6655dc03f5de7bb734da3ec8eb97f9be281dfbdb"
LINUX_VERSION:kb-v6.6-standard-tiny-common-pc = "6.6.29"
SRCREV_machine:kb-v6.6-standard-tiny-x86 ?= "6655dc03f5de7bb734da3ec8eb97f9be281dfbdb"
LINUX_VERSION:kb-v6.6-standard-tiny-x86 = "6.6.29"
SRCREV_machine:kb-v6.6-standard-x86 ?= "6655dc03f5de7bb734da3ec8eb97f9be281dfbdb"
LINUX_VERSION:kb-v6.6-standard-x86 = "6.6.29"
SRCREV_machine:kb-v6.6-standard-xilinx-zynqmp ?= "6655dc03f5de7bb734da3ec8eb97f9be281dfbdb"
LINUX_VERSION:kb-v6.6-standard-xilinx-zynqmp = "6.6.29"

# yocto-kernel-cache entries
KERNEL_CACHE_BRANCH_6.6 = "yocto-6.6"
SRCREV_meta_6.6 = "a78c74a3510067017dda1926f88bd914f0a053b3"
