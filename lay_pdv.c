#include "lay_pdv.h"
#include "jan_fechadav.h"




enum {COL_IE,COL_CODP,COL_DESCP,COL_VALORI,COL_VALORS,COL_QTD,COL_GRADE,COL_COR,COL_CORQT,COL_CORC,NUM_COL };




void  on_changedprod(GtkWidget *widget,gpointer ocli) 
{
  GtkTreeIter iter;
  GtkTreeModel *model;
  char *clisel;


  if (gtk_tree_selection_get_selected(GTK_TREE_SELECTION(widget), &model, &iter)) {

    gtk_tree_model_get(model, &iter, COL_IE, &clisel,  -1);
   // gtk_widget_set_sensitive(GTK_WIDGET(bdelcli),TRUE);
    //gtk_statusbar_push(GTK_STATUSBAR(statusbar), gtk_statusbar_get_context_id(GTK_STATUSBAR(statusbar), value), value);
    gtk_widget_set_sensitive(GTK_WIDGET(btdelprod), TRUE);
   //0 g_print(" valor = %s \n",clisel);
 
    sprintf(prodsel,"%s",clisel);
  //g_print(" valor = %s \n",clisel);
    //g_print(" valor = %s \n",value);
    //g_free(value);    
    g_free(clisel);

  }
  else {
    gtk_widget_set_sensitive(GTK_WIDGET(btdelprod), FALSE);
   // gtk_widget_set_sensitive(GTK_WIDGET(bdelcli),FALSE);
   clisel= "";
}




}









void arvoreproduto (void){


        storepro = gtk_list_store_new(NUM_COL,G_TYPE_STRING,G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,GDK_TYPE_COLOR,GDK_TYPE_COLOR,GDK_TYPE_COLOR);
        model = GTK_TREE_MODEL(storepro);
        view = gtk_tree_view_new_with_model(GTK_TREE_MODEL( model));

        col = gtk_tree_view_column_new();
        gtk_tree_view_column_set_title(col, "cod produto");
        renderer = gtk_cell_renderer_text_new();
        gtk_tree_view_column_pack_start(col, renderer, TRUE);
        gtk_tree_view_column_set_attributes(col, renderer,
                                            "text", COL_CODP,"foreground-gdk", COL_CORC,
                                            NULL);

gtk_tree_view_column_set_sort_column_id(col,0);

        gtk_tree_view_append_column(GTK_TREE_VIEW(view), col);

/*  2nd column */
///gtk_tree_view_append_column(GTK_TREE_VIEW(view), col);

        col = gtk_tree_view_column_new();
        gtk_tree_view_column_set_title(col, "descrição ");
        renderer = gtk_cell_renderer_text_new();
        gtk_tree_view_column_pack_start(col, renderer, TRUE);
        gtk_tree_view_column_set_attributes(col, renderer,"text", COL_DESCP,"cell-background-gdk", COL_COR,NULL);
gtk_tree_view_column_set_sort_column_id(col,1);
        gtk_tree_view_append_column(GTK_TREE_VIEW(view), col);

//  "cell-background-gdk"      GdkColor*  
//"foreground-gdk"






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




	col = gtk_tree_view_column_new();
	gtk_tree_view_column_set_title(col, "Qtd ");

	renderer = gtk_cell_renderer_text_new();
	gtk_tree_view_column_pack_start(col, renderer, TRUE);
	gtk_tree_view_column_set_attributes(col, renderer,
	                                    "text", COL_QTD,"foreground-gdk",COL_CORQT,"cell-background-gdk", COL_COR,
	                                    NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(view), col);


/*  4nd column */
///gtk_tree_view_append_column(GTK_TREE_VIEW(view), col);

	col = gtk_tree_view_column_new();
	gtk_tree_view_column_set_title(col, "subtotal ");

	renderer = gtk_cell_renderer_text_new();
	gtk_tree_view_column_pack_start(col, renderer, TRUE);
	gtk_tree_view_column_set_attributes(col, renderer,
	                                    "text", COL_VALORS,"foreground-gdk",COL_CORQT,"cell-background-gdk", COL_COR,
	                                    NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(view), col);
//  "cell-background-gdk"      GdkColor*  
//"foreground-gdk"

















/*  5nd column */
///gtk_tree_view_append_column(GTK_TREE_VIEW(view), col);

        col = gtk_tree_view_column_new();
        gtk_tree_view_column_set_title(col, "Grade ");
        renderer = gtk_cell_renderer_text_new();
        gtk_tree_view_column_pack_start(col, renderer, TRUE);
        gtk_tree_view_column_set_attributes(col, renderer,
                                            "text", COL_GRADE,"foreground-gdk", COL_CORC,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(view), col);





//listadeprodutos(n_not_int,view);

 selectionprod  = gtk_tree_view_get_selection(GTK_TREE_VIEW(view));
  g_signal_connect(selectionprod, "changed",G_CALLBACK(on_changedprod),btdelprod);



gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(swprod),view);
gtk_widget_show_all(swprod);






}







