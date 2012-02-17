require 'rake'
require 'rake/extensiontask'

$config_options = []

task :default => :compile

Rake::ExtensionTask.new('kryptprovideropenssl') do |ext|
  ext.ext_dir = "ext/krypt/provider/openssl"
  ext.lib_dir = "lib"
  ext.config_options = $config_options
  ext.cross_compile = true
  ext.cross_platform = 'i386-mswin32'
end

task :build => :compile
