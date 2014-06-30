#include <gtk/gtk.h>
#include <stdio.h>
#include "con.h"
#include "telach.h"
enum{ CODCLI_COL,NOMECLI_COL,CPFCLI_COL,CIDCLI_COL,NUM_COLS};
enum{CODCH_COL,CCLI_COL,DTEN_COL,DTS_COL,VCH_COL,SITFINCH,CHCH_COL,DESTCH_COL,NUM_COLSCH};

GtkWidget *vbox;
GtkWidget *fixed;
GtkWidget *ebcli;
GtkWidget *lebcli;
GtkWidget *treewcli,*treewchcli;
GtkWidget *swcli,*swchcli;
GtkTreeStore *treestorecli,*treestorechcli;
GtkTreeViewColumn *coluna;
GtkCellRenderer *celula;
GtkTreeSelection *selection,*chselection;
GtkWidget *lccli,*lnocli,*lt1cli,*ledcli,*lcocli,*lbacli,*lcicli,*lufcli,*lt2cli,*ldncli,*lcpfcli,*lrgcli,*lemcli,*lobscli;
GtkWidget *eccli,*enocli,*et1cli,*eedcli,*ecocli,*ebacli,*ecicli,*eufcli,*et2cli,*edncli,*ecpfcli,*ergcli,*eemcli;
GtkWidget *eobscli;
GtkTextBuffer *buffer;
int handler_id;
int handler2_id;
int hander;
int hander2;

int bak;


char clisele[20];
char chsele[20];
char codclich[20];

// widget menu clientes
  GtkWidget *barcli;
  GtkToolItem *ncli;
  GtkToolItem *bdelcli;
  GtkToolItem *ecli;
  GtkToolItem *scli;
  GtkToolItem *ocli;
  GtkToolItem *closecli;
  GtkToolItem *backlcli,*refche;
// widget menu princ
  GtkWidget *toolbar;
  GtkToolItem *btcli;
  GtkToolItem *open;
  GtkToolItem *save;
  GtkToolItem *sep;
  GtkToolItem *btexit;
//barracheque 
  GtkWidget *barcheque;
  GtkToolItem *addche,*remche,*ediche;
  GtkWindow *windowp;

///////////////////////////////////





void opencamposcliente(void);
void closetelacli(void);
void opencliente(void);
void editcliente(void);
void teladetalecli (void);
int telacliente(GtkWidget *btclic);
void  onch_changed(GtkWidget *widget);
void delecli(GtkWidget *widget ,gpointer windo);
void deleclidet(GtkWidget *widget ,gpointer windo);
/////////////////////////////////////////////////////////////////////////////////////
void closetelalistacliente(void){



gtk_widget_destroy(treewcli);
gtk_widget_destroy(ebcli);
gtk_widget_destroy(swcli);
gtk_widget_destroy(lebcli);
//gtk_widget_destroy(barcli);




}
//////////////////////////////////////////////////////////////////////////////////////////////////
void backtcli(void){
//closetdcli();

closetelacli();
sprintf(clisele," ");
telacliente(GTK_WIDGET(btcli));

}
//////////////////////////////////////////////////////////////////////////////////////////////////////
void closetdcli(void){

gtk_widget_destroy(barcli);
closetelalistacliente();
gtk_widget_set_sensitive(GTK_WIDGET(btcli),TRUE);

}
////////////////////////////////////////////////////////////////////////////////////////////
void refreshch(void){
listchclientecod(treestorechcli,clisele);


}


