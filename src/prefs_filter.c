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
#include "foldersel.h"
#include "procmsg.h"

#include "sylplugin_factory.h"

#include "prefs_filter.h"

static SylPluginInfo info = {
  PLUGIN_NAME,
  "0.1.0",
  "HAYASHI Kentaro",
  PLUGIN_DESC
};

PrefsFilterOption SYLPF_OPTION;

static PrefsCurrentRule current_rule;

void plugin_load(void)
{
  GList *list, *cur;
  const gchar *ver;
  gpointer mainwin;

  SYLPF_START_FUNC;
    
  sylpf_init_logger(SYLPF_ID,
                    G_LOG_FLAG_FATAL | G_LOG_FLAG_RECURSION | G_LOG_LEVEL_MASK,
                    NULL,
                    NULL);

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

  sylpf_load_option_rcfile(SYLPF_OPTION_P, SYLPF_PLUGIN_RC);
  
  SYLPF_END_FUNC;
}

void plugin_unload(void)
{
  SYLPF_START_FUNC;
  SYLPF_END_FUNC;
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
  SYLPF_START_FUNC;
  SYLPF_END_FUNC;
}

static void app_exit_cb(GObject *obj, gpointer data)
{
  SYLPF_START_FUNC;
  SYLPF_END_FUNC;
}

static void prefs_filter_menu_cb(void)
{

  /* show modal dialog */
  GtkWidget *window;
  GtkWidget *vbox;
  GtkWidget *confirm_area;
  GtkWidget *ok_btn;
  GtkWidget *cancel_btn;
    
  SYLPF_START_FUNC;

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_container_set_border_width(GTK_CONTAINER(window), 8);
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

  sylpf_pack_confirm_area(vbox,
                          G_CALLBACK(prefs_filter_menu_ok_cb),
                          G_CALLBACK(prefs_filter_menu_cancel_cb),
                          window);

  gtk_window_set_title(GTK_WINDOW(window),
                       _("Prefs filter settings [prefs_filter]"));
  gtk_widget_show(window);

  SYLPF_END_FUNC;
}

static void folderview_menu_popup_cb(GObject *obj, GtkItemFactory *ifactory,
				     gpointer data)
{
  SYLPF_START_FUNC;
  SYLPF_END_FUNC;
}

static void inc_start_cb(GObject *obj, PrefsAccount *ac)
{
  SYLPF_START_FUNC;
  SYLPF_END_FUNC;
}

static void inc_finished_cb(GObject *obj, gint new_messages)
{
  SYLPF_START_FUNC;
  SYLPF_END_FUNC;
}

static void prefs_filter_open_cb(GObject *obj, PrefsAccount *ac)
{
  SYLPF_START_FUNC;
  SYLPF_END_FUNC;
}

static void prefs_filter_edit_open_cb(GObject *obj, PrefsAccount *ac)
{
  SYLPF_START_FUNC;
  SYLPF_END_FUNC;
}

static void prefs_filter_add_msg_cb(GObject *obj, FolderItem *item,
                                    const gchar *file, guint num)
{
  SYLPF_START_FUNC;;
  SYLPF_END_FUNC;;
}


static void prefs_filter_menu_ok_cb(GtkWidget *widget, gpointer data)
{
  gsize sz;
  gchar *buf;

  SYLPF_START_FUNC;;

  g_key_file_load_from_file(SYLPF_OPTION.rcfile,
                            SYLPF_OPTION.rcpath,
                            G_KEY_FILE_KEEP_COMMENTS, NULL);

  buf = gtk_entry_get_text(GTK_ENTRY(SYLPF_OPTION.inbox));
  SYLPF_SET_RC_STRING(SYLPF_OPTION.rcfile, "prefs", "inbox", buf);

  buf = g_key_file_to_data(SYLPF_OPTION.rcfile, &sz, NULL);
  g_file_set_contents(SYLPF_OPTION.rcpath, buf, sz, NULL);

  gtk_widget_destroy(GTK_WIDGET(data));

  SYLPF_END_FUNC;;
}

static void prefs_filter_menu_cancel_cb(GtkWidget *widget, gpointer data)
{
  SYLPF_START_FUNC;
  SYLPF_END_FUNC;
  gtk_widget_destroy(GTK_WIDGET(data));
}

