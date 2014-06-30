#include "lay_pdv.h"




GdkPixbuf *create_pixbufpdv(const gchar * filename){
//gera o icone para aplicacao 

   GdkPixbuf *pixbufpdv;
   GError *error = NULL;
   pixbufpdv = gdk_pixbuf_new_from_file(filename, &error);
   if(!pixbufpdv) {
      fprintf(stderr, "%s\n", error->message);
      g_error_free(error);
   }

   return pixbufpdv;
}

void windowpdvc( int argc, char **argv[]){

  gtk_init(&argc, &argv);
  fixedpdv = gtk_fixed_new();
  windowpdv = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(windowpdv), "PDV 0.10");
  gtk_window_set_default_size(GTK_WINDOW(windowpdv), 980, 650);
  gtk_window_set_position(GTK_WINDOW(windowpdv), GTK_WIN_POS_CENTER);
  gtk_window_set_icon(GTK_WINDOW(windowpdv), create_pixbufpdv("imagens/buy_32.png"));
  gtk_widget_show(windowpdv);

  g_signal_connect_swapped(G_OBJECT(windowpdv), "destroy",G_CALLBACK(gtk_main_quit), NULL);
  //barraprincipal();
  gtk_container_add(GTK_CONTAINER(windowpdv), fixedpdv);
  gtk_widget_show_all(windowpdv);
  gtk_main();

  return;
}

