# -*- encoding : ascii-8bit -*-

$:.unshift File.expand_path('../../lib', __FILE__)

require 'minitest/autorun'
require 'ethash'

class EthashTest < Minitest::Test

  def test_mkcache_bytes
    assert_equal 16776896, Ethash.mkcache_bytes(0).size
  end

  def test_hashimoto_light
    cache = Ethash.mkcache_bytes(0)
    header = "\x01"*32
    hash = {mixhash: "\xD5\x7F\xB3|OaU\x06\x12\xC0;\x9D\xFB\xC5\xD5;k\x11\xB9\x84\xEFU\xAC\xD7\xDDh\xEC\xF5VF\xA1\xF3", result: "E~\xE8\xA0i\xD4\x18\x95iU\xF9\xA5k*\x02\x1E\xAE~\xBD\x8EoM\x10#\xB67\xFA\xAD)4\x1E\xDD"}
    assert_equal hash, Ethash.hashimoto_light(0, cache, header, 0)
  end

end
