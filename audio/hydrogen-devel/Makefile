# Created by: Shane Ambler <FreeBSD@ShaneWare.Biz>
# $FreeBSD$

PORTNAME=	hydrogen-devel
PORTVERSION=	0.9.6r2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	GH

MAINTAINER=	FreeBSD@ShaneWare.Biz
COMMENT=	Advanced drum machine

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

CONFLICTS=	hydrogen-0.*

LIB_DEPENDS+=	libsndfile.so:${PORTSDIR}/audio/libsndfile \
		libtar.so:${PORTSDIR}/devel/libtar

USE_GITHUB=	yes
GH_ACCOUNT=	hydrogen-music
GH_PROJECT=	hydrogen
GH_TAGNAME=	0.9.6-RC2
GH_COMMIT=	2ff9010

MAJORVERSION=	0.9.6
USE_QT4=	corelib gui qmake_build linguist_build moc_build network \
		qt3support rcc_build sql uic_build xml
USES=		cmake:outsource desktop-file-utils pkgconfig
CMAKE_ARGS+=	-DTHREADS_HAVE_PTHREAD_ARG:BOOL=ON -DWANT_DEBUG:BOOL=OFF \
		-DLIBSNDFILE_INCLUDE_DIR:STRING=${LOCALBASE}/include
USE_LDCONFIG=	yes
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=		ALSA JACK LADSPA LASH LIBARCHIVE OSS PORTAUDIO RDF RUBBERBAND
OPTIONS_DEFAULT=	JACK LADSPA LIBARCHIVE OSS RDF

ALSA_CMAKE_ON=		-DWANT_ALSA:BOOL=ON
ALSA_CMAKE_OFF=		-DWANT_ALSA:BOOL=OFF
ALSA_LIB_DEPENDS=	libasound.so:${PORTSDIR}/audio/alsa-lib
ALSA_RUN_DEPENDS=	alsa-plugins>=0:${PORTSDIR}/audio/alsa-plugins

JACK_CMAKE_ON=		-DWANT_JACK:BOOL=ON -DWANT_JACKSESSION:BOOL=ON
JACK_CMAKE_OFF=		-DWANT_JACK:BOOL=OFF -DWANT_JACKSESSION:BOOL=OFF
JACK_LIB_DEPENDS=	libjack.so:${PORTSDIR}/audio/jack

LADSPA_CMAKE_ON=	-DWANT_LADSPA:BOOL=ON \
			-DLADSPA_LIBRARIES:STRING=${LOCALBASE}/lib/ladspa
LADSPA_CMAKE_OFF=	-DWANT_LADSPA:BOOL=OFF
LADSPA_BUILD_DEPENDS=	ladspa>=0:${PORTSDIR}/audio/ladspa
LADSPA_RUN_DEPENDS=	analyseplugin:${PORTSDIR}/audio/ladspa

LASH_CMAKE_ON=		-DWANT_LASH:BOOL=ON \
			-DLASH_INCLUDE_DIR:STRING=${LOCALBASE}/include/lash-1.0
LASH_CMAKE_OFF=		-DWANT_LASH:BOOL=OFF
LASH_LIB_DEPENDS=	liblash.so:${PORTSDIR}/audio/lash

LIBARCHIVE_DESC=	LibArchive support
LIBARCHIVE_CMAKE_ON=	-DWANT_LIBARCHIVE:BOOL=ON
LIBARCHIVE_CMAKE_OFF=	-DWANT_LIBARCHIVE:BOOL=OFF
LIBARCHIVE_LIB_DEPENDS=	libarchive.so:${PORTSDIR}/archivers/libarchive

OSS_CMAKE_ON=		-DWANT_OSS:BOOL=ON
OSS_CMAKE_OFF=		-DWANT_OSS:BOOL=OFF

PORTAUDIO_CMAKE_ON=	-DWANT_PORTAUDIO:BOOL=ON \
			-DPORTAUDIO_INCLUDE_DIR:STRING=${LOCALBASE}/include/portaudio2 \
			-DPORTAUDIO_LIBRARIES:STRING=${LOCALBASE}/lib/portaudio2/libportaudio.so
PORTAUDIO_CMAKE_OFF=	-DWANT_PORTAUDIO:BOOL=OFF
PORTAUDIO_LIB_DEPENDS=	libportaudio.so.2:${PORTSDIR}/audio/portaudio2

RDF_DESC=		RDF File support
RDF_CMAKE_ON=		-DWANT_LRDF:BOOL=ON
RDF_CMAKE_OFF=		-DWANT_LRDF:BOOL=OFF
RDF_LIB_DEPENDS=	liblrdf.so:${PORTSDIR}/textproc/liblrdf
RDF_CXXFLAGS=		-I${LOCALBASE}/include/raptor2

# using librubberband is experimental and current versions have bad timing
# installing the rubberband cli tool still works as before
RUBBERBAND_DESC=	librubberband for time stretching
RUBBERBAND_CMAKE_ON=	-DWANT_RUBBERBAND:BOOL=ON \
			-DRUBBERBAND_INCLUDE_DIR:STRING=${LOCALBASE}/include/rubberband
RUBBERBAND_CMAKE_OFF=	-DWANT_RUBBERBAND:BOOL=OFF
RUBBERBAND_LIB_DEPENDS=	librubberband.so:${PORTSDIR}/audio/rubberband

.include <bsd.port.mk>
