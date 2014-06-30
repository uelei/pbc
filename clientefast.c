#include "clientefast.h"

GtkWidget *po;
char clisele[15];
int coddavv;

enum {COL_CODCLI,COL_NCLI,COL_CPF,NUM_COLU};

int selecli(GtkWidget *entri, gpointer treecli)
{  gchar *s;


  s = (gchar*)gtk_entry_get_text(GTK_ENTRY(entri));

  gtk_list_store_clear(listestore);

   MYSQL_RES *resp;
   MYSQL_ROW linhas;

char sql[ 1000 ];

sprintf(sql,"SELECT * FROM tb_clientes WHERE nome_cliente LIKE '%%%s%%';",s);

GtkTreeIter   iter;

  if (mysql_query(&conexao,sql))
      g_print("Erro: %s\n",mysql_error(&conexao));
  else
    {
    resp = mysql_store_result(&conexao);//recebe a consulta
    if (resp) //se houver consulta
        {
          while ((linhas=mysql_fetch_row(resp)) != NULL)  //enquanto linhas for diferente de nulo faca 
              {

                   gtk_list_store_append(listestore, &iter);  //pega interator do tree 

                   gtk_list_store_set(listestore, &iter,
                             COL_CODCLI, linhas[0],
                             COL_NCLI, linhas[1],
                             COL_CPF, linhas[10],
                             -1);

              }
          }
          mysql_free_result(resp);//limpa a variável do resultado: resp
        }

sprintf(sql,"SELECT * FROM tb_clientes WHERE cpf_cliente LIKE '%%%s%%'AND  nome_cliente NOT LIKE '%%%s%%';",s,s);
  if (mysql_query(&conexao,sql))
      g_print("Erro: %s\n",mysql_error(&conexao));
  else    {
    resp = mysql_store_result(&conexao);//recebe a consulta
    if (resp) //se houver consulta
        {
         while ((linhas=mysql_fetch_row(resp)) != NULL)  //enquanto linhas for diferente de nulo faca 
              {
                   gtk_list_store_append (listestore, &iter);  //pega interator do tree 
                   gtk_list_store_set (listestore, &iter,
                             COL_CODCLI, linhas[0],
                             COL_NCLI, linhas[1],
                             COL_CPF, linhas[10],
                             -1);
//g_print("funcao");

              }

          }
          mysql_free_result(resp);//limpa a variável do resultado: resp
        }

return 0;
}




void  on_changecli(GtkWidget *widget,gpointer ocli) 
{
  GtkTreeIter iter;
  GtkTreeModel *model;
  char *clisel;


  if (gtk_tree_selection_get_selected(GTK_TREE_SELECTION(widget), &model, &iter)) {

    gtk_tree_model_get(model, &iter, COL_CODCLI, &clisel,  -1);
   // gtk_widget_set_sensitive(GTK_WIDGET(bdelcli),TRUE);
    //gtk_statusbar_push(GTK_STATUSBAR(statusbar), gtk_statusbar_get_context_id(GTK_STATUSBAR(statusbar), value), value);
    //gtk_widget_set_sensitive(GTK_WIDGET(btdelprod), TRUE);
    //g_print(" valor = %s \n",clisel);
 
    sprintf(clisele,"%s",clisel);
  //g_print(" valor = %s \n",clisel);
    //g_print(" valor = %s \n",value);
      gtk_entry_set_text(GTK_ENTRY(po),clisele);
    //g_free(value);    
    g_free(clisel);

  }
  else {
    //gtk_widget_set_sensitive(GTK_WIDGET(btdelprod), FALSE);
   // gtk_widget_set_sensitive(GTK_WIDGET(bdelcli),FALSE);
   clisel= "";
      gtk_entry_set_text(GTK_ENTRY(po),"0");
}




}


/*struct tm *local;
time_t t;
t= time(NULL);
local=localtime(&t);
int dia,mes,ano,hora,min,seg;



dia=local->tm_mday;
mes=local->tm_mon+1;
ano=local->tm_year+1900;
hora = local->tm_hour;
min= local->tm_min;
seg=local->tm_sec;

printf("Data do Sistema: %d-%d-%d %d:%d:%d\n",ano,mes,dia,hora,min,seg); // Retorna a data
*/



/*



void fechajaneladata(GtkWidget *widget,gpointer *poi){

//GtkWidget *widget,gpointer *poi
//gtk_widget_grab_focus(GTK_WIDGET(poi));

gtk_widget_destroy(GTK_WIDGET(calendar));
gtk_widget_destroy(GTK_WIDGET(wdata));

gtk_main_quit();


}
void selecionadata(GtkWidget *widget,gpointer *entry){
gint ano,mes,dia;
char data[11];
gtk_calendar_get_date(calendar,&ano,&mes,&dia);
mes ++;
//g_print("%d/%d/%d",dia,mes,ano);
//gtk_entry_set_text
sprintf(data,"%d/%d/%d",dia,mes,ano);
gtk_entry_set_text(GTK_ENTRY(entry),data);

}
*/

