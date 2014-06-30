#include <gtk/gtk.h>
#include <stdio.h>
#include "con.h"


//                        telach 

GtkWidget *fixedch;
GtkWidget *windowch;
char codclich[20];
char chequeselec[20];
GtkTextBuffer *buffer;
GtkWidget *combocxd;
GtkWidget *btsd,*btsch,*btpch,*btech,*btfech,*btnch;
GtkWidget *lncli,*lbanco,*lagencia,*lconta,*lnche,*lvalor,*ldataatual,*ldatach,*lcxdest,*lparc;
GtkWidget *ebanco,*eagencia,*econta,*enche,*evalor,*edataatual,*edatach,*eparc;

///////////////////////////////////////////////////////////////////////////////
int telabasicach( GtkWidget *widget ,char codcliu[]);
void salvacheque(void);
void novcheque(void);
void salvacombobox(void);
/////////////////////////////////////////////////////////////////////////////
void fechajanelach(void){

gtk_widget_destroy(windowch);



}

void eddch(void){
  gtk_widget_set_sensitive(GTK_WIDGET(ebanco),TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(eagencia),TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(econta),TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(enche),TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(evalor),TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(eparc),TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(edataatual),TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(edatach),TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(btsch),TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(btech),FALSE);
gtk_widget_show_all(fixedch);
}





