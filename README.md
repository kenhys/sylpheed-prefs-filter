PrefsFilter - Mail filtering support plug-in for Sylpheed
=========================================================

Requirement
-----------

Sylpheed 3.2.0 or later

recommend to use Ubuntu 12.04 or later.

Install
-------

1. checkout sylpheed source code.
2. git clone https://github.com/kenhys/sylpheed-prefs-filter.git into plugin directory.
   HINT: sylpheed/plugin/prefs_filter
3. git clone https://github.com/kenhys/sylpheed-plugin-factory.git into plugin directory.
   HINT: sylpheed/plugin/sylplugin_factory
4. modify configure.ac for generating Makefile.
   HINT: prefs_filter/Makefile, prefs_filter/src/Makefile, sylplugin_factory/Makefile and
   sylplugin_factory/src/Makefile.
5. sh autogen.sh in sylpheed directory.
6. execute configure.
7. build plugins by make command.

copy compiled prefs_filter.so into plugin directory.

Usage
-----


