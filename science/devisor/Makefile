# Created by: Pedro F. Giffuni
# $FreeBSD$

PORTNAME=	devisor
PORTVERSION=	2.1
PORTREVISION=	2
CATEGORIES=	science java
MASTER_SITES=	http://www.featflow.de/download/
DISTNAME=	devisor${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Design and Visualization Software Resource for FeatFlow

USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_BUILD=	yes	# Sources are available though

SUB_FILES=	devisorgrid.sh

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

DATAFILES=	data images misc manual
CLASSFILES=	devisor2 devisorgrid.class

PORTDOCS=	*
PLIST_FILES=	bin/devisorgrid

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/devisorgrid.sh ${STAGEDIR}${PREFIX}/bin/devisorgrid
	cd ${WRKSRC} \
	  && ${COPYTREE_SHARE} "${DATAFILES}" ${STAGEDIR}${DATADIR} "-not -name *\.pdf"
	cd ${WRKSRC} \
	  && ${COPYTREE_SHARE} "${CLASSFILES}" ${STAGEDIR}${DATADIR} "-name *\.class"
.if ${PORT_OPTIONS:MDOCS}
	cd ${WRKSRC}/manual \
	  && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} "-name *\.pdf"
.endif

post-install:
	@cd ${WRKSRC} \
	  && ${FIND} -s ${DATAFILES} -type f -not -name '*.pdf' \
	    | ${SED} -ne 's,^,${DATADIR_REL}/,p' >> ${TMPPLIST} \
	  && ${FIND} -s -d ${DATAFILES} -type d -empty \
	    | ${SED} -ne 's,^,@dir ${DATADIR_REL}/,p' >> ${TMPPLIST}
	@cd ${WRKSRC} \
	  && ${FIND} -s ${CLASSFILES} -name '*.class' -type f \
	    | ${SED} -ne 's,^,${DATADIR_REL}/,p' >> ${TMPPLIST} \
	  && ${FIND} -s -d ${CLASSFILES} -type d -empty \
	    | ${SED} -ne 's,^,@dir ${DATADIR_REL}/,p' >> ${TMPPLIST}

.include <bsd.port.mk>
