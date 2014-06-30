#include <gtk/gtk.h>
#include <mysql/mysql.h>
#include "con.h"
#include "caixavendas.h"
#include "layout.h"
#include "nume.h"
#include "str_replace.h"


enum {COL_DAV,COL_DATA,COL_VEND,COL_VALORV,COL_CODSTA,NUM_COLDAVS };

enum {COL_CODVEND,COL_PECAS,COL_DIN,COL_CAR,COL_CHE,COL_TOT,COL_CORF,NUM_COLVENDEDORESTOTAL };

void fechavendastotal(void){
gtk_widget_destroy(GTK_WIDGET(calendario));
gtk_widget_destroy(GTK_WIDGET(btfechavendastotal));
gtk_widget_destroy(GTK_WIDGET(svendas));
gtk_widget_destroy(GTK_WIDGET(stotalvendedor));
gtk_widget_destroy(GTK_WIDGET(radio1));
gtk_widget_destroy(GTK_WIDGET(radio2));
gtk_widget_destroy(GTK_WIDGET(radio3));
gtk_widget_destroy(GTK_WIDGET(btrefdavs));


  gtk_widget_set_sensitive(GTK_WIDGET(botaocliente),TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(vendastotal),TRUE);
}





void arvoretotalvendasvendedor (void){






        storetotalvendas = gtk_list_store_new(NUM_COLVENDEDORESTOTAL,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,GDK_TYPE_COLOR);
        modeltotalvendas = GTK_TREE_MODEL(storetotalvendas);
        viewtotalvendas = gtk_tree_view_new_with_model(GTK_TREE_MODEL( modeltotalvendas));

/*1 coluna */
        coltven = gtk_tree_view_column_new();
        gtk_tree_view_column_set_title(coltven, "Vendedor");
        renderertven = gtk_cell_renderer_text_new();
        gtk_tree_view_column_pack_start(coltven, renderertven, TRUE);
        gtk_tree_view_column_set_attributes(coltven, renderertven,"text", COL_CODVEND,NULL);
        gtk_tree_view_column_set_sort_column_id(coltven,0);
        gtk_tree_view_append_column(GTK_TREE_VIEW(viewtotalvendas), coltven);

/*  2nd column */




/*  3 column */


	coltven = gtk_tree_view_column_new();
	gtk_tree_view_column_set_title(coltven, "Dinheiro ");

	renderertven = gtk_cell_renderer_text_new();
	gtk_tree_view_column_pack_start(coltven, renderertven, TRUE);
	gtk_tree_view_column_set_attributes(coltven, renderertven,"text",COL_DIN,NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(viewtotalvendas), coltven);

/* 4 column*/


	coltven = gtk_tree_view_column_new();
	gtk_tree_view_column_set_title(coltven, "Cartao ");

	renderertven = gtk_cell_renderer_text_new();
	gtk_tree_view_column_pack_start(coltven, renderertven, TRUE);
	gtk_tree_view_column_set_attributes(coltven, renderertven,
	                                    "text", COL_CAR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(viewtotalvendas), coltven);


/*  5nd column */
///gtk_tree_view_append_column(GTK_TREE_VIEW(view), col);

	coltven = gtk_tree_view_column_new();
	gtk_tree_view_column_set_title(coltven, "Cheque ");
	renderertven = gtk_cell_renderer_text_new();
	gtk_tree_view_column_pack_start(coltven, renderertven, TRUE);
	gtk_tree_view_column_set_attributes(coltven, renderertven,"text", COL_CHE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(viewtotalvendas), coltven);
//  "cell-background-gdk"      GdkColor*  
//"foreground-gdk"



/*  6nd column */
///gtk_tree_view_append_column(GTK_TREE_VIEW(view), col);

        coltven = gtk_tree_view_column_new();
        gtk_tree_view_column_set_title(coltven, "Total ");
        renderertven = gtk_cell_renderer_text_new();
        gtk_tree_view_column_pack_start(coltven, renderertven, TRUE);
        gtk_tree_view_column_set_attributes(coltven, renderertven,"text", COL_TOT,"cell-background-gdk", COL_CORF,NULL);
        gtk_tree_view_append_column(GTK_TREE_VIEW(viewtotalvendas), coltven);




        coltven = gtk_tree_view_column_new();
        gtk_tree_view_column_set_title(coltven, "pecas ");
        renderertven = gtk_cell_renderer_text_new();
        gtk_tree_view_column_pack_start(coltven, renderertven, TRUE);
        gtk_tree_view_column_set_attributes(coltven, renderertven,"text", COL_PECAS,NULL);
//gtk_tree_view_column_set_sort_column_id(col,1);
        gtk_tree_view_append_column(GTK_TREE_VIEW(viewtotalvendas), coltven);


//listadeprodutos(n_not_int,view);

 //selectionprod  = gtk_tree_view_get_selection(GTK_TREE_VIEW(view));
//  g_signal_connect(selectionprod, "changed",G_CALLBACK(on_changedprod),btdelprod);



gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(stotalvendedor),viewtotalvendas);
gtk_widget_show_all(stotalvendedor);






}











