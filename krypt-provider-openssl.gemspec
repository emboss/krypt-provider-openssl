Gem::Specification.new do |s|
  s.name = 'krypt-provider-openssl'
  s.version = '0.0.1'
  s.author = 'Hiroshi Nakamura, Martin Bosslet'
  s.email = 'Martin.Bosslet@googlemail.com'
  s.homepage = 'https://github.com/emboss/krypt-provider-openssl'
  s.summary = 'Implementation of the krypt-provider API using OpenSSL'
  s.extensions << 'ext/krypt/provider/openssl/extconf.rb'
  s.files = %w(LICENSE) + Dir.glob('{ext,lib}/**/*')
  s.require_path = "lib"
end
