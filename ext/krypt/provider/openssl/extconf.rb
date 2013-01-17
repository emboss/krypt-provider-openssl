=begin

= Info

krypt-provider-openssl - Implementation using OpenSSL

Copyright (C) 2011-2013
Hiroshi Nakamura <nahi@ruby-lang.org>
Martin Bosslet <martin.bosslet@gmail.com>
All rights reserved.

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

=end

require 'mkmf'

dir_config("openssl")

message "=== krypt-provider OpenSSL ===\n"

arg = ARGV.shift
if arg
  if arg.include? "-g"
    debug = true
  end
end

##
# Automatically adds -Wall flag for compilation when GCC is used
#
if CONFIG['GCC'] == 'yes'
  $CPPFLAGS += " -Wall" unless $CPPFLAGS.split.include? "-Wall"
end

message "=== Checking for system dependencies... ===\n"
have_library("nsl", "t_open")
have_library("socket", "socket")
have_header("assert.h")

message "=== Checking requirements... ===\n"
if $mingw
  have_library("wsock32")
  have_library("gdi32")
end

result = pkg_config("openssl") && have_header("openssl/ssl.h")

unless result
  result = have_header("openssl/ssl.h")
  result &&= %w[crypto libeay32].any? {|lib| have_library(lib, "OpenSSL_add_all_digests")}
  result &&= %w[ssl ssleay32].any? {|lib| have_library(lib, "SSL_library_init")}
  unless result
    message "=== Checking for requirements failed. ===\n"
    message "Makefile wasn't created. Please fix the errors above.\n"
    exit 1
  end
end

create_header
create_makefile("kryptprovideropenssl")
message "Done.\n"