void ini_nova_venda(void){
char num_ddv[100];
gtk_entry_set_text(GTK_ENTRY(cqtdv),"1");
//gtk_entry_set_text(GTK_ENTRY(campodata),"26/10/2010");
gtk_widget_set_sensitive(GTK_WIDGET(cqtdv),TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(cbuscaprod),TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(cprev),TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(ccodtipomov),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(ccodcli),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(btnovavenda),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(btfecha),TRUE);
//gtk_entry_set_text(GTK_ENTRY(ccodcli),"1");
//gtk_entry_set_text(GTK_ENTRY(ccodtipomov),"1");

gtk_widget_set_sensitive(GTK_WIDGET(cvend),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(campodata),FALSE);
gtk_widget_grab_focus(cbuscaprod);
sprintf(num_ddv,"<big><span color='blue'><b>%d</b></span> </big> ",crianovavenda());
 //crianovavenda();
gtk_label_set_markup(GTK_LABEL(lnumdav), num_ddv);

//g_print("numreo dave %s \n", gtk_label_get_text(GTK_LABEL(lnumdav)));

//listaprodutostree (swprod,gtk_label_get_text(GTK_LABEL(lnumdav)));
arvoreproduto();




}


void editicli(void){


gtk_widget_set_sensitive(ccodcli,TRUE);






}


void fechando(void){

int coddodav;
sscanf(gtk_label_get_text(GTK_LABEL(lnumdav)),"%d",&coddodav);

janelafechadav(btfecha,cvend,coddodav);







}




void focusnovavenda(GtkWidget *widget,GdkEventKey *event,gpointer *poi){

if(event->keyval == 65293){
gtk_widget_grab_focus(btnovavenda);
}
else if (event->keyval == 65421){
gtk_widget_grab_focus(btnovavenda);
}
}







void delproduto(void){
int i;
//g_print("produto sell %s //",prodsel);
sscanf(prodsel,"%d",&i);


deleprod(i);
listadeprodutos(gtk_label_get_text(GTK_LABEL(lnumdav)),storepro);
totalvenda();
}







void janelaclientefast(GtkWidget *botao , gpointer *edcodcli){


int coddodav;
sscanf(gtk_label_get_text(GTK_LABEL(lnumdav)),"%d",&coddodav);


janelaclifast(btedcli,ccodcli,coddodav);

}


