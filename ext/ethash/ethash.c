#include <stdlib.h>
#include <ruby.h>

#include "headers/ethash.h"
#include "headers/internal.h"

static VALUE rb_mEthash;

static VALUE
ethash_mkcache_bytes(VALUE self, VALUE blknum) {
  unsigned long block_number = NUM2ULONG(blknum);

  ethash_light_t L = ethash_light_new(block_number);
  VALUE val = rb_str_new(L->cache, L->cache_size);
  free(L->cache);

  return val;
}

static VALUE
ethash_hashimoto_light(VALUE self, VALUE blknum, VALUE cache, VALUE header, VALUE _nonce) {
  char *cache_bytes = RSTRING_PTR(cache);
  unsigned long cache_size = RSTRING_LEN(cache);

  char *header_bytes = RSTRING_PTR(header);
  unsigned long header_size = RSTRING_LEN(header);

  unsigned long block_number = NUM2ULONG(blknum);
  unsigned long nonce = NUM2ULL(_nonce);

  struct ethash_light *s;
  s = calloc(sizeof(*s), 1);
  s->cache = cache_bytes;
  s->cache_size = cache_size;
  s->block_number = block_number;

  struct ethash_h256 *h;
  h = calloc(sizeof(*h), 1);
  for (unsigned int i=0; i<32; i++) h->b[i] = header_bytes[i];

  struct ethash_return_value out = ethash_light_compute(s, *h, nonce);

  VALUE hash = rb_hash_new();
  VALUE key_mixhash = ID2SYM(rb_intern("mixhash"));
  VALUE key_result = ID2SYM(rb_intern("result"));
  rb_hash_aset(hash, key_mixhash, rb_str_new(&out.mix_hash, 32));
  rb_hash_aset(hash, key_result, rb_str_new(&out.result, 32));

  return hash;
}

static VALUE
ethash_get_seedhash_wrapper(VALUE self, VALUE blknum) {
  unsigned long block_number = NUM2ULONG(blknum);

  if (block_number >= ETHASH_EPOCH_LENGTH * 2048) {
    char error_message[1024];
    sprintf(error_message, "Block number must be less than %i (was %lu)", ETHASH_EPOCH_LENGTH*2048, block_number);

    rb_raise(rb_eRuntimeError, error_message);
    return NULL;
  }

  ethash_h256_t seedhash = ethash_get_seedhash(block_number);
  return rb_str_new((char*)&seedhash, 32);
}


void
Init_ethash() {
  rb_mEthash = rb_define_module("Ethash");
  rb_define_singleton_method(rb_mEthash, "mkcache_bytes", ethash_mkcache_bytes, 1);
  rb_define_singleton_method(rb_mEthash, "hashimoto_light", ethash_hashimoto_light, 4);
  rb_define_singleton_method(rb_mEthash, "get_seedhash", ethash_get_seedhash_wrapper, 1);
}