void arvorevendedortotal(void){






        storedavs = gtk_list_store_new(NUM_COLDAVS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
        modeldavs = GTK_TREE_MODEL(storedavs);
        viewdavs = gtk_tree_view_new_with_model(GTK_TREE_MODEL( modeldavs));

/*1 coluna */
        coldavs = gtk_tree_view_column_new();
        gtk_tree_view_column_set_title(coldavs, "DAV");
        rendererdavs = gtk_cell_renderer_text_new();
        gtk_tree_view_column_pack_start(coldavs, rendererdavs, TRUE);
        gtk_tree_view_column_set_attributes(coldavs, rendererdavs,"text", COL_DAV,NULL);
        gtk_tree_view_column_set_sort_column_id(coldavs,0);
        gtk_tree_view_append_column(GTK_TREE_VIEW(viewdavs), coldavs);


/*2 coluna */
        coldavs = gtk_tree_view_column_new();
        gtk_tree_view_column_set_title(coldavs, "DATA");
        rendererdavs = gtk_cell_renderer_text_new();
        gtk_tree_view_column_pack_start(coldavs, rendererdavs, TRUE);
        gtk_tree_view_column_set_attributes(coldavs, rendererdavs,"text", COL_DATA,NULL);
        gtk_tree_view_column_set_sort_column_id(coldavs,0);
        gtk_tree_view_append_column(GTK_TREE_VIEW(viewdavs), coldavs);


/*3 coluna */
        coldavs = gtk_tree_view_column_new();
        gtk_tree_view_column_set_title(coldavs, "VENDEDOR");
        rendererdavs = gtk_cell_renderer_text_new();
        gtk_tree_view_column_pack_start(coldavs, rendererdavs, TRUE);
        gtk_tree_view_column_set_attributes(coldavs, rendererdavs,"text", COL_VEND,NULL);
        gtk_tree_view_column_set_sort_column_id(coldavs,0);
        gtk_tree_view_append_column(GTK_TREE_VIEW(viewdavs), coldavs);

/*4 coluna */
        coldavs = gtk_tree_view_column_new();
        gtk_tree_view_column_set_title(coldavs, "VALOR");
        rendererdavs = gtk_cell_renderer_text_new();
        gtk_tree_view_column_pack_start(coldavs, rendererdavs, TRUE);
        gtk_tree_view_column_set_attributes(coldavs, rendererdavs,"text", COL_VALORV,NULL);
        gtk_tree_view_column_set_sort_column_id(coldavs,0);
        gtk_tree_view_append_column(GTK_TREE_VIEW(viewdavs), coldavs);



/*5 coluna */
        coldavs = gtk_tree_view_column_new();
        gtk_tree_view_column_set_title(coldavs, "STA");
        rendererdavs = gtk_cell_renderer_text_new();
        gtk_tree_view_column_pack_start(coldavs, rendererdavs, TRUE);
        gtk_tree_view_column_set_attributes(coldavs, rendererdavs,"text", COL_CODSTA,NULL);
        gtk_tree_view_column_set_sort_column_id(coldavs,0);
        gtk_tree_view_append_column(GTK_TREE_VIEW(viewdavs), coldavs);











//listadeprodutos(n_not_int,view);

 //selectionprod  = gtk_tree_view_get_selection(GTK_TREE_VIEW(view));
//  g_signal_connect(selectionprod, "changed",G_CALLBACK(on_changedprod),btdelprod);



gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(svendas),viewdavs);
gtk_widget_show_all(svendas);






}