void camposche(gpointer fixedch){

lncli = gtk_label_new(dadoscliente(codclich,1));
gtk_fixed_put(GTK_FIXED(fixedch),lncli,10,10);

//  lrgcli = gtk_label_new("rg :");
//  gtk_fixed_put(GTK_FIXED(fixed),lrgcli,243,203);
//  ergcli = gtk_entry_new();
//  gtk_fixed_put(GTK_FIXED(fixed),ergcli,275,196);

  lbanco = gtk_label_new("banco :");
  gtk_fixed_put(GTK_FIXED(fixedch),lbanco,5,55);
  ebanco = gtk_entry_new();
  gtk_widget_set_size_request(GTK_WIDGET(ebanco),45,30);
  gtk_fixed_put(GTK_FIXED(fixedch),ebanco,60,50);

  lagencia = gtk_label_new("agencia : ");
  gtk_fixed_put(GTK_FIXED(fixedch),lagencia,110,55);
  eagencia=gtk_entry_new();  gtk_widget_set_size_request(GTK_WIDGET(eagencia),60,30);
  gtk_fixed_put(GTK_FIXED(fixedch),eagencia,175,50);

  lconta = gtk_label_new("conta :");
  gtk_fixed_put(GTK_FIXED(fixedch),lconta,250,55);
  econta = gtk_entry_new();
  gtk_fixed_put(GTK_FIXED(fixedch),econta,300,50);

  lnche = gtk_label_new("n. ch :");
  gtk_fixed_put(GTK_FIXED(fixedch),lnche,470,55);
  enche = gtk_entry_new();
  gtk_fixed_put(GTK_FIXED(fixedch),enche,530,50);

  lvalor = gtk_label_new("valor :");
  gtk_fixed_put(GTK_FIXED(fixedch),lvalor,10,105);
  evalor = gtk_entry_new();
  gtk_fixed_put(GTK_FIXED(fixedch),evalor,60,100);

  ldataatual = gtk_label_new("data ent. :");
  gtk_fixed_put(GTK_FIXED(fixedch),ldataatual,230,105);
  edataatual = gtk_entry_new();
  gtk_fixed_put(GTK_FIXED(fixedch),edataatual,300,100);

  ldatach = gtk_label_new("data cheque : ");
  gtk_fixed_put(GTK_FIXED(fixedch),ldatach,480,105);
  edatach = gtk_entry_new();
  gtk_fixed_put(GTK_FIXED(fixedch),edatach,570,100);

  lcxdest = gtk_label_new("cx dest :");
  gtk_fixed_put(GTK_FIXED(fixedch),lcxdest,10,145);


  combocxd = gtk_combo_box_new_text();
  listcombocx(combocxd);
  //gtk_combo_box_set_active(GTK_COMBO_BOX(combocxd),1);
  gtk_fixed_put(GTK_FIXED(fixedch),combocxd,70,140);

  lparc = gtk_label_new("parcela : ");
  gtk_fixed_put(GTK_FIXED(fixedch),lparc,200,145);
  eparc = gtk_entry_new();
   gtk_widget_set_size_request(GTK_WIDGET(eparc),45,30);
  gtk_fixed_put(GTK_FIXED(fixedch),eparc,270,140);

  btsd = gtk_button_new_with_label("salva dest");
  gtk_widget_set_size_request(btsd, 80, 35);
  gtk_fixed_put(GTK_FIXED(fixedch), btsd,60,180);


  btsch = gtk_button_new_with_label("salvar");
  //gtk_widget_set_size_request(btsd, 80, 35);
  gtk_widget_set_sensitive(GTK_WIDGET(btsch),FALSE);
  gtk_fixed_put(GTK_FIXED(fixedch), btsch,180,180);

  btnch = gtk_button_new_with_label("novo");
  //gtk_widget_set_size_request(btsd, 80, 35);
//  gtk_widget_set_sensitive(GTK_WIDGET(btsch),FALSE);
  gtk_fixed_put(GTK_FIXED(fixedch), btnch,420,180);


  btpch = gtk_button_new_with_label(" proximo ");
 // gtk_widget_set_size_request(btsd, 80, 35);
  gtk_widget_set_sensitive(GTK_WIDGET(btpch),FALSE);
  gtk_fixed_put(GTK_FIXED(fixedch), btpch,240,180);

  btech = gtk_button_new_with_label("editar");
//  gtk_widget_set_size_request(btsd, 80, 35);
  gtk_widget_set_sensitive(GTK_WIDGET(btech),FALSE);
  gtk_fixed_put(GTK_FIXED(fixedch),btech,330,180);

  btfech = gtk_button_new_with_label("Fechar");
  gtk_widget_set_size_request(btfech, 150, 80);
  gtk_fixed_put(GTK_FIXED(fixedch), btfech,600,140);
  g_signal_connect_swapped(G_OBJECT(btfech), "clicked",G_CALLBACK(fechajanelach),NULL);
  g_signal_connect_swapped(G_OBJECT(btsch), "clicked",G_CALLBACK(salvacheque),NULL);
  g_signal_connect_swapped(G_OBJECT(btnch),"clicked",G_CALLBACK(novcheque),NULL);
  g_signal_connect_swapped(G_OBJECT(btsd),"clicked",G_CALLBACK(salvacombobox),NULL);
// eddch
 g_signal_connect_swapped(G_OBJECT(btech),"clicked",G_CALLBACK(eddch),NULL);
gtk_widget_show_all(fixedch);
  gtk_widget_grab_focus(ebanco);


}
void salvacheque(void) {
//sprintf(chequeselec,"%s",);
//updatechquecampo("idcliente",codclich,chequeselec);
//updatechquecampo("dest","0",chequeselec);
char textoo[300];
sprintf(textoo,"%s",gtk_entry_get_text(GTK_ENTRY(ebanco)));
updatechquecampo("banco",textoo,chequeselec);
sprintf(textoo,"%s",gtk_entry_get_text(GTK_ENTRY(eagencia)));
updatechquecampo("agencia",textoo,chequeselec);
sprintf(textoo,"%s",gtk_entry_get_text(GTK_ENTRY(econta)));
updatechquecampo("cta",textoo,chequeselec);
sprintf(textoo,"%s",gtk_entry_get_text(GTK_ENTRY(enche)));
updatechquecampo("ncheque",textoo,chequeselec);
sprintf(textoo,"%s",gtk_entry_get_text(GTK_ENTRY(evalor)));
updatechquecampo("valor",textoo,chequeselec);
sprintf(textoo,"%s",gtk_entry_get_text(GTK_ENTRY(eparc)));
updatechquecampo("idparc",textoo,chequeselec);
sprintf(textoo,"%s",gtk_entry_get_text(GTK_ENTRY(edataatual)));
updatechquecampo("entdata",textoo,chequeselec);
sprintf(textoo,"%s",gtk_entry_get_text(GTK_ENTRY(edatach)));
updatechquecampo("saidata",textoo,chequeselec);
gtk_widget_set_sensitive(GTK_WIDGET(btsch),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(btech),TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(ebanco),FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(eagencia),FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(econta),FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(enche),FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(evalor),FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(eparc),FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(edataatual),FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(edatach),FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(btsch),FALSE);
 // gtk_widget_set_sensitive(GTK_WIDGET(btech),FALSE);




}


void novcheque(void){
//char chequeselec[100];
sprintf(chequeselec,"%s",newcheque());

updatechquecampo("idcliente",codclich,chequeselec);
updatechquecampo("dest","0",chequeselec);
char textoo[300];
sprintf(textoo,"%s",gtk_entry_get_text(GTK_ENTRY(ebanco)));
updatechquecampo("banco",textoo,chequeselec);
sprintf(textoo,"%s",gtk_entry_get_text(GTK_ENTRY(eagencia)));
updatechquecampo("agencia",textoo,chequeselec);
sprintf(textoo,"%s",gtk_entry_get_text(GTK_ENTRY(econta)));
updatechquecampo("cta",textoo,chequeselec);
sprintf(textoo,"%s",gtk_entry_get_text(GTK_ENTRY(enche)));
updatechquecampo("ncheque",textoo,chequeselec);
sprintf(textoo,"%s",gtk_entry_get_text(GTK_ENTRY(evalor)));
updatechquecampo("valor",textoo,chequeselec);
sprintf(textoo,"%s",gtk_entry_get_text(GTK_ENTRY(eparc)));
updatechquecampo("idparc",textoo,chequeselec);
sprintf(textoo,"%s",gtk_entry_get_text(GTK_ENTRY(edataatual)));
updatechquecampo("entdata",textoo,chequeselec);
sprintf(textoo,"%s",gtk_entry_get_text(GTK_ENTRY(edatach)));
updatechquecampo("saidata",textoo,chequeselec);

  gtk_widget_set_sensitive(GTK_WIDGET(btsch),TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(btech),TRUE);
  gtk_widget_set_sensitive(GTK_WIDGET(ebanco),FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(eagencia),FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(econta),FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(enche),FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(evalor),FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(eparc),FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(edataatual),FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(edatach),FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(btsch),FALSE);
  gtk_widget_set_sensitive(GTK_WIDGET(btnch),FALSE);
//  gtk_widget_set_se
}

