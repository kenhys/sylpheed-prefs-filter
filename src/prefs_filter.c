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
  PLUGIN_NAME,
  "0.1.0",
  "HAYASHI Kentaro",
  PLUGIN_DESC
};

PrefsFilterOption SYLPF_OPTION;

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

  g_signal_connect(syl_app_get(), "add-msg",
                   G_CALLBACK(prefs_filter_add_msg_cb), NULL);

  syl_plugin_signal_connect("inc-mail-start",
                            G_CALLBACK(inc_start_cb), NULL);
  syl_plugin_signal_connect("inc-mail-finished",
                            G_CALLBACK(inc_finished_cb), NULL);

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

  /* show modal dialog */
  GtkWidget *window;
  GtkWidget *vbox;
  GtkWidget *confirm_area;
  GtkWidget *ok_btn;
  GtkWidget *cancel_btn;
    
  SYLPF_START_FUNC

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_container_set_border_width(GTK_CONTAINER(window), 8);
  gtk_widget_set_size_request(window, 400, 300);
  gtk_window_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_modal(GTK_WINDOW(window), TRUE);
  gtk_window_set_policy(GTK_WINDOW(window), FALSE, TRUE, FALSE);
  gtk_widget_realize(window);

  vbox = gtk_vbox_new(FALSE, 6);
  gtk_widget_show(vbox);
  gtk_container_add(GTK_CONTAINER(window), vbox);

  /* notebook */
  GtkWidget *notebook = gtk_notebook_new();
  /* main tab */
  create_config_main_page(notebook, SYLPF_OPTION.rcfile);
  /* about, copyright tab */
  create_config_about_page(notebook, SYLPF_OPTION.rcfile);

  gtk_widget_show(notebook);
  gtk_box_pack_start(GTK_BOX(vbox), notebook, TRUE, TRUE, 0);

  confirm_area = gtk_hbutton_box_new();
  gtk_button_box_set_layout(GTK_BUTTON_BOX(confirm_area), GTK_BUTTONBOX_END);
  gtk_box_set_spacing(GTK_BOX(confirm_area), 6);


  ok_btn = gtk_button_new_from_stock(GTK_STOCK_OK);
  GTK_WIDGET_SET_FLAGS(ok_btn, GTK_CAN_DEFAULT);
  gtk_box_pack_start(GTK_BOX(confirm_area), ok_btn, FALSE, FALSE, 0);
  gtk_widget_show(ok_btn);

  cancel_btn = gtk_button_new_from_stock(GTK_STOCK_CANCEL);
  GTK_WIDGET_SET_FLAGS(cancel_btn, GTK_CAN_DEFAULT);
  gtk_box_pack_start(GTK_BOX(confirm_area), cancel_btn, FALSE, FALSE, 0);
  gtk_widget_show(cancel_btn);

  gtk_widget_show(confirm_area);

  gtk_box_pack_end(GTK_BOX(vbox), confirm_area, FALSE, FALSE, 0);
  gtk_widget_grab_default(ok_btn);

  gtk_window_set_title(GTK_WINDOW(window),
                       _("Prefs filter Settings [prefs_filter]"));

  g_signal_connect(G_OBJECT(ok_btn), "clicked",
                   G_CALLBACK(prefs_filter_menu_ok_cb), window);
  g_signal_connect(G_OBJECT(cancel_btn), "clicked",
                   G_CALLBACK(prefs_filter_menu_cancel_cb), window);
  gtk_widget_show(window);

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
  gtk_widget_destroy(GTK_WIDGET(data));
#undef SYLPF_FUNC_NAME
}

static void prefs_filter_menu_cancel_cb(GtkWidget *widget, gpointer data)
{
#define SYLPF_FUNC_NAME "prefs_filter_menu_cancel_cb"
  SYLPF_START_FUNC
  SYLPF_END_FUNC
  gtk_widget_destroy(GTK_WIDGET(data));
#undef SYLPF_FUNC_NAME
}
