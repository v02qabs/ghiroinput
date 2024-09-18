#include <gtk/gtk.h>

int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *view;
    GtkTextBuffer *buffer;
    GtkTextTag *tag;
    GtkTextIter start, end;
    GdkRGBA color;

    gtk_init(&argc, &argv);

    // Create a new window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Text Color Example");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);

    // Create a GtkTextView and its associated buffer
    view = gtk_text_view_new();
    buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(view));

    // Set the initial text
    const char *text ="s";
    gtk_text_buffer_set_text(buffer, text, -1);

    // Create a tag with a specific color
    tag = gtk_text_buffer_create_tag(buffer, "colored_text", "foreground-rgba", &color, NULL);

    // Set the desired text color using GdkRGBA
    gdk_rgba_parse(&color, "red");  // You can set any valid color here

    // Apply the tag to the entire text in the buffer
    gtk_text_buffer_get_start_iter(buffer, &start);
    gtk_text_buffer_get_end_iter(buffer, &end);
    gtk_text_buffer_apply_tag(buffer, tag, &start, &end);

    // Add the GtkTextView to the window
    gtk_container_add(GTK_CONTAINER(window), view);

    // Show everything
    gtk_widget_show_all(window);

    // Connect the window close event
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_main();

    return 0;
}

