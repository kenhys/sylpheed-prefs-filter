
lib_LTLIBRARIES = prefs_filter.la

prefs_filter_la_SOURCES = prefs_filter.c prefs_filter.h \
prefs_filter_la_LDFLAGS = -module -no-undefined -avoid-version

prefs_filter_la_LIBADD = \
	$(GTK_LIBS) \
	$(ONIG_LIBS) \
	$(sylpheed_build_dir)/src/libsylpheed-plugin-0.la \
	$(sylpheed_build_dir)/libsylph/libsylph-0.la

# bin_PROGRAMS = sylprefs-filter

# sylprefs_filter_CFLAGS = \
# 	$(AM_CFLAGS) \
# 	$(GTK_CFLAGS)

# sylprefs_filter_LDADD = \
# 	$(GTK_LIBS) \
# 	$(ONIG_LIBS) \
# 	$(sylpheed_build_dir)/src/libsylpheed-plugin-0.la \
# 	$(sylpheed_build_dir)/libsylph/libsylph-0.la

# sylprefs_filter_SOURCES = \
# 	prefs_filter.h \
# 	prefs_filter.c \
# 	prefs_filter_util.h \
# 	prefs_filter_util.c

AM_CPPFLAGS = \
	$(GTK_CFLAGS) \
	-I$(includedir) \
	-I$(sylpheed_build_dir) \
	-I$(sylpheed_build_dir)/libsylph \
	-I$(sylpheed_build_dir)/src \
	-I$(sylplugin_factory_source_dir)/src


install:
install-plugin: install-am