//////////////////////////////////////////////////////////////////////////////////////////////////////////
GtkWidget *menucheque(void){

barcheque = gtk_toolbar_new();
gtk_widget_set_usize(barcheque,50,200);
gtk_toolbar_set_orientation(GTK_TOOLBAR(barcheque),GTK_ORIENTATION_VERTICAL);
gtk_container_set_border_width(GTK_CONTAINER(barcheque),2);

addche = gtk_tool_button_new_from_stock(GTK_STOCK_ADD);
gtk_toolbar_insert(GTK_TOOLBAR(barcheque),addche,-1);


remche = gtk_tool_button_new_from_stock(GTK_STOCK_REMOVE);
gtk_toolbar_insert(GTK_TOOLBAR(barcheque),remche,-1);
gtk_widget_set_sensitive(GTK_WIDGET(remche),FALSE);

ediche = gtk_tool_button_new_from_stock(GTK_STOCK_EDIT);
gtk_toolbar_insert(GTK_TOOLBAR(barcheque),ediche,-1);
gtk_widget_set_sensitive(GTK_WIDGET(ediche),FALSE);
//chsele
//g_signal_connect    
refche = gtk_tool_button_new_from_stock(GTK_STOCK_REFRESH);
gtk_toolbar_insert(GTK_TOOLBAR(barcheque),refche,-1);
//gtk_widget_set_sensitive(GTK_WIDGET(refche),TRUE);



///gtk-refresh

  g_signal_connect(G_OBJECT(refche),"clicked",G_CALLBACK(refreshch),NULL);
  g_signal_connect(G_OBJECT(ediche), "clicked",G_CALLBACK(acheque),chsele);

return barcheque;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
void teladetalecli (void){

  gtk_widget_set_sensitive(GTK_WIDGET(ocli),FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(ncli),FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(ecli),TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(backlcli),TRUE);
//g_print(" valor = %s and  \n",clisele);

closetelalistacliente();

  lccli= gtk_label_new("codigo :");
  gtk_fixed_put(GTK_FIXED(fixed),lccli,240,20);
  eccli = gtk_entry_new();
  gtk_widget_set_size_request(GTK_WIDGET(eccli),50,30);
  gtk_widget_set_sensitive(GTK_WIDGET(eccli),FALSE);
  gtk_fixed_put(GTK_FIXED(fixed),eccli,298,13);

  lcpfcli = gtk_label_new("cpf :");
  gtk_fixed_put(GTK_FIXED(fixed),lcpfcli,350,20);
  ecpfcli = gtk_entry_new();
  //gtk_widget_set_sensitive(GTK_WIDGET(ecpfcli),FALSE);
  gtk_fixed_put(GTK_FIXED(fixed),ecpfcli,390,13);


//label = gtk_label_new (NULL);
//gtk_label_set_markup (GTK_LABEL (label), "<small>Small text</small>");

 // lnocli = gtk_label_new("nome cli :");
 lnocli = gtk_label_new(NULL);
 gtk_label_set_markup(GTK_LABEL(lnocli), "<big><span color='red'><b> nome cli : </b></span> </big> ");  
//label mudado 

gtk_fixed_put(GTK_FIXED(fixed),lnocli,10,70);
  enocli = gtk_entry_new();
  
  gtk_widget_set_size_request(GTK_WIDGET(enocli),600,30);
  gtk_fixed_put(GTK_FIXED(fixed),enocli,85,63);

  ledcli = gtk_label_new("end :");
  gtk_fixed_put(GTK_FIXED(fixed),ledcli,10,105);
  eedcli= gtk_entry_new();
  gtk_widget_set_size_request(GTK_WIDGET(eedcli),350,30);
  gtk_fixed_put(GTK_FIXED(fixed),eedcli,60,98);

  lcocli = gtk_label_new("comple :");
  gtk_fixed_put(GTK_FIXED(fixed),lcocli,430,105);
  ecocli = gtk_entry_new();
  gtk_fixed_put(GTK_FIXED(fixed),ecocli,505,98);

  lbacli = gtk_label_new("bairro :");
  gtk_fixed_put(GTK_FIXED(fixed),lbacli,10,137);
  ebacli = gtk_entry_new();
  gtk_fixed_put(GTK_FIXED(fixed),ebacli,60,132);

  lcicli = gtk_label_new("cidade :");
  gtk_fixed_put(GTK_FIXED(fixed),lcicli,225,137);
  ecicli = gtk_entry_new();
  gtk_fixed_put(GTK_FIXED(fixed),ecicli,280,132);

  lufcli = gtk_label_new("uf : ");
  gtk_fixed_put(GTK_FIXED(fixed),lufcli,470,137);
  eufcli = gtk_entry_new();
  gtk_widget_set_size_request(GTK_WIDGET(eufcli),50,30);
  gtk_fixed_put(GTK_FIXED(fixed),eufcli,500,132);

  lt1cli = gtk_label_new("tel 1 :");
  gtk_fixed_put(GTK_FIXED(fixed),lt1cli,10,170);
  et1cli = gtk_entry_new();
  gtk_fixed_put(GTK_FIXED(fixed),et1cli,60,163);

  lt2cli = gtk_label_new("tel 2 :");
  gtk_fixed_put(GTK_FIXED(fixed),lt2cli,225,170);
  et2cli = gtk_entry_new();
  gtk_fixed_put(GTK_FIXED(fixed),et2cli,270,163);

  ldncli = gtk_label_new("dt nasc :");
  gtk_fixed_put(GTK_FIXED(fixed),ldncli,10,203);
  edncli = gtk_entry_new();
  gtk_fixed_put(GTK_FIXED(fixed),edncli,73,196);

  lrgcli = gtk_label_new("rg :");
  gtk_fixed_put(GTK_FIXED(fixed),lrgcli,243,203);
  ergcli = gtk_entry_new();
  gtk_fixed_put(GTK_FIXED(fixed),ergcli,275,196);

  lemcli = gtk_label_new("email :");
  gtk_fixed_put(GTK_FIXED(fixed),lemcli,10,236);
  eemcli = gtk_entry_new();
  gtk_widget_set_size_request(GTK_WIDGET(eemcli),400,30);
  gtk_fixed_put(GTK_FIXED(fixed),eemcli,60,226);

  lobscli = gtk_label_new("obs :");
  gtk_fixed_put(GTK_FIXED(fixed),lobscli,460,170);
  eobscli = gtk_text_view_new();
  gtk_widget_set_size_request(GTK_WIDGET(eobscli),300,100);
  buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(eobscli));
  gtk_fixed_put(GTK_FIXED(fixed),eobscli,500,163);

//CODCH_COL,CCLI_COL,DTEN_COL,DTS_COL,VCH_COL,SITFINCH,CHCH_COL,NUM_COLSCH

  swchcli = gtk_scrolled_window_new(NULL,NULL);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW(swchcli),GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
  gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW(swchcli),GTK_SHADOW_ETCHED_IN);
  gtk_widget_set_usize (swchcli, 820, 180);


  treestorechcli = gtk_tree_store_new (NUM_COLSCH,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
  treewchcli =gtk_tree_view_new_with_model(GTK_TREE_MODEL (treestorechcli));
  g_object_unref(G_OBJECT(treestorechcli));
//cod che interno 
  celula = gtk_cell_renderer_text_new();
  coluna = gtk_tree_view_column_new_with_attributes("cod ch",celula,"text",CODCH_COL,NULL);
  gtk_tree_view_append_column(GTK_TREE_VIEW(treewchcli),coluna);
//ccod cliente
  celula = gtk_cell_renderer_text_new();
  coluna = gtk_tree_view_column_new_with_attributes("codcliente",celula,"text",CCLI_COL,NULL);
  //coluna.set_sort_column_id(0);
  gtk_tree_view_append_column(GTK_TREE_VIEW(treewchcli),coluna);
//entrada che 
  celula = gtk_cell_renderer_text_new();
  coluna = gtk_tree_view_column_new_with_attributes("entrada",celula,"text",DTEN_COL,NULL);
  gtk_tree_view_append_column(GTK_TREE_VIEW(treewchcli),coluna);
//gtk_cell_renderer_set_fixed_size (renderer,120,20);
//data cheque 
  celula = gtk_cell_renderer_text_new();
  coluna = gtk_tree_view_column_new_with_attributes("DATA CH",celula,"text",DTS_COL,NULL);
  gtk_tree_view_append_column(GTK_TREE_VIEW(treewchcli),coluna);
  //valor che 
 celula = gtk_cell_renderer_text_new();
  coluna = gtk_tree_view_column_new_with_attributes("valor ",celula,"text",VCH_COL,NULL);
  gtk_tree_view_append_column(GTK_TREE_VIEW(treewchcli),coluna);
  //situacao 
  celula = gtk_cell_renderer_text_new();
  coluna = gtk_tree_view_column_new_with_attributes("parcela",celula,"text",SITFINCH,NULL);
  gtk_tree_view_append_column(GTK_TREE_VIEW(treewchcli),coluna);
  //checke box 
  celula = gtk_cell_renderer_text_new();
  coluna = gtk_tree_view_column_new_with_attributes("status",celula,"text",CHCH_COL,NULL);
  gtk_tree_view_append_column(GTK_TREE_VIEW(treewchcli),coluna);
  ///destino do cheque 
  celula = gtk_cell_renderer_text_new();
  coluna = gtk_tree_view_column_new_with_attributes("destino ch",celula,"text",DESTCH_COL,NULL);
  gtk_tree_view_append_column(GTK_TREE_VIEW(treewchcli),coluna);
  gtk_scrolled_window_add_with_viewport (GTK_SCROLLED_WINDOW(swchcli),treewchcli);

  chselection  = gtk_tree_view_get_selection(GTK_TREE_VIEW(treewchcli));
  g_signal_connect(chselection, "changed",G_CALLBACK(onch_changed),NULL);


  gtk_fixed_put(GTK_FIXED(fixed),swchcli,20,280);




gtk_widget_show_all(fixed);
}
//////////////////////////////////////////////////////////////////////////////////////////////
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
//////////////////////////////////////////////////////////////////////////////////////////////////
void editcliente(void){
gtk_widget_set_sensitive(GTK_WIDGET(ecli),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(scli),TRUE);

gtk_widget_set_sensitive(GTK_WIDGET(enocli),TRUE);

gtk_widget_set_sensitive(GTK_WIDGET(eedcli),TRUE);
//int listchclientecod (gpointer treeclich,char clicod[])

gtk_widget_set_sensitive(GTK_WIDGET(ecocli),TRUE);

gtk_widget_set_sensitive(GTK_WIDGET(ebacli),TRUE);

gtk_widget_set_sensitive(GTK_WIDGET(ecicli),TRUE);

gtk_widget_set_sensitive(GTK_WIDGET(eufcli),TRUE);

gtk_widget_set_sensitive(GTK_WIDGET(et1cli),TRUE);

gtk_widget_set_sensitive(GTK_WIDGET(et2cli),TRUE);

gtk_widget_set_sensitive(GTK_WIDGET(edncli),TRUE);

gtk_widget_set_sensitive(GTK_WIDGET(ergcli),TRUE);

gtk_widget_set_sensitive(GTK_WIDGET(eemcli),TRUE);

gtk_widget_set_sensitive(GTK_WIDGET(eobscli),TRUE );

}
///////////////////////////////////////////////////////////////////////////////////////
void salvacliente(void){
char textoo[300];
sprintf(textoo,"%s",gtk_entry_get_text(GTK_ENTRY(ecpfcli)));
updatecliente("cpf",textoo,clisele);

sprintf(textoo,"%s",gtk_entry_get_text(GTK_ENTRY(enocli)));
updatecliente("nomecliente",textoo,clisele);

sprintf(textoo,"%s",gtk_entry_get_text(GTK_ENTRY(eedcli)));
updatecliente("edcliente",textoo,clisele);

sprintf(textoo,"%s",gtk_entry_get_text(GTK_ENTRY(ecocli)));
updatecliente("numend",textoo,clisele);

sprintf(textoo,"%s",gtk_entry_get_text(GTK_ENTRY(ebacli)));
updatecliente("bairro",textoo,clisele);

sprintf(textoo,"%s",gtk_entry_get_text(GTK_ENTRY(ecicli)));
updatecliente("cidade",textoo,clisele);

sprintf(textoo,"%s",gtk_entry_get_text(GTK_ENTRY(eufcli)));
updatecliente("uf",textoo,clisele);

sprintf(textoo,"%s",gtk_entry_get_text(GTK_ENTRY(et1cli)));
updatecliente("tel1",textoo,clisele);

sprintf(textoo,"%s",gtk_entry_get_text(GTK_ENTRY(et2cli)));
updatecliente("tel2",textoo,clisele);

sprintf(textoo,"%s",gtk_entry_get_text(GTK_ENTRY(edncli)));
updatecliente("dtnasc",textoo,clisele);

sprintf(textoo,"%s",gtk_entry_get_text(GTK_ENTRY(ergcli)));
updatecliente("rg",textoo,clisele);

sprintf(textoo,"%s",gtk_entry_get_text(GTK_ENTRY(eemcli)));
updatecliente("email",textoo,clisele);

  GtkTextIter start_find, end_find;

  buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (eobscli));
  gtk_text_buffer_get_start_iter(buffer, &start_find);
  gtk_text_buffer_get_end_iter(buffer, &end_find);
  /* Set the default buffer text.  
  //gtk_text_buffer_set_text (buffer,dadoscliente(clisele,13), -1);
gchar *             gtk_text_buffer_get_text            (GtkTextBuffer *buffer,
                                                         const GtkTextIter *start,
                                                         const GtkTextIter *end,
                                                         gboolean include_hidden_chars);
*/