static gchar* copyright_message =
  N_("PrefsFilter is distributed under 2-Clause BSD license.\n"
     "\n"
     "Copyright (C) 2012 HAYASHI Kentaro <kenhys@gmail.com>"
     "\n");

static GtkWidget *create_config_main_page(GtkWidget *notebook, GKeyFile *pkey)
{

  GtkWidget *vbox;
  GtkWidget *hbox;
  GtkWidget *startup_align;
  GtkWidget *label;
  GtkWidget *filter_label;
  GtkWidget *filter_name_widget;
  GtkWidget *filter_rule_widget;
  GtkWidget *filter_to_widget;
  GtkWidget *create_folder_widget;
  GtkWidget *filter_editing_button_widget;
  GtkWidget *filter_manage_button_widget;
  GtkWidget *filter_exec;
  GtkWidget *filter_save;
  GtkWidget *filter_save_folder;
  GtkWidget *inbox_frame;
  GtkWidget *inbox_widget;
  GtkWidget *edit_frame;
  GtkWidget *manage_frame;
  GtkWidget *page;

  SYLPF_START_FUNC;

  vbox = gtk_vbox_new(FALSE, 0);
  page = gtk_vbox_new(FALSE, 0);

  inbox_widget = create_inbox_widget();
  gtk_box_pack_start(GTK_BOX(vbox), inbox_widget, FALSE, FALSE, 0);

  inbox_frame = sylpf_pack_widget_with_aligned_frame(vbox, _("Mail inbox"));
  gtk_box_pack_start(GTK_BOX(page), inbox_frame, FALSE, FALSE, 0);

  vbox = gtk_vbox_new(FALSE, 0);

  filter_name_widget = create_filter_name_widget();
  gtk_box_pack_start(GTK_BOX(vbox), filter_name_widget, FALSE, FALSE, 0);
                     
  filter_rule_widget = create_filter_rule_widget();
  gtk_box_pack_start(GTK_BOX(vbox), filter_rule_widget, FALSE, FALSE, 0);
  
  filter_to_widget = create_filter_to_widget();
  gtk_box_pack_start(GTK_BOX(vbox), filter_to_widget, FALSE, FALSE, 0);

  create_folder_widget = create_folder_option_widget();
  gtk_box_pack_start(GTK_BOX(vbox), create_folder_widget, FALSE, FALSE, 0);

  filter_editing_button_widget = \
    create_filter_edit_button_widget();
  gtk_box_pack_start(GTK_BOX(vbox), filter_editing_button_widget, FALSE, FALSE, 0);

  edit_frame = sylpf_pack_widget_with_aligned_frame(vbox, _("Edit filter rule"));
  gtk_box_pack_start(GTK_BOX(page), edit_frame, FALSE, FALSE, 0);
  

  vbox = gtk_vbox_new(FALSE, 0);

  filter_manage_button_widget =                 \
    create_filter_manage_button_widget();
  gtk_box_pack_start(GTK_BOX(vbox), filter_manage_button_widget, FALSE, FALSE, 0);
  
  manage_frame = sylpf_pack_widget_with_aligned_frame(vbox, _("Manage filter rule"));
  gtk_box_pack_start(GTK_BOX(page), manage_frame, FALSE, FALSE, 0);

  label = gtk_label_new(_("General"));
  gtk_notebook_append_page(GTK_NOTEBOOK(notebook), page, label);
  gtk_widget_show_all(notebook);

  SYLPF_END_FUNC;

  return NULL;
}

static void prefs_filter_to_folder_cb(GObject *obj, gpointer data);
static void inbox_folder_identifier_cb(GObject *obj, gpointer data);

static GtkWidget *create_inbox_widget(void)
{
  GtkWidget *hbox;
  GtkWidget *label;
  GtkWidget *text;
  GtkWidget *folder;
  const gchar *inbox;
  
  hbox = gtk_hbox_new(FALSE, 0);
  label = gtk_label_new(_("Inbox:"));
  text = gtk_entry_new();

  folder = gtk_button_new_from_stock(GTK_STOCK_OPEN);
  g_signal_connect(folder, "clicked",
                   G_CALLBACK(inbox_folder_identifier_cb), text);

  SYLPF_OPTION.inbox = text;
  current_rule.inbox = text;

  inbox = SYLPF_GET_RC_STRING(SYLPF_OPTION.rcfile, "prefs", "inbox");
  if (inbox) {
    gtk_entry_set_text(GTK_ENTRY(text), inbox);
  }

  gtk_box_pack_start(GTK_BOX(hbox), label, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(hbox), text, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(hbox), folder, FALSE, FALSE, 0);

  return hbox;
}

