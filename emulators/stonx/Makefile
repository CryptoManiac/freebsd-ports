# Created by: Tobias Reifenberger <tr@freebsd.mayn.de>
# $FreeBSD$

PORTNAME=	stonx
PORTVERSION=	0.6.7e.6
CATEGORIES=	emulators
MASTER_SITES=	SF/stonx/stonx/0.6.7.6
DISTNAME=	STonX-0.6.7.6

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	AtariST emulator

BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf \
		gccmakedep:${PORTSDIR}/devel/gccmakedep \
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir \
		mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale \
		${LOCALBASE}/lib/X11/fonts/misc/10x20-ISO8859-1.pcf.gz:${PORTSDIR}/x11-fonts/font-misc-misc
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir

RESTRICTED=	Contains ROM (C) by Atari

TOSIMG?=	tos.img
USE_XORG=	x11 sm ice xext xextproto
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--x-includes=${LOCALBASE}/include \
		--x-libraries=${LOCALBASE}/lib
ALL_TARGET=	all fnttobdf tosfonts fonts

BINDIR=	${PREFIX}/bin
FNTDIR=	${PREFIX}/lib/X11/fonts/misc

DATA=	atari/bench1.pas atari/bench1.prg
ETCFILES=	keysyms-alternative keysyms-german keysyms-spanish
DOCS=	../COPYING AUTHORS DEBUGGING INSTALL README RELEASE_NOTES \
	TOS-VERSIONS
FONTS=	System0-iso.pcf System0.pcf System1-iso.pcf System1.pcf \
	System2-iso.pcf System2.pcf

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.options.mk>

pre-build:
	${CP} ${DISTDIR}/${TOSIMG} ${WRKSRC}/tos.img

post-install:
.for f in ${ETCFILES}
	${INSTALL_DATA} ${WRKSRC}/etc/$f ${STAGEDIR}${ETCDIR}/
.endfor
	@${ECHO_MSG} "===> Installing fonts"
	${MKDIR} ${STAGEDIR}${FNTDIR}
.for f in ${FONTS}
	${INSTALL_DATA} ${WRKSRC}/data/$f ${STAGEDIR}${FNTDIR}/
	${GZIP_CMD} ${STAGEDIR}${FNTDIR}/$f
.endfor
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCS:S,^,${WRKSRC}/docs/,} ${STAGEDIR}${DOCSDIR}/
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${DATA:S,^,${WRKSRC}/,} ${STAGEDIR}${EXAMPLESDIR}/
.endif

.if !exists(${DISTDIR}/${TOSIMG})
IGNORE=	please get a ROM dump from your AtariST and save it as\
"${TOSIMG}" in "${DISTDIR}" manually, and then make again
.endif

.include <bsd.port.mk>
