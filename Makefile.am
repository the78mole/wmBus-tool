ACLOCAL_AMFLAGS = -I m4
AM_CFLAGS = -I$(top_srcdir) -I$(top_srcdir)/include

dist_doc_DATA = README.md

SUBDIRS = src . test

doc: Doxyfile
	doxygen
