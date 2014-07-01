#include <mysql/mysql.h>
#include <gtk/gtk.h>
#include "layout.h"
#include "lay_lista_cli.h"
#include "lay_det_cli.h"
#include "con.h"
#include "datausuario.h"
#include "nume.h"

//enum{ CODCLI_COL,NOMECLI_COL,CPFCLI_COL,CIDCLI_COL,NUM_COLS};

enum
{
  COL_DATA,COL_DESCVE,COL_VALORI,COL_VALORR,COL_DATAEFE,COL_PAR,COL_ICO,COL_COR,NUM_COL
};



int scliente(GtkWidget *entri, gpointer treecli){
  gchar *s;

  s = (gchar*)gtk_entry_get_text(GTK_ENTRY(entri));

  gtk_tree_store_clear(treecli);

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

                   gtk_tree_store_append (treecli, &iter, NULL);  //pega interator do tree 

                   gtk_tree_store_set (treecli, &iter,
                             CODCLI_COL, linhas[0],
                             NOMECLI_COL, linhas[1],
                             CPFCLI_COL, linhas[10],
                             CIDCLI_COL,linhas[5],
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
                   gtk_tree_store_append (treecli, &iter, NULL);  //pega interator do tree 
                   gtk_tree_store_set (treecli, &iter,
                             CODCLI_COL, linhas[0],
                             NOMECLI_COL, linhas[1],
                             CPFCLI_COL, linhas[10],
                             CIDCLI_COL,linhas[5],
                             -1);
              }
          }
          mysql_free_result(resp);//limpa a variável do resultado: resp
        }

return 0;

}



