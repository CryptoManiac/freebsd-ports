# Created by: bsam
# $FreeBSD$

PORTNAME=	libtheora
PORTVERSION=	1.0rc1
PORTREVISION=	1
CATEGORIES=	multimedia linux
MASTER_SITES=	CRITICAL/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Theora Video Compression Codec (Linux Fedora 10)

CONFLICTS=	linux-libtheora-[0-9]* 

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	f10
USE_LINUX_RPM=	yes

RPMVERSION=	2.fc10
USE_LDCONFIG=	yes

PLIST_FILES=	usr/lib/libtheora.so.0 usr/lib/libtheora.so.0.3.3 \
		usr/lib/libtheoradec.so.1 usr/lib/libtheoradec.so.1.0.0 \
		usr/lib/libtheoraenc.so.1 usr/lib/libtheoraenc.so.1.0.0
DOCSDIR=	${PREFIX}/usr/share/doc/${PORTNAME}-${PORTVERSION}
PORTDOCS=	COPYING README
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
