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
SRCREV_machine:kb-v6.6-standard-preempt-rt-arm-versatile-926ejs ?= "007e9844eecbf3f7e4f40d8c96b5c91185c42d57"
LINUX_VERSION:kb-v6.6-standard-preempt-rt-arm-versatile-926ejs = "6.6.29"
SRCREV_machine:kb-v6.6-standard-preempt-rt-base ?= "752cb376a7c71d9b42b3b5a9f11313de965f6b3a"
LINUX_VERSION:kb-v6.6-standard-preempt-rt-base = "6.6.29"
SRCREV_machine:kb-v6.6-standard-preempt-rt-bcm-2xxx-rpi ?= "b027809f6add3a433f4131b6c27dfaac677bc1d1"
LINUX_VERSION:kb-v6.6-standard-preempt-rt-bcm-2xxx-rpi = "6.6.29"
SRCREV_machine:kb-v6.6-standard-preempt-rt-nxp-sdk-6.6-nxp-soc ?= "f768e2b18ccd7d676184cbfc5ce2d9fb32d5e771"
LINUX_VERSION:kb-v6.6-standard-preempt-rt-nxp-sdk-6.6-nxp-soc = "6.6.29"
SRCREV_machine:kb-v6.6-standard-preempt-rt-x86 ?= "8d822dc0f868279f797c103fa3787eecd87f2c08"
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
SRCREV_meta_6.6 = "1cd08f1fb2b33510783fa31c11150038a1ff8c42"