static GtkWidget *create_filter_name_widget(void)
{
  GtkWidget *hbox;
  GtkWidget *label;
  GtkWidget *text;

  hbox = gtk_hbox_new(FALSE, 0);
  label = gtk_label_new(_("Filter name:"));
  text = gtk_entry_new();
  gtk_box_pack_start(GTK_BOX(hbox), label, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(hbox), text, TRUE, TRUE, 0);

  return hbox;
}

static const gchar *header_list[] = {
  "Date:",
  "From:",
  "To:",
  "Subject:",
  "In-Reply-To:",
  "Cc:",
};

static GtkWidget *create_filter_rule_widget(void)
{
  GtkWidget *hbox;
  GtkWidget *label;
  GtkWidget *combo;
  GtkWidget *text;

  hbox = gtk_hbox_new(FALSE, 0);
  label = gtk_label_new(_("Filter rule:"));
#if GTK_CHECK_VERSION(2, 24, 0)
  combo = gtk_combo_box_text_new();
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo),
                            _("Subject"));
#else
  combo = gtk_combo_box_new_with_text();
  gtk_combo_box_append_text(GTK_COMBO_BOX(combo),
                            _("Subject"));
#endif
  text = gtk_entry_new();

  gtk_box_pack_start(GTK_BOX(hbox), label, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(hbox), combo, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(hbox), text, TRUE, TRUE, 0);

  return hbox;
}

static void inbox_folder_identifier_cb(GObject *obj, gpointer data)
{
  gchar *dir_name = NULL;
  gchar *identifier;
  FolderItem *dest_item;
  dest_item = syl_plugin_folder_sel(NULL,
                                    FOLDER_SEL_COPY,
                                    NULL);
  if (dest_item && dest_item->path) {
    SYLPF_DEBUG_STR("name", dest_item->name);
    SYLPF_DEBUG_STR("path", dest_item->path);
    identifier = folder_item_get_identifier(dest_item);
    SYLPF_DEBUG_STR("identifier", identifier);
    gtk_entry_set_text(GTK_ENTRY(data), identifier);
  }
}

static void prefs_filter_to_folder_cb(GObject *obj, gpointer data)
{
  gchar *dir_name = NULL;
  GtkWidget *dialog;
  FolderItem *dest_item;
  dest_item = syl_plugin_folder_sel(NULL,
                                    FOLDER_SEL_COPY,
                                    NULL);
  if (dest_item && dest_item->path) {
    SYLPF_DEBUG_STR("name", dest_item->name);
    SYLPF_DEBUG_STR("path", dest_item->path);
    SYLPF_DEBUG_STR("identifier", folder_item_get_identifier(dest_item));
    gtk_entry_set_text(GTK_ENTRY(data), dest_item->path);
  }
}

static GtkWidget *create_filter_to_widget(void)
{
  GtkWidget *hbox;
  GtkWidget *label;
  GtkWidget *folder;
  GtkWidget *text;

  hbox = gtk_hbox_new(FALSE, 0);
  label = gtk_label_new(_("Apply to:"));
  text = gtk_entry_new();
  gtk_box_pack_start(GTK_BOX(hbox), label, FALSE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(hbox), text, TRUE, TRUE, 0);

  folder = gtk_button_new_from_stock(GTK_STOCK_OPEN);
  g_signal_connect(folder, "clicked",
                   G_CALLBACK(prefs_filter_to_folder_cb), text);
  gtk_box_pack_start(GTK_BOX(hbox), folder, FALSE, FALSE, 0);

  return hbox;
}

static GtkWidget *create_folder_option_widget(void)
{
  GtkWidget *hbox;

  hbox = gtk_hbox_new(FALSE, 0);
  SYLPF_OPTION.create_folder = \
    gtk_check_button_new_with_label(_("Create filtering folder automatically"));
  gtk_box_pack_start(GTK_BOX(hbox), SYLPF_OPTION.create_folder, FALSE, FALSE, 0);

  return hbox;
}


