# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	efl
PORTVERSION=	1.12.1
PORTREVISION=	1
CATEGORIES=	devel enlightenment
MASTER_SITES=	http://download.enlightenment.org/rel/libs/${PORTNAME}/

MAINTAINER=	gblach@FreeBSD.org
COMMENT=	Enlightenment Foundation Libraries

LICENSE=	BSD2CLAUSE LGPL21
LICENSE_COMB=	multi

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libgif.so:${PORTSDIR}/graphics/giflib \
		libpng.so:${PORTSDIR}/graphics/png \
		libtiff.so:${PORTSDIR}/graphics/tiff \
		libfreetype.so:${PORTSDIR}/print/freetype2 \
		libfontconfig.so:${PORTSDIR}/x11-fonts/fontconfig \
		libdbus-1.so:${PORTSDIR}/devel/dbus \
		libluajit-5.1.so:${PORTSDIR}/lang/luajit \
		libsndfile.so:${PORTSDIR}/audio/libsndfile

DIST_SUBDIR=	enlightenment
USE_AUTOTOOLS=	automake aclocal autoconf
GNU_CONFIGURE=	yes
USES=		compiler:c++11-lib gmake libtool pathfix pkgconfig shared-mime-info tar:xz
USE_XORG=	x11 xcursor xcomposite xdamage xext xinerama xp xrandr xtst xscrnsaver
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--with-profile=release \
		--enable-i-really-know-what-i-am-doing-and-that-this-will-probably-break-things-and-i-will-fix-them-myself-and-send-patches-aba
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	BRANCHVERSION=${PORTVERSION:R} PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=		AVAHI FRIBIDI HARFBUZZ NVIDIA PHYSICS PULSEAUDIO SSL
OPTIONS_GROUP=		ENGINE EMOTION INPUT LOADER
OPTIONS_GROUP_ENGINE=	OPENGL SDL
OPTIONS_GROUP_EMOTION=	GSTREAMER LIBXINE V4L
OPTIONS_GROUP_INPUT=	IBUS SCIM
OPTIONS_GROUP_LOADER=	OPENJPEG WEBP
OPTIONS_DEFAULT=	FRIBIDI HARFBUZZ PHYSICS SSL OPENGL GSTREAMER
OPTIONS_SUB=		yes

HARFBUZZ_DESC=		OpenType text shaping engine
NVIDIA_DESC=		Apply Nvidia workaround
PHYSICS_DESC=		Physics effects
IBUS_DESC=		Intelligent Input Bus
SCIM_DESC=		Smart Common Input Method

AVAHI_LIB_DEPENDS=		libavahi-client.so:${PORTSDIR}/net/avahi-app
AVAHI_CONFIGURE_ENABLE=		avahi

FRIBIDI_LIB_DEPENDS=		libfribidi.so:${PORTSDIR}/converters/fribidi
FRIBIDI_CONFIGURE_ENABLE=	fribidi

HARFBUZZ_LIB_DEPENDS=		libharfbuzz.so:${PORTSDIR}/print/harfbuzz
HARFBUZZ_CONFIGURE_ENABLE=	harfbuzz

PULSEAUDIO_LIB_DEPENDS=		libpulse.so:${PORTSDIR}/audio/pulseaudio
PULSEAUDIO_CONFIGURE_ENABLE=	pulseaudio

PHYSICS_LIB_DEPENDS=		libBulletDynamics.so:${PORTSDIR}/devel/bullet
PHYSICS_CONFIGURE_ENABLE=	physics

OPENGL_USE=			GL=gl

SLD_USE=			SLD=sdl
SLD_CONFIGURE_ENABLE=		sdl

GSTREAMER_USE=			GSTREAMER1=core
GSTREAMER_CONFIGURE_ENABLE=	gstreamer1

LIBXINE_LIB_DEPENDS=		libxine.so:${PORTSDIR}/multimedia/libxine
LIBXINE_CONFIGURE_ENABLE=	xine

V4L_BUILD_DEPENDS=		${LOCALBASE}/include/linux/videodev2.h:${PORTSDIR}/multimedia/v4l_compat
V4L_CONFIGURE_ENABLE=		v4l2

IBUS_LIB_DEPENDS=		libibus-1.0.so:${PORTSDIR}/textproc/ibus

SCIM_LIB_DEPENDS=		libscim-1.0.so:${PORTSDIR}/textproc/scim
SCIM_CONFIGURE_ENABLE=		scim

OPENJPEG_LIB_DEPENDS=		libopenjpeg.so:${PORTSDIR}/graphics/openjpeg15
OPENJPEG_CONFIGURE_ENABLE=	image-loader-jp2k

WEBP_LIB_DEPENDS=		libwebp.so:${PORTSDIR}/graphics/webp
WEBP_CONFIGURE_ENABLE=		image-loader-webp

DOCS_BUILD_DEPENDS=		doxygen:${PORTSDIR}/devel/doxygen
DOCS_CONFIGURE_ENABLE=		doc

NLS_USES=			gettext
NLS_CONFIGURE_ENABLE=		nls

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNVIDIA}
EXTRA_PATCHES+=			${FILESDIR}/extra-patch-src-lib-ecore_x-ecore_x_vsync_tool.c
.endif

.if ${PORT_OPTIONS:MSSL}
USE_OPENSSL=			yes
WITH_OPENSSL_PORT=		yes
.else
CONFIGURE_ARGS+=		--with-crypto=none
.endif

.if empty(PORT_OPTIONS:MOPENGL)
CONFIGURE_ARGS+=		--with-opengl=none
.endif

.if ${PORT_OPTIONS:MGSTREAMER} || ${PORT_OPTIONS:MLIBXINE} || ${PORT_OPTIONS:MV4L}
PLIST_SUB+=			EMOTION=""
.else
PLIST_SUB+=			EMOTION="@comment "
.endif

.if ${PORT_OPTIONS:MIBUS}
CONFIGURE_ARGS+=		--with-glib=yes
.else
CONFIGURE_ARGS+=		--disable-ibus --with-glib=no
.endif

.if ${PORT_OPTIONS:MNLS}
PLIST_SUB+=			NLS=""
.else
PLIST_SUB+=			NLS="@comment "
.endif

.if ${PORT_OPTIONS:MPULSEAUDIO}
PLIST_SUB+=			AUDIO=""
.else
CONFIGURE_ARGS+=		--disable-audio
PLIST_SUB+=			AUDIO="@comment "
.endif

pre-patch:
	@${REINPLACE_CMD} -e \
		's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.am

post-stage:
	${RM} -rf ${STAGEDIR}${PREFIX}/share/gdb
	for i in `${FIND} ${STAGEDIR}${PREFIX}/bin ${STAGEDIR}${PREFIX}/lib -type f`; do \
	    if ${FILE} $$i | ${GREP} -q "not stripped"; then ${STRIP_CMD} $$i; fi; \
	done

.include <bsd.port.mk>