void btrefdavsclick(void){


gtk_list_store_clear(storedavs);
gtk_list_store_clear(storetotalvendas);
MYSQL_RES *respdavs,*respvr,*respvenda,*respnumpc;
MYSQL_ROW ldavs,lvr,lvenda,lnumpc;
char sqldavs[ 1000 ];
int anod,mesd,diad,horad,mind,segd;
gint anoi,mesi,diai;
char datad[11];
GtkTreeIter    iterdavs,itervenda;

gtk_calendar_get_date(GTK_CALENDAR(calendario),&anoi,&mesi,&diai);
mesi ++;

char diaf[3];
char mesf[3];

sprintf(diaf,"%02d", diai); 
//g_print("dia f = %s",diaf);

sprintf(mesf,"%02d", mesi); 

char sqlvr[1000];
char sqlvenda[1000];


if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radio1))){
//g_print("btrefdavs sel dia");
sprintf(sqldavs,"SELECT * FROM tb_dav WHERE numemp LIKE '%d'AND data LIKE '%%%d-%s-%s%%' AND id_status > 1",numep(),anoi,mesf,diaf);
sprintf(sqlvenda,"SELECT * FROM tb_payment WHERE numemp='%d' AND data_venda LIKE '%%%d-%s-%s%%' ",numep(),anoi,mesf,diaf);
}
else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radio2))){
//g_print("btrefdavs sel mes ");
sprintf(sqldavs,"SELECT * FROM tb_dav WHERE numemp LIKE '%d'AND data LIKE '%%%d-%s%%' AND id_status > 1",numep(),anoi,mesf);
sprintf(sqlvenda,"SELECT * FROM tb_payment WHERE numemp='%d' AND data_venda LIKE '%%%d-%s%%' ",numep(),anoi,mesf);
}

else if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(radio3))){
//g_print("btrefdavs sel ano ");
sprintf(sqldavs,"SELECT * FROM tb_dav WHERE numemp LIKE '%d'AND data LIKE '%%%d%%' AND id_status > 1",numep(),anoi);
sprintf(sqlvenda,"SELECT * FROM tb_payment WHERE numemp='%d' AND data_venda LIKE '%%%d%%' ",numep(),anoi);


}








sprintf(sqlvr,"SELECT * FROM tb_vendedores WHERE numemp='%d'",numep());
int vendee=0;

if (mysql_query(&conexao,sqlvr))
        g_print("Erro: %s\n",mysql_error(&conexao));
else
    {
    respvr = mysql_store_result(&conexao);//recebe a consulta
    if (respvr) //se houver consulta
        {
          while ((lvr=mysql_fetch_row(respvr)) != NULL)  //enquanto linhas for diferente de nulo faca 
              {
vendee +=1;
              }
          }
          mysql_free_result(respvr);//limpa a variável do resultado: resp
        }

