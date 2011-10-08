#import <gtk/gtk.h>

void do_jailbreak(GtkWidget *button) {
	if (strcmp(gtk_button_get_label(button), "Jailbreak succeeded, exit") == 0) {
		gtk_main_quit();
		exit(0); // yay, if success, why report error?
	}
	if (strcmp(gtk_button_get_label(button), "Failed") == 0) {
		gtk_main_quit();
		exit(1);
	}
	gtk_button_set_label(button, "Jailbreaking...");
	int status = system("./spirit");
	if (status != 0) {
		gtk_button_set_label(button, "Failed");
	} else {
		gtk_button_set_label(button, "Jailbreak succeeded, exit");
	}
}

int main() {
	gtk_init(NULL, NULL);
	GtkWindow *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(window, "Spirit Jailbreak");
	gtk_window_set_default_size(window, 400, 200);
	gtk_window_set_position(window, GTK_WIN_POS_CENTER);
	g_signal_connect(window, "destroy", gtk_main_quit, NULL);
	GtkWidget *button = gtk_button_new_with_label("Jailbreak!");
	gtk_container_add(window, button);
	g_signal_connect(button, "clicked", do_jailbreak, NULL);
	gtk_widget_show_all(window);
	gtk_main();
	return 0;
}

