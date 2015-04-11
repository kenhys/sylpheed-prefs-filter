
lib_LTLIBRARIES = prefs_filter.la

prefs_filter_la_SOURCES = prefs_filter.c prefs_filter.h
prefs_filter_la_LDFLAGS = -module -no-undefined -avoid-version

prefs_filter_la_LIBADD = \
	$(GTK_LIBS) \
	$(ONIG_LIBS) \
	$(SYLPHEED_LIBS) \
	$(SYLPF_LIBS)

bin_PROGRAMS = sylprefs-filter

sylprefs_filter_CFLAGS = \
	$(AM_CFLAGS) \
	$(GTK_CFLAGS)

sylprefs_filter_LDADD = \
	$(GTK_LIBS) \
	$(ONIG_LIBS) \
	$(SYLPHEED_LIBS)

sylprefs_filter_SOURCES = \
	prefs_filter.h \
	prefs_filter.c \
	prefs_filter_util.h \
	prefs_filter_util.c

AM_CPPFLAGS = \
	$(GTK_CFLAGS) \
	-I$(includedir) \
	$(SYLPHEED_CFLAGS) \
	$(SYLPF_CFLAGS)


install:
install-plugin: install-am
