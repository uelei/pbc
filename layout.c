#include <gtk/gtk.h>
#include "lay_lista_cli.h"
#include "lay_pdv.h"
#include "caixavendas.h"

//principal
GtkWidget *vbox;
GtkWidget *fixed;
GtkWidget *window;
GtkWidget *toolbar;
GtkToolItem *botaocliente;
GtkToolItem *bpdv;
GtkToolItem *save;
GtkToolItem *vendastotal;
GtkToolItem *sep;
GtkToolItem *exi;
////////////////////////

void barraprincipal(void)
{
  vbox = gtk_vbox_new(FALSE, 0);
  gtk_container_add(GTK_CONTAINER(window), vbox);

  toolbar = gtk_toolbar_new();
  gtk_toolbar_set_style(GTK_TOOLBAR(toolbar), GTK_TOOLBAR_ICONS);

  gtk_container_set_border_width(GTK_CONTAINER(toolbar), 2);

GtkWidget *icon_new,*icon_pdv;

  icon_new = gtk_image_new_from_file("imagens/kdmconfig.png");
  botaocliente = gtk_tool_button_new(icon_new, NULL);

  //new = gtk_tool_button_new_from_stock(GTK_STOCK_NEW);
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar),botaocliente, -1);


  icon_pdv = gtk_image_new_from_file("imagens/buy_32.png");
  bpdv= gtk_tool_button_new(icon_pdv, NULL);


  //bpdv = gtk_tool_button_new_from_stock(GTK_STOCK_OPEN);
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), bpdv, -1);

//  save = gtk_tool_button_new_from_stock(GTK_STOCK_SAVE);
//  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), save, -1);



GtkWidget *icon_vendastotal;

  icon_vendastotal = gtk_image_new_from_file("imagens/moneycalculator.png");
  vendastotal = gtk_tool_button_new(icon_vendastotal, NULL);
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar),vendastotal, -1);



  sep = gtk_separator_tool_item_new();
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), sep, -1); 

  exi = gtk_tool_button_new_from_stock(GTK_STOCK_QUIT);
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), exi, -1);

  gtk_box_pack_start(GTK_BOX(vbox), toolbar, FALSE, FALSE, 5);

  g_signal_connect(G_OBJECT(exi), "clicked", 
        G_CALLBACK(gtk_main_quit), NULL);

  g_signal_connect_swapped(G_OBJECT(window), "destroy",
        G_CALLBACK(gtk_main_quit), NULL);

  g_signal_connect_swapped(G_OBJECT(botaocliente), "clicked",G_CALLBACK(telacliente),NULL);
  g_signal_connect_swapped(G_OBJECT(bpdv), "clicked",G_CALLBACK(windowpdvc),NULL);

  g_signal_connect_swapped(G_OBJECT(vendastotal), "clicked",G_CALLBACK(telatotalvendas),NULL);

  fixed = gtk_fixed_new();
  gtk_box_pack_start(GTK_BOX(vbox),fixed,FALSE,FALSE,1);

  gtk_widget_show_all(window);

  return ;
}


GdkPixbuf *create_pixbuf(const gchar * filename){
//gera o icone para aplicacao 

   GdkPixbuf *pixbuf;
   GError *error = NULL;
   pixbuf = gdk_pixbuf_new_from_file(filename, &error);
   if(!pixbuf) {
      fprintf(stderr, "%s\n", error->message);
      g_error_free(error);
   }

   return pixbuf;
}

void windowmain( gint argc, gchar *argv[]){

  gtk_init(&argc, &argv);

  window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(window), "piubol 0.10");
  gtk_window_set_default_size(GTK_WINDOW(window), 1280, 750);
  gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_icon(GTK_WINDOW(window), create_pixbuf("imagens/smile.png"));
  gtk_widget_show(window);

  g_signal_connect_swapped(G_OBJECT(window), "destroy",G_CALLBACK(gtk_main_quit), NULL);
  barraprincipal();
  gtk_main();

  return;
}
