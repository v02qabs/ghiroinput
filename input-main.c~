#include <gtk/gtk.h>
int main(int argc, char *argv[]) {
    // Initialize GTK
    gtk_init(&argc, &argv);

    // Create a new window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "あ");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

	//Create a new text
	GtkWidget *view = gtk_text_view_new();
	    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(view));
	    
    const char *text = "あ";
    gtk_text_buffer_set_text(buffer, text, -1);  
 gtk_container_add(GTK_CONTAINER(window), view);


	gtk_widget_show_all(window);

    // Enter the GTK main loop
    gtk_main();

    return 0;
}
