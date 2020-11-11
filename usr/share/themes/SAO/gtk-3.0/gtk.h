#include <gtk/gtk.h>

gint main (gint argc, gchar **argv)
{
    GtkCssProvider *css_provider = NULL;
    GtkStyleContext *context = NULL;
    GError *error = NULL;
    GFile *file = NULL;
    GtkWidget *pButton = NULL;
    GtkWidget *pWindow = NULL;

    gtk_init (&argc, &argv);

    pWindow=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(pWindow), GTK_WIN_POS_CENTER);
    gtk_widget_set_size_request(pWindow, 80, 80);

    pButton = gtk_button_new();

    gtk_container_add(GTK_CONTAINER (pWindow), pButton);

    g_signal_connect(G_OBJECT(pWindow), "destroy",
(GCallback)gtk_main_quit, NULL);

    file = g_file_new_for_path("mygtk.css");
    css_provider = gtk_css_provider_get_default ();
    gtk_css_provider_load_from_file (css_provider, file, &error);
    context = gtk_style_context_new ();
    gtk_style_context_add_provider(context,
GTK_STYLE_PROVIDER(css_provider), 10);

    gtk_widget_show_all (pWindow);

    gtk_main ();

    return 0;
}
--------------------------------------------------

The "mygtk.css" file contains :

--------------------------------------------------
GtkButton {
    background-image: url("assets/Button_PushButton_NormalImage.png");
}

GtkButton:active {
    background-image: url("assets/Button_PushButton_PressedImage.png");
}
--------------------------------------------------

