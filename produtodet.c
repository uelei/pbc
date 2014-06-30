#include <gtk/gtk.h>
#include <mysql/mysql.h>
#include "con.h"
#include "produtos.h"
#include "layout.h"
#include "nume.h"
#include "str_replace.h"
#include "produtodet.h"



enum {COL_IGRA,COL_DEGRA,COL_QTGRA,COL_AGRA,NUM_COLGRA };

int ifor=0;

gint codfor;



char gradsel[13];




void apagadetpro(void){


gtk_widget_destroy(GTK_WIDGET(btfechadetpro));
gtk_widget_set_sensitive(GTK_WIDGET(botaocliente),TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(vendastotal),TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(btproduto),TRUE);
gtk_widget_destroy(GTK_WIDGET(btbackpro));

gtk_widget_destroy(GTK_WIDGET(swgrapro));
gtk_widget_destroy(GTK_WIDGET(swmovpro));
gtk_widget_destroy(GTK_WIDGET(lcodpro));
gtk_widget_destroy(GTK_WIDGET(ecodpro));
gtk_widget_destroy(GTK_WIDGET(lie));
gtk_widget_destroy(GTK_WIDGET(lcodbar));
gtk_widget_destroy(GTK_WIDGET(ecodbar));
gtk_widget_destroy(GTK_WIDGET(ldescpro));
gtk_widget_destroy(GTK_WIDGET(edescpro));

gtk_widget_destroy(GTK_WIDGET(lunpro));
gtk_widget_destroy(GTK_WIDGET(eunpro));

gtk_widget_destroy(GTK_WIDGET(lpvpro));
gtk_widget_destroy(GTK_WIDGET(epvpro));
gtk_widget_destroy(GTK_WIDGET(lpcpro));
gtk_widget_destroy(GTK_WIDGET(epcpro));

gtk_widget_destroy(GTK_WIDGET(lqfazpro));
gtk_widget_destroy(GTK_WIDGET(lqminpro));
gtk_widget_destroy(GTK_WIDGET(lqtdpro));
gtk_widget_destroy(GTK_WIDGET(eqfazpro));
gtk_widget_destroy(GTK_WIDGET(eqminpro));
gtk_widget_destroy(GTK_WIDGET(eqtdpro));

gtk_widget_destroy(GTK_WIDGET(lforpro));
gtk_widget_destroy(GTK_WIDGET(cbforpro));
gtk_widget_destroy(GTK_WIDGET(llevelpro));
gtk_widget_destroy(GTK_WIDGET(pblevelpro));

gtk_widget_destroy(GTK_WIDGET(lgrupro));
gtk_widget_destroy(GTK_WIDGET(egrupro));
gtk_widget_destroy(GTK_WIDGET(lqtdgra));
gtk_widget_destroy(GTK_WIDGET(ldescgra));
gtk_widget_destroy(GTK_WIDGET(eqtdgra));
gtk_widget_destroy(GTK_WIDGET(edescgra));

gtk_widget_destroy(GTK_WIDGET(btgranew));
gtk_widget_destroy(GTK_WIDGET(btgraedt));
gtk_widget_destroy(GTK_WIDGET(btgrasal));
gtk_widget_destroy(GTK_WIDGET(ligrad));

gtk_widget_destroy(GTK_WIDGET(enivel));

gtk_widget_destroy(GTK_WIDGET(btsalvapro));
gtk_widget_destroy(GTK_WIDGET(btedipro));



}

void backpro(void){

apagadetpro();


telaprodutos();



}


void notedipro(void){



gtk_widget_set_sensitive(GTK_WIDGET(lcodpro),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(ecodpro),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(lie),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(lcodbar),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(ecodbar),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(ldescpro),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(edescpro),FALSE);

gtk_widget_set_sensitive(GTK_WIDGET(lunpro),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(eunpro),FALSE);

gtk_widget_set_sensitive(GTK_WIDGET(lpvpro),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(epvpro),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(lpcpro),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(epcpro),FALSE);

gtk_widget_set_sensitive(GTK_WIDGET(lqfazpro),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(lqminpro),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(lqtdpro),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(eqfazpro),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(eqminpro),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(eqtdpro),FALSE);

gtk_widget_set_sensitive(GTK_WIDGET(lforpro),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(cbforpro),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(llevelpro),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(pblevelpro),FALSE);

gtk_widget_set_sensitive(GTK_WIDGET(lgrupro),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(egrupro),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(lqtdgra),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(ldescgra),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(eqtdgra),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(edescgra),FALSE);

gtk_widget_set_sensitive(GTK_WIDGET(btgranew),TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(btgraedt),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(btgrasal),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(ligrad),FALSE);

gtk_widget_set_sensitive(GTK_WIDGET(enivel),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(btsalvapro),FALSE);




}


