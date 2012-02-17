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

int md;
int prov;

krypt_provider *
krypt_provider_get_default(void)
{
    printf("provider_get_default called\n");
    return &prov;
}

krypt_md *
krypt_md_new_oid(krypt_provider *provider, const char *oid, size_t len)
{
    printf("new_oid called\n");
    return &md;
}

krypt_md *
krypt_md_new_name(krypt_provider *provider, const char *name, size_t len)
{
    printf("new_name called\n");
    return &md;
}

int
krypt_md_update(krypt_md *md, unsigned char *data, size_t len)
{
    printf("Update called\n");
    return 0;
}

int
krypt_md_final(krypt_md *md, unsigned char **digest, size_t *len)
{
    unsigned char *ret;
    const char *text = "letest";
    size_t retlen = strlen(text);

    printf("Final called\n");

    ret = ALLOC_N(unsigned char, retlen);
    memcpy(ret, text, retlen);
    *digest = ret;
    *len = retlen;
    return 0;
}

int
krypt_md_digest(krypt_md *md, unsigned char *data, size_t len, unsigned char **digest, size_t *digest_len)
{
    unsigned char *ret;
    const char *text = "letest";
    size_t retlen = strlen(text);

    printf("Digest called\n");

    ret = ALLOC_N(unsigned char, retlen);
    memcpy(ret, text, retlen);
    *digest = ret;
    *digest_len = retlen;
    return 0;
}

void
krypt_md_free(krypt_md *md)
{
    printf("Free called\n");
}

void
Init_kryptprovideropenssl(void)
{
    printf("Init called\n");
}
