#include <stdlib.h>
#include <ruby.h>

static VALUE rb_mEthash;

static VALUE
ethash_mkcache_bytes(VALUE self, VALUE blk_number) {
  return INT2FIX(100);
}

void
Init_ethash() {
  rb_mEthash = rb_define_module("Ethash");
  rb_define_singleton_method(rb_mEthash, "mkcache_bytes", ethash_mkcache_bytes, 1);
}