void editpro (void){





gtk_widget_set_sensitive(GTK_WIDGET(lcodpro),TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(ecodpro),TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(lie),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(lcodbar),TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(ecodbar),TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(ldescpro),TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(edescpro),TRUE);

gtk_widget_set_sensitive(GTK_WIDGET(lunpro),TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(eunpro),TRUE);

gtk_widget_set_sensitive(GTK_WIDGET(lpvpro),TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(epvpro),TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(lpcpro),TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(epcpro),TRUE);

gtk_widget_set_sensitive(GTK_WIDGET(lqfazpro),TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(lqminpro),TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(lqtdpro),TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(eqfazpro),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(eqminpro),TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(eqtdpro),TRUE);

gtk_widget_set_sensitive(GTK_WIDGET(lforpro),TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(cbforpro),TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(llevelpro),TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(pblevelpro),TRUE);

gtk_widget_set_sensitive(GTK_WIDGET(lgrupro),TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(egrupro),FALSE);
//gtk_widget_set_sensitive(GTK_WIDGET(lqtdgra),TRUE);
//gtk_widget_set_sensitive(GTK_WIDGET(ldescgra),TRUE);
//gtk_widget_set_sensitive(GTK_WIDGET(eqtdgra),TRUE);
//gtk_widget_set_sensitive(GTK_WIDGET(edescgra),TRUE);

//gtk_widget_set_sensitive(GTK_WIDGET(btgranew),TRUE);
//gtk_widget_set_sensitive(GTK_WIDGET(btgraedt),TRUE);
//gtk_widget_set_sensitive(GTK_WIDGET(btgrasal),TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(btedipro),FALSE);



gtk_widget_set_sensitive(GTK_WIDGET(enivel),TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(btsalvapro),TRUE);









}




void listagrade (void){




MYSQL_RES *resp;
MYSQL_ROW linhas;
GtkTreeIter iter;


char s[10];
char sql[ 1000 ];
char nuu[5];

sprintf(s,"%s", gtk_label_get_text(GTK_LABEL(lie)));
gtk_list_store_clear(storegrad);

sprintf(nuu,"%d",numep());

sprintf(sql,"SELECT * FROM tb_grad WHERE iestoque LIKE '%s' AND numemp LIKE '%s' ;",s,nuu);



///enum {COL_IGRA,COL_DEGRA,COL_QTGRA,NUM_COLGRA };

  if (mysql_query(&conexao,sql))
      g_print("Erro: %s\n",mysql_error(&conexao));
  else
    {
    resp = mysql_store_result(&conexao);//recebe a consulta
    if (resp) //se houver consulta
        {
          while ((linhas=mysql_fetch_row(resp)) != NULL)  //enquanto linhas for diferente de nulo faca 
              {

                   gtk_list_store_append (storegrad, &iter);  //pega interator do tree 

                   gtk_list_store_set (storegrad, &iter,
                             COL_IGRA, linhas[0],
                             COL_DEGRA, linhas[4],
                             COL_QTGRA, linhas[3],
                                COL_AGRA,linhas[6],
                             -1);

              }
          }
          mysql_free_result(resp);//limpa a variável do resultado: resp
        }














}



















