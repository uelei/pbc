#include <gtk/gtk.h>
#include <mysql/mysql.h>
#include "con.h"
#include "produtos.h"
#include "layout.h"
#include "nume.h"
#include "str_replace.h"
#include "produtodet.h"

enum {COL_IE,COL_COD,COL_BAR,COL_DESC,COL_PV,COL_QT,COL_COR,NUM_COLPRO };
char nup[2];


void apagatelaprodutos(void){
gtk_widget_destroy(GTK_WIDGET(btfechaprodutos));
gtk_widget_set_sensitive(GTK_WIDGET(botaocliente),TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(vendastotal),TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(btproduto),TRUE);
gtk_widget_destroy(GTK_WIDGET(lbuspro));
gtk_widget_destroy(GTK_WIDGET(ebuspro));
gtk_widget_destroy(GTK_WIDGET(swlpro));
gtk_widget_destroy(GTK_WIDGET(btabrepro));

gtk_widget_destroy(GTK_WIDGET(ckcod));
gtk_widget_destroy(GTK_WIDGET(ckbar));
gtk_widget_destroy(GTK_WIDGET(ckdesc));
gtk_widget_destroy(GTK_WIDGET(cklcem));

}

        

void  on_changedpro(GtkWidget *widget,gpointer ocli) 
{
  GtkTreeIter iter;
  GtkTreeModel *model;
  char *ie;


  if (gtk_tree_selection_get_selected(GTK_TREE_SELECTION(widget), &model, &iter)) {

    gtk_tree_model_get(model, &iter, COL_IE, &ie,  -1);
    gtk_widget_set_sensitive(GTK_WIDGET(btabrepro),TRUE);
    //gtk_statusbar_push(GTK_STATUSBAR(statusbar), gtk_statusbar_get_context_id(GTK_STATUSBAR(statusbar), value), value);
    //gtk_widget_set_sensitive(GTK_WIDGET(ocli), TRUE);
    
    sprintf(iesel,"%s",ie);
  //g_print(" valor = %s \n",clisel);
    //g_print(" valor = %s \n",value);
    //g_free(value);    
    g_free(ie);

  }
  else {
    gtk_widget_set_sensitive(GTK_WIDGET(btabrepro), FALSE);
   // gtk_widget_set_sensitive(GTK_WIDGET(bdelcli),FALSE);
   ie= "";

}
}














void buscapro(void){

char s[50];
MYSQL_RES *resp;
MYSQL_ROW linhas;
char sql[ 1000 ];
GtkTreeIter iter;
char slq[300];
char sqq[5];


sprintf(s,"%s", gtk_entry_get_text(GTK_ENTRY(ebuspro)));
gtk_list_store_clear(storeprodutos);
sprintf(nup,"%d",numep());
sprintf(sql,"SELECT * FROM tb_estoque WHERE");
sprintf(sqq," ");

if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(ckcod))) { 

strcat (sql,sqq);
sprintf(slq,"cod_prod LIKE '%%%s%%' AND numemp LIKE '%s' ",s,nup);
strcat(sql,slq);
sprintf(sqq," OR ");

}

if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(ckbar))) {

strcat (sql,sqq);
sprintf(slq,"numemp LIKE '%s' AND `cod_barras_prod` LIKE '%%%s%%' ",nup,s);
strcat(sql,slq);
sprintf(sqq," OR ");

}

if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(ckdesc))) {

strcat (sql,sqq);
sprintf(slq," `numemp` LIKE '%s' AND `desc_prod` LIKE '%%%s%%' ",nup,s);
strcat(sql,slq);
sprintf(sqq," OR ");

}
 
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(cklcem))) {

sprintf (sqq," LIMIT 100;"); 
}else {

sprintf (sqq,";");}
strcat(sql,sqq);

