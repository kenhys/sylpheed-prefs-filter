#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([prefs_filter], [0.1.0], [kenhys@gmail.com])
AC_CONFIG_SRCDIR([src/prefs_filter_util.c])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_AUX_DIR([config])
AC_CONFIG_MACRO_DIR([m4])

AM_INIT_AUTOMAKE([foreign])

AC_DEFINE([SYLPF_ID], ["prefs_filter"], [""])
AC_DEFINE([SYLPF_OPTION], [prefs_filter_option], [""])


# Checks for programs.
AC_PROG_AWK
AC_PROG_CC
AC_PROG_MAKE_SET
AC_PROG_LIBTOOL

m4_include(macros/sylplugin_factory.m4)

# Checks for libraries.
AM_PATH_GLIB_2_0(2.8.0,, AC_MSG_ERROR(Test for GLib failed. See the 'INSTALL' for help.))
AM_PATH_GTK_2_0(2.8.0,, AC_MSG_ERROR(Test for Gtk failed. See the 'INSTALL' for help.))
GETTEXT_PACKAGE=sylnotify
AC_SUBST(GETTEXT_PACKAGE)
AC_DEFINE_UNQUOTED(GETTEXT_PACKAGE,"$GETTEXT_PACKAGE", [Define text domain.])
AM_GLIB_GNU_GETTEXT
AC_SUBST(GTK_CFLAGS)
AC_SUBST(GTK_LIBS)

PKG_CHECK_MODULES([GLIB], [glib-2.0])
PKG_CHECK_MODULES([GTK], [gtk+-2.0])
PKG_CHECK_MODULES([SYLPF], [sylplugin-factory])
PKG_CHECK_MODULES([ONIG],
		  [oniguruma],
		  [oniguruma_exists=yes],
		  [oniguruma_exists=no])
if test "$oniguruma_exists" = "no"; then
  AC_CHECK_PROG(ONIG_CONFIG, onig-config, onig-config)
  if test "$ONIG_CONFIG" = "onig-config"; then
     ONIG_CFLAGS=`onig-config --cflags`
     ONIG_LIBS=`onig-config --libs`
     AC_SUBST(ONIG_CFLAGS)
     AC_SUBST(ONIG_LIBS)
  fi
fi

# Checks for header files.

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.

AC_CONFIG_FILES([Makefile
                 src/Makefile])
AC_OUTPUT
