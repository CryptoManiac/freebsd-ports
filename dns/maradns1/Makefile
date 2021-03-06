# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	maradns
PORTVERSION=	1.4.14
CATEGORIES=	dns
MASTER_SITES=	http://maradns.samiam.org/download/1.4/\
		http://www.maradns.org/download/1.4/
PKGNAMESUFFIX=	1

MAINTAINER=	mat@FreeBSD.org
COMMENT=	DNS server with focus on security and simplicity

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	MaraDNS 1 end-of-life: June 21, 2015, use dns/maradns
EXPIRATION_DATE=2015-06-21

REINPLACE_ARGS=	-i ""
MAKE_ENV=	FLAGS="${CFLAGS}"

USE_RC_SUBR=	${PORTNAME} zoneserver
USERS=		bind
GROUPS=		bind

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e \
		's|/etc/maradns|${ETCDIR}|g; s|/etc/mararc|${ETCDIR}|g'
	@${FIND} ${WRKSRC} -name '*Makefile*' | ${XARGS} ${REINPLACE_CMD} -e \
		's|make|\$$\{MAKE\}|g ; \
		 s|^FLAGS =|#FLAGS =|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/server/maradns ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/tcp/getzone ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tcp/fetchzone ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tcp/zoneserver ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/askmara ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/duende ${STAGEDIR}${PREFIX}/bin

	${INSTALL_MAN} ${WRKSRC}/doc/en/man/askmara.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/en/man/getzone.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/en/man/fetchzone.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/en/man/maradns.8 ${STAGEDIR}${MANPREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/doc/en/man/zoneserver.8 ${STAGEDIR}${MANPREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/doc/en/man/duende.8 ${STAGEDIR}${MANPREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/doc/en/man/mararc.5 ${STAGEDIR}${MANPREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/doc/en/man/csv1.5 ${STAGEDIR}${MANPREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/doc/en/man/csv2.5 ${STAGEDIR}${MANPREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/doc/en/man/csv2_txt.5 ${STAGEDIR}${MANPREFIX}/man/man5

	${INSTALL_DATA} ${WRKSRC}/doc/en/examples/example_full_mararc ${STAGEDIR}${PREFIX}/etc/mararc.sample

	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/en/examples/example_csv2 ${STAGEDIR}${ETCDIR}/example_csv2
	${MKDIR} ${STAGEDIR}${ETCDIR}/logger
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/doc/en/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/en
	${INSTALL_DATA} ${WRKSRC}/doc/en/*.* ${STAGEDIR}${DOCSDIR}/en
	${INSTALL_DATA} ${WRKSRC}/doc/en/QuickStart ${STAGEDIR}${DOCSDIR}/en
	${INSTALL_DATA} ${WRKSRC}/doc/en/README ${STAGEDIR}${DOCSDIR}/en
	(cd ${WRKSRC}/doc/en && ${COPYTREE_SHARE} misc ${STAGEDIR}${DOCSDIR}/en)
	(cd ${WRKSRC}/doc/en && ${COPYTREE_SHARE} pdf ${STAGEDIR}${DOCSDIR}/en)
	(cd ${WRKSRC}/doc/en && ${COPYTREE_SHARE} tutorial ${STAGEDIR}${DOCSDIR}/en)
	(cd ${WRKSRC}/doc/en && ${COPYTREE_SHARE} text ${STAGEDIR}${DOCSDIR}/en)

.include <bsd.port.mk>
