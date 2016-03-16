# -*- encoding : ascii-8bit -*-

$:.unshift File.expand_path('../../lib', __FILE__)

require 'minitest/autorun'
require 'ethash'

class EthashTest < Minitest::Test

  def test_mkcache_bytes
    assert_equal 16776896, Ethash.mkcache_bytes(0)
  end

end