static void check_current_rule_cancel_cb(GtkWidget *widget,
                                         gpointer data)
{
  SYLPF_START_FUNC;;

  PrefsCurrentRule *current;

  current = (PrefsCurrentRule*)data;
  gtk_widget_destroy(current->dialog);

  SYLPF_END_FUNC;;
}

static GAsyncQueue *queue;

typedef struct _PrefsMatchedMail
{
  guint id;
  guint total;
} PrefsMatchedMail;

static gpointer check_current_rule_thread(gpointer data)
{
  SYLPF_START_FUNC;;

  PrefsMatchedMail *matched;
  gint step = 0;
  guint length = 0;
  GSList *mlist;
  MsgInfo *minfo;

  mlist = (GSList*)data;
  if (mlist) {
    length = g_slist_length(mlist);
    for (step = 0; step < length; step++) {
      minfo = (MsgInfo*)g_slist_nth(mlist, step)->data;
      SYLPF_DEBUG_STR("subject", minfo->subject);

      matched = g_new(PrefsMatchedMail, 1);
      matched->id = step + 1;
      matched->total = length;
      g_async_queue_push(queue, (gpointer)matched);
    }
  }

  SYLPF_END_FUNC;;
}

static gboolean check_current_rule_polling(gpointer data)
{
  gint queue_length;
  PrefsMatchedMail *matched;

  SYLPF_START_FUNC;;

  queue_length = g_async_queue_length(queue);
  SYLPF_DEBUG_VAL("queue length", queue_length);
  while (queue_length > 0) {
    matched = (PrefsMatchedMail*)g_async_queue_pop(queue);
    if (matched) {
      SYLPF_DEBUG_PTR("queue item", matched);
      SYLPF_DEBUG_VAL("queue id", matched->id);
      SYLPF_DEBUG_VAL("queue total", matched->total);
      if (matched->id < matched->total) {
        gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(current_rule.progress),
                                      (gdouble)matched->id/matched->total);
      } else {
        gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(current_rule.progress),
                                      1.0);
        g_thread_join(data);
        return FALSE;
      }
    }
    queue_length--;
  }

  SYLPF_END_FUNC;;

  return TRUE;
}

static void prefs_filter_check_current_rule_cb(GtkWidget *widget,
                                               gpointer data)
{

  PrefsCurrentRule *current;
  GtkWidget *progress;
  GtkWidget *dialog;
  GtkWidget *vbox, *cancel;
  GThread *worker;
  GSList *mlist;
  FolderItem *folder;
  const gchar *identifier;

  SYLPF_START_FUNC;;

  current = (PrefsCurrentRule *)data;
  g_return_if_fail(current != NULL);

  g_return_if_fail(current_rule.inbox != NULL);

  identifier = gtk_entry_get_text(GTK_ENTRY(current_rule.inbox));
  g_return_if_fail(identifier != NULL);

  folder = folder_find_item_from_identifier(identifier);
  g_return_if_fail(folder != NULL);

  SYLPF_DEBUG_STR("default name", folder->name);
  SYLPF_DEBUG_STR("default path", folder->path);
  SYLPF_DEBUG_STR("default identifier", folder_item_get_identifier(folder));
  mlist = folder_item_get_msg_list(folder, FALSE);
  g_return_if_fail(mlist != NULL);

  progress = gtk_progress_bar_new();
  gtk_progress_bar_set_text(GTK_PROGRESS_BAR(progress), _("Searching received mail archives..."));
  gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progress), 0.0);

  dialog = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_modal(GTK_WINDOW(dialog), TRUE);

  vbox = gtk_vbox_new(TRUE, 0);

  cancel = gtk_button_new_with_label(_("Cancel"));

  current->dialog = dialog;
  current->progress = progress;

  g_signal_connect(GTK_WIDGET(cancel), "clicked",
                   G_CALLBACK(check_current_rule_cancel_cb),
                   data);

  gtk_box_pack_start(GTK_BOX(vbox), progress, TRUE, TRUE, SYLPF_ALIGN_TOP);
  gtk_box_pack_start(GTK_BOX(vbox), cancel, FALSE, FALSE, SYLPF_ALIGN_TOP);

  gtk_container_add(GTK_CONTAINER(dialog), vbox);
  gtk_widget_show_all(dialog);

  queue = g_async_queue_new();

  worker = g_thread_new("", check_current_rule_thread, mlist);

  g_timeout_add(1000, check_current_rule_polling, worker);

  SYLPF_END_FUNC;;
}

