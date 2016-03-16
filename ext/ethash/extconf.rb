# -*- encoding : ascii-8bit -*-

require 'mkmf'

$CFLAGS << " " << "-w"

create_makefile('ethash/ethash')
