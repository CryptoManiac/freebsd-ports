# Created by: dwcjr@inethouston.net
# $FreeBSD$

PORTNAME=	openssh
DISTVERSION=	6.6p1
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	security ipv6
MASTER_SITES=	${MASTER_SITE_OPENBSD}
MASTER_SITE_SUBDIR=	OpenSSH/portable
PKGNAMESUFFIX?=	-portable66

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	The portable version of OpenBSD's OpenSSH

#LICENSE=      BSD2,BSD3,MIT,public domain,BSD-Style,BEER-WARE,"any purpose with notice intact",ISC-Style
#LICENSE_FILE= ${WRKSRC}/LICENCE

CONFLICTS?=		openssh-3.* ssh-1.* ssh2-3.*

USES=			alias
USE_AUTOTOOLS=		autoconf autoheader
USE_OPENSSL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV=		ac_cv_func_strnvis=no
CONFIGURE_ARGS=		--prefix=${PREFIX} --with-md5-passwords \
			--without-zlib-version-check --with-ssl-engine
PRECIOUS=		ssh_config sshd_config ssh_host_key ssh_host_key.pub \
			ssh_host_rsa_key ssh_host_rsa_key.pub ssh_host_dsa_key \
			ssh_host_dsa_key.pub
ETCOLD=			${PREFIX}/etc

SUDO?=		# empty
MAKE_ENV+=	SUDO="${SUDO}"

# https://github.com/openssh/openssh-portable/commit/5618210618256bbf5f4f71b2887ff186fd451736.patch
EXTRA_PATCHES+=		${FILESDIR}/extra-patch-openssh661

OPTIONS_DEFINE=		PAM TCP_WRAPPERS LIBEDIT BSM \
			HPN LPK X509 KERB_GSSAPI \
			OVERWRITE_BASE SCTP AES_THREADED LDNS NONECIPHER
OPTIONS_DEFAULT=	LIBEDIT PAM TCP_WRAPPERS HPN LDNS NONECIPHER
OPTIONS_RADIO=		KERBEROS
OPTIONS_RADIO_KERBEROS=	MIT HEIMDAL HEIMDAL_BASE
TCP_WRAPPERS_DESC=	tcp_wrappers support
BSM_DESC=		OpenBSM Auditing
KERB_GSSAPI_DESC=	Kerberos/GSSAPI patch (req: GSSAPI)
HPN_DESC=		HPN-SSH patch
LPK_DESC=		LDAP Public Key (LPK) [OBSOLETE]
LDNS_DESC=		SSHFP/LDNS support
X509_DESC=		x509 certificate patch
SCTP_DESC=		SCTP support
OVERWRITE_BASE_DESC=	OpenSSH overwrite base
HEIMDAL_DESC=		Heimdal Kerberos (security/heimdal)
HEIMDAL_BASE_DESC=	Heimdal Kerberos (base)
MIT_DESC=		MIT Kerberos (security/krb5)
AES_THREADED_DESC=	Threaded AES-CTR
NONECIPHER_DESC=	NONE Cipher support

OPTIONS_SUB=		yes
PLIST_SUB+=		MANPREFIX=${MANPREFIX}

LDNS_CONFIGURE_WITH=	ldns
LDNS_LIB_DEPENDS=	libldns.so:${PORTSDIR}/dns/ldns
LDNS_EXTRA_PATCHES=	${FILESDIR}/extra-patch-ldns
LDNS_CFLAGS=		-I${LOCALBASE}/include
LDNS_CONFIGURE_ON=	--with-ldflags='-L${LOCALBASE}/lib'

# http://www.psc.edu/index.php/hpn-ssh
HPN_EXTRA_PATCHES=	${FILESDIR}/extra-patch-hpn-window-size
HPN_CONFIGURE_WITH=		hpn
NONECIPHER_CONFIGURE_WITH=	nonecipher
AES_THREADED_CONFIGURE_WITH=	aes-threaded

# See http://code.google.com/p/openssh-lpk/wiki/Main
# and svn repo described here:
# http://code.google.com/p/openssh-lpk/source/checkout
# LPK is now OBSOLETE with 6.2: https://code.google.com/p/openssh-lpk/issues/detail?id=15#c1
LPK_PATCHFILES=		${PORTNAME}-lpk-6.3p1.patch.gz
LPK_CPPFLAGS=		-I${LOCALBASE}/include
LPK_CONFIGURE_ON=	--with-ldap=yes \
			--with-ldflags='-L${LOCALBASE}/lib' \
			--with-cppflags='${CPPFLAGS}'
LPK_USE=		OPENLDAP=yes

# See http://www.roumenpetrov.info/openssh/
X509_VERSION=		7.9
X509_PATCH_SITES=	http://www.roumenpetrov.info/openssh/x509-${X509_VERSION}/:x509
X509_PATCHFILES=	${PORTNAME}-6.6p1+x509-${X509_VERSION}.diff.gz:-p1:x509

