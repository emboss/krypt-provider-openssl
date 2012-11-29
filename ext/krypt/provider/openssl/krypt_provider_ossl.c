/*
* krypt-provider OpenSSL
*
* Copyright (C) 2012
* Hiroshi Nakamura <nahi@ruby-lang.org>
* Martin Bosslet <martin.bosslet@googlemail.com>
* All rights reserved.
*
* This software is distributed under the same license as Ruby.
* See the file 'LICENSE' for further details.
*/

#include "krypt-provider.h"
#include "krypt-provider-ossl.h"

krypt_provider krypt_provider_ossl = {
    "openssl",
    krypt_ossl_md_new_oid,
    krypt_ossl_md_new_name
};

void
Init_kryptprovideropenssl(void)
{
    OpenSSL_add_ssl_algorithms();
    OpenSSL_add_all_algorithms();
    ERR_load_crypto_strings();
    SSL_load_error_strings();

    krypt_provider_register(&krypt_provider_ossl);
}
