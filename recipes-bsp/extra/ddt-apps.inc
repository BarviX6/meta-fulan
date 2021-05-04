HOMEPAGE = "https://github/Duckbox-Developers/apps"
SECTION = "base"
LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://${OPENPLI_BASE}/LICENSE;md5=eb723b61539feef013de476e68b5c50a"
DEPENDS = "fulan-dvb-modules-${MACHINE}"

inherit autotools gitpkgv

SRCREV = "${AUTOREV}"
PV = "1.0+git${SRCPV}"
PKGV = "1.0+git${GITPKGV}"

SRC_URI = " \
    git://github.com/BarviX6/apps.git;protocol=git \
"

S = "${WORKDIR}/git/tools/${@d.getVar('PN',1).replace('-', '_')}"

EXTRA_OECONF = "--enable-silent-rules --prefix="
LDFLAGS += "-lpthread -lrt"
EXTRA_OEMAKE = " DRIVER_TOPDIR=${STAGING_KERNEL_DIR}"
CFLAGS_append = " -I${STAGING_KERNEL_DIR}/multicom/include"

do_configure_prepend() {
    touch ${S}/NEWS
    touch ${S}/README
    touch ${S}/AUTHORS
    touch ${S}/COPYING
    touch ${S}/ChangeLog
}

