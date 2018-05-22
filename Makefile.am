

AM_CFLAGS = -I$(top_srcdir) -I$(top_srcdir)/include

bin_PROGRAMS	= wmbus-tool
wmbus_tool_SOURCES = src/wmbus-tool.c src/apputils.c src/wmbus.c
wmbus_tool_LDADD = -lpthread

include_HEADERS = include/wmbusext.h

dist_doc_DATA = README.md

TESTS = check_wmbuslib
check_PROGRAMS = check_wmbuslib
check_wmbuslib_SOURCES = \
        $(top_srcdir)/test/test-wmbus.c \
        $(top_srcdir)/src/wmbus.c

check_wmbuslib_CFLAGS = @CHECK_CFLAGS@
check_wmbuslib_LDADD = $(top_builddir)/src/libmoney.la @CHECK_LIBS@

