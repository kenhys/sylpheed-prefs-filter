/*
 * Prefs-filter plugin for Sylpheed -- 
 * Copyright (C) 2012 HAYASHI Kentaro <kenhys@gmail.com>
 *
 */

#ifndef __PREFS_FILTER_H__
#define __PREFS_FILTER_H__

#define SYLPF_PLUGIN_RC "prefsfilterrc"

#define PLUGIN_NAME N_("Prefs filter Plugin")
#define PLUGIN_DESC N_("Preference filter settings plug-in for Sylpheed")

#define SYLPF_FUNC(arg) prefs_filter ## _ ## arg

typedef struct  _PrefsFilterOption PrefsFilterOption;
struct _PrefsFilterOption
{
  gchar *rcpath;
  GKeyFile *rcfile;

  gboolean plugin_enabled;

  GtkWidget *plugin_on;
  GtkWidget *plugin_off;
  GtkWidget *plugin_switch;
  GtkTooltips *plugin_tooltip;

  GtkWidget *inbox;
  GtkWidget *create_folder;
};

typedef struct _PrefsFilterItem
{
  gchar *name;
  gchar *source;
  gchar *filter;
  gchar *folder;
  gboolean mkdir;
} PrefsFilterItem;

typedef struct _PrefsCurrentRule
{
  GtkWidget *dialog;
  GtkWidget *progress;
  GtkWidget *store;
  GtkWidget *tree;
  GtkWidget *inbox;
  GtkWidget *name;
  GtkWidget *target;
  GtkWidget *filter;
  GtkWidget *folder;
} PrefsCurrentRule;

enum {
  RULE_MKDIR_COLUMN,
  RULE_NAME_COLUMN,
  RULE_SRC_COLUMN,
  RULE_FILTER_COLUMN,
  RULE_TO_COLUMN,
  N_RULE_COLUMNS
};

static void init_done_cb(GObject *obj, gpointer data);

static void prefs_filter_menu_cb(void);

static void inc_start_cb(GObject *obj, PrefsAccount *ac);
static void inc_finished_cb(GObject *obj, gint new_messages);

static void prefs_filter_open_cb(GObject *obj, PrefsAccount *ac);
static void prefs_filter_edit_open_cb(GObject *obj, PrefsAccount *ac);
static void prefs_filter_add_msg_cb(GObject *obj, FolderItem *item,
                                    const gchar *file, guint num);
static void prefs_filter_menu_ok_cb(GtkWidget *widget, gpointer data);
static void prefs_filter_menu_cancel_cb(GtkWidget *widget, gpointer data);

static GtkWidget *create_config_main_page(GtkWidget *notebook, GKeyFile *pkey);
static GtkWidget *create_config_about_page(GtkWidget *notebook, GKeyFile *pkey);
static GtkWidget *create_inbox_widget(void);
static GtkWidget *create_filter_name_widget(void);
static GtkWidget *create_filter_rule_widget(void);
static GtkWidget *create_filter_to_widget(void);
static GtkWidget *create_folder_option_widget(void);
static GtkWidget *create_filter_edit_button_widget(void);
static GtkWidget *create_filter_manage_button_widget(void);
static GtkWidget *create_rule_store_widget(void);



#endif /* __PREFS_FILTER_H__ */