static void prefs_filter_add_current_rule_cb(GtkWidget *widget,
                                             gpointer data)
{
  SYLPF_START_FUNC;;

  SYLPF_END_FUNC;;
}


static GtkWidget *create_filter_edit_button_widget(void)
{
  GtkWidget *hbox;
  GtkWidget *check_rule;
  GtkWidget *add_rule;

  hbox = gtk_hbox_new(FALSE, 0);
  add_rule = gtk_button_new_from_stock(GTK_STOCK_SAVE);
  check_rule = gtk_button_new_from_stock(GTK_STOCK_FIND);
  gtk_box_pack_end(GTK_BOX(hbox), add_rule, FALSE, FALSE, 0);
  gtk_box_pack_end(GTK_BOX(hbox), check_rule, FALSE, FALSE, 0);

  g_signal_connect(GTK_WIDGET(check_rule), "clicked",
                   G_CALLBACK(prefs_filter_check_current_rule_cb),
                   &current_rule);
  g_signal_connect(GTK_WIDGET(add_rule), "clicked",
                   G_CALLBACK(prefs_filter_add_current_rule_cb),
                   NULL);

  return hbox;
}

static GtkWidget *create_filter_manage_button_widget(void)
{
  GtkWidget *hbox;
  GtkWidget *find;
  GtkWidget *edit;
  GtkWidget *delete;
  GtkWidget *exec;

  hbox = gtk_hbox_new(FALSE, 0);
  find = gtk_button_new_from_stock(GTK_STOCK_FIND);
  edit = gtk_button_new_from_stock(GTK_STOCK_EDIT);
  delete = gtk_button_new_from_stock(GTK_STOCK_DELETE);
  exec = gtk_button_new_from_stock(GTK_STOCK_EXECUTE);

  gtk_box_pack_end(GTK_BOX(hbox), exec, FALSE, FALSE, 0);
  gtk_box_pack_end(GTK_BOX(hbox), delete, FALSE, FALSE, 0);
  gtk_box_pack_end(GTK_BOX(hbox), edit, FALSE, FALSE, 0);
  gtk_box_pack_end(GTK_BOX(hbox), find, FALSE, FALSE, 0);

  return hbox;
}


static GtkWidget *create_config_about_page(GtkWidget *notebook, GKeyFile *pkey)
{

  GtkWidget *hbox;
  GtkWidget *vbox;
  GtkWidget *misc;
  GtkWidget *scrolled;
  GtkTextBuffer *tbuffer;
  GtkWidget *tview;
  GtkWidget *label;
  
  SYLPF_START_FUNC;

  hbox = gtk_hbox_new(TRUE, 6);
  vbox = gtk_vbox_new(FALSE, 6);
  gtk_box_pack_start(GTK_BOX(hbox), vbox, TRUE, TRUE, 6);

  misc = gtk_label_new("PrefsFilter");
  gtk_box_pack_start(GTK_BOX(vbox), misc, FALSE, TRUE, 6);

  misc = gtk_label_new(PLUGIN_DESC);
  gtk_box_pack_start(GTK_BOX(vbox), misc, FALSE, TRUE, 6);

  /* copyright */
  scrolled = gtk_scrolled_window_new(NULL, NULL);

  tbuffer = gtk_text_buffer_new(NULL);
  gtk_text_buffer_set_text(tbuffer, _(copyright_message),
                           strlen(copyright_message));
  tview = gtk_text_view_new_with_buffer(tbuffer);
  gtk_text_view_set_editable(GTK_TEXT_VIEW(tview), FALSE);
  gtk_container_add(GTK_CONTAINER(scrolled), tview);

  gtk_box_pack_start(GTK_BOX(vbox), scrolled, TRUE, TRUE, 6);

  label = gtk_label_new(_("About"));
  gtk_notebook_append_page(GTK_NOTEBOOK(notebook), hbox, label);
  gtk_widget_show_all(notebook);

  SYLPF_END_FUNC;

  return NULL;
}

