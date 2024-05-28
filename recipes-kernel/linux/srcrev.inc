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
SRCREV_machine:kb-v6.6-base ?= "91de249b6804473d49984030836381c3b9b3cfb0"
LINUX_VERSION:kb-v6.6-base = "6.6.32"
SRCREV_machine:kb-v6.6-standard-arm-versatile-926ejs ?= "6e4ec0ec5052e3a107ec7e5977ea9282d3642ea7"
LINUX_VERSION:kb-v6.6-standard-arm-versatile-926ejs = "6.6.32"
SRCREV_machine:kb-v6.6-standard-base ?= "9576b5b9f8e3c78e6c315f475def18e5c29e475a"
LINUX_VERSION:kb-v6.6-standard-base = "6.6.32"
SRCREV_machine:kb-v6.6-standard-bcm-2xxx-rpi ?= "9576b5b9f8e3c78e6c315f475def18e5c29e475a"
LINUX_VERSION:kb-v6.6-standard-bcm-2xxx-rpi = "6.6.32"
SRCREV_machine:kb-v6.6-standard-beaglebone ?= "9576b5b9f8e3c78e6c315f475def18e5c29e475a"
LINUX_VERSION:kb-v6.6-standard-beaglebone = "6.6.32"
SRCREV_machine:kb-v6.6-standard-edgerouter ?= "9576b5b9f8e3c78e6c315f475def18e5c29e475a"
LINUX_VERSION:kb-v6.6-standard-edgerouter = "6.6.32"
SRCREV_machine:kb-v6.6-standard-fsl-mpc8315e-rdb ?= "b446489ebbf29a6ff8d83ef74e0a371bde34e0cb"
LINUX_VERSION:kb-v6.6-standard-fsl-mpc8315e-rdb = "6.6.32"
SRCREV_machine:kb-v6.6-standard-mti-malta32 ?= "cab976b23497344b74b7e4cbcb5df732f8630150"
LINUX_VERSION:kb-v6.6-standard-mti-malta32 = "6.6.32"
SRCREV_machine:kb-v6.6-standard-mti-malta64 ?= "aa0c0197b3a0628992e959708a2ad015603e93ad"
LINUX_VERSION:kb-v6.6-standard-mti-malta64 = "6.6.32"
SRCREV_machine:kb-v6.6-standard-nxp-ls20xx ?= "9576b5b9f8e3c78e6c315f475def18e5c29e475a"
LINUX_VERSION:kb-v6.6-standard-nxp-ls20xx = "6.6.32"
SRCREV_machine:kb-v6.6-standard-nxp-sdk-6.6-nxp-soc ?= "5422d57e79fa0c5b6a47fe18b5ea783224c18372"
LINUX_VERSION:kb-v6.6-standard-nxp-sdk-6.6-nxp-soc = "6.6.32"
SRCREV_machine:kb-v6.6-standard-preempt-rt-arm-versatile-926ejs ?= "cd394769f4c4dd702c702eeac073d080ea8e8fc5"
LINUX_VERSION:kb-v6.6-standard-preempt-rt-arm-versatile-926ejs = "6.6.32"
SRCREV_machine:kb-v6.6-standard-preempt-rt-base ?= "59b2635b04e2ef8162e52f82e848b81073cea708"
LINUX_VERSION:kb-v6.6-standard-preempt-rt-base = "6.6.32"
SRCREV_machine:kb-v6.6-standard-preempt-rt-bcm-2xxx-rpi ?= "4bd407daaaff964ce8ee91300e253e144546d533"
LINUX_VERSION:kb-v6.6-standard-preempt-rt-bcm-2xxx-rpi = "6.6.32"
SRCREV_machine:kb-v6.6-standard-preempt-rt-nxp-sdk-6.6-nxp-soc ?= "1eff2e17c42a5a3ebc983be8d6ae2c86d0be3284"
LINUX_VERSION:kb-v6.6-standard-preempt-rt-nxp-sdk-6.6-nxp-soc = "6.6.32"
SRCREV_machine:kb-v6.6-standard-preempt-rt-x86 ?= "244b4225dcee445d6b093098c8ef87ad04b6276a"
LINUX_VERSION:kb-v6.6-standard-preempt-rt-x86 = "6.6.32"
SRCREV_machine:kb-v6.6-standard-qemuarm64 ?= "9576b5b9f8e3c78e6c315f475def18e5c29e475a"
LINUX_VERSION:kb-v6.6-standard-qemuarm64 = "6.6.32"
SRCREV_machine:kb-v6.6-standard-qemuppc ?= "9576b5b9f8e3c78e6c315f475def18e5c29e475a"
LINUX_VERSION:kb-v6.6-standard-qemuppc = "6.6.32"
SRCREV_machine:kb-v6.6-standard-ti-am335x ?= "9576b5b9f8e3c78e6c315f475def18e5c29e475a"
LINUX_VERSION:kb-v6.6-standard-ti-am335x = "6.6.32"
SRCREV_machine:kb-v6.6-standard-tiny-arm-versatile-926ejs ?= "503e7e960d8030b6fa0a5e0df951b2c2d4182eb1"
LINUX_VERSION:kb-v6.6-standard-tiny-arm-versatile-926ejs = "6.6.32"
SRCREV_machine:kb-v6.6-standard-tiny-base ?= "9576b5b9f8e3c78e6c315f475def18e5c29e475a"
LINUX_VERSION:kb-v6.6-standard-tiny-base = "6.6.32"
SRCREV_machine:kb-v6.6-standard-tiny-common-pc ?= "9576b5b9f8e3c78e6c315f475def18e5c29e475a"
LINUX_VERSION:kb-v6.6-standard-tiny-common-pc = "6.6.32"
SRCREV_machine:kb-v6.6-standard-tiny-x86 ?= "9576b5b9f8e3c78e6c315f475def18e5c29e475a"
LINUX_VERSION:kb-v6.6-standard-tiny-x86 = "6.6.32"
SRCREV_machine:kb-v6.6-standard-x86 ?= "cd1adfbf1a15d30852d917386a3af12e1406befe"
LINUX_VERSION:kb-v6.6-standard-x86 = "6.6.32"
SRCREV_machine:kb-v6.6-standard-xilinx-zynqmp ?= "9576b5b9f8e3c78e6c315f475def18e5c29e475a"
LINUX_VERSION:kb-v6.6-standard-xilinx-zynqmp = "6.6.32"

# yocto-kernel-cache entries
KERNEL_CACHE_BRANCH_6.6 = "yocto-6.6"
SRCREV_meta_6.6 = "66bebb6789d02e775d4c93d7ca4bf79c2ead4b28"