void fechatelacli(void){
updatevenda();
gtk_widget_destroy(wcli);
gtk_main_quit();




}




int updatevenda(void){
//  MYSQL_RES *resp;
//  MYSQL_ROW linhas;
char sql[1000];

sprintf(sql,"UPDATE tb_dav SET cod_cli ='%s' WHERE cod_cli='%d';",clisele,coddav);
//g_print("texto passado = %s\n%d\n",codclic,campo);
g_print("%s\n\n",sql);
  if (mysql_query(&conexao,sql))
      g_print("Erro: %s\n",mysql_error(&conexao));
  else
    { 
sprintf(sql," ");

//mysql_free_result(resp);//limpa a variável do resultado: resp
        }

return 0;
}



void janelaclifast(GtkWidget *widge,gpointer *poi,int coddav){

coddavv = coddav;
gtk_init(0,0);
po = poi;
wcli  = gtk_window_new(GTK_WINDOW_POPUP);
gtk_window_set_default_size(GTK_WINDOW(wcli), 730, 550);
gtk_window_set_modal(GTK_WINDOW(wcli),TRUE);
gtk_window_set_position(GTK_WINDOW(wcli), GTK_WIN_POS_CENTER);
gtk_window_set_modal(GTK_WINDOW(wcli),TRUE);
//calendar = gtk_calendar_new();



hbox = gtk_hbox_new(TRUE,2);
lnome = gtk_label_new("nome ou cpf :");
gtk_container_add(GTK_CONTAINER(hbox),lnome);

entry = gtk_entry_new();
gtk_container_add(GTK_CONTAINER(hbox),entry);

vbox = gtk_vbox_new(TRUE, 2);

gtk_container_add(GTK_CONTAINER(vbox),hbox);


  swcli = gtk_scrolled_window_new(NULL,NULL);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW(swcli),GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
  gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW(swcli),GTK_SHADOW_ETCHED_IN);
 gtk_widget_set_usize (swcli, 700, 250);



listestore = gtk_list_store_new(NUM_COLU,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
        modelo = GTK_TREE_MODEL(listestore);
        treeview = gtk_tree_view_new_with_model(GTK_TREE_MODEL( modelo));

        colu = gtk_tree_view_column_new();
        gtk_tree_view_column_set_title(colu, "nome do cliente");
        cel = gtk_cell_renderer_text_new();
        gtk_tree_view_column_pack_start(colu,cel, TRUE);
        gtk_tree_view_column_set_attributes(colu, cel,
                                            "text", COL_NCLI,NULL);

//gtk_tree_view_column_set_sort_column_id(col,0);

        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), colu);


///gtk_tree_view_append_column(GTK_TREE_VIEW(view), col);

        colu = gtk_tree_view_column_new();
        gtk_tree_view_column_set_title(colu, "CPF");
        cel = gtk_cell_renderer_text_new();
        gtk_tree_view_column_pack_start(colu, cel, TRUE);
        gtk_tree_view_column_set_attributes(colu,cel,"text", COL_CPF,NULL);
//gtk_tree_view_column_set_sort_column_id(col,1);
        gtk_tree_view_append_column(GTK_TREE_VIEW(treeview), colu);

//  "cell-background-gdk"      GdkColor*  
//"foreground-gdk"


gtk_scrolled_window_add_with_viewport (GTK_SCROLLED_WINDOW(swcli),treeview);
gtk_container_add(GTK_CONTAINER(vbox),swcli);

//gtk_fixed_put(GTK_FIXED(fixed),swcli,10,50);
//gtk_container_add(GTK_CONTAINER(wcli), vbox);
//gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(swprod),view);
//gtk_widget_show_all(swprod);
//gtk_box_pack_start(GTK_BOX(vbox), settings, TRUE, TRUE, 0);

gtk_container_add(GTK_CONTAINER(wcli), vbox);
//g_signal_connect_swapped(G_OBJECT(wdata), "destroy",G_CALLBACK(gtk_main_quit), NULL);
//g_signal_connect(G_OBJECT(calendar),"day-selected-double-click",G_CALLBACK(fechajaneladata),poi);
g_signal_connect(G_OBJECT(entry),"changed",G_CALLBACK(selecli),treeview);
g_signal_connect(G_OBJECT(treeview),"row-activated",G_CALLBACK(fechatelacli),NULL);

 slee = gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview));
  g_signal_connect(slee, "changed",G_CALLBACK(on_changecli),poi);


g_signal_connect_swapped(G_OBJECT(wcli), "destroy",G_CALLBACK(gtk_main_quit), NULL);
gtk_widget_show_all(wcli);
gtk_widget_grab_focus(entry);
gtk_main();

}