void  on_changedgrade(GtkWidget *widget,gpointer ocli) 
{
  GtkTreeIter iter;
  GtkTreeModel *model;
  char *grad,*descgrad,*qtdgradd;


  if (gtk_tree_selection_get_selected(GTK_TREE_SELECTION(widget), &model, &iter)) {

    gtk_tree_model_get(model, &iter, COL_IGRA, &grad,COL_DEGRA,&descgrad,COL_QTGRA,&qtdgradd,  -1);
    gtk_widget_set_sensitive(GTK_WIDGET(btgraedt),TRUE);
    //gtk_statusbar_push(GTK_STATUSBAR(statusbar), gtk_statusbar_get_context_id(GTK_STATUSBAR(statusbar), value), value);
    //gtk_widget_set_sensitive(GTK_WIDGET(ocli), TRUE);
    
gtk_label_set_text(GTK_LABEL(ligrad),grad);
gtk_entry_set_text(GTK_ENTRY(edescgra),descgrad);
gtk_entry_set_text(GTK_ENTRY(eqtdgra),qtdgradd);


    sprintf(gradsel,"%s",grad);
  //g_print(" valor = %s \n",clisel);
    //g_print(" valor = %s \n",value);
    //g_free(value);    
    g_free(grad);

  }
  else {
    gtk_widget_set_sensitive(GTK_WIDGET(btgraedt), FALSE);
   // gtk_widget_set_sensitive(GTK_WIDGET(bdelcli),FALSE);
   grad = " ";
gtk_label_set_text(GTK_LABEL(ligrad),"igrad");
gtk_entry_set_text(GTK_ENTRY(edescgra),"");
gtk_entry_set_text(GTK_ENTRY(eqtdgra),"");




}
}


















void novograd (void){




MYSQL_RES *resp;
MYSQL_ROW linhas;
GtkTreeIter iter;
int i ;

char s[10];
char sql[ 1000 ];
char nuu[5];
char codapco[6];

sprintf(s,"%s", gtk_label_get_text(GTK_LABEL(lie)));
sprintf(codapco,"%s",gtk_entry_get_text(GTK_ENTRY(ecodpro)));


sprintf(nuu,"%d",numep());


sprintf(sql," INSERT INTO `tb_grad` (`igrad` ,`iestoque` ,`codprod` ,`qta_grade` ,`des_grade` ,`numemp`,`ativo`) VALUES (NULL , '%s', '%s', '0', 'descricaodagrade', '%s' ,'1');",s,codapco,nuu);

if (mysql_query(&conexao,sql))
        g_print("Erro: %s\n",mysql_error(&conexao));
else
        {
        //printf("Last inserted record has id %d\n", (int)mysql_insert_id(&conexao));
        i =(int)mysql_insert_id(&conexao);
        //g_print("DAV num= %d criado \n",i);
        }
char is[15];
sprintf(is,"%d",i);
gtk_label_set_text(GTK_LABEL(ligrad), is);

gtk_widget_set_sensitive(GTK_WIDGET(edescgra),TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(eqtdgra),TRUE);
gtk_entry_set_text(GTK_ENTRY(edescgra),"");
gtk_entry_set_text(GTK_ENTRY(eqtdgra),"0");



gtk_widget_set_sensitive(GTK_WIDGET(btgraedt),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(btgrasal),TRUE);
gtk_widget_grab_focus(GTK_WIDGET(edescgra));

}











void salvagra(void){

MYSQL_RES *resp;
MYSQL_ROW linhas;
GtkTreeIter iter;
int i ;

char s[10];
char sql[ 1000 ];
char nuu[5];
char qtdgrad[6];
char descgrad[100];

sprintf(s,"%s", gtk_label_get_text(GTK_LABEL(ligrad)));
sprintf(qtdgrad,"%s",gtk_entry_get_text(GTK_ENTRY(eqtdgra)));
sprintf(descgrad,"%s",gtk_entry_get_text(GTK_ENTRY(edescgra)));



sprintf(sql," UPDATE `tb_grad` SET qta_grade = '%s' , des_grade ='%s' WHERE igrad ='%s'    ;",qtdgrad,descgrad,s);

if (mysql_query(&conexao,sql))
        g_print("Erro: %s\n",mysql_error(&conexao));
else
        {

listagrade();


gtk_widget_set_sensitive(GTK_WIDGET(edescgra),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(eqtdgra),FALSE);

gtk_widget_set_sensitive(GTK_WIDGET(btgraedt),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(btgrasal),FALSE);

gtk_entry_set_text(GTK_ENTRY(edescgra),"");
gtk_entry_set_text(GTK_ENTRY(eqtdgra),"0");
gtk_label_set_text(GTK_LABEL(ligrad),"igrad");




        }



}




















