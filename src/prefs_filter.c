/*
 * Preference filter settings plug-in for Sylpheed
 * Copyright (C) 2012 HAYASHI Kentaro <kenhys@gmail.com>
 *
 */

#include <glib.h>
#include <glib/gi18n.h>
#include <gtk/gtk.h>

#include "sylmain.h"
#include "plugin.h"
#include "folder.h"
#include "procmsg.h"
#include "prefs_filter.h"

#include "sylpf_utility.h"

static SylPluginInfo info = {
  "Prefs filter Plugin",
  "0.1.0",
  "HAYASHI Kentaro",
  "Preference filter settings plug-in for Sylpheed"
};


void plugin_load(void)
{
  GList *list, *cur;
  const gchar *ver;
  gpointer mainwin;

#define SYLPF_FUNC_NAME "plugin_load"
  SYLPF_START_FUNC

  mainwin = syl_plugin_main_window_get();
  syl_plugin_main_window_popup(mainwin);

  syl_plugin_add_menuitem("/Tools", NULL, NULL, NULL);
  syl_plugin_add_menuitem("/Tools", 
                          N_("Prefs filter settings [prefs_filter]"),
                          prefs_filter_menu_cb,
                          NULL);

  g_signal_connect_after(syl_app_get(), "init-done", G_CALLBACK(init_done_cb),
                         NULL);
  syl_plugin_signal_connect("inc-mail-start",
                            G_CALLBACK(inc_start_cb), NULL);
  syl_plugin_signal_connect("inc-mail-finished",
                            G_CALLBACK(inc_finished_cb), NULL);
  syl_plugin_signal_connect("add-msg",
                            G_CALLBACK(prefs_filter_add_msg_cb), NULL);
  syl_plugin_signal_connect("prefs-filter-open",
                            G_CALLBACK(prefs_filter_open_cb), NULL);
  syl_plugin_signal_connect("prefs-filter-edit-open",
                            G_CALLBACK(prefs_filter_edit_open_cb), NULL);

  SYLPF_END_FUNC
#undef SYLPF_FUNC_NAME
}

void plugin_unload(void)
{
#define SYLPF_FUNC_NAME "plugin_unload"
  SYLPF_START_FUNC
  SYLPF_END_FUNC
#undef SYLPF_FUNC_NAME
}

SylPluginInfo *plugin_info(void)
{
  return &info;
}

gint plugin_interface_version(void)
{
  return SYL_PLUGIN_INTERFACE_VERSION;
}

static void init_done_cb(GObject *obj, gpointer data)
{
#define SYLPF_FUNC_NAME "init_done_cb"
  SYLPF_START_FUNC
  SYLPF_END_FUNC
#undef SYLPF_FUNC_NAME
}

static void app_exit_cb(GObject *obj, gpointer data)
{
#define SYLPF_FUNC_NAME "app_exit_cb"
  SYLPF_START_FUNC
  SYLPF_END_FUNC
#undef SYLPF_FUNC_NAME
}

static void prefs_filter_menu_cb(void)
{
#define SYLPF_FUNC_NAME "prefs_filter_menu_cb"
  SYLPF_START_FUNC
  SYLPF_END_FUNC
#undef SYLPF_FUNC_NAME
}

static void folderview_menu_popup_cb(GObject *obj, GtkItemFactory *ifactory,
				     gpointer data)
{
#define SYLPF_FUNC_NAME "folderview_menu_popup_cb"
  SYLPF_START_FUNC
  SYLPF_END_FUNC
#undef SYLPF_FUNC_NAME
}

static void inc_start_cb(GObject *obj, PrefsAccount *ac)
{
#define SYLPF_FUNC_NAME "inc_start_cb"
  SYLPF_START_FUNC
  SYLPF_END_FUNC
#undef SYLPF_FUNC_NAME
}

static void inc_finished_cb(GObject *obj, gint new_messages)
{
#define SYLPF_FUNC_NAME "inc_finished_cb"
  SYLPF_START_FUNC
  SYLPF_END_FUNC
#undef SYLPF_FUNC_NAME
}

static void prefs_filter_open_cb(GObject *obj, PrefsAccount *ac)
{
#define SYLPF_FUNC_NAME "prefs_filter_open_cb"
  SYLPF_START_FUNC
  SYLPF_END_FUNC
#undef SYLPF_FUNC_NAME
}

static void prefs_filter_edit_open_cb(GObject *obj, PrefsAccount *ac)
{
#define SYLPF_FUNC_NAME "prefs_filter_edit_open_cb"
  SYLPF_START_FUNC
  SYLPF_END_FUNC
#undef SYLPF_FUNC_NAME
}

static void prefs_filter_add_msg_cb(GObject *obj, FolderItem *item,
                                    const gchar *file, guint num)
{
#define SYLPF_FUNC_NAME "prefs_filter_add_msg_cb"
  SYLPF_START_FUNC
  SYLPF_END_FUNC
#undef SYLPF_FUNC_NAME
}


static void prefs_filter_menu_ok_cb(GtkWidget *widget, gpointer data)
{
#define SYLPF_FUNC_NAME "prefs_filter_menu_ok_cb"
  SYLPF_START_FUNC
  SYLPF_END_FUNC
#undef SYLPF_FUNC_NAME
}

static void prefs_filter_menu_cancel_cb(GtkWidget *widget, gpointer data)
{
#define SYLPF_FUNC_NAME "prefs_filter_menu_cancel_cb"
  SYLPF_START_FUNC
  SYLPF_END_FUNC
#undef SYLPF_FUNC_NAME
}
