#include <gtk/gtk.h>

// Callback function to handle "destroy" signal
static void on_destroy(GtkWidget *widget, gpointer data) {
    gtk_main_quit();
}

int main(int argc, char *argv[]) {
    GtkWidget *window;
    GtkWidget *scrolled_window;
    GtkWidget *tree_view;
    GtkListStore *list_store;
    GtkTreeIter iter;
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;

    // Initialize GTK+
    gtk_init(&argc, &argv);

    // Create a new top-level window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "ListView Example");
    gtk_window_set_default_size(GTK_WINDOW(window), 300, 200);

    // Connect the "destroy" signal of the window to the callback function
    g_signal_connect(window, "destroy", G_CALLBACK(on_destroy), NULL);

    // Create a new scrolled window
    scrolled_window = gtk_scrolled_window_new(NULL, NULL);
    gtk_container_add(GTK_CONTAINER(window), scrolled_window);

    // Create a new tree view
    tree_view = gtk_tree_view_new();
    gtk_container_add(GTK_CONTAINER(scrolled_window), tree_view);

    // Create a new list store with one column of type string
    list_store = gtk_list_store_new(1, G_TYPE_STRING);

    // Insert some rows into the list store
    gtk_list_store_append(list_store, &iter);
    gtk_list_store_set(list_store, &iter, 0, "Item 1", -1);
    gtk_list_store_append(list_store, &iter);
    gtk_list_store_set(list_store, &iter, 0, "Item 2", -1);
    gtk_list_store_append(list_store, &iter);
    gtk_list_store_set(list_store, &iter, 0, "Item 3", -1);

    // Set the model for the tree view
    gtk_tree_view_set_model(GTK_TREE_VIEW(tree_view), GTK_TREE_MODEL(list_store));

    // Create a new cell renderer
    renderer = gtk_cell_renderer_text_new();
    
    // Create a new tree view column
    column = gtk_tree_view_column_new_with_attributes("Column 1", renderer, "text", 0, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view), column);

    // Show all widgets
    gtk_widget_show_all(window);

    // Start the GTK+ main loop
    gtk_main();

    return 0;
}