sprintf(textoo,"%s",gtk_text_buffer_get_text(buffer,&start_find,&end_find,TRUE));
updatecliente("obs",textoo,clisele);
opencamposcliente();
gtk_widget_set_sensitive(GTK_WIDGET(ecli),TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(scli),FALSE);







}
//////////////////////////////////////////////////////////////////////////////////////
void opencliente(void){
teladetalecli();
opencamposcliente();
g_signal_handler_disconnect(closecli, handler_id);
handler_id =  g_signal_connect(G_OBJECT(closecli), "clicked",G_CALLBACK(closetelacli),NULL);
//handler_id = g_signal_connect(G_OBJECT(closecli), "clicked",G_CALLBACK(closetelalistacliente),NULL);
 g_signal_handler_disconnect(bdelcli, hander);
hander2 =  g_signal_connect(G_OBJECT(bdelcli), "clicked",G_CALLBACK(deleclidet),NULL);


}

///////////////////////////////////////////////////////////////////////////////////////
void closetelacli(void){

gtk_widget_destroy(treewchcli);
gtk_widget_destroy(eccli);
gtk_widget_destroy(enocli);
gtk_widget_destroy(ecpfcli);
gtk_widget_destroy(lccli);
gtk_widget_destroy(lcpfcli);
gtk_widget_destroy(lnocli);

gtk_widget_destroy(swchcli);
gtk_widget_destroy(lemcli);
gtk_widget_destroy(eemcli);
gtk_widget_destroy(edncli);
gtk_widget_destroy(ldncli);
gtk_widget_destroy(ledcli);
gtk_widget_destroy(eedcli);
gtk_widget_destroy(ecocli);
gtk_widget_destroy(lcocli);
gtk_widget_destroy(lbacli);
gtk_widget_destroy(ebacli);
gtk_widget_destroy(ecicli);
gtk_widget_destroy(lcicli);
gtk_widget_destroy(lufcli);
gtk_widget_destroy(eufcli);
gtk_widget_destroy(et1cli);
gtk_widget_destroy(lt1cli);
gtk_widget_destroy(et2cli);
gtk_widget_destroy(lt2cli);
gtk_widget_destroy(lobscli);
gtk_widget_destroy(lrgcli);
gtk_widget_destroy(ergcli);
gtk_widget_destroy(eobscli);
gtk_widget_set_sensitive(GTK_WIDGET(closecli) ,FALSE);
gtk_widget_destroy(barcli);
gtk_widget_destroy(barcheque);//barcheque
gtk_widget_set_sensitive(GTK_WIDGET(btcli) ,TRUE);
// g_signal_handler_disconnect(bdelcli, hander2);
//hander =  g_signal_connect(G_OBJECT(bdelcli), "clicked",G_CALLBACK(delecli),NULL);
}








