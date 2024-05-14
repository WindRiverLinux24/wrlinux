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
SRCREV_machine:kb-v6.6-base ?= "5697d159afef8c475f13a0b7b85f09bd4578106c"
LINUX_VERSION:kb-v6.6-base = "6.6.30"
SRCREV_machine:kb-v6.6-standard-arm-versatile-926ejs ?= "25741eb502ad719afba306e4f3739d79228167d6"
LINUX_VERSION:kb-v6.6-standard-arm-versatile-926ejs = "6.6.30"
SRCREV_machine:kb-v6.6-standard-base ?= "955c18e54b19dae67fdeb54cedc003225bcd9380"
LINUX_VERSION:kb-v6.6-standard-base = "6.6.30"
SRCREV_machine:kb-v6.6-standard-bcm-2xxx-rpi ?= "955c18e54b19dae67fdeb54cedc003225bcd9380"
LINUX_VERSION:kb-v6.6-standard-bcm-2xxx-rpi = "6.6.30"
SRCREV_machine:kb-v6.6-standard-beaglebone ?= "955c18e54b19dae67fdeb54cedc003225bcd9380"
LINUX_VERSION:kb-v6.6-standard-beaglebone = "6.6.30"
SRCREV_machine:kb-v6.6-standard-edgerouter ?= "955c18e54b19dae67fdeb54cedc003225bcd9380"
LINUX_VERSION:kb-v6.6-standard-edgerouter = "6.6.30"
SRCREV_machine:kb-v6.6-standard-fsl-mpc8315e-rdb ?= "1c1de4ac3bbb367653cad51f79677ec797150883"
LINUX_VERSION:kb-v6.6-standard-fsl-mpc8315e-rdb = "6.6.30"
SRCREV_machine:kb-v6.6-standard-mti-malta32 ?= "6f385885b5cc0a6dd65829173eee6af2901be70d"
LINUX_VERSION:kb-v6.6-standard-mti-malta32 = "6.6.30"
SRCREV_machine:kb-v6.6-standard-mti-malta64 ?= "40b35be7a83982472153cbf0a80fd8ed3f21b053"
LINUX_VERSION:kb-v6.6-standard-mti-malta64 = "6.6.30"
SRCREV_machine:kb-v6.6-standard-nxp-ls20xx ?= "955c18e54b19dae67fdeb54cedc003225bcd9380"
LINUX_VERSION:kb-v6.6-standard-nxp-ls20xx = "6.6.30"
SRCREV_machine:kb-v6.6-standard-nxp-sdk-6.6-nxp-soc ?= "a400242955c77dc50d05ebfda006e8576b3ade73"
LINUX_VERSION:kb-v6.6-standard-nxp-sdk-6.6-nxp-soc = "6.6.30"
SRCREV_machine:kb-v6.6-standard-preempt-rt-arm-versatile-926ejs ?= "27285513e61aa0635bd2b4ff66736b461529ab99"
LINUX_VERSION:kb-v6.6-standard-preempt-rt-arm-versatile-926ejs = "6.6.30"
SRCREV_machine:kb-v6.6-standard-preempt-rt-base ?= "d6479bad645622afeeefff281c6be5339662c701"
LINUX_VERSION:kb-v6.6-standard-preempt-rt-base = "6.6.30"
SRCREV_machine:kb-v6.6-standard-preempt-rt-bcm-2xxx-rpi ?= "5bb84cd10a4331932fc46e8ee44b699b5813d0cf"
LINUX_VERSION:kb-v6.6-standard-preempt-rt-bcm-2xxx-rpi = "6.6.30"
SRCREV_machine:kb-v6.6-standard-preempt-rt-nxp-sdk-6.6-nxp-soc ?= "fd73467d4aaaedb42fa0eda3b9873a2c0d662d7a"
LINUX_VERSION:kb-v6.6-standard-preempt-rt-nxp-sdk-6.6-nxp-soc = "6.6.30"
SRCREV_machine:kb-v6.6-standard-preempt-rt-x86 ?= "af6a90e49d2b095f8b4c29c75dc428225f60d146"
LINUX_VERSION:kb-v6.6-standard-preempt-rt-x86 = "6.6.30"
SRCREV_machine:kb-v6.6-standard-qemuarm64 ?= "955c18e54b19dae67fdeb54cedc003225bcd9380"
LINUX_VERSION:kb-v6.6-standard-qemuarm64 = "6.6.30"
SRCREV_machine:kb-v6.6-standard-qemuppc ?= "955c18e54b19dae67fdeb54cedc003225bcd9380"
LINUX_VERSION:kb-v6.6-standard-qemuppc = "6.6.30"
SRCREV_machine:kb-v6.6-standard-ti-am335x ?= "955c18e54b19dae67fdeb54cedc003225bcd9380"
LINUX_VERSION:kb-v6.6-standard-ti-am335x = "6.6.30"
SRCREV_machine:kb-v6.6-standard-tiny-arm-versatile-926ejs ?= "a30d4d89f5d394b5883251bcd4dd74a8aab97f1d"
LINUX_VERSION:kb-v6.6-standard-tiny-arm-versatile-926ejs = "6.6.30"
SRCREV_machine:kb-v6.6-standard-tiny-base ?= "955c18e54b19dae67fdeb54cedc003225bcd9380"
LINUX_VERSION:kb-v6.6-standard-tiny-base = "6.6.30"
SRCREV_machine:kb-v6.6-standard-tiny-common-pc ?= "955c18e54b19dae67fdeb54cedc003225bcd9380"
LINUX_VERSION:kb-v6.6-standard-tiny-common-pc = "6.6.30"
SRCREV_machine:kb-v6.6-standard-tiny-x86 ?= "955c18e54b19dae67fdeb54cedc003225bcd9380"
LINUX_VERSION:kb-v6.6-standard-tiny-x86 = "6.6.30"
SRCREV_machine:kb-v6.6-standard-x86 ?= "faec8ade48070e10d89dccc75ad456ce25af0410"
LINUX_VERSION:kb-v6.6-standard-x86 = "6.6.30"
SRCREV_machine:kb-v6.6-standard-xilinx-zynqmp ?= "955c18e54b19dae67fdeb54cedc003225bcd9380"
LINUX_VERSION:kb-v6.6-standard-xilinx-zynqmp = "6.6.30"

# yocto-kernel-cache entries
KERNEL_CACHE_BRANCH_6.6 = "yocto-6.6"
SRCREV_meta_6.6 = "49698cadd79745fa26aa7ef507c16902250c1750"