void editgrad(void){





gtk_widget_set_sensitive(GTK_WIDGET(edescgra),TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(eqtdgra),TRUE);




gtk_widget_set_sensitive(GTK_WIDGET(btgraedt),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(btgrasal),TRUE);
gtk_widget_grab_focus(GTK_WIDGET(edescgra));









}




















void criaarvoreelistagrade (void){
//enum {COL_IGRA,COL_DEGRA,COL_QTGRA,NUM_COLGRA };
        storegrad = gtk_list_store_new(NUM_COLGRA,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
        modelgrad = GTK_TREE_MODEL(storegrad);
        viewgrad = gtk_tree_view_new_with_model(GTK_TREE_MODEL( modelgrad));

/*1 coluna */
        colgrad = gtk_tree_view_column_new();
        gtk_tree_view_column_set_title(colgrad, "Descrição");
        rendergrad = gtk_cell_renderer_text_new();
        gtk_tree_view_column_pack_start(colgrad, rendergrad, TRUE);
        gtk_tree_view_column_set_attributes(colgrad, rendergrad,"text", COL_DEGRA,NULL);
        gtk_tree_view_column_set_sort_column_id(colgrad,0);
gtk_cell_renderer_set_fixed_size(rendergrad,180,20);
        gtk_tree_view_append_column(GTK_TREE_VIEW(viewgrad), colgrad);

/*  2nd column */
        colgrad = gtk_tree_view_column_new();
        gtk_tree_view_column_set_title(colgrad, "Qtd");
        rendergrad = gtk_cell_renderer_text_new();
        gtk_tree_view_column_pack_start(colgrad, rendergrad, TRUE);
        gtk_tree_view_column_set_attributes(colgrad, rendergrad,"text", COL_QTGRA,NULL);
        gtk_tree_view_column_set_sort_column_id(colgrad,1);
gtk_cell_renderer_set_fixed_size(rendergrad,100,20);
        gtk_tree_view_append_column(GTK_TREE_VIEW(viewgrad), colgrad);

/*  3 column */
        colgrad = gtk_tree_view_column_new();
        gtk_tree_view_column_set_title(colgrad, "A");
        rendergrad = gtk_cell_renderer_text_new();
        gtk_tree_view_column_pack_start(colgrad, rendergrad, TRUE);
        gtk_tree_view_column_set_attributes(colgrad, rendergrad,"text", COL_AGRA,NULL);
        gtk_tree_view_column_set_sort_column_id(colgrad,3);




        gtk_tree_view_append_column(GTK_TREE_VIEW(viewgrad), colgrad);




//listadeprodutos(n_not_int,view);

 selectiongrad = gtk_tree_view_get_selection(GTK_TREE_VIEW(viewgrad));
 g_signal_connect(selectiongrad, "changed",G_CALLBACK(on_changedgrade),NULL);


listagrade();


gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(swgrapro),viewgrad);
gtk_widget_show_all(swgrapro);


}




void listfor(void){

char s[10];
char sql[ 1000 ];
char nuu[5];
char codfor[13];
sprintf(s,"%s", gtk_label_get_text(GTK_LABEL(lie)));
sprintf(nuu,"%d",numep());
char tfor[61];

MYSQL_RES *respfor;
MYSQL_ROW linhasfor;

//sprintf(sql,"SELECT * FROM tb_forn WHERE cod_forn LIKE '%s' ;",codfor);
sprintf(sql,"SELECT * FROM tb_forn ;");

///enum {COL_IGRA,COL_DEGRA,COL_QTGRA,NUM_COLGRA };

  if (mysql_query(&conexao,sql))
      g_print("Erro: %s\n",mysql_error(&conexao));
  else
    {
    respfor = mysql_store_result(&conexao);//recebe a consulta
    if (respfor) //se houver consulta
        {ifor=0;
          while ((linhasfor=mysql_fetch_row(respfor)) != NULL)  //enquanto linhas for diferente de nulo faca 
              {
sprintf(tfor,"%s",linhasfor[1]);
gtk_combo_box_append_text(GTK_COMBO_BOX(cbforpro),tfor); 
ifor++;

              }
          }
          mysql_free_result(respfor);//limpa a variável do resultado: resp
        }






}








