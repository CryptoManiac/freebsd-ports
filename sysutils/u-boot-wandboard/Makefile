# $FreeBSD$

PORTNAME=	u-boot
PORTVERSION=	2013.10
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-wandboard
DISTNAME=	u-boot-${PORTVERSION}-technexion-edm

MAINTAINER=	ian@FreeBSD.org
COMMENT=	Cross-build U-Boot loader for Wandboard (solo, dual, and quad)

LICENSE=	GPLv2

BUILD_DEPENDS=  arm-none-eabi-gcc:${PORTSDIR}/devel/arm-none-eabi-gcc

USE_GITHUB=	yes
GH_ACCOUNT=	TechNexion
GH_PROJECT=	u-boot-edm
GH_COMMIT=	87f595d
GH_TAGNAME=	${GH_COMMIT}
NO_ARCH=	yes

WRKSRC=		${WRKDIR}/${GH_ACCOUNT}-${GH_PROJECT}-${GH_TAGNAME}
USES=		gmake
SSP_UNSAFE=	yes # cross-build static linking dies with -fstack-protector

U_BOOT_DIR=	share/u-boot/${PORTNAME}${PKGNAMESUFFIX}
PLIST_DIRS=	${U_BOOT_DIR} share/u-boot
PLIST_FILES=	${U_BOOT_DIR}/u-boot.imx \
		${U_BOOT_DIR}/README

MAKE_ARGS+=	ARCH=arm \
		CROSS_COMPILE=arm-none-eabi- \
		HOSTCC=clang

do-configure:
	cd ${WRKSRC}; ${GMAKE} ${MAKE_ARGS} edm_cf_imx6_config

# The build results in two output files: SPL, and u-boot.img.
# Combine them into a single u-boot.imx so that there is only one file to be
# copied onto the boot media starting at a 1K offset on the disk.
IMXFILE=	${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}/u-boot.imx
do-install:
	${MKDIR} ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}
	dd bs=1k oseek=0  conv=sync of=${IMXFILE} if=${WRKSRC}/SPL
	dd bs=1k oseek=68 conv=sync of=${IMXFILE} if=${WRKSRC}/u-boot.img
	${CP} ${.CURDIR}/pkg-descr ${STAGEDIR}/${PREFIX}/${U_BOOT_DIR}/README

.include <bsd.port.mk>
