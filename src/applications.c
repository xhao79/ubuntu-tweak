#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include "ubuntu-tweak.h"
#include "desktop_page.h"
#include "mplayer_page.h"
#include "awn_page.h"
#include <stdio.h>

GtkWidget *create_applications_notebook()
{
	GtkWidget *notebook;
	GtkWidget *main_vbox;
	GtkWidget *page_label;
	GConfClient *client;
	gboolean *bool;

	client=gconf_client_get_default();

	notebook=gtk_notebook_new();
	gtk_notebook_set_tab_pos(GTK_NOTEBOOK(notebook),GTK_POS_TOP);

	bool=gconf_client_get_bool(client,"/apps/ubuntu-tweak/system/fcitx",NULL);
	if(bool==TRUE){
		main_vbox=create_fcitx_page();
		page_label=gtk_label_new("Fcitx输入法");
		gtk_widget_show(page_label);
		gtk_notebook_append_page(GTK_NOTEBOOK(notebook),main_vbox,page_label);
	}

	main_vbox=create_awn_page();
	gtk_widget_show(main_vbox);
	page_label=gtk_label_new("Avant Window Navigator");
	gtk_widget_show(page_label);
	gtk_notebook_append_page(GTK_NOTEBOOK(notebook),main_vbox,page_label);	
	
	main_vbox=create_mplayer_page();
	gtk_widget_show(main_vbox);
	page_label=gtk_label_new("Mplayer");
	gtk_widget_show(page_label);
	gtk_notebook_append_page(GTK_NOTEBOOK(notebook),main_vbox,page_label);	
	
	return notebook;
}

