# Created by: Cezary Morga <cm@therek.net>
# $FreeBSD$

PORTNAME=	ORLite-Migrate
PORTVERSION=	1.10
PORTREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ADAMK
PKGNAMEPREFIX=	p5-

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Light weight SQLite-specific schema migration

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-File-pushd>=1.00:${PORTSDIR}/devel/p5-File-pushd \
		p5-IPC-Run3>=0.042:${PORTSDIR}/devel/p5-IPC-Run3 \
		p5-ORLite>=1.28:${PORTSDIR}/databases/p5-ORLite \
		p5-Probe-Perl>=0.01:${PORTSDIR}/sysutils/p5-Probe-Perl \
		p5-DBI>=1.58:${PORTSDIR}/databases/p5-DBI \
		p5-DBD-SQLite>=1.21:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-Params-Util>0.37:${PORTSDIR}/devel/p5-Params-Util \
		p5-File-Which>=0.05:${PORTSDIR}/sysutils/p5-File-Which
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
