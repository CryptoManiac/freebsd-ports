# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libmrss
PORTVERSION=	0.19.2
PORTREVISION=	7
CATEGORIES=	textproc
MASTER_SITES=	http://www.autistici.org/bakunin/libmrss/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C library for parsing, writing, and creating RSS

LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl \
		libnxml.so:${PORTSDIR}/textproc/libnxml

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USES=		libtool pathfix pkgconfig
USE_LDCONFIG=	yes

.include <bsd.port.mk>
