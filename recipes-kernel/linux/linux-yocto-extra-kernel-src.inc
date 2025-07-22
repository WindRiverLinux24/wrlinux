EXTRA_KERNEL_FILES ?= ""
EXTRA_KERNEL_SRC_URI ?= ""
EXTRA_KERNEL_FILES:prepend:bcm-2xxx-rpi4 = "${THISDIR}/linux-yocto:"

#Kernel CVE local patches for LTS24 2025 wk27-wk28
#LIN1024-8688 CVE-2025-22115 0001-LIN1024-8688-btrfs-fix-block-group-refcount-race-in-btrfs_create_.patch
#LIN1024-3112 CVE-2024-41023 0001-LIN1024-3112-sched-deadline-Fix-task_struct-reference-leak.patch
#LIN1024-6513 CVE-2025-21649 0001-LIN1024-6513-net-hns3-fix-kernel-crash-when-1588-is-sent-on-HIP08.patch
#LIN1024-9254 CVE-2025-37842 0001-LIN1024-9254-spi-fsl-qspi-use-devm-function-instead-of-driver-rem.patch
#LIN1024-8291 CVE-2025-21927 0001-LIN1024-8291-nvme-tcp-fix-potential-memory-corruption-in-nvme_tcp.patch
#LIN1024-7684 CVE-2024-42123 0001-LIN1024-7684-wifi-rtw89-fix-race-between-cancel_hw_scan-and-hw_sc.patch
#LIN1024-8202 CVE-2025-21729 0001-LIN1024-8202-RDMA-bnxt_re-Fix-the-page-details-for-the-srq-create.patch
#LIN1024-8209 CVE-2025-21892 0001-LIN1024-8209-RDMA-mlx5-Fix-the-recovery-flow-of-the-UMR-QP.patch

EXTRA_KERNEL_SRC_URI:append:bcm-2xxx-rpi4 = " \
    file://0001-Revert-Revert-mmc-sdhci-Mask-spurious-interrupts.patch \
	file://0001-LIN1024-8688-btrfs-fix-block-group-refcount-race-in-btrfs_create_.patch \
	file://0001-LIN1024-3112-sched-deadline-Fix-task_struct-reference-leak.patch \
	file://0001-LIN1024-6513-net-hns3-fix-kernel-crash-when-1588-is-sent-on-HIP08.patch \
	file://0001-LIN1024-9254-spi-fsl-qspi-use-devm-function-instead-of-driver-rem.patch \
	file://0001-LIN1024-8291-nvme-tcp-fix-potential-memory-corruption-in-nvme_tcp.patch \
	file://0001-LIN1024-7684-wifi-rtw89-fix-race-between-cance-n-and-hw_sc.patch \
	file://0001-LIN1024-8202-RDMA-bnxt_re-Fix-the-page-details-for-the-srq-create.patch \
	file://0001-LIN1024-8209-RDMA-mlx5-Fix-the-recovery-flow-of-the-UMR-QP.patch \
"

FILESEXTRAPATHS:prepend:osv-wrlinux := "${EXTRA_KERNEL_FILES}:"
SRC_URI:append:osv-wrlinux = " ${EXTRA_KERNEL_SRC_URI}"
