# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	audiofile
PORTVERSION=	0.2.4
PORTREVISION=	1
CATEGORIES=	audio ruby
MASTER_SITES=	SF/ruby-${PORTNAME}/ruby-${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	ruby-${PORTNAME}-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${CDDB_DISTNAME}${EXTRACT_SUFX}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby binding to the audiofile library

LIB_DEPENDS=	libaudiofile.so:${PORTSDIR}/audio/libaudiofile

USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes

CDDB_DISTNAME=	cddb-0.2
CDDB_WRKSRC=	${WRKDIR}/example

INSTALL_TARGET=	site-install
REINPLACE_ARGS=	-i ""

DOCS=		audiofile.rd

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -E -e "s,/home/jaredj/ruby-lib/(cddb),\1,g" \
		${CDDB_WRKSRC}/wavcddb

post-install:
	${MKDIR} ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/cddb
	${INSTALL_DATA} ${WRKSRC}/test.rb ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/
	${INSTALL_DATA} ${CDDB_WRKSRC}/* ${STAGEDIR}${RUBY_MODEXAMPLESDIR}/cddb/
	${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${RUBY_MODDOCDIR}/

.include <bsd.port.mk>