int updatecliente(char dcampo[], char valorup[],char codclic[]){
//  MYSQL_RES *resp;
//  MYSQL_ROW linhas;
char sql[1000];

sprintf(sql,"UPDATE tb_clientes SET %s ='%s' WHERE cod_cliente='%s';",dcampo,valorup,codclic);
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


char* lastnewcliente(void){
char sql[1000];
char* s;
MYSQL_RES *resp;
MYSQL_ROW linhas;
//int lastid;

sprintf(sql,"INSERT INTO `tb_clientes` (`cod_cliente` ,`nome_cliente` ,`ed_cliente` ,`num_end_cliente` ,`bairro_cliente` ,`cidade_cliente` ,`uf_cliente` ,`tel1_cliente` ,`tel2_cliente` ,`dtnasc_cliente` ,`cpf_cliente` ,`rg_cliente` ,`email_cliente` ,`obs_cliente`)VALUES (NULL , '','', '', '', '', '', '', '', '', '111.111.111-11', '', '', '');");
mysql_query(&conexao,sql);
  ///g_print("Last inserted record has id %d\n", (int)mysql_insert_id(&conexao));
sprintf(sql,"SELECT * FROM tb_clientes WHERE cpf_cliente LIKE '111.111.111-11';");
  if (mysql_query(&conexao,sql))
      g_print("Erro: %s\n",mysql_error(&conexao));
  else
    {

    resp = mysql_store_result(&conexao);//recebe a consulta
    if (resp) //se houver consulta
        {
              while ((linhas=mysql_fetch_row(resp)) != NULL)  //enquanto linhas for diferente de nulo faca 
              {
                    s = linhas[0];
              }
          }
          mysql_free_result(resp);//limpa a variável do resultado: resp
        }
return (s);
}


char* dadoscliente (char codclid[], int campo){
//g_print("codclid e campo = %s\n%d\n",codclid,campo);

   MYSQL_RES *resp;
   MYSQL_ROW linhas;

char sql[1000];
char* tex ="";

sprintf(sql,"SELECT * FROM tb_clientes WHERE cod_cliente LIKE '%s';",codclid);
  if (mysql_query(&conexao,sql))
      g_print("Erro: %s\n",mysql_error(&conexao));
  else
    {
    resp = mysql_store_result(&conexao);//recebe a consulta
    if (resp) //se houver consulta
        {
              while ((linhas=mysql_fetch_row(resp)) != NULL)  //enquanto linhas for diferente de nulo faca 
              {
                    tex = linhas[campo];
              }
          }
          mysql_free_result(resp);//limpa a variável do resultado: resp
        }
return (tex);
}


int apagacli(char codcli[]){

char sql[1000];
g_print("cliente numeto  %s  apagado .\n",codcli );
sprintf(sql,"DELETE FROM tb_clientes WHERE `cod_cliente` LIKE '%s' ",codcli);
//g_print("texto passado = %s\n%d\n",codclic,campo);
//g_print("%s\n",sql);
  if (mysql_query(&conexao,sql))
      g_print("Erro: %s\n",mysql_error(&conexao));
  else
    { 
sprintf(sql," ");
        }

//g_print("todos os pagamentos do cliente  %s  apagados .\n",codcli );
//sprintf(sql,"DELETE FROM tb_cheques WHERE `idcliente` LIKE '%s' ",codcli);
//g_print("texto passado = %s\n%d\n",codclic,campo);
//g_print("%s\n",sql);
 // if (mysql_query(&conexao,sql)){
  //    g_print("Erro: %s\n",mysql_error(&conexao));
 // else
   // { 
//sprintf(sql," ");
  //      }
return 0;
}







/////////////////////////////////////////////////////////////////////////////////////
GtkListStore * create_liststore(char clicod[])
{
GtkListStore  *store;
GtkTreeIter    iter;
GdkPixbuf     *icon;
GError        *error = NULL;
gchar *s;
GdkColor color;
//gboolean success;
s = (gchar*)clicod;

//gtk_tree_store_clear(&store);
store = gtk_list_store_new(NUM_COL,G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,GDK_TYPE_PIXBUF,GDK_TYPE_COLOR);

MYSQL_RES *resp;
MYSQL_ROW linhas;

char sql[ 1000 ];

sprintf(sql,"SELECT * FROM tb_payment WHERE cod_cliente LIKE '%%%s%%' AND numemp LIKE '%%%d%%' ; ",s,numep());


  if (mysql_query(&conexao,sql))
      g_print("Erro: %s\n",mysql_error(&conexao));
  else
    {
    resp = mysql_store_result(&conexao);//recebe a consulta
    if (resp) //se houver consulta
        {
          while ((linhas=mysql_fetch_row(resp)) != NULL)  //enquanto linhas for diferente de nulo faca 
              {
                //int ano,mes,dia,hora,min,seg;

                int codmov;
                //codmov = linhas[11];
                sscanf(linhas[11],"%d",&codmov);
                char data[20],datae[20];
                int ano,mes,dia,hora,min,seg;

                sscanf(linhas[8],"%d-%d-%d %d:%d:%d",&ano,&mes,&dia,&hora,&min,&seg);
                sprintf(data,"%d/%d/%d",dia,mes,ano);
                sscanf(linhas[7],"%d-%d-%d %d:%d:%d",&ano,&mes,&dia,&hora,&min,&seg);
                sprintf(datae,"%d/%d/%d",dia,mes,ano);

                MYSQL_RES *respe;
                MYSQL_ROW linhase;

                char sqle[1000];
                char descmov[100];

                sprintf(sqle,"SELECT * FROM tb_cod_mov WHERE cod_mov_merc LIKE '%s';",linhas[2]);
                if (mysql_query(&conexao,sqle))
                        g_print("Erro: %s\n",mysql_error(&conexao));
                else
                        {
                                respe = mysql_store_result(&conexao);//recebe a consulta
                                if (respe) //se houver consulta
                                        {
                                                while ((linhase=mysql_fetch_row(respe)) != NULL)  //enquanto linhas for diferente de nulo faca 
                                                        {
                                                                sprintf( descmov,"%s",linhase[1]);
                                                        }
                                        }
                                mysql_free_result(respe);//limpa a variável do resultado: resp
                        }





                if(codmov == 1)
                        {
                                icon = gdk_pixbuf_new_from_file("imagens/share.png", &error);//35535,65333,15000
                                color.red = 65535;
                                color.blue = 47424;
                                color.green = 65535;
                                if (error)
                                         {
                                                 g_warning ("Could not load icon: %s\n", error->message);
                                                 g_error_free(error);
                                                 error = NULL;
                                         }
                        }
                else if (codmov == 2 )
                        {
                                icon = gdk_pixbuf_new_from_file("imagens/tick_32.png", &error);
                                color.red = 62194;
                                color.blue = 58596;
                                color.green = 65535;
                                if (error)
                                         {
                                                 g_warning ("Could not load icon: %s\n", error->message);
                                                 g_error_free(error);
                                                 error = NULL;
                                         }
                        }
                else 
                        {
                                icon = gdk_pixbuf_new_from_file("imagens/warning_32.png", &error);
                                color.red = 60762;
                                color.blue = 21242;
                                color.green = 21242;
                                if (error)
                                         {
                                                 g_warning ("Could not load icon: %s\n", error->message);
                                                 g_error_free(error);
                                                 error = NULL;
                                         }
                        } 



gtk_list_store_append(store, &iter);
gtk_list_store_set(store, &iter,COL_DATA,data,COL_DESCVE,descmov,COL_VALORI,linhas[5],COL_VALORR,linhas[10],COL_DATAEFE,datae,COL_PAR,linhas[6],COL_ICO,icon,COL_COR,&color,-1);
              }
          }
          mysql_free_result(resp);//limpa a variável do resultado: resp
        }





  return store;
}


/**************************************************************
 *
 *   create_treeview
 *
 **************************************************************/

GtkWidget *
create_treeview(char clicod[])
{
	GtkTreeModel      *model;
	GtkTreeViewColumn *col;
	GtkCellRenderer   *renderer;
	GtkWidget         *view;

	model = GTK_TREE_MODEL(create_liststore(clicod));

	view = gtk_tree_view_new_with_model(model);

	col = gtk_tree_view_column_new();
	gtk_tree_view_column_set_title(col, "Data inic");


 
	renderer = gtk_cell_renderer_text_new();
	gtk_tree_view_column_pack_start(col, renderer, TRUE);
	gtk_tree_view_column_set_attributes(col, renderer,
	                                    "text", COL_DATA,"cell-background-gdk", COL_COR,
	                                    NULL);

	gtk_tree_view_append_column(GTK_TREE_VIEW(view), col);

/*  2nd column */
///gtk_tree_view_append_column(GTK_TREE_VIEW(view), col);

	col = gtk_tree_view_column_new();
	gtk_tree_view_column_set_title(col, "descrição ");

	renderer = gtk_cell_renderer_text_new();
	gtk_tree_view_column_pack_start(col, renderer, TRUE);
	gtk_tree_view_column_set_attributes(col, renderer,
	                                    "text", COL_DESCVE,"cell-background-gdk", COL_COR,
	                                    NULL);
//  "cell-background-gdk"      GdkColor*  
//"foreground-gdk"


	gtk_tree_view_append_column(GTK_TREE_VIEW(view), col);



/*  3 column */


	col = gtk_tree_view_column_new();
	gtk_tree_view_column_set_title(col, "valor ");

	renderer = gtk_cell_renderer_text_new();
	gtk_tree_view_column_pack_start(col, renderer, TRUE);
	gtk_tree_view_column_set_attributes(col, renderer,
	                                    "text", COL_VALORI,"cell-background-gdk", COL_COR,
	                                    NULL);
//  "cell-background-gdk"      GdkColor*  
//"foreground-gdk"


	gtk_tree_view_append_column(GTK_TREE_VIEW(view), col);


/*  4nd column */
///gtk_tree_view_append_column(GTK_TREE_VIEW(view), col);

	col = gtk_tree_view_column_new();
	gtk_tree_view_column_set_title(col, "Data efetuada ");

	renderer = gtk_cell_renderer_text_new();
	gtk_tree_view_column_pack_start(col, renderer, TRUE);
	gtk_tree_view_column_set_attributes(col, renderer,
	                                    "text", COL_DATAEFE,"cell-background-gdk", COL_COR,
	                                    NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(view), col);
//  "cell-background-gdk"      GdkColor*  
//"foreground-gdk"

/*  5nd column */
///gtk_tree_view_append_column(GTK_TREE_VIEW(view), col);

	col = gtk_tree_view_column_new();
	gtk_tree_view_column_set_title(col, "valor realizado ");

	renderer = gtk_cell_renderer_text_new();
	gtk_tree_view_column_pack_start(col, renderer, TRUE);
	gtk_tree_view_column_set_attributes(col, renderer,
	                                    "text", COL_VALORR,"cell-background-gdk", COL_COR,
	                                    NULL);
//  "cell-background-gdk"      GdkColor*  
//"foreground-gdk"


	gtk_tree_view_append_column(GTK_TREE_VIEW(view), col);


/*  6nd column */
///gtk_tree_view_append_column(GTK_TREE_VIEW(view), col);

	col = gtk_tree_view_column_new();
	gtk_tree_view_column_set_title(col, "parc ");

	renderer = gtk_cell_renderer_text_new();
	gtk_tree_view_column_pack_start(col, renderer, TRUE);
	gtk_tree_view_column_set_attributes(col, renderer,
	                                    "text", COL_PAR,"cell-background-gdk", COL_COR,
	                                    NULL);
//  "cell-background-gdk"      GdkColor*  
//"foreground-gdk"


	gtk_tree_view_append_column(GTK_TREE_VIEW(view), col);

	col = gtk_tree_view_column_new();
	gtk_tree_view_column_set_title(col, "st");
	renderer = gtk_cell_renderer_pixbuf_new();
	gtk_tree_view_column_pack_start(col, renderer, FALSE);
	gtk_tree_view_column_set_attributes(col, renderer,
	                                    "pixbuf", COL_ICO,
	                                    NULL);

	gtk_tree_view_append_column(GTK_TREE_VIEW(view), col);

	return view;
}

int listpgclientecod (gpointer swp ,char clicod[]){

gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(swp),create_treeview(clicod));

return 0;

}