void opencamposcliente(void){
//g_print(" valor = %s opencliente  \n",clisele);


listchclientecod(treestorechcli,clisele);
gtk_entry_set_text(GTK_ENTRY(eccli),dadoscliente(clisele,0));
//gtk_widget_set_sensitive(GTK_WIDGET(eccli),FALSE);


//codclich
  sprintf(codclich,"%s",dadoscliente(clisele,0));

gtk_entry_set_text(GTK_ENTRY(enocli),dadoscliente(clisele,1));
gtk_widget_set_sensitive(GTK_WIDGET(enocli),FALSE);

gtk_entry_set_text(GTK_ENTRY(ecpfcli),dadoscliente(clisele,10));
gtk_widget_set_sensitive(GTK_WIDGET(ecpfcli),FALSE);

gtk_entry_set_text(GTK_ENTRY(eedcli),dadoscliente(clisele,2));
gtk_widget_set_sensitive(GTK_WIDGET(eedcli),FALSE);
//int listchclientecod (gpointer treeclich,char clicod[])

gtk_entry_set_text(GTK_ENTRY(ecocli),dadoscliente(clisele,3));
gtk_widget_set_sensitive(GTK_WIDGET(ecocli),FALSE);

gtk_entry_set_text(GTK_ENTRY(ebacli),dadoscliente(clisele,4));
gtk_widget_set_sensitive(GTK_WIDGET(ebacli),FALSE);

gtk_entry_set_text(GTK_ENTRY(ecicli),dadoscliente(clisele,5));
gtk_widget_set_sensitive(GTK_WIDGET(ecicli),FALSE);

gtk_entry_set_text(GTK_ENTRY(eufcli),dadoscliente(clisele,6));
gtk_widget_set_sensitive(GTK_WIDGET(eufcli),FALSE);

gtk_entry_set_text(GTK_ENTRY(et1cli),dadoscliente(clisele,7));
gtk_widget_set_sensitive(GTK_WIDGET(et1cli),FALSE);

gtk_entry_set_text(GTK_ENTRY(et2cli),dadoscliente(clisele,8));
gtk_widget_set_sensitive(GTK_WIDGET(et2cli),FALSE);

gtk_entry_set_text(GTK_ENTRY(edncli),dadoscliente(clisele,9));
gtk_widget_set_sensitive(GTK_WIDGET(edncli),FALSE);

gtk_entry_set_text(GTK_ENTRY(ergcli),dadoscliente(clisele,11));
gtk_widget_set_sensitive(GTK_WIDGET(ergcli),FALSE);

gtk_entry_set_text(GTK_ENTRY(eemcli),dadoscliente(clisele,12));
gtk_widget_set_sensitive(GTK_WIDGET(eemcli),FALSE);

//gtk_entry_set_text(GTK_ENTRY(eobscli),dadoscliente(clisele,13));
 buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (eobscli));
  /* Set the default buffer text. */ 
  gtk_text_buffer_set_text (buffer,dadoscliente(clisele,13), -1);
  gtk_widget_set_sensitive(GTK_WIDGET(eobscli),FALSE);
 // gtk_widget_set_sensitive(GTK_WIDGET(delecli),FALSE);
