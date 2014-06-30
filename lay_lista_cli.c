#include <gtk/gtk.h>
#include "fuc_cli.h"
#include "layout.h"
#include "lay_det_cli.h"


//menucliente
  GtkWidget *barcli;
  GtkToolItem *ncli;
  GtkToolItem *bdelcli;
  GtkToolItem *ecli;
  GtkToolItem *scli;
  GtkToolItem *ocli;
  GtkToolItem *closecli;
  GtkToolItem *backlcli,*refche;
int handler_id;

//listadecliente
GtkWidget *lebcli;
GtkWidget *ebcli;
GtkWidget *swcli;
GtkTreeStore *treestorecli;
GtkWidget *treewcli;
GtkTreeSelection *selection;
GtkTreeViewColumn *coluna;
GtkCellRenderer *celula;
char clisele[20];
enum{ CODCLI_COL,NOMECLI_COL,CPFCLI_COL,CIDCLI_COL,NUM_COLS};


void novcli(GtkWidget *widget,gpointer poniter);

void upbotaocliente(void){

gtk_widget_set_sensitive(GTK_WIDGET(botaocliente),TRUE);
gtk_widget_destroy(barcli);

}

void limpatelalistaclienteparatelacheque(void){
gtk_widget_destroy(treewcli);
gtk_widget_destroy(ebcli);
gtk_widget_destroy(swcli);
gtk_widget_destroy(lebcli);

}


void limpatelalistacliente(void){
gtk_widget_destroy(treewcli);
gtk_widget_destroy(ebcli);
gtk_widget_destroy(swcli);
gtk_widget_destroy(lebcli);

upbotaocliente();
}



void menucliente(void){


//  GtkTreeSelection *selection; 

  barcli = gtk_toolbar_new();
  gtk_widget_set_usize(barcli,280,50);
  gtk_toolbar_set_style(GTK_TOOLBAR(barcli), GTK_TOOLBAR_ICONS);
  //gtk_toolbar_set_orientation(GTK_TOOLBAR(toolbar), GTK_ORIENTATION_VERTICAL);
  gtk_container_set_border_width(GTK_CONTAINER(barcli), 2);

  ncli = gtk_tool_button_new_from_stock(GTK_STOCK_NEW);
  gtk_toolbar_insert(GTK_TOOLBAR(barcli),ncli, -1);

  ocli = gtk_tool_button_new_from_stock(GTK_STOCK_OPEN);
  gtk_toolbar_insert(GTK_TOOLBAR(barcli),ocli, -1);
  gtk_widget_set_sensitive(GTK_WIDGET(ocli), FALSE);

  ecli = gtk_tool_button_new_from_stock(GTK_STOCK_EDIT);
  gtk_toolbar_insert(GTK_TOOLBAR(barcli),ecli, -1);
  gtk_widget_set_sensitive(GTK_WIDGET(ecli), FALSE);

  scli = gtk_tool_button_new_from_stock(GTK_STOCK_SAVE);
  gtk_toolbar_insert(GTK_TOOLBAR(barcli),scli, -1);
  gtk_widget_set_sensitive(GTK_WIDGET(scli) ,FALSE);

  backlcli = gtk_tool_button_new_from_stock(GTK_STOCK_GO_BACK);
  gtk_toolbar_insert(GTK_TOOLBAR(barcli),backlcli, -1);
  gtk_widget_set_sensitive(GTK_WIDGET(backlcli) ,FALSE);

  closecli = gtk_tool_button_new_from_stock(GTK_STOCK_CLOSE);
  gtk_toolbar_insert(GTK_TOOLBAR(barcli),closecli, -1);
  //gtk_widget_set_sensitive(GTK_WIDGET(closecli) ,FALSE);
  bdelcli = gtk_tool_button_new_from_stock(GTK_STOCK_REMOVE);
  gtk_toolbar_insert(GTK_TOOLBAR(barcli),bdelcli,-1);
  gtk_widget_set_sensitive(GTK_WIDGET(bdelcli),FALSE);

  //ncli = gtk_button_new_with_label("novo");
  //gtk_fixed_put(GTK_FIXED(fixed),barcli,230,0); 
  //selection  = gtk_tree_view_get_selection(GTK_TREE_VIEW(treewcli));
 //g_signal_connect(selection, "changed",G_CALLBACK(on_changed),ocli);
 g_signal_connect(G_OBJECT(ocli), "clicked",G_CALLBACK(opencliente),NULL);
  g_signal_connect(G_OBJECT(ncli), "clicked",G_CALLBACK(novcli),NULL);
  g_signal_connect(G_OBJECT(ecli), "clicked",G_CALLBACK(editcliente),NULL);
 g_signal_connect(G_OBJECT(scli), "clicked",G_CALLBACK(salvacliente),NULL);
 g_signal_connect(G_OBJECT(backlcli), "clicked",G_CALLBACK(voltateladecliente),NULL);
 g_signal_connect(G_OBJECT(bdelcli),"clicked",G_CALLBACK(deleclidet),barcli);
handler_id =  g_signal_connect(G_OBJECT(closecli), "clicked",G_CALLBACK(limpatelalistacliente),NULL);
//handler_id = g_signal_connect(G_OBJECT(closecli), "clicked",G_CALLBACK(closetdcli),NULL);

///void voltateladecliente(void)
 //g_signal_handler_disconnect(closecli, handler_id);


//  g_signal_connect(G_OBJECT(ebcli), "changed",G_CALLBACK(scliente),treestorecli);

  gtk_fixed_put(GTK_FIXED(fixed),barcli,0,0);

gtk_widget_show(barcli);
gtk_widget_show_all(fixed);

return ;
}