void produtodados (void){


MYSQL_RES *resp;
MYSQL_ROW linhas;

char s[10];
char sql[ 1000 ];
char nuu[5];
double nivv;
int niv;



sprintf(s,"%s", gtk_label_get_text(GTK_LABEL(lie)));
gtk_list_store_clear(storegrad);
sprintf(nuu,"%d",numep());



sprintf(sql,"SELECT * FROM tb_estoque WHERE ie LIKE '%s' AND numemp LIKE '%s' ;",s,nuu);



///enum {COL_IGRA,COL_DEGRA,COL_QTGRA,NUM_COLGRA };

  if (mysql_query(&conexao,sql))
      g_print("Erro: %s\n",mysql_error(&conexao));
  else
    {
    resp = mysql_store_result(&conexao);//recebe a consulta
    if (resp) //se houver consulta
        {
          while ((linhas=mysql_fetch_row(resp)) != NULL)  //enquanto linhas for diferente de nulo faca 
              {
gtk_entry_set_text(GTK_ENTRY(ecodpro),linhas[2]);
gtk_entry_set_text(GTK_ENTRY(ecodbar),linhas[3]);
gtk_entry_set_text(GTK_ENTRY(edescpro),linhas[4]);
gtk_entry_set_text(GTK_ENTRY(epvpro),linhas[7]);
gtk_entry_set_text(GTK_ENTRY(epcpro),linhas[8]);
gtk_entry_set_text(GTK_ENTRY(eunpro),linhas[6]);
gtk_entry_set_text(GTK_ENTRY(eqtdpro),linhas[9]);
gtk_entry_set_text(GTK_ENTRY(eqfazpro),linhas[10]);
gtk_entry_set_text(GTK_ENTRY(eqminpro),linhas[11]);
gtk_entry_set_text(GTK_ENTRY(egrupro),linhas[13]);
gtk_entry_set_text(GTK_ENTRY(enivel),linhas[12]);
sscanf(linhas[12],"%d",&niv);
nivv = niv/100;
gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(pblevelpro),nivv); 
//sprintf(codfor,"%s",linhas[5]);
sscanf(linhas[5],"%d",&codfor);

codfor--;

gtk_combo_box_set_active(GTK_COMBO_BOX(cbforpro),codfor);

g_print("for %d\n",codfor);




              }
          }
          mysql_free_result(resp);//limpa a variável do resultado: resp
        }







}
















void telaprodet (void){
apagatelaprodutos();


btfechadetpro = gtk_tool_button_new_from_stock(GTK_STOCK_CLOSE);
gtk_fixed_put(GTK_FIXED(fixed),btfechadetpro,1240,0);


btbackpro = gtk_tool_button_new_from_stock(GTK_STOCK_GO_BACK);
gtk_fixed_put(GTK_FIXED(fixed),btbackpro,1200,0);



swmovpro = gtk_scrolled_window_new(NULL,NULL);
gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW(swmovpro),GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW(swmovpro),GTK_SHADOW_ETCHED_IN);
//gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(svendas),ldesprod);
gtk_widget_set_usize (swmovpro, 850, 350);
gtk_fixed_put(GTK_FIXED(fixed),swmovpro,30,300);


swgrapro = gtk_scrolled_window_new(NULL,NULL);
gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW(swgrapro),GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW(swgrapro),GTK_SHADOW_ETCHED_IN);
//gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(svendas),ldesprod);
gtk_widget_set_usize (swgrapro, 320, 480);
gtk_fixed_put(GTK_FIXED(fixed),swgrapro,920,170);


lie = gtk_label_new(" IE numero ");
gtk_label_set_text(GTK_LABEL(lie),iesel);

gtk_fixed_put(GTK_FIXED(fixed),lie,200,03);


lcodpro = gtk_label_new("Codigo :");
gtk_fixed_put(GTK_FIXED(fixed),lcodpro,13,20);


const GdkColor RED_COLOR = { 0,0, 65535, 0 };
ecodpro = gtk_entry_new();
  
gtk_widget_set_size_request(GTK_WIDGET(ecodpro),120,50);
PangoFontDescription *font_desc;
font_desc = pango_font_description_from_string ("Serif Bold 22");
gtk_widget_modify_font (ecodpro, font_desc);
gtk_widget_modify_text(ecodpro, GTK_STATE_NORMAL, &RED_COLOR);
gtk_fixed_put(GTK_FIXED(fixed),ecodpro,73,05);




