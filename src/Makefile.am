
lib_LTLIBRARIES = prefs_filter.la

sylpf_srcdir = $(sylpheed_build_dir)/plugin/sylplugin_factory/src


prefs_filter_la_SOURCES = prefs_filter.c prefs_filter.h \
	$(sylpf_srcdir)/sylplugin_factory.c \
	$(sylpf_srcdir)/sylplugin_factory.h
prefs_filter_la_LDFLAGS = -module -no-undefined -avoid-version

prefs_filter_la_LIBADD = \
	$(GTK_LIBS) \
	$(sylpheed_build_dir)/src/libsylpheed-plugin-0.la \
	$(sylpheed_build_dir)/libsylph/libsylph-0.la

bin_PROGRAMS = prefs-filter

prefs_filter_CFLAGS = \
	$(AM_CFLAGS) \
	$(GTK_CFLAGS)

prefs_filter_LDADD = \
	$(GTK_LIBS) \
	$(sylpheed_build_dir)/src/libsylpheed-plugin-0.la \
	$(sylpheed_build_dir)/libsylph/libsylph-0.la

prefs_filter_SOURCES = \
	$(sylpf_srcdir)/sylplugin_factory.c \
	$(sylpf_srcdir)/sylplugin_factory.h \
	prefs_filter.h \
	prefs_filter.c \
	prefs_filter_util.h \
	prefs_filter_util.c

INCLUDES = \
	$(GTK_CFLAGS) \
	-I$(includedir) \
	-I$(sylpheed_build_dir) \
	-I$(sylpheed_build_dir)/libsylph \
	-I$(sylpheed_build_dir)/src \
	-I$(sylpf_srcdir)


install:
install-plugin: install-am