int ii=0;
char ietemp[13];

  if (mysql_query(&conexao,sql))
      g_print("Erro: %s\n",mysql_error(&conexao));
  else
    {
    resp = mysql_store_result(&conexao);//recebe a consulta
    if (resp) //se houver consulta
        {  ii=0;
          while ((linhas=mysql_fetch_row(resp)) != NULL)  //enquanto linhas for diferente de nulo faca 
              {

                   gtk_list_store_append (storeprodutos, &iter);  //pega interator do tree 

                   gtk_list_store_set (storeprodutos, &iter,
                             COL_IE, linhas[0],
                             COL_COD, linhas[2],
                             COL_BAR, linhas[3],
                             COL_DESC,linhas[4],
                             COL_QT,linhas[9],
                             COL_PV,linhas[7],
                             -1);
ii++;
sprintf(ietemp,"%s",linhas[0]);

              }
          }
          mysql_free_result(resp);//limpa a variável do resultado: resp
        }
if (ii ==1){
    sprintf(iesel,"%s",ietemp);
  gtk_widget_set_sensitive(GTK_WIDGET(btabrepro),TRUE);
}else {

//    sprintf(iesel,"%s",ietemp);
  gtk_widget_set_sensitive(GTK_WIDGET(btabrepro),FALSE);

}

}




void focusbtabrepro(GtkWidget *widget,GdkEventKey *event,gpointer *poi){
if(event->keyval == 65293){
gtk_widget_grab_focus(btabrepro);
}
else if (event->keyval == 65421){
gtk_widget_grab_focus(btabrepro);
}

}







void arvoreprodutos (void){

        storeprodutos = gtk_list_store_new(NUM_COLPRO,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,GDK_TYPE_COLOR);
        modelprodutos = GTK_TREE_MODEL(storeprodutos);
        viewprodutos = gtk_tree_view_new_with_model(GTK_TREE_MODEL( modelprodutos));

/*1 coluna */
        colpro = gtk_tree_view_column_new();
        gtk_tree_view_column_set_title(colpro, "codigo");
        renderpro = gtk_cell_renderer_text_new();
        gtk_tree_view_column_pack_start(colpro, renderpro, TRUE);
        gtk_tree_view_column_set_attributes(colpro, renderpro,"text", COL_COD,NULL);
        gtk_tree_view_column_set_sort_column_id(colpro,0);
        gtk_tree_view_append_column(GTK_TREE_VIEW(viewprodutos), colpro);

/*  2nd column */
        colpro = gtk_tree_view_column_new();
        gtk_tree_view_column_set_title(colpro, "barras");
        renderpro = gtk_cell_renderer_text_new();
        gtk_tree_view_column_pack_start(colpro, renderpro, TRUE);
        gtk_tree_view_column_set_attributes(colpro, renderpro,"text", COL_BAR,NULL);
        gtk_tree_view_column_set_sort_column_id(colpro,1);
        gtk_tree_view_append_column(GTK_TREE_VIEW(viewprodutos), colpro);



/*  3 column */

        colpro = gtk_tree_view_column_new();
        gtk_tree_view_column_set_title(colpro, "Descricao");
        renderpro = gtk_cell_renderer_text_new();
        gtk_tree_view_column_pack_start(colpro, renderpro, TRUE);
        gtk_tree_view_column_set_attributes(colpro, renderpro,"text", COL_DESC,NULL);
        gtk_tree_view_column_set_sort_column_id(colpro,2);
        gtk_tree_view_append_column(GTK_TREE_VIEW(viewprodutos), colpro);

/* 4 column*/

        colpro = gtk_tree_view_column_new();
        gtk_tree_view_column_set_title(colpro, "preço");
        renderpro = gtk_cell_renderer_text_new();
        gtk_tree_view_column_pack_start(colpro, renderpro, TRUE);
        gtk_tree_view_column_set_attributes(colpro, renderpro,"text", COL_PV,NULL);
        gtk_tree_view_column_set_sort_column_id(colpro,3);
        gtk_tree_view_append_column(GTK_TREE_VIEW(viewprodutos), colpro);


/* 5 column*/

        colpro = gtk_tree_view_column_new();
        gtk_tree_view_column_set_title(colpro, "Qtd");
        renderpro = gtk_cell_renderer_text_new();
        gtk_tree_view_column_pack_start(colpro, renderpro, TRUE);
        gtk_tree_view_column_set_attributes(colpro, renderpro,"text", COL_QT, NULL);
      //  gtk_tree_view_column_set_sort_column_id(colpro,4);
        gtk_tree_view_append_column(GTK_TREE_VIEW(viewprodutos), colpro);




//listadeprodutos(n_not_int,view);

 selectionpro = gtk_tree_view_get_selection(GTK_TREE_VIEW(viewprodutos));
 g_signal_connect(selectionpro, "changed",G_CALLBACK(on_changedpro),NULL);



gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(swlpro),viewprodutos);
gtk_widget_show_all(swlpro);


}



