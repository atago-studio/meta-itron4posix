SUMMARY = "itron4posix"
DESCRIPTION = "ITRON4 API on the POSIX API (ITRON wrapper)"
LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://${THISDIR}/../../COPYING.MIT;md5=3da9cfbcb788c80a0384361b4de20420"

SRC_URI = "git://github.com/atago-studio/itron4posix;protocol=http"
SRC_URI[sha256sum] = "3c651e6d95105c5246f782136e8a0d17d9b98378779788a4c4ee5cfebaaaf349"
SRCREV = "d5591590384dbbf801e1a82a77256b22d85b117f"

APP_LIB = "/usr/lib"
APP_INC = "/usr/include"

FILES_${PN} += "${APP_LIB}/*.so*"
FILES_${PN}-staticdev += "${APP_LIB}/*.a"
FILES_${PN} += "${APP_INC}/*.h"

S = "${WORKDIR}/git"
TARGET_CC_ARCH += "${LDFLAGS}"

do_compile() {
	cd ${S}/src;make
}

do_install() {
	install -d ${D}${APP_LIB}
	install -m 0755 src/libitron.a ${D}${APP_LIB}
	install -d ${D}${APP_INC}
	install -m 0755 include/* ${D}${APP_INC}
}
