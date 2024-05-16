IMAGE_INSTALL += " dpdk dpdk-tools dpdk-module"

BSP_NXP_DERIVED ??= ""
# NXP dpdk supports dpdk-examples, so install this package when building dpdk for NXP ls/lx series platform.
IMAGE_INSTALL:append = " ${@bb.utils.contains_any('MACHINE', '${BSP_NXP_DERIVED}', 'dpdk-examples', '', d)}"
# NXP BSPs doesn't need dpdk-module package, so remove it for these BSPs.
IMAGE_INSTALL:remove = "${@bb.utils.contains_any('MACHINE', '${BSP_NXP_DERIVED}', 'dpdk-module', '', d)}"
