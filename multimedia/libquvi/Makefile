# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libquvi
PORTVERSION=	0.4.1
PORTREVISION=	4
CATEGORIES=	multimedia devel
MASTER_SITES=	SF/quvi/${PORTVERSION:R}/${PORTNAME}/ \
		GOOGLE_CODE

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Cross-platform library for parsing flash media stream URLs

LICENSE=	LGPL21 LGPL3
LICENSE_COMB=	dual

BUILD_DEPENDS=	libquvi-scripts>=0.4.0:${PORTSDIR}/multimedia/libquvi-scripts
LIB_DEPENDS=	libcurl.so:${PORTSDIR}/ftp/curl
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	DOCS LUAJIT
LUAJIT_DESC=	Use LuaJIT instead of Lua

PORTSCOUT=	limit:0.4.[0-9]*

CPPFLAGS+=	-I${LOCALBASE}/include
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		iconv libtool pathfix pkgconfig tar:xz
USE_LDCONFIG=	yes

PORTDOCS=	*

PROJECTHOST=	quvi

LUAJIT_LIB_DEPENDS=	libluajit-5.1.so:${PORTSDIR}/lang/luajit
LUAJIT_USES_OFF=	lua

.include <bsd.port.options.mk>

post-patch:
.if ${PORT_OPTIONS:MLUAJIT}
	@${REINPLACE_CMD} 's|lua >= 5.1|luajit|g' ${WRKSRC}/configure
.else
	@${REINPLACE_CMD} 's|lua-5.1|lua-${LUA_VER}|g' ${WRKSRC}/configure
.endif

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/doc/nd/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