double total[vendee][6];
double subtot[5]= { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
double tpcas;
int tipo,t;
int vendedor;
double vpay;
double tgeral;
int liha,coua;
int dd;
dd= vendee + 1;


//subtot[] = { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
tpcas = 0 ;



for (liha = 0; liha < dd; liha++)

         for (coua = 0; coua < 7; coua++)
        total[liha][coua] =0;

if (mysql_query(&conexao,sqlvenda))
        g_print("Erro: %s\n",mysql_error(&conexao));
else
    {
    respvenda = mysql_store_result(&conexao);//recebe a consulta
    if (respvenda) //se houver consulta
        {
          while ((lvenda=mysql_fetch_row(respvenda)) != NULL)  //enquanto linhas for diferente de nulo faca 
              {

sscanf(lvenda[3],"%d",&tipo);
sscanf(lvenda[9],"%d",&vendedor);
char valorpay[20];
sprintf(valorpay,"%s",lvenda[5]);
char *valorpay2= str_replace(valorpay,".", ",");
vpay = strtod(valorpay2,NULL);

if (tipo == 1)
        {
                t=1;
        }
else if (tipo > 1 )
        {
        if(tipo <9)
                {
                        t=2;
                }
        else if (tipo ==10)
                {
                        t=3;
                }
        else 
                {
                        t=4;
                }
        }
total[vendedor][t]   += vpay; 
total[vendedor][5] += vpay;
subtot[t] +=vpay;

tgeral +=vpay;
total[vendedor][0] = 0;

              }
          }
          mysql_free_result(respvenda);//limpa a variável do resultado: resp
        }

int linha,couna;
int ddd;
ddd= vendee + 1;

int npcs;
if (mysql_query(&conexao,sqldavs))
        g_print("Erro: %s\n",mysql_error(&conexao));
else
    {
    respdavs = mysql_store_result(&conexao);//recebe a consulta
    if (respdavs) //se houver consulta
        {
          while ((ldavs=mysql_fetch_row(respdavs)) != NULL)  //enquanto linhas for diferente de nulo faca 
              {
                sscanf(ldavs[2],"%d-%d-%d %d:%d:%d",&anod,&mesd,&diad,&horad,&mind,&segd);
                sprintf(datad,"%d/%d/%d",diad,mesd,anod);
                gtk_list_store_append(storedavs, &iterdavs);
                gtk_list_store_set(storedavs, &iterdavs,COL_DAV,ldavs[0],COL_DATA,datad,COL_VEND,ldavs[3],COL_VALORV,ldavs[5],COL_CODSTA,ldavs[10],-1);
sscanf(ldavs[3],"%d",&vendedor);
sscanf(ldavs[13],"%d",&npcs);
                total[vendedor][6] += npcs;
tpcas +=npcs;
              }
          }
          mysql_free_result(respdavs);//limpa a variável do resultado: resp
        }

GdkColor colore;
char codvend[10];
char spcs[11];
char sdin[14];
char scar[14];
char sche[14];
char stotal[15];
char sfinal[15];



for (linha = 0; linha < ddd; linha++){

                                colore.red = 63479;
                                colore.blue = 49087;
                                colore.green = 65535;
///G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,GDK_TYPE_COLOR);
//enum {COL_CODVEND,COL_PECAS,COL_DIN,COL_CAR,COL_CHE,COL_TOT,COL_CORF,NUM_COLVENDEDORESTOTAL };



sprintf(codvend,"%d",linha);
sprintf(spcs,"%.1lf",total[linha][6]);
sprintf(sdin,"%.2lf",total[linha][1]);
sprintf(scar,"%.2lf",total[linha][2]);
sprintf(sche,"%.2lf",total[linha][3]);
sprintf(stotal,"%.2lf",total[linha][5]);


//g_print("inta = %d " , linha);

//gtk_list_store_set(storetotalvendas, &itervenda,COL_CODVEND,linha,COL_PECAS,total[linha][6],COL_DIN,total[linha][1],COL_CAR,total[linha][2],COL_CHE,total[linha][3],COL_TOT,total[linha][4],COL_CORF,&colore,-1);

if (total[linha][5] > 0 ){

gtk_list_store_append(storetotalvendas, &itervenda);
gtk_list_store_set(storetotalvendas, &itervenda,COL_CODVEND,codvend,COL_PECAS,spcs,COL_DIN,sdin,COL_CAR,scar,COL_CHE,sche,COL_TOT,stotal,COL_CORF,&colore,-1);
}

}




char stpcs[11];
char stdin[14];
char stcar[14];
char stche[14];
char stot[15];
colore.red = 65535;
colore.blue = 10000;
colore.green = 45512;
///G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,GDK_TYPE_COLOR);
//enum {COL_CODVEND,COL_PECAS,COL_DIN,COL_CAR,COL_CHE,COL_TOT,COL_CORF,NUM_COLVENDEDORESTOTAL };



sprintf(codvend,"%d",linha);
sprintf(stpcs,"%.1lf",tpcas);
sprintf(stdin,"%.2lf",subtot[1]);
sprintf(stcar,"%.2lf",subtot[2]);
sprintf(stche,"%.2lf",subtot[3]);
sprintf(stot,"%.2lf",tgeral);


//g_print("inta = %d " , linha);

//gtk_list_store_set(storetotalvendas, &itervenda,COL_CODVEND,linha,COL_PECAS,total[linha][6],COL_DIN,total[linha][1],COL_CAR,total[linha][2],COL_CHE,total[linha][3],COL_TOT,total[linha][4],COL_CORF,&colore,-1);


gtk_list_store_append(storetotalvendas, &itervenda);
gtk_list_store_set(storetotalvendas, &itervenda,COL_CODVEND,"total",COL_PECAS,stpcs,COL_DIN,stdin,COL_CAR,stcar,COL_CHE,stche,COL_TOT,stot,COL_CORF,&colore,-1);

}


