void  on_changed(GtkWidget *widget,gpointer ocli) 
{
  GtkTreeIter iter;
  GtkTreeModel *model;
  char *clisel;


  if (gtk_tree_selection_get_selected(GTK_TREE_SELECTION(widget), &model, &iter)) {

    gtk_tree_model_get(model, &iter, CODCLI_COL, &clisel,  -1);
   // gtk_widget_set_sensitive(GTK_WIDGET(bdelcli),TRUE);
    //gtk_statusbar_push(GTK_STATUSBAR(statusbar), gtk_statusbar_get_context_id(GTK_STATUSBAR(statusbar), value), value);
    gtk_widget_set_sensitive(GTK_WIDGET(ocli), TRUE);
    
    sprintf(clisele,"%s",clisel);
  //g_print(" valor = %s \n",clisel);
    //g_print(" valor = %s \n",value);
    //g_free(value);    
    g_free(clisel);

  }
  else {
    gtk_widget_set_sensitive(GTK_WIDGET(ocli), FALSE);
   // gtk_widget_set_sensitive(GTK_WIDGET(bdelcli),FALSE);
   clisel= "";
}
}


void listadecliente (void){

  gtk_widget_set_sensitive(GTK_WIDGET(botaocliente), FALSE);

  //gtk_fixed_put(GTK_FIXED(fixed),menucliente(),0,0);

  lebcli = gtk_label_new("cliente :");

  gtk_fixed_put(GTK_FIXED(fixed),lebcli,300,17);
  ebcli= gtk_entry_new();
  gtk_fixed_put(GTK_FIXED(fixed),ebcli,380,12);


  swcli = gtk_scrolled_window_new(NULL,NULL);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW(swcli),GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
  gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW(swcli),GTK_SHADOW_ETCHED_IN);
  gtk_widget_set_usize (swcli, 900, 360);


  treestorecli = gtk_tree_store_new (NUM_COLS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
  treewcli =gtk_tree_view_new_with_model(GTK_TREE_MODEL (treestorecli));
  g_object_unref(G_OBJECT(treestorecli));
//coluna cod cliente 
  celula = gtk_cell_renderer_text_new();
  coluna = gtk_tree_view_column_new_with_attributes("codcli",celula,"text",CODCLI_COL,NULL);
  gtk_tree_view_append_column(GTK_TREE_VIEW(treewcli),coluna);
//coluna nome cliente
  celula = gtk_cell_renderer_text_new();
  coluna = gtk_tree_view_column_new_with_attributes("nomecliente",celula,"text",NOMECLI_COL,NULL);
  //coluna.set_sort_column_id(0);
  gtk_tree_view_append_column(GTK_TREE_VIEW(treewcli),coluna);
//cpf cliente 
  celula = gtk_cell_renderer_text_new();
  coluna = gtk_tree_view_column_new_with_attributes("cpfcli",celula,"text",CPFCLI_COL,NULL);
  gtk_tree_view_append_column(GTK_TREE_VIEW(treewcli),coluna);
//gtk_cell_renderer_set_fixed_size (renderer,120,20);
//cidade cliente 
  celula = gtk_cell_renderer_text_new();
  coluna = gtk_tree_view_column_new_with_attributes("cidadecli",celula,"text",CIDCLI_COL,NULL);
  gtk_tree_view_append_column(GTK_TREE_VIEW(treewcli),coluna);

  gtk_scrolled_window_add_with_viewport (GTK_SCROLLED_WINDOW(swcli),treewcli);

  gtk_fixed_put(GTK_FIXED(fixed),swcli,10,50);

//menucliente();



  //gtk_widget_show(ncli);

  //botao = gtk_button_new_with_label("teste");
  //gtk_widget_set_size_request(botao, 80, 35);
 // gtk_entry_set_text(GTK_ENTRY(entrycliente),"texto");
  //gtk_fixed_put(GTK_FIXED(fixed),botao,100,100);
  
 // char entritext[] = gtk_entry_get_buffer(entrycliente);
  //g_print(" testo %s ",entritext);
//  char txto = gtk_entry_get_text(GTK_ENTRY(entrycliente));

//gchar *entry_text = g_strdup(gtk_entry_get_text(GTK_ENTRY(entrycliente)));
//g_signal_connect(G_OBJECT(zatwierdz), "clicked", G_CALLBACK(druk_katalog), entry_text);



  //gchar *gtk_entry_get_text(GtkEntry *entry)

//g_signal_connect(G_OBJECT(zatwierdz), "clicked", G_CALLBACK(druk_katalog), entry_text);
  //g_signal_connect_swapped(G_OBJECT(botao), "clicked",G_CALLBACK(scliente),"");

//  g_signal_connect(G_OBJECT(entrycliente), "changed",G_CALLBACK(scliente),treestorecli);



//busca string e lista 
g_signal_connect(G_OBJECT(ebcli), "changed",G_CALLBACK(scliente),treestorecli);
  //g_signal_connect(G_OBJECT(ebcli), "key-release-event",G_CALLBACK(maskcpf),NULL);
  //g_signal_connect(G_OBJECT(ebcli), "backspace",G_CALLBACK(baks),NULL);
//desativado



 selection  = gtk_tree_view_get_selection(GTK_TREE_VIEW(treewcli));
  g_signal_connect(selection, "changed",G_CALLBACK(on_changed),ocli);

 g_signal_connect(G_OBJECT(treewcli),"row-activated",G_CALLBACK(opencliente),NULL);


  //scliente(ebcli,treestorecli);
  gtk_widget_grab_focus(ebcli);
  //gtk_widget_show(treewcli);
  gtk_widget_show_all(fixed);

return ;
}

void novcli(GtkWidget *widget,gpointer poniter){
 //clisele
//g_print("novo cliente print %s\n\n", lastnewcliente() );
sprintf(clisele,"%s",lastnewcliente());
//gtk_widget_set_sensitive(GTK_WIDGET(ecli), FALSE);
//gtk_widget_set_sensitive(GTK_WIDGET(scli),TRUE);
opencliente();
editcliente();
gtk_widget_set_sensitive(GTK_WIDGET(ecpfcli),TRUE);


}











void telacliente (void){
menucliente();
listadecliente();



}


