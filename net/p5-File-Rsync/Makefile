# Created by: petef@FreeBSD.org
# $FreeBSD$

PORTNAME=	File-Rsync
PORTVERSION=	0.43
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Perl convenience wrapper for the rsync(1) program

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	rsync:${PORTSDIR}/net/rsync
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
