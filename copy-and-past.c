#include <gtk/gtk.h>

void copy_to_clipboard(GtkWidget *widget, gpointer user_data) {
    // Get the default clipboard
    GtkClipboard *clipboard = gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);

    // Set the text you want to copy to the clipboard
    const gchar *text = "あ";
    gtk_clipboard_set_text(clipboard, text, -1);

    g_print("Text copied to clipboard: %s\n", text);
}

// Callback function to handle the clipboard data
void on_clipboard_text_received(GtkClipboard *clipboard, const gchar *text, gpointer user_data) {
    if (text != NULL) {
        g_print("Clipboard text: %s\n", text); // Print the clipboard contents
    } else {
        g_print("No text on the clipboard.\n");
    }
}

int main(int argc, char *argv[]) {
    // Initialize GTK
    gtk_init(&argc, &argv);

    // Create a new window
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Clipboard Example");
    gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);
    GtkWidget *button = gtk_button_new_with_label("あ");
    g_signal_connect(button, "clicked", G_CALLBACK(copy_to_clipboard), NULL);
    // Get the default clipboard
    GtkClipboard *clipboard = gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);

    // Request the clipboard text asynchronously
    gtk_clipboard_request_text(clipboard, on_clipboard_text_received, NULL);
    gtk_container_add(GTK_CONTAINER(window), button);
    // Show the window
    gtk_widget_show_all(window);

    // Enter the GTK main loop
    gtk_main();

    return 0;
}
