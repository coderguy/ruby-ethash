# -*- encoding : ascii-8bit -*-

require 'mkmf'

$CFLAGS << " " << "-w -std=c99"

create_makefile('ethash/ethash')