gtk_fixed_put(GTK_FIXED(fixed),menucheque(),840,300);
//barcheque
  g_signal_connect(G_OBJECT(addche), "clicked",G_CALLBACK(telabasicach),codclich);
gtk_widget_show_all(fixed);
//  gtk_fixed_put(GTK_FIXED(fixed),menucliente(),0,0);
}

//////////////////////////////////////////////////////////////////////////////////////////
void  on_changed(GtkWidget *widget,gpointer ocli) 
{
  GtkTreeIter iter;
  GtkTreeModel *model;
  char *clisel;


  if (gtk_tree_selection_get_selected(GTK_TREE_SELECTION(widget), &model, &iter)) {

    gtk_tree_model_get(model, &iter, CODCLI_COL, &clisel,  -1);
    gtk_widget_set_sensitive(GTK_WIDGET(bdelcli),TRUE);
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
    gtk_widget_set_sensitive(GTK_WIDGET(bdelcli),FALSE);
   clisel= "";
}
}
//////////////////////////////////////////////////////////////////////////////////////////
void  onch_changed(GtkWidget *widget) 
{
  GtkTreeIter iter;
  GtkTreeModel *model;
  char *chsel;


  if (gtk_tree_selection_get_selected(GTK_TREE_SELECTION(widget), &model, &iter)) {

    gtk_tree_model_get(model, &iter,CODCH_COL, &chsel,  -1);
    //gtk_statusbar_push(GTK_STATUSBAR(statusbar), gtk_statusbar_get_context_id(GTK_STATUSBAR(statusbar), value), value);
    gtk_widget_set_sensitive(GTK_WIDGET(ediche), TRUE);
    gtk_widget_set_sensitive(GTK_WIDGET(remche), TRUE);
    
    sprintf(chsele,"%s",chsel);
  //g_print(" valor = %s \n",clisel);
    //g_print(" valor = %s \n",value);
    //g_free(value);    
    g_free(chsel);

  }
  else {
    gtk_widget_set_sensitive(GTK_WIDGET(remche), FALSE);
    gtk_widget_set_sensitive(GTK_WIDGET(ediche), FALSE);
   chsel= "";
}
}

