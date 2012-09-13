libdir = $(plugindir)

lib_LTLIBRARIES = prefs_filter.la

sylpf_srcdir = $(top_srcdir)/plugin/sylplugin_factory/src


prefs_filter_la_SOURCES = prefs_filter.c prefs_filter.h \
	$(sylpf_srcdir)/sylpf_utility.c \
	$(sylpf_srcdir)/sylpf_utility.h
prefs_filter_la_LDFLAGS = -module -no-undefined -avoid-version

if PREFS_FILTER_UTILITY
bin_PROGRAMS = prefs_filter

prefs_filter_CFLAGS = \
	$(AM_CFLAGS) \
	$(GTK_CFLAGS)

prefs_filter_LDADD = \
	$(GTK_LIBS) \
	$(top_builddir)/src/libsylpheed-plugin-0.la \
	$(top_builddir)/libsylph/libsylph-0.la

prefs_filter_SOURCES = \
	prefs_filter.h \
	prefs_filter.c \
	prefs_filter_util.h \
	prefs_filter_util.c

endif

INCLUDES = \
	$(GTK_CFLAGS) \
	-I$(includedir) \
	-I$(top_srcdir) \
	-I$(top_srcdir)/libsylph \
	-I$(top_srcdir)/src \
	-I$(sylpf_srcdir)

prefs_filter_la_LIBADD = \
	$(GTK_LIBS) \
        $(top_builddir)/src/libsylpheed-plugin-0.la \
	$(top_builddir)/libsylph/libsylph-0.la

install:
install-plugin: install-am
