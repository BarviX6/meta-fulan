FILESEXTRAPATHS_prepend := "${THISDIR}/${PN}:"

SRC_URI_append_sh4 = " file://usbhd-automount-sh4.rules"

do_install_append_sh4() {
	install -m 0644 ${WORKDIR}/usbhd-automount-sh4.rules ${D}${sysconfdir}/udev/rules.d/usbhd-automount.rules
}
