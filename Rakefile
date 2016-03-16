require 'rake/extensiontask'
require 'rake/testtask'

Rake::ExtensionTask.new "ethash" do |ext|
  ext.ext_dir = 'ext/ethash'
  ext.lib_dir = 'lib/ethash'
end

Rake::TestTask.new do |t|
  t.libs += %w(lib test)
  t.test_files = FileList['test/**/*_test.rb']
  t.verbose = true
end

task default: [:test]
