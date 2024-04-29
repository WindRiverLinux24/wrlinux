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
SRCREV_machine:kb-v6.6-base ?= "ba151416051a45ffca565f708584b9cd5c971481"
LINUX_VERSION:kb-v6.6-base = "6.6.28"
SRCREV_machine:kb-v6.6-standard-arm-versatile-926ejs ?= "c57230148694fc5902bdf9d157232c6ebb88dc1a"
LINUX_VERSION:kb-v6.6-standard-arm-versatile-926ejs = "6.6.28"
SRCREV_machine:kb-v6.6-standard-base ?= "c59995318b24c6b5a9969d43c0ca0179612aac2d"
LINUX_VERSION:kb-v6.6-standard-base = "6.6.28"
SRCREV_machine:kb-v6.6-standard-bcm-2xxx-rpi ?= "c59995318b24c6b5a9969d43c0ca0179612aac2d"
LINUX_VERSION:kb-v6.6-standard-bcm-2xxx-rpi = "6.6.28"
SRCREV_machine:kb-v6.6-standard-beaglebone ?= "c59995318b24c6b5a9969d43c0ca0179612aac2d"
LINUX_VERSION:kb-v6.6-standard-beaglebone = "6.6.28"
SRCREV_machine:kb-v6.6-standard-edgerouter ?= "c59995318b24c6b5a9969d43c0ca0179612aac2d"
LINUX_VERSION:kb-v6.6-standard-edgerouter = "6.6.28"
SRCREV_machine:kb-v6.6-standard-fsl-mpc8315e-rdb ?= "1e69aaf5c31446401e0631e4fa4c03bd78d36128"
LINUX_VERSION:kb-v6.6-standard-fsl-mpc8315e-rdb = "6.6.28"
SRCREV_machine:kb-v6.6-standard-mti-malta32 ?= "997005f111bca244db370a8ecaa3bcb37302d800"
LINUX_VERSION:kb-v6.6-standard-mti-malta32 = "6.6.28"
SRCREV_machine:kb-v6.6-standard-mti-malta64 ?= "262154440336f42524f03266bb0cc6e7ed62f9d6"
LINUX_VERSION:kb-v6.6-standard-mti-malta64 = "6.6.28"
SRCREV_machine:kb-v6.6-standard-nxp-ls20xx ?= "c59995318b24c6b5a9969d43c0ca0179612aac2d"
LINUX_VERSION:kb-v6.6-standard-nxp-ls20xx = "6.6.28"
SRCREV_machine:kb-v6.6-standard-nxp-sdk-6.6-nxp-soc ?= "bbcf840734671399c98efcea43dfd80da51795fb"
LINUX_VERSION:kb-v6.6-standard-nxp-sdk-6.6-nxp-soc = "6.6.28"
SRCREV_machine:kb-v6.6-standard-preempt-rt-arm-versatile-926ejs ?= "039c93f0a02e702983a3869272c884483c048371"
LINUX_VERSION:kb-v6.6-standard-preempt-rt-arm-versatile-926ejs = "6.6.28"
SRCREV_machine:kb-v6.6-standard-preempt-rt-base ?= "471a0c8db3216975eaf56a8fe3a19550a6210e27"
LINUX_VERSION:kb-v6.6-standard-preempt-rt-base = "6.6.28"
SRCREV_machine:kb-v6.6-standard-preempt-rt-bcm-2xxx-rpi ?= "9a4147ce743b06b5f819c52b16e6a0367973427c"
LINUX_VERSION:kb-v6.6-standard-preempt-rt-bcm-2xxx-rpi = "6.6.28"
SRCREV_machine:kb-v6.6-standard-preempt-rt-nxp-sdk-6.6-nxp-soc ?= "c7a69f2d14637dda6f093fc38eb5ee2ee9d26d7a"
LINUX_VERSION:kb-v6.6-standard-preempt-rt-nxp-sdk-6.6-nxp-soc = "6.6.28"
SRCREV_machine:kb-v6.6-standard-preempt-rt-x86 ?= "fbb4c2ac11087e8cf6069b159458e3d349f86095"
LINUX_VERSION:kb-v6.6-standard-preempt-rt-x86 = "6.6.28"
SRCREV_machine:kb-v6.6-standard-qemuarm64 ?= "c59995318b24c6b5a9969d43c0ca0179612aac2d"
LINUX_VERSION:kb-v6.6-standard-qemuarm64 = "6.6.28"
SRCREV_machine:kb-v6.6-standard-qemuppc ?= "c59995318b24c6b5a9969d43c0ca0179612aac2d"
LINUX_VERSION:kb-v6.6-standard-qemuppc = "6.6.28"
SRCREV_machine:kb-v6.6-standard-ti-am335x ?= "c59995318b24c6b5a9969d43c0ca0179612aac2d"
LINUX_VERSION:kb-v6.6-standard-ti-am335x = "6.6.28"
SRCREV_machine:kb-v6.6-standard-tiny-arm-versatile-926ejs ?= "c96c1d2be1068596ba3b04c46da0df89d8af685a"
LINUX_VERSION:kb-v6.6-standard-tiny-arm-versatile-926ejs = "6.6.28"
SRCREV_machine:kb-v6.6-standard-tiny-base ?= "c59995318b24c6b5a9969d43c0ca0179612aac2d"
LINUX_VERSION:kb-v6.6-standard-tiny-base = "6.6.28"
SRCREV_machine:kb-v6.6-standard-tiny-common-pc ?= "c59995318b24c6b5a9969d43c0ca0179612aac2d"
LINUX_VERSION:kb-v6.6-standard-tiny-common-pc = "6.6.28"
SRCREV_machine:kb-v6.6-standard-tiny-x86 ?= "c59995318b24c6b5a9969d43c0ca0179612aac2d"
LINUX_VERSION:kb-v6.6-standard-tiny-x86 = "6.6.28"
SRCREV_machine:kb-v6.6-standard-x86 ?= "c59995318b24c6b5a9969d43c0ca0179612aac2d"
LINUX_VERSION:kb-v6.6-standard-x86 = "6.6.28"
SRCREV_machine:kb-v6.6-standard-xilinx-zynqmp ?= "c59995318b24c6b5a9969d43c0ca0179612aac2d"
LINUX_VERSION:kb-v6.6-standard-xilinx-zynqmp = "6.6.28"

# yocto-kernel-cache entries
KERNEL_CACHE_BRANCH_6.6 = "yocto-6.6"
SRCREV_meta_6.6 = "1cd08f1fb2b33510783fa31c11150038a1ff8c42"
