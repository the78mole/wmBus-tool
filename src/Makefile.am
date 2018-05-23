ACLOCAL_AMFLAGS = -I m4
AM_CFLAGS = -I$(top_srcdir) -I$(top_srcdir)/include

lib_LTLIBRARIES = libwmbus.la
libwmbus_la_SOURCES = wmbus.c
include_HEADERS = $(top_srcdir)/include/wmbusext.h 

bin_PROGRAMS	= wmbus-tool
wmbus_tool_SOURCES = wmbus-tool.c apputils.c
wmbus_tool_LDADD = libwmbus.la -lpthread

