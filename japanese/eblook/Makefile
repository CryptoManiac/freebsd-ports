# Created by: Shigeyuki Fukushima <shige@FreeBSD.org>
# $FreeBSD$

PORTNAME=	eblook
PORTVERSION=	1.6.1
PORTREVISION=	8
CATEGORIES=	japanese textproc
MASTER_SITES=	http://openlab.ring.gr.jp/edict/eblook/dist/
DIST_SUBDIR=	eb

MAINTAINER=	yasu@utahime.org
COMMENT=	Command to lookup words in EB format dictionaries

LICENSE=	GPLv2

LIB_DEPENDS=	libeb.so:${PORTSDIR}/japanese/eb

USES=		iconv
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--with-eb-conf=${PREFIX}/etc/eb.conf
CPPFLAGS+=	-I${ICONV_PREFIX}/include
LDFLAGS+=	-L${ICONV_PREFIX}/lib ${ICONV_LIB}

INFO=		eblook
PLIST_FILES=	bin/eblook
PORTDOCS=	AUTHORS COPYING ChangeLog NEWS README

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
