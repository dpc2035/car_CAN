//
//
#include <can_real_time.h>
#include "includes.h"

static gboolean on_expose_event(GtkWidget * widget, GdkEventExpose * event, gpointer data)
{
	cairo_t *cr;
	
//	cr = gdk_cairo_create(widget->window);
	
	cairo_set_source_rgb(cr, 0.627, 0, 0);
	cairo_select_font_face(cr, "Adobe Heiti Std", CAIRO_FONT_SLANT_NORMAL,
			CAIRO_FONT_WEIGHT_NORMAL);
	cairo_set_font_size(cr, 24.0);
	
	cairo_move_to(cr, 10.0, 34.0);
	cairo_show_text(cr, "是");
	
	cairo_destroy(cr);
	
	return FALSE;
}

int cairo_no_1(int argc, char *argv[])
{
	
	GtkWidget *window;
	
	gtk_init(&argc, &argv);
	
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	
	g_signal_connect(window, "expose-event", G_CALLBACK ( on_expose_event), NULL);
	g_signal_connect(window, "destroy", G_CALLBACK ( gtk_main_quit), NULL);
	
	gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
	gtk_window_set_default_size(GTK_WINDOW(window), 320, 48);
	gtk_widget_set_app_paintable(window, TRUE);
	
	gtk_widget_show_all(window);
	
	gtk_main();
	
	return 0;
}
