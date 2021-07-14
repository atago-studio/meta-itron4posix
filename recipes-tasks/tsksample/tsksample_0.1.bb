SUMMARY = "original package"
SECTION = "applications"
LICENSE = "CLOSED"

#You should set your task source base path
FILESEXTRAPATHS_prepend := "${THISDIR}:"

SRC_PATH = "tasks"

SRC_URI = "file://${SRC_PATH}"

DEPENDS += " itron4posix"

#example
APP_BIN = "/usr/local/bin"
APP_LIB = "/usr/local/lib"

FILES_${PN} += "${APP_BIN}/*"
FILES_${PN} += "${APP_LIB}/*.so*"
FILES_${PN}-staticdev += "${APP_LIB}/*.a"

S = "${WORKDIR}/${SRC_PATH}"
TARGET_CC_ARCH += "${LDFLAGS}"