lcodbar = gtk_label_new("cod barras :");
gtk_fixed_put(GTK_FIXED(fixed),lcodbar,250,18);

ecodbar = gtk_entry_new();
font_desc = pango_font_description_from_string ("Serif Bold 16");
gtk_widget_modify_font (ecodbar, font_desc);
gtk_widget_set_size_request(GTK_WIDGET(ecodbar),210,35);
gtk_fixed_put(GTK_FIXED(fixed),ecodbar,335,10);




btedipro = gtk_tool_button_new_from_stock(GTK_STOCK_EDIT);
gtk_fixed_put(GTK_FIXED(fixed),btedipro,600,10);

btsalvapro = gtk_tool_button_new_from_stock(GTK_STOCK_SAVE);
gtk_fixed_put(GTK_FIXED(fixed),btsalvapro,650,10);





ldescpro = gtk_label_new("Descrição :");
gtk_fixed_put(GTK_FIXED(fixed),ldescpro,10,72);

edescpro = gtk_entry_new();
font_desc = pango_font_description_from_string ("Serif Bold 14");
gtk_widget_modify_font (edescpro, font_desc);
gtk_widget_set_size_request(GTK_WIDGET(edescpro),790,35);
gtk_fixed_put(GTK_FIXED(fixed),edescpro,100,65);


const GdkColor ED_COLOR = { 0,65535,0, 0 };

lpvpro = gtk_label_new("Preço :");
gtk_fixed_put(GTK_FIXED(fixed),lpvpro,10,120);

epvpro = gtk_entry_new();
font_desc = pango_font_description_from_string ("Serif Bold 16");
gtk_widget_modify_font (epvpro, font_desc);
gtk_widget_set_size_request(GTK_WIDGET(epvpro),155,35);
gtk_widget_modify_text(epvpro, GTK_STATE_NORMAL, &ED_COLOR);
gtk_fixed_put(GTK_FIXED(fixed),epvpro,70,110);




lpcpro = gtk_label_new("Custo :");
gtk_fixed_put(GTK_FIXED(fixed),lpcpro,230,120);

epcpro = gtk_entry_new();
font_desc = pango_font_description_from_string ("Serif Bold 16");
gtk_widget_modify_font (epcpro, font_desc);
gtk_widget_set_size_request(GTK_WIDGET(epcpro),155,35);
gtk_widget_modify_text(epcpro, GTK_STATE_NORMAL, &ED_COLOR);
gtk_fixed_put(GTK_FIXED(fixed),epcpro,290,110);



lunpro = gtk_label_new("Und :");
gtk_fixed_put(GTK_FIXED(fixed),lunpro,10,160);

eunpro = gtk_entry_new();
font_desc = pango_font_description_from_string ("Serif Bold 14");
gtk_widget_modify_font (eunpro, font_desc);
gtk_widget_set_size_request(GTK_WIDGET(eunpro),55,30);
gtk_fixed_put(GTK_FIXED(fixed),eunpro,60,155);

lqtdpro = gtk_label_new("Qtd :");
gtk_fixed_put(GTK_FIXED(fixed),lqtdpro,130,160);

eqtdpro = gtk_entry_new();
font_desc = pango_font_description_from_string ("Serif Bold 14");
gtk_widget_modify_font (eqtdpro, font_desc);
gtk_widget_set_size_request(GTK_WIDGET(eqtdpro),125,30);
gtk_fixed_put(GTK_FIXED(fixed),eqtdpro,170,155);



lqfazpro = gtk_label_new("Q Faz :");
gtk_fixed_put(GTK_FIXED(fixed),lqfazpro,310,160);

eqfazpro = gtk_entry_new();
font_desc = pango_font_description_from_string ("Serif Bold 14");
gtk_widget_modify_font (eqfazpro, font_desc);
gtk_widget_set_size_request(GTK_WIDGET(eqfazpro),125,30);
gtk_fixed_put(GTK_FIXED(fixed),eqfazpro,360,155);



lqminpro = gtk_label_new("Q Min :");
gtk_fixed_put(GTK_FIXED(fixed),lqminpro,500,160);

eqminpro = gtk_entry_new();
font_desc = pango_font_description_from_string ("Serif Bold 14");
gtk_widget_modify_font (eqminpro, font_desc);
gtk_widget_set_size_request(GTK_WIDGET(eqminpro),125,30);
gtk_fixed_put(GTK_FIXED(fixed),eqminpro,550,155);



