# Created by: Martin Wilke <miwi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pam_ssh_agent_auth
PORTVERSION=	0.10.2
CATEGORIES=	security
MASTER_SITES=	SF/pamsshagentauth/${PORTNAME}/v${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PAM module which permits authentication via ssh-agent

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_func_strnvis=no
CONFIGURE_ARGS=	--libexecdir=${LOCALBASE}/lib
USES=		perl5 tar:bzip2

PLIST_FILES=	lib/pam_ssh_agent_auth.so \
		man/man8/pam_ssh_agent_auth.8.gz

.include <bsd.port.mk>
