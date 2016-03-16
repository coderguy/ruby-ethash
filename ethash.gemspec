$:.push File.expand_path("../lib", __FILE__)

require 'ethash/version'

Gem::Specification.new do |s|
  s.name        = "ethash"
  s.version     = Ethash::VERSION
  s.authors     = ["Jan Xie"]
  s.email       = ["jan.h.xie@gmail.com"]
  s.homepage    = "https://github.com/janx/ruby-ethash"
  s.summary     = "Ruby binding to libethash."
  s.description = "Ethash is Ethereum's mining algorithm."
  s.license     = 'MIT'

  s.files      = `git ls-files`.split("\n")
  s.test_files = `git ls-files -- {test,spec,features}/*`.split("\n")
  s.extensions = ['ext/ethash/extconf.rb']

  s.add_development_dependency('rake', '~> 10.5')
  s.add_development_dependency('rake-compiler', '~> 0.9')
  s.add_development_dependency('minitest', '5.8.3')
  s.add_development_dependency('yard', '0.8.7.6')
end
