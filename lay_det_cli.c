#include <gtk/gtk.h>
#include "fuc_cli.h"
#include "layout.h"
#include "lay_lista_cli.h"
#include "maskcpf.h"

//tela cheque 
enum{CODCH_COL,CCLI_COL,DTEN_COL,DTS_COL,VCH_COL,SITFINCH,CHCH_COL,DESTCH_COL,COL_ICON,NUM_COLSCH};

GtkWidget *lccli,*lnocli,*lt1cli,*ledcli,*lcocli,*lbacli,*lcicli,*lufcli,*lt2cli,*ldncli,*lcpfcli,*lrgcli,*lemcli,*lobscli;
GtkWidget *eccli,*enocli,*et1cli,*eedcli,*ecocli,*ebacli,*ecicli,*eufcli,*et2cli,*edncli,*ecpfcli,*ergcli,*eemcli;
GtkWidget *barcheque;
GtkToolItem *addche,*remche,*ediche;
GtkWindow *windowp;
GtkWidget *treewchcli;
GtkWidget *swchcli;
GtkTreeStore *treestorechcli;
GtkWidget *eobscli;
GtkTextBuffer *buffer;










void teladetalecli (void){

  gtk_widget_set_sensitive(GTK_WIDGET(ocli),FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(ncli),FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(ecli),TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(backlcli),TRUE);
//g_print(" valor = %s and  \n",clisele);

limpatelalistaclienteparatelacheque();


  lccli= gtk_label_new("codigo :");
  gtk_fixed_put(GTK_FIXED(fixed),lccli,340,20);
  eccli = gtk_entry_new();
  gtk_widget_set_size_request(GTK_WIDGET(eccli),50,30);
  gtk_widget_set_sensitive(GTK_WIDGET(eccli),FALSE);
  gtk_fixed_put(GTK_FIXED(fixed),eccli,398,13);

  lcpfcli = gtk_label_new("cpf :");
  gtk_fixed_put(GTK_FIXED(fixed),lcpfcli,450,20);
  ecpfcli = gtk_entry_new();
  //gtk_widget_set_sensitive(GTK_WIDGET(ecpfcli),FALSE);
  gtk_fixed_put(GTK_FIXED(fixed),ecpfcli,490,13);

 g_signal_connect(G_OBJECT(ecpfcli), "key-release-event",G_CALLBACK(maskcpf),NULL);
//label = gtk_label_new (NULL);
//gtk_label_set_markup (GTK_LABEL (label), "<small>Small text</small>");

 lnocli = gtk_label_new("nome cli :");
// lnocli = gtk_label_new(NULL);
/// gtk_label_set_markup(GTK_LABEL(lnocli), "<big><span color='red'><b> nome cli : </b></span> </big> ");  
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
  gtk_widget_set_usize (swchcli, 820, 280);


  listpgclientecod(swchcli,clisele);

  gtk_fixed_put(GTK_FIXED(fixed),swchcli,20,280);




gtk_widget_show_all(fixed);
}

void opencamposcliente(void){
//g_print(" valor = %s opencliente  \n",clisele);


//listchclientecod(treestorechcli,clisele);
gtk_entry_set_text(GTK_ENTRY(eccli),dadoscliente(clisele,0));
//gtk_widget_set_sensitive(GTK_WIDGET(eccli),FALSE);


//codclich
  //sprintf(codclich,"%s",dadoscliente(clisele,0));

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
//gtk_fixed_put(GTK_FIXED(fixed),menucheque(),840,300);
//barcheque
  //g_signal_connect(G_OBJECT(addche), "clicked",G_CALLBACK(telabasicach),codclich);
gtk_widget_show_all(fixed);
//  gtk_fixed_put(GTK_FIXED(fixed),menucliente(),0,0);
}







