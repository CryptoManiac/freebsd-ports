# Created by: Anton Berezin <tobez@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Data-Remember
PORTVERSION=	0.07
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	Data
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Remember complex information without giving yourself a headache

BUILD_DEPENDS=	p5-DBM-Deep>0:${PORTSDIR}/databases/p5-DBM-Deep \
		p5-YAML-Syck>0:${PORTSDIR}/textproc/p5-YAML-Syck \
		p5-UNIVERSAL-require>0:${PORTSDIR}/devel/p5-UNIVERSAL-require \
		p5-POE>0:${PORTSDIR}/devel/p5-POE
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
