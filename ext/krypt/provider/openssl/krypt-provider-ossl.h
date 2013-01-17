/*
 * krypt-provider-openssl - Implementation using OpenSSL
 *
 * Copyright (c) 2011-2013
 * Hiroshi Nakamura <nahi@ruby-lang.org>
 * Martin Bosslet <martin.bosslet@gmail.com>
 * All rights reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
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