# See https://bugzilla.mindrot.org/show_bug.cgi?id=2016
SCTP_PATCHFILES=	${PORTNAME}-6.6p1-sctp-2329.patch.gz
SCTP_CONFIGURE_WITH=	sctp

# 6.6 patch taken from http://www.stacken.kth.se/~haba/ which was originally
# based on 5.7 patch at http://www.sxw.org.uk/computing/patches/
KERB_GSSAPI_PATCHFILES=	openssh-6.6p1-gsskex-all-20140318.patch.gz:-p1:gsskex
#KERB_GSSAPI_PATCH_SITES=http://www.stacken.kth.se/~haba/:gsskex

MIT_LIB_DEPENDS=		libkrb5.so.3:${PORTSDIR}/security/krb5
HEIMDAL_LIB_DEPENDS=		libkrb5.so.26:${PORTSDIR}/security/heimdal

PAM_CONFIGURE_WITH=	pam
TCP_WRAPPERS_CONFIGURE_WITH=	tcp-wrappers

LIBEDIT_CONFIGURE_WITH=	libedit
BSM_CONFIGURE_ON=	--with-audit=bsm

.include <bsd.port.pre.mk>

PATCH_SITES+=		http://mirror.shatow.net/freebsd/${PORTNAME}/:DEFAULT,x509,hpn,gsskex

# http://www.psc.edu/index.php/hpn-ssh
.if ${PORT_OPTIONS:MHPN} || ${PORT_OPTIONS:MAES_THREADED} || ${PORT_OPTIONS:MNONECIPHER}
PORTDOCS+=		HPN-README
HPN_VERSION=		14v2
HPN_DISTVERSION=	6.6.1p1
PATCH_SITES+=		${MASTER_SITE_SOURCEFORGE:S/$/:hpn/}
PATCH_SITE_SUBDIR+=	hpnssh/HPN-SSH%20${HPN_VERSION}%20${HPN_DISTVERSION}/:hpn
PATCHFILES+=		${PORTNAME}-${HPN_DISTVERSION}-hpnssh${HPN_VERSION}.diff.gz:-p1:hpn
EXTRA_PATCHES+=		${FILESDIR}/extra-patch-hpn-build-options
# Remove HPN if only AES requested
.  if !${PORT_OPTIONS:MHPN}
EXTRA_PATCHES+=		${FILESDIR}/extra-patch-hpn-no-hpn
.  endif
.endif

.if ${OSVERSION} >= 900000
CONFIGURE_LIBS+=	-lutil
.endif

# 900007 is when utmp(5) was removed and utmpx(3) added
.if ${OSVERSION} >= 900007
CONFIGURE_ARGS+=	--disable-utmp --disable-wtmp --disable-wtmpx --without-lastlog
.else
EXTRA_PATCHES+=		${FILESDIR}/extra-patch-sshd-utmp-size
.endif

.if ${PORT_OPTIONS:MX509}
.  if ${PORT_OPTIONS:MHPN} || ${PORT_OPTIONS:MAES_THREADED} || ${PORT_OPTIONS:MNONECIPHER}
BROKEN=		X509 patch and HPN patch do not apply cleanly together
.  endif

.  if ${PORT_OPTIONS:MSCTP}
BROKEN=		X509 patch and SCTP patch do not apply cleanly together
.  endif

.  if ${PORT_OPTIONS:MLPK}
BROKEN=		X509 patch and LPK patch do not apply cleanly together
.  endif

.  if ${PORT_OPTIONS:MKERB_GSSAPI}
BROKEN=		X509 patch incompatible with KERB_GSSAPI patch
.  endif

.endif

.if ${PORT_OPTIONS:MHEIMDAL_BASE} && ${PORT_OPTIONS:MKERB_GSSAPI}
BROKEN=		KERB_GSSAPI Requires either MIT or HEMIDAL, does not build with base Heimdal currently
.endif

.if ${PORT_OPTIONS:MHEIMDAL_BASE} && !exists(/usr/lib/libkrb5.so)
IGNORE=		you have selected HEIMDAL_BASE but do not have heimdal installed in base
.endif

.if ${PORT_OPTIONS:MPAM} && !exists(/usr/include/security/pam_modules.h)
IGNORE=		PAM must be installed in base
.endif

.if ${PORT_OPTIONS:MTCP_WRAPPERS} && !exists(/usr/include/tcpd.h)
IGNORE=		required /usr/include/tcpd.h missing
.endif

.if defined(OPENSSH_OVERWRITE_BASE)
PORT_OPTIONS+=		OVERWRITE_BASE
.endif

