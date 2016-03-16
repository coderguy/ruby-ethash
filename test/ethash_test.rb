# -*- encoding : ascii-8bit -*-

$:.unshift File.expand_path('../../lib', __FILE__)

require 'minitest/autorun'
require 'ethash'

class EthashTest < Minitest::Test

  def test_mkcache_bytes
    p Ethash.mkcache_bytes('')
  end

end
