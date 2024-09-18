#include <gtk/gtk.h>

GtkWidget *txt_choice_win;

gboolean on_key_s(GtkWidget *widget, GdkEventKey *event, gpointer user_data){
	GtkTextBuffer *buffer = GTK_TEXT_BUFFER(user_data);
	GtkTextIter iter;
	GtkTreeIter iter2;
	if(event->keyval == GDK_KEY_a){
		g_print("さ");
		gtk_text_buffer_get_end_iter(buffer, &iter);
		gtk_text_buffer_insert(buffer, &iter , "さ", -1);
gtk_widget_hide(txt_choice_win);  
		return TRUE;
	}
	if(event->keyval==GDK_KEY_i){
		g_print("し");
		gtk_text_buffer_get_end_iter(buffer, &iter);
		gtk_text_buffer_insert(buffer, &iter, "し", -1);
gtk_widget_hide(txt_choice_win);  
		return TRUE;
	}

	return FALSE;
}

const char text;

void setText(const char txt){
	text == txt;
}


const char get_text(){
	return text;
}

GtkListStore *tree_store;

// キーボード入力のコールバック関数
gboolean on_key_press(GtkWidget *widget, GdkEventKey *event, gpointer user_data) {
    GtkTextBuffer *buffer = GTK_TEXT_BUFFER(user_data);
    GtkTreeIter iter2;
	GtkWidget *scroll;

    // 'a' キーが押されたかを確認
    if (event->keyval == GDK_KEY_a) {
        // テキストバッファの末尾に "あ" を挿入
	GtkWidget *a_choice_win;
	a_choice_win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size(GTK_WINDOW(a_choice_win), 100,50);
	GtkWidget *tree_view = gtk_tree_view_new();
	tree_store = gtk_list_store_new(1, G_TYPE_STRING);

	scroll = gtk_scrolled_window_new(NULL,NULL);
	gtk_list_store_append(tree_store, &iter2);
	gtk_list_store_set(tree_store, &iter2, 0, "有", -1);
	gtk_tree_view_set_model(GTK_TREE_VIEW(tree_view), GTK_TREE_MODEL(tree_store));
	gtk_container_add(GTK_CONTAINER(scroll),tree_view);

	GtkCellRenderer *red;
	GtkTreeViewColumn *column;

	red = gtk_cell_renderer_text_new();
	column = gtk_tree_view_column_new_with_attributes("Col", red,"text",0,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view), column);
	gtk_container_add(GTK_CONTAINER(a_choice_win), scroll);
	gtk_widget_show_all(a_choice_win);
        return TRUE;  // TRUE を返して他のハンドラを呼び出さない
    }

    if(event->keyval == GDK_KEY_s)
{
	GdkRGBA color;
	GtkTextTag *tag;
	const char *text = "s";
	txt_choice_win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size(GTK_WINDOW(txt_choice_win), 400, 200);
	GtkWidget *text_view = gtk_text_view_new();
	gtk_container_add(GTK_CONTAINER(txt_choice_win),text_view);
	get_text("さ");
g_signal_connect
(txt_choice_win, "key-press-event", G_CALLBACK(on_key_s), buffer);

	gtk_widget_show(txt_choice_win);

	return TRUE;
}

	if(event->keyval == GDK_KEY_space){
		g_print("変換します。");
	}



    // 'Enter' キーが押されたかを確認
    if (event->keyval == GDK_KEY_Return || event->keyval == GDK_KEY_KP_Enter) {
        // テキストバッファの末尾にメッセージを挿入
	g_print("enter.\n");
    GtkClipboard *clipboard = gtk_clipboard_get(GDK_SELECTION_CLIPBOARD);

    // Set the text you want to copy to the clipboard
    const gchar *text = "あ";
    gtk_clipboard_set_text(clipboard, text, -1);


    g_print("Text copied to clipboard: %s\n", text);


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
