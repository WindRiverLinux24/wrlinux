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
SRCREV_machine:kb-v6.6-base ?= "5e828009c8b380739e13da92be847f10461c38b1"
LINUX_VERSION:kb-v6.6-base = "6.6.27"
SRCREV_machine:kb-v6.6-standard-arm-versatile-926ejs ?= "51c07ec56f85fbbfa9ea6944a4b14eee7e715566"
LINUX_VERSION:kb-v6.6-standard-arm-versatile-926ejs = "6.6.27"
SRCREV_machine:kb-v6.6-standard-base ?= "4f3a41583a21c529bc7fc3a6c4a33bdffb16fa24"
LINUX_VERSION:kb-v6.6-standard-base = "6.6.27"
SRCREV_machine:kb-v6.6-standard-bcm-2xxx-rpi ?= "4f3a41583a21c529bc7fc3a6c4a33bdffb16fa24"
LINUX_VERSION:kb-v6.6-standard-bcm-2xxx-rpi = "6.6.27"
SRCREV_machine:kb-v6.6-standard-beaglebone ?= "4f3a41583a21c529bc7fc3a6c4a33bdffb16fa24"
LINUX_VERSION:kb-v6.6-standard-beaglebone = "6.6.27"
SRCREV_machine:kb-v6.6-standard-edgerouter ?= "4f3a41583a21c529bc7fc3a6c4a33bdffb16fa24"
LINUX_VERSION:kb-v6.6-standard-edgerouter = "6.6.27"
SRCREV_machine:kb-v6.6-standard-fsl-mpc8315e-rdb ?= "242ec0306e911c833ca56d4178baaef87407b28b"
LINUX_VERSION:kb-v6.6-standard-fsl-mpc8315e-rdb = "6.6.27"
SRCREV_machine:kb-v6.6-standard-mti-malta32 ?= "4bf661a8afc7323030a6af73fc5640ef4dabe01f"
LINUX_VERSION:kb-v6.6-standard-mti-malta32 = "6.6.27"
SRCREV_machine:kb-v6.6-standard-mti-malta64 ?= "d3abfe3c736d5869cb26f24c653b7e6eeafac715"
LINUX_VERSION:kb-v6.6-standard-mti-malta64 = "6.6.27"
SRCREV_machine:kb-v6.6-standard-nxp-ls20xx ?= "4f3a41583a21c529bc7fc3a6c4a33bdffb16fa24"
LINUX_VERSION:kb-v6.6-standard-nxp-ls20xx = "6.6.27"
SRCREV_machine:kb-v6.6-standard-nxp-sdk-6.6-nxp-soc ?= "684b6eec5fbda6cfaebef037ee98a4f34ee29c42"
LINUX_VERSION:kb-v6.6-standard-nxp-sdk-6.6-nxp-soc = "6.6.27"
SRCREV_machine:kb-v6.6-standard-preempt-rt-arm-versatile-926ejs ?= "1a4e954ad0a9b3b83cb8479fc7b435cdc4d0003b"
LINUX_VERSION:kb-v6.6-standard-preempt-rt-arm-versatile-926ejs = "6.6.27"
SRCREV_machine:kb-v6.6-standard-preempt-rt-base ?= "5272561b019836f2ee2f175b23029649431d6fca"
LINUX_VERSION:kb-v6.6-standard-preempt-rt-base = "6.6.27"
SRCREV_machine:kb-v6.6-standard-preempt-rt-bcm-2xxx-rpi ?= "3e3ff7905609e097b6ea902eaf893765b064e396"
LINUX_VERSION:kb-v6.6-standard-preempt-rt-bcm-2xxx-rpi = "6.6.27"
SRCREV_machine:kb-v6.6-standard-preempt-rt-nxp-sdk-6.6-nxp-soc ?= "7706cccdb9362935b3db097e621b199fcdea9c50"
LINUX_VERSION:kb-v6.6-standard-preempt-rt-nxp-sdk-6.6-nxp-soc = "6.6.27"
SRCREV_machine:kb-v6.6-standard-preempt-rt-x86 ?= "bfa0d6cc9aac162c6d82724d1beeefd98710c185"
LINUX_VERSION:kb-v6.6-standard-preempt-rt-x86 = "6.6.27"
SRCREV_machine:kb-v6.6-standard-qemuarm64 ?= "4f3a41583a21c529bc7fc3a6c4a33bdffb16fa24"
LINUX_VERSION:kb-v6.6-standard-qemuarm64 = "6.6.27"
SRCREV_machine:kb-v6.6-standard-qemuppc ?= "4f3a41583a21c529bc7fc3a6c4a33bdffb16fa24"
LINUX_VERSION:kb-v6.6-standard-qemuppc = "6.6.27"
SRCREV_machine:kb-v6.6-standard-ti-am335x ?= "4f3a41583a21c529bc7fc3a6c4a33bdffb16fa24"
LINUX_VERSION:kb-v6.6-standard-ti-am335x = "6.6.27"
SRCREV_machine:kb-v6.6-standard-tiny-arm-versatile-926ejs ?= "f659799f1ecd7904f3743cb17d6909ba524429fe"
LINUX_VERSION:kb-v6.6-standard-tiny-arm-versatile-926ejs = "6.6.27"
SRCREV_machine:kb-v6.6-standard-tiny-base ?= "4f3a41583a21c529bc7fc3a6c4a33bdffb16fa24"
LINUX_VERSION:kb-v6.6-standard-tiny-base = "6.6.27"
SRCREV_machine:kb-v6.6-standard-tiny-common-pc ?= "4f3a41583a21c529bc7fc3a6c4a33bdffb16fa24"
LINUX_VERSION:kb-v6.6-standard-tiny-common-pc = "6.6.27"
SRCREV_machine:kb-v6.6-standard-tiny-x86 ?= "4f3a41583a21c529bc7fc3a6c4a33bdffb16fa24"
LINUX_VERSION:kb-v6.6-standard-tiny-x86 = "6.6.27"
SRCREV_machine:kb-v6.6-standard-x86 ?= "4f3a41583a21c529bc7fc3a6c4a33bdffb16fa24"
LINUX_VERSION:kb-v6.6-standard-x86 = "6.6.27"
SRCREV_machine:kb-v6.6-standard-xilinx-zynqmp ?= "4f3a41583a21c529bc7fc3a6c4a33bdffb16fa24"
LINUX_VERSION:kb-v6.6-standard-xilinx-zynqmp = "6.6.27"

# yocto-kernel-cache entries
KERNEL_CACHE_BRANCH_6.6 = "yocto-6.6"
SRCREV_meta_6.6 = "c3d1322fb6ff68cdcf4d7a3c1140d81bfdc1320a"
