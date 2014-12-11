# Created by: Alex D. <balthazar.ad@gmail.com>
# $FreeBSD: head/net-p2p/novacoin/Makefile$

PORTNAME=	novacoin
PORTVERSION=	0.5.0
PORTREVISION=	0
CATEGORIES=	net-p2p
MASTER_SITES=	GH

MAINTAINER=	balthazar.ad@gmail.com
COMMENT=	Decentralized, open-source and energy-efficient cryptocurrency

LIB_DEPENDS=	libboost_date_time.so:${PORTSDIR}/devel/boost-libs libexecinfo.so:${PORTSDIR}/devel/libexecinfo

OPTIONS_DEFINE=	X11 QRCODES DBUS UPNP LEVELDB ASM
OPTIONS_DEFAULT= X11 QRCODES UPNP

UPNP_DESC=	Build with UPNP support
QRCODES_DESC=	Build with QR code display
LEVELDB_DESC= Build with LevelDB block index code
ASM_DESC= Use assembler implementation of scrypt

USE_GITHUB=	yes
GH_ACCOUNT=	novacoin-project
GH_PROJECT=	novacoin
GH_COMMIT=	92b6f58
GH_TAGNAME=	nvc-v${PORTVERSION}

USES=		gmake
USE_OPENSSL=	yes
USE_BDB=	yes
WANT_BDB_VER=	48

CXXFLAGS+=	-I${LOCALBASE}/include -I${BDB_INCLUDE_DIR}
LDFLAGS+=	-L${LOCALBASE}/lib -L${BDB_LIB_DIR}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MX11}
USE_QT4=	corelib network gui qmake_build linguist_build uic_build moc_build rcc_build

BINARY=		novacoin-qt
LIB_DEPENDS+=	libprotobuf.so:${PORTSDIR}/devel/protobuf
.else
BINARY=		novacoind
USE_RC_SUBR+=	novacoin
MAKE_ARGS+=	-C ${WRKSRC}/src
USE_GNOME=	glib20
.endif

.if ${PORT_OPTIONS:MQRCODES}
LIB_DEPENDS+=	libqrencode.so:${PORTSDIR}/graphics/libqrencode
QMAKE_USE_QRCODE=1
.else
QMAKE_USE_QRCODE=0
.endif

.if ${PORT_OPTIONS:MLEVELDB}
QMAKE_USE_LEVELDB=1
.else
QMAKE_USE_LEVELDB=0
.endif

.if ${PORT_OPTIONS:MASM}
QMAKE_USE_ASM=1
.else
QMAKE_USE_ASM=0
.endif

.if ${PORT_OPTIONS:MDBUS}
USE_QT4+=	dbus
QMAKE_USE_DBUS=	1
.else
QMAKE_USE_DBUS=	0
.endif

PLIST_FILES+=	bin/${BINARY}

.if ${PORT_OPTIONS:MUPNP}
LIB_DEPENDS+=	libminiupnpc.so:${PORTSDIR}/net/miniupnpc
QMAKE_USE_UPNP=	1
.else
QMAKE_USE_UPNP=	-
.endif

.include <bsd.port.pre.mk>

post-patch:
.if ${PORT_OPTIONS:MASM}
	USES=perl5
	USE_PERL5=patch
	@cd ${WRKSRC}/src && perl5 ${WRKSRC}/contrib/clang/nomacro.pl
.endif

.if !${PORT_OPTIONS:MX11}
	@cd ${WRKSRC}/src && ${CP} ${WRKSRC}/src/makefile.bsd Makefile
	@${REINPLACE_CMD} \
		-e 's|^USE_UPNP.*$$|USE_UPNP=${QMAKE_USE_UPNP}|' \
		-e 's|^USE_LEVELDB.*$$|USE_LEVELDB=${QMAKE_USE_LEVELDB}|' \
		-e 's|^USE_ASM.*$$|USE_ASM=${QMAKE_USE_ASM}|' \
		-e 's|-l pthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/src/Makefile
.endif

do-configure:
.if ${PORT_OPTIONS:MX11}
	cd ${WRKSRC} && ${SETENV} ${QMAKE_ENV} \
		${QMAKE} ${QMAKE_ARGS} USE_UPNP=${QMAKE_USE_UPNP} USE_QRCODE=${QMAKE_USE_QRCODE} USE_LEVELDB=${QMAKE_USE_LEVELDB} USE_ASM=${QMAKE_USE_ASM} \
		QMAKE_LRELEASE=${LRELEASE} INCLUDEPATH+=${BDB_INCLUDE_DIR} \
		QMAKE_LIBDIR+=${BDB_LIB_DIR} ${BINARY}.pro
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/bin
.if ${PORT_OPTIONS:MX11}
	${INSTALL_PROGRAM} ${WRKSRC}/${BINARY} ${STAGEDIR}${PREFIX}/bin/
.else
	${INSTALL_PROGRAM} ${WRKSRC}/src/${BINARY} ${STAGEDIR}${PREFIX}/bin/
.endif

.include <bsd.port.post.mk>