.if ${PORT_OPTIONS:MMIT} || ${PORT_OPTIONS:MHEIMDAL} || ${PORT_OPTIONS:MHEIMDAL_BASE}
.	if ${PORT_OPTIONS:MHEIMDAL_BASE}
CONFIGURE_LIBS+=	-lgssapi_krb5
CONFIGURE_ARGS+=	--with-kerberos5=/usr
.	else
CONFIGURE_ARGS+=	--with-kerberos5=${LOCALBASE}
.	endif
.	if ${OPENSSLBASE} == "/usr"
CONFIGURE_ARGS+=	--without-rpath
LDFLAGS=		# empty
.	endif
.else
.	if ${PORT_OPTIONS:MKERB_GSSAPI}
IGNORE=	KERB_GSSAPI requires one of MIT HEIMDAL or HEIMDAL_BASE
.	endif
.endif

.if ${OPENSSLBASE} != "/usr"
CONFIGURE_ARGS+=	--with-ssl-dir=${OPENSSLBASE}
.endif

.if ${PORT_OPTIONS:MLPK}
CONFIGURE_LIBS+=	-lldap
.endif

EMPTYDIR=		/var/empty

.if ${PORT_OPTIONS:MOVERWRITE_BASE}
# XXX: Mark this BROKEN rather than remove the option to force people to notice for POLA.
DEPRECATED=		Overwrite-base option/port/pkg will be removed. There is no real need for foot-shooting.
EXPIRATION_DATE=	2015-01-01
WITH_OPENSSL_BASE=	yes
CONFIGURE_ARGS+=	--localstatedir=/var
PREFIX=			/usr
NO_MTREE=		yes
ETCSSH=			/etc/ssh
USE_RCORDER=		openssh
PLIST_SUB+=		NOTBASE="@comment "
.else
ETCSSH=			${PREFIX}/etc/ssh
USE_RC_SUBR=		openssh
PLIST_SUB+=		NOTBASE=""
.endif

PLIST_SUB+=		BASEPREFIX="${PREFIX}"

# After all
SUB_LIST+=		ETCSSH="${ETCSSH}"
CONFIGURE_ARGS+=	--sysconfdir=${ETCSSH} --with-privsep-path=${EMPTYDIR}
.if !empty(CONFIGURE_LIBS)
CONFIGURE_ARGS+=	--with-libs='${CONFIGURE_LIBS}'
.endif

RC_SCRIPT_NAME=		openssh

post-patch:
	@${REINPLACE_CMD} -e 's|-ldes|-lcrypto|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} \
	    -e 's|install: \(.*\) host-key check-config|install: \1|g' \
	    -e 's|-lpthread|${PTHREAD_LIBS}|' \
	    ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|/usr/X11R6|${LOCALBASE}|' \
			${WRKSRC}/pathnames.h ${WRKSRC}/sshd_config.5 \
			${WRKSRC}/ssh_config.5
.if !${PORT_OPTIONS:MOVERWRITE_BASE}
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${LOCALBASE}|' \
		-e 's|%%RC_SCRIPT_NAME%%|${RC_SCRIPT_NAME}|' ${WRKSRC}/sshd.8
.endif
	@${REINPLACE_CMD} -E -e 's|SSH_VERSION|TMP_SSH_VERSION|' \
		-e 's|.*SSH_RELEASE.*||' ${WRKSRC}/version.h
	@${ECHO_CMD} '#define FREEBSD_PORT_VERSION	" FreeBSD-${PKGNAME}"' >> \
		${WRKSRC}/version.h
	@${ECHO_CMD} '#define SSH_VERSION	TMP_SSH_VERSION SSH_PORTABLE FREEBSD_PORT_VERSION' >> \
		${WRKSRC}/version.h
	@${ECHO_CMD} '#define SSH_RELEASE	TMP_SSH_VERSION SSH_PORTABLE FREEBSD_PORT_VERSION' >> \
		${WRKSRC}/version.h
.if ${PORT_OPTIONS:MHPN}
	@${REINPLACE_CMD} -e 's|TMP_SSH_VERSION SSH_PORTABLE|TMP_SSH_VERSION SSH_PORTABLE SSH_HPN|' \
		${WRKSRC}/version.h
.endif

pre-install:
# Workaround not running mtree BSD.root.dist on / since PREFIX=/usr
.if ${PORT_OPTIONS:MOVERWRITE_BASE}
	${MKDIR} ${STAGEDIR}/etc/rc.d
.endif

post-install:
	${MV} ${STAGEDIR}${ETCSSH}/ssh_config ${STAGEDIR}${ETCSSH}/ssh_config.sample
	${MV} ${STAGEDIR}${ETCSSH}/sshd_config ${STAGEDIR}${ETCSSH}/sshd_config.sample
.if ${PORT_OPTIONS:MHPN} || ${PORT_OPTIONS:MAES_THREADED} || ${PORT_OPTIONS:MNONECIPHER}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/HPN-README ${STAGEDIR}${DOCSDIR}
.endif

test:	build
	(cd ${WRKSRC}/regress && ${SETENV} OBJ=${WRKDIR} ${MAKE_ENV} TEST_SHELL=/bin/sh \
		PATH=${WRKSRC}:${PREFIX}/bin:${PREFIX}/sbin:${PATH} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS})

.include <bsd.port.post.mk>
