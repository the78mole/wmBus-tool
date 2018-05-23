ACLOCAL_AMFLAGS = -I m4
AM_CFLAGS = -I$(top_srcdir) -I$(top_srcdir)/include

TESTS = test-wmbus
check_PROGRAMS = test-wmbus
test_wmbus_SOURCES = test-wmbus.c
test_wmbus_CFLAGS = @CHECK_CFLAGS@ $(AM_CFLAGS)
test_wmbus_LDADD = $(top_builddir)/src/libwmbus.la @CHECK_LIBS@

#TESTS = check-wmbuslib
#check_PROGRAMS = check-wmbuslib
#check_wmbuslib_SOURCES = \
#        $(top_srcdir)/test/test-wmbus.c \
#        $(top_srcdir)/src/wmbus.c
#
#check_wmbuslib_CFLAGS = @CHECK_CFLAGS@
#check_wmbuslib_LDADD = @CHECK_LIBS@