void telaprodutos(void){

//botao fechar 
btfechaprodutos = gtk_tool_button_new_from_stock(GTK_STOCK_CLOSE);
gtk_fixed_put(GTK_FIXED(fixed),btfechaprodutos,1240,0);



//entri e label 
  lbuspro = gtk_label_new("produto :");
  
  gtk_fixed_put(GTK_FIXED(fixed),lbuspro,10,10);
  ebuspro= gtk_entry_new();
gtk_widget_set_usize (ebuspro, 550, 30);
  gtk_fixed_put(GTK_FIXED(fixed),ebuspro,80,6);




btabrepro = gtk_tool_button_new_from_stock(GTK_STOCK_OPEN);
    gtk_widget_set_sensitive(GTK_WIDGET(btabrepro), FALSE);
gtk_fixed_put(GTK_FIXED(fixed),btabrepro,650,4);


ckcod = gtk_check_button_new_with_label("Codigo");
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(ckcod), TRUE);
  GTK_WIDGET_UNSET_FLAGS(ckcod, GTK_CAN_FOCUS);
  gtk_fixed_put(GTK_FIXED(fixed),ckcod, 30, 50);


ckbar = gtk_check_button_new_with_label("Cod Barras");
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(ckbar), FALSE);
  GTK_WIDGET_UNSET_FLAGS(ckbar, GTK_CAN_FOCUS);
  gtk_fixed_put(GTK_FIXED(fixed),ckbar, 120, 50);


ckdesc = gtk_check_button_new_with_label("Descrição");
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(ckdesc), FALSE);
  GTK_WIDGET_UNSET_FLAGS(ckdesc, GTK_CAN_FOCUS);
  gtk_fixed_put(GTK_FIXED(fixed),ckdesc, 240, 50);

cklcem = gtk_check_button_new_with_label("Lim 100");
  gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(cklcem), TRUE);
  GTK_WIDGET_UNSET_FLAGS(cklcem, GTK_CAN_FOCUS);
  gtk_fixed_put(GTK_FIXED(fixed),cklcem, 360, 50);





swlpro = gtk_scrolled_window_new(NULL,NULL);
gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW(swlpro),GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW(swlpro),GTK_SHADOW_ETCHED_IN);
//gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(svendas),ldesprod);
gtk_widget_set_usize (swlpro, 800, 480);
gtk_fixed_put(GTK_FIXED(fixed),swlpro,50,140);

arvoreprodutos();

g_signal_connect_swapped(G_OBJECT(btfechaprodutos),"clicked",G_CALLBACK(apagatelaprodutos),NULL);

g_signal_connect_swapped(G_OBJECT(ebuspro), "key-release-event",G_CALLBACK(focusbtabrepro),NULL);

g_signal_connect_swapped(G_OBJECT(ebuspro),"changed",G_CALLBACK(buscapro),NULL);
 g_signal_connect(ckcod, "clicked",G_CALLBACK(buscapro), NULL);
 g_signal_connect(ckbar, "clicked",G_CALLBACK(buscapro), NULL);
 g_signal_connect(ckdesc, "clicked",G_CALLBACK(buscapro), NULL);

g_signal_connect_swapped(G_OBJECT(btabrepro),"clicked",G_CALLBACK(telaprodet),NULL);
 g_signal_connect(G_OBJECT(viewprodutos),"row-activated",G_CALLBACK(telaprodet),NULL);




sprintf(nup,"%d",numep());


gtk_widget_set_sensitive(GTK_WIDGET(botaocliente),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(vendastotal),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(btproduto),FALSE);

gtk_widget_grab_focus(ebuspro);
  gtk_widget_show_all(window);

}
