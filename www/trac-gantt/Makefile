# Created by: Dryice Liu <dryice@dryice.name>
# $FreeBSD$

PORTNAME=	TracGantt
PORTVERSION=	0.3.2a
PORTREVISION=	7
CATEGORIES=	www devel python
MASTER_SITES=	http://willbarton.com/files/ \
		http://dryice.name/computer/FreeBSD/distfiles/
PKGNAMEPREFIX=	trac-

MAINTAINER=	dryice@dryice.name
COMMENT=	Plugin to creates Gantt charts for trac

RUN_DEPENDS+=	trac>=0.11:${PORTSDIR}/www/trac

USE_PYTHON=		2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	PKG-INFO README
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${INSTALL} -d ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include "${.CURDIR}/../../www/trac/plugin.mk"
.include <bsd.port.mk>
