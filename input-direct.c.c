#include <gtk/gtk.h>

// キーボード入力のコールバック関数
gboolean on_key_press(GtkWidget *widget, GdkEventKey *event, gpointer user_data) {
    GtkTextBuffer *buffer = GTK_TEXT_BUFFER(user_data);
    GtkTextIter iter;

    // 'a' キーが押されたかを確認
    if (event->keyval == GDK_KEY_a) {
        // テキストバッファの末尾に "あ" を挿入
        gtk_text_buffer_get_end_iter(buffer, &iter);
        gtk_text_buffer_insert(buffer, &iter, "あ", -1);
        return TRUE;  // TRUE を返して他のハンドラを呼び出さない
    }

    return FALSE;  // 他のキーイベントは引き続き処理する
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // ウィンドウを作成
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "TextView Key Press Example");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 200);

    // GtkTextView と GtkTextBuffer を作成
    GtkWidget *text_view = gtk_text_view_new();
    GtkTextBuffer *buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(text_view));

    // ウィンドウにテキストビューを追加
    gtk_container_add(GTK_CONTAINER(window), text_view);

    // ウィンドウが閉じられたらプログラムを終了
    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // テキストビューにキー入力イベントを接続
    g_signal_connect(window, "key-press-event", G_CALLBACK(on_key_press), buffer);

    gtk_widget_show_all(window);
    gtk_main();

    return 0;
}