void acheque(GtkWidget *widget, gchar chequesel[]){

//g_print("idche = %s \n ",chequesel);

sprintf(chequeselec,"%s",chequesel);
//g_print("idche = %s \n ",dadosche(chequesel,7));

telabasicach(widget,dadosche(chequesel,7));


gtk_entry_set_text(GTK_ENTRY(ebanco),dadosche(chequesel,2));
gtk_widget_set_sensitive(GTK_WIDGET(ebanco),FALSE);

gtk_entry_set_text(GTK_ENTRY(eagencia),dadosche(chequesel,3));
gtk_widget_set_sensitive(GTK_WIDGET(eagencia),FALSE);

gtk_entry_set_text(GTK_ENTRY(econta),dadosche(chequesel,4));
gtk_widget_set_sensitive(GTK_WIDGET(econta),FALSE);

gtk_entry_set_text(GTK_ENTRY(enche),dadosche(chequesel,5));
gtk_widget_set_sensitive(GTK_WIDGET(enche),FALSE);

gtk_entry_set_text(GTK_ENTRY(evalor),dadosche(chequesel,6));
gtk_widget_set_sensitive(GTK_WIDGET(evalor),FALSE);

gtk_entry_set_text(GTK_ENTRY(edataatual),dadosche(chequesel,10));
gtk_widget_set_sensitive(GTK_WIDGET(edataatual),FALSE);

gtk_entry_set_text(GTK_ENTRY(eparc),dadosche(chequesel,8));
gtk_widget_set_sensitive(GTK_WIDGET(eparc),FALSE);

gtk_entry_set_text(GTK_ENTRY(edatach),dadosche(chequesel,11));
gtk_widget_set_sensitive(GTK_WIDGET(edatach),FALSE);

gtk_widget_set_sensitive(GTK_WIDGET(btsd),TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(btsch),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(btech),TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(btsch),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(btnch),FALSE);

int t,j ;
//int i, j, k;
//char string1[] = "10 20 30";
//sscanf(string1, "%d %d %d", &i, &j, &k);
//char string1[20]  = dadosche(chequesel,9);
sscanf(dadosche(chequesel,9),"%d",&j);
t = j -1;
//g_print("numeto t = %d \n ", t);
gtk_combo_box_set_active(GTK_COMBO_BOX(combocxd),t);
gtk_widget_set_sensitive(GTK_WIDGET(combocxd),TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(btsd),TRUE);
if ( t >= 0 && t < 100){
gtk_widget_set_sensitive(GTK_WIDGET(combocxd),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(btsd),FALSE);

}



}
void salvacombobox(void){
gint comv;
char com[5];
gint i =gtk_combo_box_get_active(GTK_COMBO_BOX(combocxd));
comv = i +1 ;
if (comv > 0) {
sprintf(com,"%d",comv);
updatechquecampo("dest",com,chequeselec);
gtk_widget_set_sensitive(GTK_WIDGET(btsd),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(combocxd),FALSE);
}



}







void fechatelach (void){
gtk_widget_destroy(windowch);
}

int telabasicach( GtkWidget *widget ,char codcliu[])
{


  sprintf(codclich,"%s",codcliu);

  windowch = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_position(GTK_WINDOW(windowch), GTK_WIN_POS_CENTER);
  gtk_window_set_default_size(GTK_WINDOW(windowch), 900, 250);
  gtk_window_set_title(GTK_WINDOW(windowch), "Cheque");

  fixedch = gtk_fixed_new();
  gtk_container_add(GTK_CONTAINER(windowch),fixedch);

  gtk_widget_show(fixedch);
  g_signal_connect_swapped(G_OBJECT(windowch), "destroy",G_CALLBACK(fechatelach), NULL);
  camposche(fixedch);
  gtk_widget_set_sensitive(GTK_WIDGET(btsd),FALSE);
  gtk_widget_show_all(windowch);


  return 0;
}