////////////////////////////////////////////////////////////////////////////////////////
void delecli(GtkWidget *widget ,gpointer windo){

  GtkWidget *dialog;
  dialog = gtk_message_dialog_new(windowp,
            GTK_DIALOG_DESTROY_WITH_PARENT,
            GTK_MESSAGE_QUESTION,
            GTK_BUTTONS_YES_NO,
            "Are you sure to delete?");
  gtk_window_set_title(GTK_WINDOW(dialog), "Question");
  gint result = gtk_dialog_run(GTK_DIALOG(dialog));
g_print("valor %d \n ",result);
if(result == -8 ){
apagacli(clisele);
//g_print("cliente numeto  %s  apagado .\n",clisele );
scliente(ebcli,treestorecli);

}
gtk_widget_destroy (dialog);

}
void deleclidet(GtkWidget *widget ,gpointer windo){

  GtkWidget *dialog;
  dialog = gtk_message_dialog_new(windowp,
            GTK_DIALOG_DESTROY_WITH_PARENT,
            GTK_MESSAGE_QUESTION,
            GTK_BUTTONS_YES_NO,
            "Are you sure to delete?");
  gtk_window_set_title(GTK_WINDOW(dialog), "Question");
  gint result = gtk_dialog_run(GTK_DIALOG(dialog));
g_print("valor %d \n ",result);
if(result == -8 ){
apagacli(clisele);
//g_print("cliente numeto  %s  apagado .\n",clisele );
scliente(ebcli,treestorecli);

}
gtk_widget_destroy (dialog);
backtcli();
}

////////////////////////////////////////////////////////////////////////////////////////

