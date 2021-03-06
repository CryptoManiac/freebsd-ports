# Created by: luigi@FreeBSD.org
# $FreeBSD$

PORTNAME=	busybox
PORTVERSION=	1.22.1
PORTREVISION=	1
CATEGORIES=	sysutils misc shells
MASTER_SITES=	http://www.busybox.net/downloads/

PATCH_SITES=	http://www.busybox.net/downloads/fixes-${PORTVERSION}/
PATCH_DIST_STRIP=	-p1
PATCHFILES=	busybox-1.22.1-ash.patch \
		busybox-1.22.1-date.patch \
		busybox-1.22.1-iplink.patch \
		#

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	Busybox for FreeBSD

LICENSE=	GPLv2

BUILD_DEPENDS=	gsed:${PORTSDIR}/textproc/gsed

CONFLICTS_INSTALL=	busybox-unstable-*

PORTSCOUT=	skipv:1.23.0

MAKE_ARGS+=	SKIP_STRIP=y CC="${CC}" HOSTCC="${CC}" CXX="${CXX}" HOSTCXX="${CXX}"
# findutils/find.c l. 752+, uses a GCC extension/invalid C code:
USES=		compiler:nestedfct gmake tar:bz2

PLIST_FILES=	bin/busybox

OPTIONS_DEFINE=	DOCS STATIC

STATIC_LDFLAGS=	-static

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
USES+=		perl5
USE_PERL5=	build
PORTDOCS=	*
.endif

post-patch:
	${REINPLACE_CMD} -e 's/sed/gsed/' ${WRKSRC}/scripts/gen_build_files.sh
	${REINPLACE_CMD} -e 's/<malloc.h>/<stdlib.h>/' \
		${WRKSRC}/libbb/appletlib.c \
		${WRKSRC}/shell/hush.c
	${REINPLACE_CMD} -e 's/<alloca.h>/<stdlib.h>/' \
		${WRKSRC}/scripts/basic/*.c

do-configure:
	${CP} ${FILESDIR}/data-.config ${WRKSRC}/.config
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${_MAKE_JOBS} ${MAKE_ARGS} oldconfig

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
	${RM} -f ${STAGEDIR}${DOCSDIR}/.gitignore
.endif

.include <bsd.port.mk>
