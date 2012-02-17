=begin

= Info

krypt-core API - C version

Copyright (C) 2011
Hiroshi Nakamura <nahi@ruby-lang.org>
Martin Bosslet <martin.bosslet@googlemail.com>
All rights reserved.

= License
This program is distributed under the same license as Ruby.
See the file 'LICENSE' for further details.

=end

require 'mkmf'

message "=== krypt-provider OpenSSL ===\n"

arg = ARGV.shift
if arg
  if arg.include? "-g"
    debug = true
  end
end

if CONFIG['GCC'] == 'yes'
  
end

message "=== Checking Ruby features ===\n"

create_header
create_makefile("kryptprovideropenssl")
message "Done.\n"