void apagarcamposdetalecliente(void){

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
//gtk_widget_set_sensitive(GTK_WIDGET(closecli) ,FALSE);
//gtk_widget_destroy(barcli);
//gtk_widget_destroy(barcheque);//barcheque
//gtk_widget_set_sensitive(GTK_WIDGET(btcli) ,TRUE);
// g_signal_handler_disconnect(bdelcli, hander2);
//g_signal_connect(G_OBJECT(bdelcli), "clicked",G_CALLBACK(delecli),NULL);





}
void fechateladetalecliente(void){

apagarcamposdetalecliente();

gtk_widget_destroy(barcli);

gtk_widget_set_sensitive(GTK_WIDGET(botaocliente),TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(btproduto),TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(vendastotal),TRUE);



}

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





void salvacliente(void){
char textoo[300];
sprintf(textoo,"%s",gtk_entry_get_text(GTK_ENTRY(ecpfcli)));
updatecliente("cpf_cliente",textoo,clisele);

sprintf(textoo,"%s",gtk_entry_get_text(GTK_ENTRY(enocli)));
updatecliente("nome_cliente",textoo,clisele);

sprintf(textoo,"%s",gtk_entry_get_text(GTK_ENTRY(eedcli)));
updatecliente("ed_cliente",textoo,clisele);

sprintf(textoo,"%s",gtk_entry_get_text(GTK_ENTRY(ecocli)));
updatecliente("num_end_cliente",textoo,clisele);

sprintf(textoo,"%s",gtk_entry_get_text(GTK_ENTRY(ebacli)));
updatecliente("bairro_cliente",textoo,clisele);

sprintf(textoo,"%s",gtk_entry_get_text(GTK_ENTRY(ecicli)));
updatecliente("cidade_cliente",textoo,clisele);

sprintf(textoo,"%s",gtk_entry_get_text(GTK_ENTRY(eufcli)));
updatecliente("uf_cliente",textoo,clisele);

sprintf(textoo,"%s",gtk_entry_get_text(GTK_ENTRY(et1cli)));
updatecliente("tel1_cliente",textoo,clisele);

sprintf(textoo,"%s",gtk_entry_get_text(GTK_ENTRY(et2cli)));
updatecliente("tel2_cliente",textoo,clisele);

sprintf(textoo,"%s",gtk_entry_get_text(GTK_ENTRY(edncli)));
updatecliente("dtnasc_cliente",textoo,clisele);

sprintf(textoo,"%s",gtk_entry_get_text(GTK_ENTRY(ergcli)));
updatecliente("rg_cliente",textoo,clisele);

sprintf(textoo,"%s",gtk_entry_get_text(GTK_ENTRY(eemcli)));
updatecliente("email_cliente",textoo,clisele);

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
updatecliente("obs_cliente",textoo,clisele);
opencamposcliente();
gtk_widget_set_sensitive(GTK_WIDGET(ecli),TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(scli),FALSE);







}







void voltateladecliente(void){

//salvacliente();

apagarcamposdetalecliente();

listadecliente();

//
//
//
gtk_widget_set_sensitive(GTK_WIDGET(bdelcli),FALSE);
//gtk_widget_set_sensitive(GTK_WIDGET(salvacliente),FALSE);

g_signal_handler_disconnect(closecli, handler_id);

handler_id =  g_signal_connect(G_OBJECT(closecli), "clicked",G_CALLBACK(limpatelalistacliente),NULL);

gtk_widget_set_sensitive(GTK_WIDGET(backlcli),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(ncli),TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(ecli),FALSE);
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
//g_print("valor %d \n ",result);
if(result == -8 ){
apagacli(clisele);
g_print("cliente numeto  %s  apagado .\n",clisele );
scliente(ebcli,treestorecli);

}
gtk_widget_destroy (dialog);
voltateladecliente();
}


void opencliente(void){

teladetalecli();


opencamposcliente();

gtk_widget_set_sensitive(GTK_WIDGET(bdelcli),TRUE);

g_signal_handler_disconnect(closecli, handler_id);
handler_id =  g_signal_connect(G_OBJECT(closecli), "clicked",G_CALLBACK(fechateladetalecliente),NULL);


//handler_id = g_signal_connect(G_OBJECT(closecli), "clicked",G_CALLBACK(closetelalistacliente),NULL);
// g_signal_handler_disconnect(bdelcli, hander);
//hander2 =  g_signal_connect(G_OBJECT(bdelcli), "clicked",G_CALLBACK(deleclidet),NULL);


}








