#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([WMBUS-TOOL], [0.0.1], [the78mole@chaintronics.com])
AM_INIT_AUTOMAKE([-Wall -Werror foreign subdir-objects])
AC_CONFIG_SRCDIR([src/wmbus.c])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIRS([m4])

# Checks for programs.
AC_PROG_CC
AM_PROG_AR
LT_INIT
ACX_PTHREAD

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([fcntl.h stdint.h stdlib.h string.h sys/time.h termios.h unistd.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_CHECK_HEADER_STDBOOL
AC_TYPE_INT8_T
AC_TYPE_SSIZE_T
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT8_T

# Checks for library functions.
AC_FUNC_MALLOC
AC_CHECK_FUNCS([atexit memset])

#AM_PATH_CHECK([0.9.0],[],[AC_MSG_ERROR([check is missing])]) # DEPRECATED
PKG_CHECK_MODULES([CHECK], [check >= 0.10.0])
AC_SUBST([CHECK_VERSION])
AC_SUBST([CHECK_CFLAGS])
AC_SUBST([CHECK_LIBS])

AC_CONFIG_FILES([
    Makefile
    src/Makefile
    test/Makefile
    Doxyfile
])

AC_MSG_NOTICE([
*************************************************************
* $PACKAGE $VERSION - Configuration results
*
* LIBS  : $LIBS
* CFLAGS: $CFLAGS
* 
* Packages:
*   CHECK  CF: $CHECK_CFLAGS
*        LIBS: $CHECK_LIBS
*************************************************************
])

AC_OUTPUT