GtkWidget *menucliente(void){


//  GtkTreeSelection *selection; 

  barcli = gtk_toolbar_new();
  gtk_widget_set_usize(barcli,400,50);
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
 // selection  = gtk_tree_view_get_selection(GTK_TREE_VIEW(treewcli));
 // g_signal_connect(selection, "changed",G_CALLBACK(on_changed),ocli);
  g_signal_connect(G_OBJECT(ocli), "clicked",G_CALLBACK(opencliente),NULL);
  g_signal_connect(G_OBJECT(ncli), "clicked",G_CALLBACK(novcli),NULL);
  g_signal_connect(G_OBJECT(ecli), "clicked",G_CALLBACK(editcliente),NULL);
  g_signal_connect(G_OBJECT(scli), "clicked",G_CALLBACK(salvacliente),NULL);
  g_signal_connect(G_OBJECT(backlcli), "clicked",G_CALLBACK(backtcli),NULL);
 hander =  g_signal_connect(G_OBJECT(bdelcli),"clicked",G_CALLBACK(delecli),barcli);
//handler_id =  g_signal_connect(G_OBJECT(closecli), "clicked",G_CALLBACK(closetelacli),NULL);
handler_id = g_signal_connect(G_OBJECT(closecli), "clicked",G_CALLBACK(closetdcli),NULL);


 //g_signal_handler_disconnect(closecli, handler_id);


//  g_signal_connect(G_OBJECT(ebcli), "changed",G_CALLBACK(scliente),treestorecli);

return barcli;
}
////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int maskcpf(GtkWidget *widget,GdkEventKey *event,gpointer *poi){
//(widget, event, user_param1, ...)
//  gchar *s;
//  s = gtk_entry_get_text(GTK_ENTRY(ebcli));
// g_print("keyval=%d" ,event->keyval);
char tt[20];
//int i = gtk_entry_get_text_length(GTK_ENTRY(ebcli));
gint *j;
	
   //gtk_editable_get_position           (GtkEditable *editable);
//gtk_entry_buffer_get_length (gtk_entry_get_buffer(ebcli));
if(event->keyval == 65288){ //g_print("erro");
bak=0;}else {
j = gtk_editable_get_position(widget); 
//sprintf(tt,"%s",gtk_entry_get_text(GTK_ENTRY(ebcli)));
if( j == 3) { 
//j = tt[0];
//sscanf(tt[0],"%d",&j);
//g_print ("j = %d",j);

sprintf(tt,"%s.",gtk_entry_get_text(GTK_ENTRY(widget)));
//gtk_entry_set_text(tt)
gtk_entry_set_text(GTK_ENTRY(widget),tt);
gtk_editable_set_position(GTK_ENTRY(widget),4); 


}
if( j == 7) { 
//j = tt[0];
//sscanf(tt[0],"%d",&j);
//g_print ("j = %d",j);

sprintf(tt,"%s.",gtk_entry_get_text(GTK_ENTRY(widget)));
//gtk_entry_set_text(tt)
gtk_entry_set_text(GTK_ENTRY(widget),tt);
gtk_editable_set_position(GTK_ENTRY(widget),8); 


}
if( j == 11) { 
//j = tt[0];
//sscanf(tt[0],"%d",&j);
//g_print ("j = %d",j);

sprintf(tt,"%s-",gtk_entry_get_text(GTK_ENTRY(widget)));
//gtk_entry_set_text(tt)
gtk_entry_set_text(GTK_ENTRY(widget),tt);
gtk_editable_set_position(GTK_ENTRY(widget),12); 


}


}
//if (event->length > 0){

//}
//printf("The key event's string is `%s'\n", event->string);
//printf("The name of this keysym is `%s'\n",gdk_keyval_name(event->keyval));
//g_print ("evente = %d",event);
//}
/*

char textt[20];
// j,k,l,m,n,o,p,q,r,s,t,u,v,x;
//char a,b,c,d
sprintf(tt,"%s",gtk_entry_get_text(GTK_ENTRY(ebcli)));
//sscanf(texto,"%d%d%d%c%d%d%d%c%d%d%d%c%d%d",&j,&k,&l);
//int i = length(tt);

g_print("tamnho do string %d \n ",i+1);
//sprintf(textt,"%c%c%c.%c",tt[0],tt[1],tt[2],tt[3]);
//sscanf(string1, "%d %d %d", &i, &j, &k);}
if (i == 4){
sprintf(textt,"%s%s",);


}

//gtk_entry_set_text(GTK_ENTRY(ebcli),textt);
else if (i ==3 ){
sprintf(textt,"%s.",gtk_entry_get_text(GTK_ENTRY(ebcli)));
gtk_entry_set_text(GTK_ENTRY(ebcli),textt);
gtk_entry_select_region(GTK_ENTRY(ebcli),4,5);

//

}
//if (event->length > 0)
   // printf("The key event's string is `%s'\n", event->string);

//  printf("The name of this keysym is `%s'\n",gdk_keyval_name(event->keyval));
//sprintf(textt,"%s%s",gtk_entry_get_text(GTK_ENTRY(ebcli)),event->string);
//gtk_entry_set_text(GTK_ENTRY(ebcli),textt);
 /* switch (event->keyval)
    {
    case GDK_Home:
      printf("The Home key was pressed.\n");
      break;
    case GDK_Up:
      printf("The Up arrow key was pressed.\n");
      break;
    default:
      break;
    }

  if (gdk_keyval_is_lower(event->keyval))
    {
      printf("A non-uppercase key was pressed.\n");
    }
  else if (gdk_keyval_is_upper(event->keyval))
    {
    
      printf("An uppercase letter was pressed.\n");
    }
*/

 //
