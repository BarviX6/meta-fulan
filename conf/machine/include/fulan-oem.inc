# We know about rtc
include conf/machine/include/build-extras.inc

BRAND_OEM = "fulan"
MACHINE_NAME = "${@bb.utils.contains('MACHINE', 'spark7162', 'SPARK TRIPLEX', 'SPARK 990 LX', d)}"
MACHINE_BRAND = "GOLDEN MEDIA"
IMAGEDIR ?= "enigma2"
MTD_KERNEL = "mtd5"
MTD_ROOTFS = "mtd6"
KERNEL_FILE = "uImage"
ROOTFS_FILE = "e2jffs2.img"

MACHINE_KERNEL_PR = "r4"
KERNEL_MODULE_PACKAGE_SUFFIX = ""

TARGET_ARCH = "sh4"
DEFAULTTUNE = "sh4"

GCCVERSION = "4.9.4"
GLIBCVERSION = "2.23"

HOSTTOOLS_NONFATAL += "whoami"

OLDEST_KERNEL = "2.6.32"

PREFERRED_PROVIDER_virtual/kernel = "linux-fulan"
PREFERRED_VERSION_directfb = "1.7.7"
PREFERRED_VERSION_samba = "3.%"
PREFERRED_PROVIDER_lirc = "stlirc"
PREFERRED_PROVIDER_virtual/egl = "libstgles"
PREFERRED_PROVIDER_virtual/libgles1 = "libstgles"
PREFERRED_PROVIDER_virtual/enigma2-mediaservice ?= "enigma2-plugin-systemplugins-servicemp3"

SERIAL_CONSOLE = "115200 ttyAS0"

DVBPROVIDER = "kernel"

MACHINE_FEATURES += "3dtv alsa ext2 usbhost serial hdmicec switchoff singlecore legacykernel fulan textlcd sh4booster no-nmap omb skins1080 directfb wlan"
DISTRO_FEATURES_append += "gtk-directfb libsigc2"

KERNEL_IMAGETYPE = "uImage"
#KERNEL_OUTPUT = "${KERNEL_IMAGETYPE}"

JFFS2_ERASEBLOCK = "0x20000"
JFFS2_ENDIANNESS = "${@oe.utils.conditional('SITEINFO_ENDIANNESS', 'le', '--little-endian', '--big-endian', d)}"
EXTRA_IMAGECMD_jffs2 = "--pad ${JFFS2_ENDIANNESS} --eraseblock=${JFFS2_ERASEBLOCK} --no-cleanmarkers"
MKUBIFS_ARGS = "--pad ${JFFS2_ENDIANNESS} --eraseblock=${JFFS2_ERASEBLOCK} --no-cleanmarkers"
DVBMEDIASINK_CONFIG = "--with-wma --with-wmv --with-pcm --with-dtsdownmix --with-eac3"

IMAGE_FSTYPES ?= "jffs2"

# enable this for debug
IMAGE_FSTYPES += "tar.gz"
#IMAGE_FSTYPES += "spark71xx-usbimg"
#INHERIT += "usb_image-spark71xx"

IMAGE_CLASSES += "usb_image-spark71xx update_image-spark"
INITRAMFS_FSTYPES = "ext2.gz spark-updt"

IMAGE_CMD_jffs2_prepend = " \
    rm -rf ${IMAGE_ROOTFS}/tmp/*; \
    "

IMAGE_CMD_jffs2_append = "\
    ; \
    while [ ! -s ${IMGDEPLOYDIR}/${IMAGE_NAME}.rootfs.jffs2 ]; do sleep 1; done ; \
    cp ${IMGDEPLOYDIR}/${IMAGE_NAME}.rootfs.jffs2 ${DEPLOY_DIR_IMAGE}/${IMAGE_NAME}.rootfs.jffs2; \
    mkdir -p ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}; \
    while [ ! -s ${DEPLOY_DIR_IMAGE}/${IMAGE_NAME}.rootfs.jffs2 ]; do sleep 1; done ; \
    mv ${DEPLOY_DIR_IMAGE}/${IMAGE_NAME}.rootfs.jffs2 ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/${ROOTFS_FILE}; \
    cp ${DEPLOY_DIR_IMAGE}/uImage ${DEPLOY_DIR_IMAGE}/${IMAGEDIR}/${KERNEL_FILE}; \
    cd ${DEPLOY_DIR_IMAGE}; \
    zip ${IMAGE_NAME}_usb.zip ${IMAGEDIR}/*; \
    rm -f ${DEPLOY_DIR_IMAGE}/*.jffs2; \
    rm -f ${DEPLOY_DIR_IMAGE}/*.manifest; \
    rm -f ${DEPLOY_DIR_IMAGE}/.jffs2; \
    rm -f ${DEPLOY_DIR_IMAGE}/.manifest; \
    rm -rf ${IMAGEDIR}; \
    "

# Add uImage in tar image boot directory
IMAGE_CMD_tar_prepend = "\
    cp ${DEPLOY_DIR_IMAGE}/uImage ${IMAGE_ROOTFS}/boot/${KERNEL_FILE}; \
    "
	
MACHINE_ESSENTIAL_EXTRA_RDEPENDS += "\
    stlinux24-sh4-stx7111-fdma-firmware \
    libmme-image \
    stslave-fw \
    ustslave \
    stfbcontrol \
    fp-control \
    stlirc \
    stinit \
    fulan-dvb-modules-${MACHINE} \
    mountspark \
    mtd-utils-jffs2 \
    "

MACHINE_EXTRA_RRECOMMENDS += "\
    enigma2-plugin-systemplugins-servicemp3 \
    enigma2-plugin-systemplugins-serviceapp \
    enigma2-plugin-systemplugins-sh4osdadjustment \
    "

MACHINE_ESSENTIAL_EXTRA_RRECOMMENDS += "\
	kernel-module-mt7601usta \
	firmware-mt7601u \
	kernel-module-extrawlan-rt3070 \
	firmware-rt2870 \
    "

EXTRA_IMAGEDEPENDS += "\
    libpcre \
    libstgles \
    aio-grab \
    "

MACHINE_EXTRA_RDEPENDS += "\
    libpcre \
    aio-grab \
    "

include conf/machine/include/autoload-filesystems.inc
require conf/machine/include/tune-sh4.inc
require conf/machine/include/soc-family.inc