void telatotalvendas(void){

  calendario = gtk_calendar_new();
  gtk_widget_set_usize (calendario, 320, 180);
  gtk_fixed_put(GTK_FIXED(fixed),calendario,20,4);

  gtk_widget_set_sensitive(GTK_WIDGET(botaocliente),FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(vendastotal),FALSE);
  btfechavendastotal = gtk_tool_button_new_from_stock(GTK_STOCK_CLOSE);
  gtk_fixed_put(GTK_FIXED(fixed),btfechavendastotal,1240,0);

   /* Create a radio button with a GtkEntry widget */
   radio1 = gtk_radio_button_new_with_label(NULL,"Total Dia");

   /* Create a radio button with a label */
   radio2 = gtk_radio_button_new_with_label_from_widget (GTK_RADIO_BUTTON (radio1),"Total Mes");
   radio3 = gtk_radio_button_new_with_label_from_widget (GTK_RADIO_BUTTON (radio1),"Total Ano");


  btrefdavs = gtk_tool_button_new_from_stock(GTK_STOCK_REFRESH);
  gtk_fixed_put(GTK_FIXED(fixed),btrefdavs,380,150);


  gtk_fixed_put(GTK_FIXED(fixed), radio1, 380,30);

  gtk_fixed_put(GTK_FIXED(fixed), radio2, 380,60);

  gtk_fixed_put(GTK_FIXED(fixed), radio3, 380,90);


svendas= gtk_scrolled_window_new(NULL,NULL);
gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW(svendas),GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW(svendas),GTK_SHADOW_ETCHED_IN);
//gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(svendas),ldesprod);
  gtk_widget_set_usize (svendas, 690, 680);
gtk_fixed_put(GTK_FIXED(fixed),svendas,550,0);


stotalvendedor= gtk_scrolled_window_new(NULL,NULL);
gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW(stotalvendedor),GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW(stotalvendedor),GTK_SHADOW_ETCHED_IN);
//gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(svendas),ldesprod);
  gtk_widget_set_usize (stotalvendedor, 520, 480);
gtk_fixed_put(GTK_FIXED(fixed),stotalvendedor,10,200);


arvoretotalvendasvendedor();
arvorevendedortotal();
btrefdavsclick();

 g_signal_connect(G_OBJECT(btrefdavs), "clicked",G_CALLBACK(btrefdavsclick),NULL);

  g_signal_connect(G_OBJECT(calendario),"day-selected",G_CALLBACK(btrefdavsclick),NULL);
  g_signal_connect(G_OBJECT(btfechavendastotal), "clicked",G_CALLBACK(fechavendastotal),NULL);

  g_signal_connect(G_OBJECT(radio1),"clicked",G_CALLBACK(btrefdavsclick),NULL);
  g_signal_connect(G_OBJECT(radio2),"clicked",G_CALLBACK(btrefdavsclick),NULL);
  g_signal_connect(G_OBJECT(radio3),"clicked",G_CALLBACK(btrefdavsclick),NULL);

 // g_signal_connect(G_OBJECT(ckdia),"clicked",G_CALLBACK(ckdiaclick),NULL);
//  g_signal_connect(G_OBJECT(ckmes),"clicked",G_CALLBACK(ckmesclick),NULL);
  //g_signal_connect(G_OBJECT(ckano),"clicked",G_CALLBACK(ckanoclick),NULL);
  gtk_widget_show_all(window);


}