void telapdv (void){

ldata = gtk_label_new("data :");
gtk_fixed_put(GTK_FIXED(fixedpdv),ldata,10,13);
campodata= gtk_entry_new();
gtk_widget_set_size_request(GTK_WIDGET(campodata),105,30);
gtk_fixed_put(GTK_FIXED(fixedpdv),campodata,50,7);

lvend = gtk_label_new("vendedor :");
gtk_fixed_put(GTK_FIXED(fixedpdv),lvend,160,13);
cvend= gtk_entry_new();
gtk_widget_set_size_request(GTK_WIDGET(cvend),40,30);
gtk_fixed_put(GTK_FIXED(fixedpdv),cvend,230,7);

lnomevend = gtk_label_new("nome do vendedor ");
gtk_fixed_put(GTK_FIXED(fixedpdv),lnomevend,280,13);

lbuscaprod = gtk_label_new("codigo :");
gtk_fixed_put(GTK_FIXED(fixedpdv),lbuscaprod,7,55);

const GdkColor RED_COLOR = { 0,0,  65535, 0 };
cbuscaprod = gtk_entry_new();
  
gtk_widget_set_size_request(GTK_WIDGET(cbuscaprod),160,50);
PangoFontDescription *font_desc;
font_desc = pango_font_description_from_string ("Serif Bold 22");
gtk_widget_modify_font (cbuscaprod, font_desc);

gtk_widget_modify_text(cbuscaprod, GTK_STATE_NORMAL, &RED_COLOR);
gtk_fixed_put(GTK_FIXED(fixedpdv),cbuscaprod,63,40);

lqtdv = gtk_label_new("qtd : ");
gtk_fixed_put(GTK_FIXED(fixedpdv),lqtdv,230,55);

cqtdv = gtk_entry_new();
gtk_widget_modify_font (cqtdv, font_desc);
  gtk_widget_set_size_request(GTK_WIDGET(cqtdv),60,50);
gtk_fixed_put(GTK_FIXED(fixedpdv),cqtdv,263,40);

lprev = gtk_label_new("preço :");
gtk_fixed_put(GTK_FIXED(fixedpdv),lprev,333,55);

cprev = gtk_entry_new();
gtk_widget_modify_font (cprev, font_desc);
  gtk_widget_set_size_request(GTK_WIDGET(cprev),190,50);
gtk_fixed_put(GTK_FIXED(fixedpdv),cprev,383,40);

combograde = gtk_combo_box_new_text();
gtk_widget_set_size_request(GTK_WIDGET(combograde),150,50);
font_desc = pango_font_description_from_string ("Serif Bold 22");
gtk_widget_modify_font (combograde, font_desc);
gtk_fixed_put(GTK_FIXED(fixedpdv),combograde,600,40);

btnovavenda = gtk_button_new_with_label("Nova Venda");
gtk_widget_set_size_request(btnovavenda, 130, 45);
gtk_fixed_put(GTK_FIXED(fixedpdv),btnovavenda, 770,50);

lnumdavs = gtk_label_new("numero da venda ");
gtk_fixed_put(GTK_FIXED(fixedpdv),lnumdavs,780,10);

lnumdav = gtk_label_new("");
gtk_label_set_markup(GTK_LABEL(lnumdav),"<big><span color='blue'><b> 999999  </b></span> </big> ");
gtk_fixed_put(GTK_FIXED(fixedpdv),lnumdav,790,30);

ldesprod = gtk_label_new("");
gtk_label_set_markup(GTK_LABEL(ldesprod), "<big><b> produto  </b> </big> ");

swdesp = gtk_scrolled_window_new(NULL,NULL);
gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW(swdesp),GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW(swdesp),GTK_SHADOW_ETCHED_IN);
gtk_widget_set_usize (swdesp, 860, 45);
gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(swdesp),ldesprod);
gtk_fixed_put(GTK_FIXED(fixedpdv),swdesp,15,100);

swprod = gtk_scrolled_window_new(NULL,NULL);
gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW(swprod),GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW(swprod),GTK_SHADOW_ETCHED_IN);
gtk_widget_set_usize (swprod, 900, 400);




gtk_fixed_put(GTK_FIXED(fixedpdv),swprod,10,155);

ltotal = gtk_label_new("");
gtk_label_set_markup(GTK_LABEL(ltotal), "<big><span color='red' font_size='larger' bgcolor='#FFFFFF' ><b> total </b></span> </big> ");

gtk_fixed_put(GTK_FIXED(fixedpdv),ltotal,790,600);

lcodcli = gtk_label_new("cod c :");
gtk_fixed_put(GTK_FIXED(fixedpdv),lcodcli,10,570);

ccodcli = gtk_entry_new();
gtk_widget_set_size_request(GTK_WIDGET(ccodcli),50,30);
gtk_fixed_put(GTK_FIXED(fixedpdv),ccodcli,10,590);

lnomecli = gtk_label_new("nome : ");
gtk_fixed_put(GTK_FIXED(fixedpdv),lnomecli,95,570);

lnomecliente = gtk_label_new("");

gtk_label_set_markup(GTK_LABEL(lnomecliente), "<b> cliente balcão  </b> ");
gtk_fixed_put(GTK_FIXED(fixedpdv),lnomecliente,97,598);

lcodtpmov = gtk_label_new("tipo de operacao :");
gtk_fixed_put(GTK_FIXED(fixedpdv),lcodtpmov,400,570);

ccodtipomov = gtk_entry_new();
gtk_widget_set_size_request(GTK_WIDGET(ccodtipomov),50,30);
gtk_fixed_put(GTK_FIXED(fixedpdv),ccodtipomov,420,590);


btfecha = gtk_button_new_with_label("Finalizar");
gtk_widget_set_size_request(btfecha, 130, 95);
gtk_fixed_put(GTK_FIXED(fixedpdv),btfecha, 620,560);
gtk_widget_set_sensitive(GTK_WIDGET(btfecha),FALSE);



