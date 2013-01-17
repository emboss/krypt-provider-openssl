/*
* krypt-provider API - OpenSSL version
*
* Copyright (C) 2011-2013
* Hiroshi Nakamura <nahi@ruby-lang.org>
* Martin Bosslet <martin.bosslet@gmail.com>
* All rights reserved.
*
* This software is distributed under the same license as Ruby.
* See the file 'LICENSE' for further details.
*/

#ifndef _KRYPT_PROVIDER_OSSL_H_
#define _KRYPT_PROVIDER_OSSL_H_

#if defined(__cplusplus)
extern "C" {
#endif

#include <openssl/opensslv.h>

#if defined(_WIN32)
#  include <openssl/e_os2.h>
#  define OSSL_NO_CONF_API 1
#  ifndef OPENSSL_SYS_WIN32
#    define OPENSSL_SYS_WIN32 1
#  endif
#  include <winsock2.h>
#endif

#include <errno.h>
#include <openssl/err.h>
#include <openssl/ssl.h>

extern krypt_provider krypt_provider_ossl;

krypt_md * krypt_ossl_md_new_oid(krypt_provider *provider, const char *oid);
krypt_md * krypt_ossl_md_new_name(krypt_provider *provider, const char *name);

#if defined(__cplusplus)
}
#endif

#endif /* _KRYPT_PROVIDER_H_ */
