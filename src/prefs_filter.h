/*
 * Prefs-filter plugin for Sylpheed -- 
 * Copyright (C) 2012 HAYASHI Kentaro <kenhys@gmail.com>
 *
 */

#ifndef __PREFS_FILTER_H__
#define __PREFS_FILTER_H__

#define SYLPF_ID "prefs_filter"
#define SYLPF_OPTION prefs_filter_option

#define SYLPF_FUNC(arg) prefs_filter ## _ ## arg

static void init_done_cb(GObject *obj, gpointer data);
static void app_exit_cb(GObject *obj, gpointer data);

static void folderview_menu_popup_cb(GObject *obj, GtkItemFactory *ifactory,
                                     gpointer data);
static void summaryview_menu_popup_cb(GObject *obj, GtkItemFactory *ifactory,
                                      gpointer data);

static void textview_menu_popup_cb(GObject *obj, GtkMenu *menu,
                                   GtkTextView *textview,
                                   const gchar *uri,
                                   const gchar *selected_text,
                                   MsgInfo *msginfo);

static void prefs_filter_menu_cb(void);

static void messageview_show_cb(GObject *obj, gpointer msgview,
				MsgInfo *msginfo, gboolean all_headers);
static void inc_start_cb(GObject *obj, PrefsAccount *ac);
static void inc_finished_cb(GObject *obj, gint new_messages);

static void prefs_filter_open_cb(GObject *obj, PrefsAccount *ac);
static void prefs_filter_edit_open_cb(GObject *obj, PrefsAccount *ac);
static void prefs_filter_add_msg_cb(GObject *obj, FolderItem *item,
                                    const gchar *file, guint num);

#endif /* __PREFS_FILTER_H__ */