lforpro = gtk_label_new("Forneçedor :");
gtk_fixed_put(GTK_FIXED(fixed),lforpro,10,205);


cbforpro = gtk_combo_box_new_text();
font_desc = pango_font_description_from_string ("Serif Bold 14");
gtk_widget_modify_font (cbforpro, font_desc);
gtk_widget_set_size_request(GTK_WIDGET(cbforpro),425,30);
gtk_fixed_put(GTK_FIXED(fixed),cbforpro,100,200);

llevelpro = gtk_label_new("ok :");
gtk_fixed_put(GTK_FIXED(fixed),llevelpro,550,205);

pblevelpro = gtk_progress_bar_new();
gtk_widget_set_size_request(GTK_WIDGET(pblevelpro),225,30);
gtk_fixed_put(GTK_FIXED(fixed),pblevelpro,590,200);


enivel =gtk_entry_new();
//font_desc = pango_font_description_from_string ("Serif Bold 14");
//gtk_widget_modify_font (enivel, font_desc);
gtk_widget_set_size_request(GTK_WIDGET(enivel),45,30);
gtk_fixed_put(GTK_FIXED(fixed),enivel,820,200);



lgrupro = gtk_label_new("grupo :");
gtk_fixed_put(GTK_FIXED(fixed),lgrupro,10,250);

egrupro = gtk_entry_new();
font_desc = pango_font_description_from_string ("Serif Bold 14");
gtk_widget_modify_font (egrupro, font_desc);
gtk_widget_set_size_request(GTK_WIDGET(egrupro),525,30);
gtk_fixed_put(GTK_FIXED(fixed),egrupro,80,245);


//*edescgra,*eqtsgra;


ligrad = gtk_label_new("igrad");
gtk_fixed_put(GTK_FIXED(fixed),ligrad,930,140);

ldescgra = gtk_label_new("Grade :");
gtk_fixed_put(GTK_FIXED(fixed),ldescgra,920,105);

edescgra = gtk_entry_new();
font_desc = pango_font_description_from_string ("Serif Bold 14");
gtk_widget_modify_font (edescgra, font_desc);
gtk_widget_set_size_request(GTK_WIDGET(edescgra),225,30);
gtk_fixed_put(GTK_FIXED(fixed),edescgra,980,95);



lqtdgra = gtk_label_new("Qtd grad :");
gtk_fixed_put(GTK_FIXED(fixed),lqtdgra,990,137);

eqtdgra = gtk_entry_new();
font_desc = pango_font_description_from_string ("Serif Bold 14");
gtk_widget_modify_font (eqtdgra, font_desc);
gtk_widget_set_size_request(GTK_WIDGET(eqtdgra),75,30);
gtk_fixed_put(GTK_FIXED(fixed),eqtdgra,1070,130);




btgranew = gtk_tool_button_new_from_stock(GTK_STOCK_NEW);
gtk_fixed_put(GTK_FIXED(fixed),btgranew ,1145,130);

btgraedt = gtk_tool_button_new_from_stock(GTK_STOCK_EDIT);
gtk_fixed_put(GTK_FIXED(fixed),btgraedt ,1185,130);

btgrasal = gtk_tool_button_new_from_stock(GTK_STOCK_SAVE);
gtk_fixed_put(GTK_FIXED(fixed),btgrasal ,1225,130);








g_signal_connect_swapped(G_OBJECT(btfechadetpro),"clicked",G_CALLBACK(apagadetpro),NULL);
g_signal_connect_swapped(G_OBJECT(btbackpro),"clicked",G_CALLBACK(backpro),NULL);

g_signal_connect_swapped(G_OBJECT(btedipro),"clicked",G_CALLBACK(editpro),NULL);

g_signal_connect_swapped(G_OBJECT(btgranew),"clicked",G_CALLBACK(novograd),NULL);
g_signal_connect_swapped(G_OBJECT(btgrasal),"clicked",G_CALLBACK(salvagra),NULL);
g_signal_connect_swapped(G_OBJECT(btgraedt),"clicked",G_CALLBACK(editgrad),NULL);
  gtk_widget_show_all(window);

listfor();
produtodados();
criaarvoreelistagrade();

notedipro();



}

