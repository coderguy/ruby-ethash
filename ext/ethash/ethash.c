#include <stdlib.h>
#include <ruby.h>

#include "headers/ethash.h"
#include "headers/internal.h"

static VALUE rb_mEthash;

static VALUE
ethash_mkcache_bytes(VALUE self, VALUE n) {
    unsigned long block_number = NUM2LONG(n);

    ethash_light_t L = ethash_light_new(block_number);
    VALUE val = rb_str_new(L->cache, L->cache_size);
    free(L->cache);

    return val;
}

void
Init_ethash() {
  rb_mEthash = rb_define_module("Ethash");
  rb_define_singleton_method(rb_mEthash, "mkcache_bytes", ethash_mkcache_bytes, 1);
}