return 0;
}
/////////////////////////////////////////////////////////////////////////////////////////////

int telacliente(GtkWidget *btclic){

  gtk_widget_set_sensitive(GTK_WIDGET(btclic), FALSE);



  gtk_fixed_put(GTK_FIXED(fixed),menucliente(),0,0);

  lebcli = gtk_label_new("cliente :");

  gtk_fixed_put(GTK_FIXED(fixed),lebcli,240,17);
  ebcli= gtk_entry_new();
  gtk_fixed_put(GTK_FIXED(fixed),ebcli,300,12);


  swcli = gtk_scrolled_window_new(NULL,NULL);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW(swcli),GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
  gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW(swcli),GTK_SHADOW_ETCHED_IN);
  gtk_widget_set_usize (swcli, 820, 360);


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

//  menucliente(treewcli,fixed);



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
  g_signal_connect(G_OBJECT(ebcli), "key-release-event",G_CALLBACK(maskcpf),NULL);
  //g_signal_connect(G_OBJECT(ebcli), "backspace",G_CALLBACK(baks),NULL);
//desativado



  selection  = gtk_tree_view_get_selection(GTK_TREE_VIEW(treewcli));
  g_signal_connect(selection, "changed",G_CALLBACK(on_changed),ocli);

  g_signal_connect(G_OBJECT(treewcli),"row-activated",G_CALLBACK(opencliente),NULL);


  scliente(ebcli,treestorecli);
  gtk_widget_grab_focus(ebcli);
  //gtk_widget_show(treewcli);
  gtk_widget_show_all(fixed);





return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////////
GtkWidget *menusup (void){


  toolbar = gtk_toolbar_new();
  gtk_toolbar_set_style(GTK_TOOLBAR(toolbar), GTK_TOOLBAR_ICONS);
  //gtk_toolbar_set_orientation(GTK_TOOLBAR(toolbar), GTK_ORIENTATION_VERTICAL);
  gtk_container_set_border_width(GTK_CONTAINER(toolbar), 2);

  btcli = gtk_tool_button_new_from_stock(GTK_STOCK_ORIENTATION_PORTRAIT);
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar),btcli, -1);

  open = gtk_tool_button_new_from_stock(GTK_STOCK_OPEN);
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), open, -1);

  save = gtk_tool_button_new_from_stock(GTK_STOCK_SAVE);
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), save, -1);

  sep = gtk_separator_tool_item_new();
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), sep, -1); 

  btexit = gtk_tool_button_new_from_stock(GTK_STOCK_QUIT);
  gtk_toolbar_insert(GTK_TOOLBAR(toolbar), btexit, -1);

  g_signal_connect_swapped(G_OBJECT(btexit), "clicked",G_CALLBACK(gtk_main_quit),NULL);

  g_signal_connect_swapped(G_OBJECT(btcli), "clicked",G_CALLBACK(telacliente),btcli);

  //g_signal_connect_swapped(G_OBJECT(save), "clicked",G_CALLBACK(test),NULL);

  //g_signal_connect(G_OBJECT(cliente), "clicked",G_CALLBACK(telacliente),fixed);



  //g_signal_connect(G_OBJECT(open), "clicked",G_CALLBACK(menusp),vboxp);


return toolbar;

}


///////////////////////////////////////////////////////////////////////////////////



int telabasica(gpointer window){

  windowp = window;
  //cria box horizontal 
  vbox = gtk_vbox_new(FALSE, 0);
  //adiciona box horizontal a janela 
  gtk_container_add(GTK_CONTAINER(window),vbox);

  fixed = gtk_fixed_new();

//  menusup(vbox,fixed,1);
  gtk_box_pack_start(GTK_BOX(vbox),menusup(), FALSE, FALSE, 1);

  gtk_box_pack_start(GTK_BOX(vbox),fixed,FALSE,FALSE,1);


  gtk_widget_show(fixed);

  g_signal_connect_swapped(G_OBJECT(window), "destroy",G_CALLBACK(gtk_main_quit), NULL);



  gtk_widget_show_all(window);

  gtk_main();

return 0;
}


