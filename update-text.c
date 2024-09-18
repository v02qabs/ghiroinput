#include <gtk/gtk.h>

// タイマーでテキストを更新するコールバック関数
gboolean update_text(gpointer user_data) {
    GtkTextBuffer *buffer = GTK_TEXT_BUFFER(user_data);
    GtkTextIter iter;
    static int count = 0;

    // テキストバッファの末尾にテキストを追加
    gtk_text_buffer_get_end_iter(buffer, &iter);
    gchar *new_text = g_strdup_printf("Update %d\n", count++);
    gtk_text_buffer_insert(buffer, &iter, new_text, -1);
    g_free(new_text);

    return TRUE;  // TRUE を返すことで、タイマーが再び呼び出される
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // ウィンドウを作成
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Real-time GtkTextView Update");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 200);

    // GtkTextView と GtkTextBuffer を作成
    GtkWidget *text_view = gtk_text_view_new();
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));

    // ウィンドウにテキストビューを追加
    gtk_container_add(GTK_CONTAINER(window), text_view);

    // ウィンドウが閉じられたらプログラムを終了
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // 1秒ごとにテキストを更新するタイマーを設定
    g_timeout_add(1000, update_text, buffer);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}