btedcli = gtk_tool_button_new_from_stock(GTK_STOCK_EDIT);
//btedcli = gtk_button_new_with_label("Finalizar");
//gtk_widget_set_size_request(btfecha, , 95);
gtk_fixed_put(GTK_FIXED(fixedpdv),btedcli, 58,586);
//gtk_widget_set_sensitive(GTK_WIDGET(btfecha),FALSE);

btdelprod = gtk_tool_button_new_from_stock(GTK_STOCK_DELETE);
//btedcli = gtk_button_new_with_label("Finalizar");
//gtk_widget_set_size_request(btfecha, , 95);
gtk_fixed_put(GTK_FIXED(fixedpdv),btdelprod,880,100);
gtk_widget_set_sensitive(GTK_WIDGET(btdelprod),FALSE);




pango_font_description_free (font_desc);

g_signal_connect(G_OBJECT(cvend), "changed",G_CALLBACK(verificavendedor),NULL);
g_signal_connect(G_OBJECT(cvend), "key-release-event",G_CALLBACK(focusnovavenda),NULL);
g_signal_connect(G_OBJECT(ccodcli), "changed",G_CALLBACK(verificacliente),NULL);
g_signal_connect(G_OBJECT(btnovavenda),"clicked",G_CALLBACK(ini_nova_venda),NULL);


g_signal_connect(G_OBJECT(cbuscaprod),"changed",G_CALLBACK(verificaproduto),NULL);


g_signal_connect(G_OBJECT(cbuscaprod),"key-release-event",G_CALLBACK(insereprodudo),NULL);
g_signal_connect(G_OBJECT(cqtdv),"key-release-event",G_CALLBACK(insereprodudo),NULL);
g_signal_connect(G_OBJECT(cprev),"key-release-event",G_CALLBACK(insereprodudo),NULL);
g_signal_connect(G_OBJECT(combograde),"key-release-event",G_CALLBACK(insereprodudo),NULL);
g_signal_connect(G_OBJECT(campodata),"button-press-event",G_CALLBACK(janeladata),cvend);
g_signal_connect(G_OBJECT(btedcli),"clicked",G_CALLBACK(janelaclientefast),NULL);
g_signal_connect(G_OBJECT(btdelprod),"clicked",G_CALLBACK(delproduto),NULL);
g_signal_connect(G_OBJECT(btfecha),"clicked",G_CALLBACK(fechando),NULL);



}

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





void prepraratelapdv(void){
gtk_entry_set_text(GTK_ENTRY(cqtdv),"");


char data[11];
struct tm *local;
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
sprintf(data,"%d/%d/%d",dia,mes,ano);
gtk_entry_set_text(GTK_ENTRY(campodata),data);

gtk_widget_set_sensitive(GTK_WIDGET(cqtdv),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(cbuscaprod),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(cprev),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(ccodtipomov),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(ccodcli),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(btnovavenda),FALSE);
gtk_entry_set_text(GTK_ENTRY(ccodcli),"0");
gtk_entry_set_text(GTK_ENTRY(ccodtipomov),"1");
gtk_widget_set_sensitive(GTK_WIDGET(btfecha),FALSE);
gtk_label_set_markup(GTK_LABEL(ltotal), "<big><span color='red' font_size='larger' bgcolor='#FFFFFF' ><b> 0,00 </b></span> </big> ");


}















void windowpdvc( int argc, char *argv[]){

  gtk_init(&argc, &argv);
  fixedpdv = gtk_fixed_new();
  windowpdv = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(windowpdv), "PDV 0.10");
  gtk_window_set_default_size(GTK_WINDOW(windowpdv), 920, 650);
  gtk_window_set_position(GTK_WINDOW(windowpdv), GTK_WIN_POS_CENTER);
  gtk_window_set_icon(GTK_WINDOW(windowpdv), create_pixbufpdv("imagens/buy_32.png"));
  gtk_widget_show(windowpdv);

  g_signal_connect_swapped(G_OBJECT(windowpdv), "destroy",G_CALLBACK(gtk_main_quit), NULL);
  //barraprincipal();
  telapdv();
  prepraratelapdv();

  gtk_widget_grab_focus(cvend);

  gtk_container_add(GTK_CONTAINER(windowpdv), fixedpdv);
  gtk_widget_show_all(windowpdv);
  gtk_widget_grab_focus(cvend);
  gtk_main();

  return;
}

