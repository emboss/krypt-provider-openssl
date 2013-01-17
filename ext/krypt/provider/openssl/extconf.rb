=begin

= Info

krypt-core API - C version

Copyright (C) 2011-2013
Hiroshi Nakamura <nahi@ruby-lang.org>
Martin Bosslet <martin.bosslet@gmail.com>
All rights reserved.

= License
This program is distributed under the same license as Ruby.
See the file 'LICENSE' for further details.

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
