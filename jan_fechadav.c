#include "jan_fechadav.h"
#include <stdlib.h>


enum {COL_IPAY,COL_TPCONTA,COL_PARC,COL_VALOR,COL_DATAI,COL_DATAP,COL_CX,COL_ICO,COL_COR,NUM_COLU};

void editanota(void){
if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(checknt)))
{
gtk_widget_set_sensitive(GTK_WIDGET(enumnot),TRUE);
gtk_widget_grab_focus(GTK_WIDGET(enumnot));

}else {

gtk_widget_set_sensitive(GTK_WIDGET(enumnot),FALSE);
}

}



void listatppg(void){



MYSQL_RES *rep;
MYSQL_ROW ls;

char sqll[1000];
sprintf(sqll,"SELECT * FROM tb_tp_conta  WHERE fator_mult >0;");
  if (mysql_query(&conexao,sqll))
      g_print("Erro: %s\n",mysql_error(&conexao));
  else
    {
    rep = mysql_store_result(&conexao);//recebe a consulta
    if (rep) //se houver consulta
        {
           while ((ls=mysql_fetch_row(rep)) != NULL)  //enquanto linhas for diferente de nulo faca 
                {
                        /*sprintf(strcom," ");
                        strcat(strcom,ls[4]);
                        strcat(strcom," = ");
                        strcat(strcom,ls[3]);*/
                        gtk_combo_box_append_text(GTK_COMBO_BOX(cbtppg), ls[1]);
                       // gra=1;
                        //f++;
              }


          }
          mysql_free_result(rep);//limpa a variável do resultado: resp
        }



}






void enterf(GtkWidget *widget,GdkEventKey *event){
g_print("tecla %d\n ",event->keyval);
if(event->keyval ==65476){
 gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checknt),TRUE);
editanota();



}






if(event->keyval == 65477){


gtk_widget_set_sensitive(GTK_WIDGET(etotal),TRUE);
gtk_widget_grab_focus(GTK_WIDGET(etotal));



}

if(event->keyval == 65293){

gtk_widget_grab_focus(GTK_WIDGET(cbtppg));





}






}
void comboenter(GtkWidget *widget,GdkEventKey *event){
//g_print("tecla %d\n ",event->keyval);

if(event->keyval == 65293){

gtk_widget_grab_focus(GTK_WIDGET(eparc));





}






}


void parcenter(GtkWidget *widget,GdkEventKey *event){
//g_print("tecla %d\n ",event->keyval);

if(event->keyval == 65293){

gtk_widget_grab_focus(GTK_WIDGET(btaddpg));
// ou finaliza direto 
}
}
void listapagamentos(void){
int davnumero;
GtkTreeIter    iter;
GdkPixbuf     *icon;
GError        *error = NULL;
GdkColor color;
                int idpgst;
                char data[20],datae[20];
                int ano,mes,dia,hora,min,seg;
char parce[10];
char valor[13];

int idtppg;
char tpdepag[20];
int cx;
char desccx[25];
char svalori[20];
double valorpg;
double valorre;
char svalorre[20];
double valorsomado=0;

sscanf(gtk_label_get_text(GTK_LABEL(lnumdav)),"%d",&davnumero);

gtk_list_store_clear(listtore);

MYSQL_RES *resp;
MYSQL_ROW linhas;

sprintf(svalori,"%s",gtk_entry_get_text(GTK_ENTRY(etotal)));
char *pvalor= str_replace(svalori,".", ",");
valorpg = strtod(pvalor,NULL);

char sql[ 1000 ];

sprintf(sql,"SELECT * FROM tb_payment WHERE cod_dav = '%d' AND numemp ='%d' ; ",davnumero,numep());


  if (mysql_query(&conexao,sql))
      g_print("Erro: %s\n",mysql_error(&conexao));
  else
    {
    resp = mysql_store_result(&conexao);//recebe a consulta
    if (resp) //se houver consulta
        {
          while ((linhas=mysql_fetch_row(resp)) != NULL)  //enquanto linhas for diferente de nulo faca 
              {

                sscanf(linhas[11],"%d",&idpgst);
                sscanf(linhas[8],"%d-%d-%d %d:%d:%d",&ano,&mes,&dia,&hora,&min,&seg);
                sprintf(data,"%d/%d/%d",dia,mes,ano);
                sscanf(linhas[7],"%d-%d-%d %d:%d:%d",&ano,&mes,&dia,&hora,&min,&seg);
                sprintf(datae,"%d/%d/%d",dia,mes,ano);
                sprintf(parce,"%s",linhas[6]);
                sprintf(valor,"%s",linhas[5]);
                sscanf(linhas[3],"%d",&idtppg);
                sscanf(linhas[13],"%d",&cx);

sprintf(svalorre,"%s",valor);
char *pvalorre= str_replace(svalorre,".", ",");

valorre = strtod(pvalorre,NULL);

valorsomado = valorsomado + valorre;


                MYSQL_RES *respe;
                MYSQL_ROW linhase;

                char sqle[1000];


                sprintf(sqle,"SELECT * FROM tb_tp_conta WHERE icod_tp_conta ='%d';",idtppg);
                if (mysql_query(&conexao,sqle))
                        g_print("Erro: %s\n",mysql_error(&conexao));
                else
                        {
                                respe = mysql_store_result(&conexao);//recebe a consulta
                                if (respe) //se houver consulta
                                        {
                                                while ((linhase=mysql_fetch_row(respe)) != NULL)  //enquanto linhas for diferente de nulo faca 
                                                        {
                                                                sprintf(tpdepag,"%s",linhase[1]);
                                                        }
                                        }
                                mysql_free_result(respe);//limpa a variável do resultado: resp
                        }

                MYSQL_RES *repe;
                MYSQL_ROW line;

                char sqlee[1000];

//g_print(" dinheiro = %d desc %s ",idtppg,tpdepag);

                sprintf(sqlee,"SELECT * FROM tb_caixas WHERE numemp ='%d' AND i_cod_cx ='%d';",numep(),cx);
                if (mysql_query(&conexao,sqlee))
                        g_print("Erro: %s\n",mysql_error(&conexao));
                else
                        {
                                repe = mysql_store_result(&conexao);//recebe a consulta
                                if (repe) //se houver consulta
                                        {
                                                while ((line=mysql_fetch_row(repe)) != NULL)  //enquanto linhas for diferente de nulo faca 
                                                        {
                                                                sprintf(desccx,"%s",line[2]);
                                                        }
                                        }
                                mysql_free_result(repe);//limpa a variável do resultado: resp
                        }
//g_print ("\n\n\n                                             idpgst = %d \n\n\n ",idpgst);

                if(idpgst == 1)
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
                else if (idpgst == 2 )
                        {
////g_print ("                  //carregado o  = %d \n\n\n ",idpgst);
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
//enum {COL_TPCONTA,COL_PARC,COL_VALOR,COL_DATAI,COL_DATAP,COL_CX,COL_SIT,NUM_COLU};
gtk_list_store_append(listtore, &iter);
gtk_list_store_set(listtore, &iter,COL_IPAY,linhas[0],COL_TPCONTA,tpdepag,COL_PARC,parce,COL_VALOR,valor,COL_DATAI,data,COL_DATAP,datae,COL_CX,desccx,COL_ICO,icon,COL_COR,&color,-1);



int vs,vi;


//g_print("vsoma = %f  vpg = %f ",valorsomado,valorpg);

vs = valorsomado *10;
vi= valorpg *10;

///g_print("vi = %d  vs = %d ",vi,vs);

if (vs == vi ){

gtk_widget_set_sensitive(GTK_WIDGET(btfecharcpg),TRUE);
 gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkpago), TRUE);
gtk_widget_grab_focus(GTK_WIDGET(btfecharcpg));
gtk_entry_set_text(GTK_ENTRY(evalor),"0,00");

}else {

gtk_widget_set_sensitive(GTK_WIDGET(btfecharcpg),FALSE);
 gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkpago), FALSE);

char dif[25];
double p= 0.00;
p =(valorpg -valorsomado);
sprintf(dif,"%.2f",p);
gtk_entry_set_text(GTK_ENTRY(evalor), dif);

gtk_widget_grab_focus(GTK_WIDGET(evalor));

}



}

                                        }
                                mysql_free_result(resp);//limpa a variável do resultado: resp
}
gtk_entry_set_text(GTK_ENTRY(eparc),"1");
gtk_combo_box_set_active(GTK_COMBO_BOX(cbtppg),0);


}





void addpg(void){

char codvendedor[11];
char desctpconta[21];
char coddovendedor[12];
char coddocliente[12];
int davnumero;
char sjuros[11];
int icod_tp_conta;
int ftmult;
int precebimento;
int defaultcx;
int qparc;
double valorpg;
int loopparcelas=1;
double valordasparcelas;
double juros;
int dia,mes,ano;
char data[14];
char datasql[20];
char datasqlparc[20];
int hora,min,seg;
struct tm *local;
char valoruni[20];
double valorliqparcelas;
char svalorliqparcelas[20];
int i;
char svalori[20];
int idpgstatus;
int idpg;
double jva;

sprintf(svalori,"%s",gtk_entry_get_text(GTK_ENTRY(evalor)));
char *pvalor= str_replace(svalori,".", ",");
sscanf(gtk_label_get_text(GTK_LABEL(lnumdav)),"%d",&davnumero);
sprintf(desctpconta,"%s", gtk_combo_box_get_active_text(GTK_COMBO_BOX(cbtppg)));
sprintf(codvendedor,"%s",gtk_entry_get_text(GTK_ENTRY(cvend)));
sscanf(gtk_entry_get_text(GTK_ENTRY(eparc)),"%d",&qparc);
valorpg = strtod(pvalor,NULL);
valordasparcelas = valorpg / qparc ;
sprintf(data,"%s",gtk_entry_get_text(GTK_ENTRY(campodata)));
sscanf(data,"%d/%d/%d ",&dia,&mes,&ano);
time_t t;
t= time(NULL);
local=localtime(&t);
hora = local->tm_hour;
min= local->tm_min;
seg=local->tm_sec;
sprintf(datasql,"%d-%d-%d %d:%d:%d",ano,mes,dia,hora,min,seg);
sprintf(coddovendedor,"%s",gtk_entry_get_text(GTK_ENTRY(cvend)));
sprintf(coddocliente,"%s",gtk_entry_get_text(GTK_ENTRY(ccodcli)));



if(valorpg != 0 ){


MYSQL_RES *resposta;
MYSQL_ROW linha;
char ssql[1000];
sprintf(ssql,"SELECT * FROM tb_tp_conta WHERE des_tp_conta='%s';",desctpconta);
  if (mysql_query(&conexao,ssql))
      g_print("Erro: %s\n",mysql_error(&conexao));
  else
    {
    resposta = mysql_store_result(&conexao);//recebe a consulta
    if (resposta) //se houver consulta
        {
           while ((linha=mysql_fetch_row(resposta)) != NULL)  //enquanto linhas for diferente de nulo faca 
                {

sscanf(linha[0],"%d",&icod_tp_conta);
sscanf(linha[2],"%d",&ftmult);
sprintf(sjuros,"%s",linha[3]);
sscanf(linha[4],"%d",&precebimento);
sscanf(linha[5],"%d",&defaultcx);
sscanf(linha[6],"%d",&idpgstatus);
              }

          }
          mysql_free_result(resposta);//limpa a variável do resultado: resp
        }

char *psjuros= str_replace(sjuros,".", ",");
juros = strtod(psjuros,NULL);
sprintf(valoruni,"%f",valordasparcelas);
jva = (valordasparcelas * juros)/100;
valorliqparcelas = valordasparcelas - jva;

sprintf(svalorliqparcelas,"%f",valorliqparcelas);
char *pvalordasparcelas= str_replace(valoruni,",",".");
char *pvalorliqparcelas= str_replace(svalorliqparcelas,",",".");
int mesm;
int diam;


if(precebimento == 30){
mesm =1;
diam =0;

}
if (precebimento == 2) {
mesm =0;
diam = 2;

}


if (precebimento == 0) {
mesm=0;
diam = 0;

}




sprintf(datasqlparc,"%d-%d-%d %d:%d:%d",ano,mes,dia,hora,min,seg);


if (icod_tp_conta == 1)
        {
                idpg = 2;
        }
else
        {
                idpg =1;
        }

char sql[1000];

while(loopparcelas <= qparc ){


int mesf,diaf,anof;
mesf = mes + (mesm * loopparcelas);
diaf = dia + (diam * loopparcelas);
anof = ano;  



if (diaf > 30 ){
mesf++;
diaf = diaf -30 ;

}
if (mesf > 12){
anof++;
mesf = mesf -12;

}




sprintf(datasqlparc,"%d-%d-%d %d:%d:%d",anof,mesf,diaf,hora,min,seg);


sprintf(sql,"INSERT INTO `mmm`.`tb_payment` (`i_pay`, `numemp`, `icod_tp_conta`, `cod_desc_tp_pg`, `cod_dav`, `valor_inc`, `parcela`, `data_prevista`, `data_venda`, `cod_vend`, `valor_entrada`, `id_pg_status`, `cod_cliente`, `i_cod_cx`,`idcheque`) VALUES (NULL, '%d', '%s', '%d', '%d', '%s', '%d/%d', '%s', '%s', '%s', '%s', '%d', '%s', '%d','0');",numep(),gtk_entry_get_text(GTK_ENTRY(ccodtipomov)),icod_tp_conta,davnumero,pvalordasparcelas,loopparcelas,qparc,datasqlparc,datasql,coddovendedor,pvalorliqparcelas,idpgstatus,coddocliente,defaultcx);
//g_print("\n\nsql --- %s\n ",sql);
//g_print(" loopparcelas %d ",loopparcelas);
if (mysql_query(&conexao,sql))
        g_print("Erro: %s\n",mysql_error(&conexao));
else
        {
        //printf("Last inserted record has id %d\n", (int)mysql_insert_id(&conexao));
        i =(int)mysql_insert_id(&conexao);
        //g_print("pagamento ide  num= %d \n",i);
        }
loopparcelas++;
}


}
listapagamentos();
}


void entertotal(GtkWidget *widget,GdkEventKey *event){
int davnumero;
sscanf(gtk_label_get_text(GTK_LABEL(lnumdav)),"%d",&davnumero);

if(event->keyval == 65293){
double valorbonito;
char  svabonito[15];
char *s1= str_replace(gtk_entry_get_text(GTK_ENTRY(etotal)),".",",");
//gtk_entry_set_text(GTK_ENTRY(etotal),s1);
valorbonito = strtod(s1,NULL);
sprintf(svabonito,"%.2f",valorbonito);
gtk_entry_set_text(GTK_ENTRY(etotal),svabonito);

char sql[1000];
char *etotals= str_replace(gtk_entry_get_text(GTK_ENTRY(etotal)),",",".");
sprintf(sql,"UPDATE tb_dav SET vtv ='%s' WHERE num_dav='%d';",etotals,davnumero);
//g_print("texto passado = %s\n%d\n",codclic,campo);
//g_print("%s\n\n",sql);
  if (mysql_query(&conexao,sql))
      g_print("Erro: %s\n",mysql_error(&conexao));
  else
    { 
sprintf(sql," ");


        }

gtk_widget_set_sensitive(GTK_WIDGET(etotal),FALSE);

listapagamentos();








}
//else if (event->keyval == 65421){
//gtk_widget_grab_focus(btnovavenda);
//}



}








void edietotal(void){
gtk_widget_set_sensitive(GTK_WIDGET(etotal),TRUE);
gtk_widget_grab_focus(GTK_WIDGET(etotal));


}

void enternotao(GtkWidget *widget,GdkEventKey *event){
int davnumero;
int nota;

sscanf(gtk_label_get_text(GTK_LABEL(lnumdav)),"%d",&davnumero);

sscanf(gtk_entry_get_text(GTK_ENTRY(enumnot)),"%d",&nota);

if(event->keyval == 65293){

char sql[1000];
sprintf(sql,"UPDATE tb_dav SET n_not_ext='%d',cod_mov='2'  WHERE num_dav='%d';",nota,davnumero);
g_print("%s\n\n",sql);
  if (mysql_query(&conexao,sql))
      g_print("Erro: %s\n",mysql_error(&conexao));
  else
    { 
sprintf(sql," ");
        }

listapagamentos();
gtk_widget_grab_focus(GTK_WIDGET(evalor));
gtk_entry_set_text(GTK_ENTRY(ccodtipomov),"2");
}


}

void deletepagamento (void){

char sql[1000];
sprintf(sql,"DELETE FROM tb_payment WHERE i_pay ='%s' ;",sipay);
g_print("%s\n\n",sql);
  if (mysql_query(&conexao,sql))
      g_print("Erro: %s\n",mysql_error(&conexao));
  else
    { 
sprintf(sql," ");
        }

listapagamentos();
gtk_widget_grab_focus(GTK_WIDGET(evalor));











}




void  on_changedpg(GtkWidget *widget,gpointer *ocli) 
{
  GtkTreeIter iter;
  GtkTreeModel *model;
  char *selectpg;


  if (gtk_tree_selection_get_selected(GTK_TREE_SELECTION(widget), &model, &iter)) {

    gtk_tree_model_get(model, &iter, COL_IPAY , &selectpg,-1);
   // gtk_widget_set_sensitive(GTK_WIDGET(bdelcli),TRUE);
    //gtk_statusbar_push(GTK_STATUSBAR(statusbar), gtk_statusbar_get_context_id(GTK_STATUSBAR(statusbar), value), value);
    gtk_widget_set_sensitive(GTK_WIDGET(delpg), TRUE);
    
    sprintf(sipay,"%s",selectpg);
  //g_print(" valor = %s \n",selectpg);
    //g_print(" valor = %s \n",value);
    //g_free(value);    
    g_free(selectpg);

  }
  else {
    gtk_widget_set_sensitive(GTK_WIDGET(delpg), FALSE);
   // gtk_widget_set_sensitive(GTK_WIDGET(bdelcli),FALSE);
   //clisel= "";
}
}
























































































































































void fechacpagamento(void){
MYSQL_RES *resp;
MYSQL_ROW linhas;


int davnumero;
int iestoque;
int codgradesel;
int numerodanota;
int codtpmov;
double qtdvendida;
double qtdreceita;
double frec;
double freal;
double qtdreal;
double qtdreceitaf;
double qtdrealf;
double qtdgra;
double qtdgraf;
char sql[1000];
char sqtdrf[15];
char sqtdcf[15];


sscanf(gtk_label_get_text(GTK_LABEL(lnumdav)),"%d",&davnumero);
sscanf(gtk_entry_get_text(GTK_ENTRY(ccodtipomov)),"%d",&codtpmov);

int sut=0;
 if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(checklevouproduto))) {
sut += 8;
  }

 if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(checkfabriok))) {
sut += 1;
  }

 if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(checkdespachado))) {
sut += 4;
  }

 if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(checkpago))) {
sut += 2;
  }

char sqlup[1000];
sprintf(sqlup,"UPDATE tb_dav SET id_status ='%d' WHERE num_dav='%d';",sut,davnumero);
  if (mysql_query(&conexao,sqlup))
      g_print("Erro: %s\n",mysql_error(&conexao));
  else
    { 
sprintf(sqlup," ");
       }






















MYSQL_RES *rpe;
MYSQL_ROW lase;
char se[1000];
sprintf(se,"SELECT * FROM tb_cod_mov WHERE cod_mov_merc LIKE '%d';",codtpmov);
if (mysql_query(&conexao,se))
g_print("Erro: %s\n",mysql_error(&conexao));
else
{
rpe = mysql_store_result(&conexao);//recebe a consulta
if (rpe) //se houver consulta
{
while ((lase=mysql_fetch_row(rpe)) != NULL)  //enquanto linhas for diferente de nulo faca 
{

char *sfreal= str_replace(lase[2], ".", ",");
freal = strtod(sfreal,NULL);
char *sfrec= str_replace(lase[3], ".", ",");
frec = strtod(sfrec,NULL);


}
}
mysql_free_result(rpe);//limpa a variável do resultado: resp
}


 if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(checklevouproduto))) {
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(checkdespachado))) {

// 
int frse =0 ;


} else {
freal = 0;
g_print ("nao levou ");
}
  }










sprintf(sql,"SELECT * FROM tb_ctrl_est WHERE n_not_int ='%d' AND numemp LIKE '%d' ;",davnumero,numep());
if(mysql_query(&conexao,sql))
        g_print("Erro: %s\n",mysql_error(&conexao));
else
        {
                resp = mysql_store_result(&conexao);//recebe a consulta
                if (resp) //se houver consulta
                        {
                                while ((linhas=mysql_fetch_row(resp)) != NULL)  //enquanto linhas for diferente de nulo faca
                                        {

                                                sscanf(linhas[3],"%d ",&iestoque);
                                                char *sqtd= str_replace(linhas[4], ".", ",");
                                                qtdvendida = strtod(sqtd,NULL);
                                                sscanf(linhas[9],"%d ",&codgradesel);
                                                sscanf(linhas[11],"%d ",&numerodanota);

MYSQL_RES *respe;
MYSQL_ROW linhase;
char sqle[1000];
sprintf(sqle,"SELECT * FROM tb_estoque WHERE ie LIKE '%d'AND numemp ='%d' ;",iestoque,numep());
if (mysql_query(&conexao,sqle))
g_print("Erro: %s\n",mysql_error(&conexao));
else
{
respe = mysql_store_result(&conexao);//recebe a consulta
if (respe) //se houver consulta
{
while ((linhase=mysql_fetch_row(respe)) != NULL)  //enquanto linhas for diferente de nulo faca 
{

char *sqtdreal= str_replace(linhase[9], ".", ",");
qtdreal = strtod(sqtdreal,NULL);
char *sqtdreceita= str_replace(linhase[10], ".", ",");
qtdreceita = strtod(sqtdreceita,NULL);


}
}
mysql_free_result(respe);//limpa a variável do resultado: resp
}



if(codgradesel !=0){
MYSQL_RES *re;
MYSQL_ROW lse;
char ss[1000];
sprintf(ss,"SELECT * FROM tb_grad WHERE igrad LIKE '%d';",codgradesel);
if (mysql_query(&conexao,ss))
g_print("Erro: %s\n",mysql_error(&conexao));
else
{
re = mysql_store_result(&conexao);//recebe a consulta
if (re) //se houver consulta
{
while ((lse=mysql_fetch_row(re)) != NULL)  //enquanto linhas for diferente de nulo faca 
{

char *sqtdgra= str_replace(lse[3], ".", ",");
qtdgra = strtod(sqtdgra,NULL);

}
}
mysql_free_result(re);//limpa a variável do resultado: resp
}

qtdgraf = qtdgra + (qtdvendida * freal);

g_print("grade final %f " , qtdgraf);
char sqtdgrf[15];
sprintf(sqtdgrf,"%f",qtdgraf);
char *qtdgr = str_replace(sqtdgrf,",",".");

char sqlgrad[1000];

sprintf(sqlgrad,"UPDATE tb_grad SET qta_grade='%s' WHERE numemp ='%d' AND igrad ='%d';",qtdgr,numep(),codgradesel);
g_print("%s",sqlgrad);
  if (mysql_query(&conexao,sqlgrad))
      g_print("Erro: %s\n",mysql_error(&conexao));
  else
    { 
sprintf(sqlgrad," ");
        }


}


qtdrealf = qtdreal + (qtdvendida * freal);
qtdreceitaf = qtdreceita + (qtdvendida *frec);

sprintf(sqtdrf,"%f",qtdrealf);
char *qtdr = str_replace(sqtdrf,",",".");

sprintf(sqtdcf,"%f",qtdreceitaf);
char *qtdc = str_replace(sqtdcf,",",".");



/* */



char sqlee[1000];

sprintf(sqlee,"UPDATE tb_estoque SET qtd_prod='%s',qtd_prod_faz='%s' WHERE numemp ='%d' AND ie ='%d';",qtdr,qtdc,numep(),iestoque);
g_print("%s",sqlee);
  if (mysql_query(&conexao,sqlee))
      g_print("Erro: %s\n",mysql_error(&conexao));
  else
    { 
sprintf(sqlee," ");
        }

          }
          mysql_free_result(resp);//limpa a variável do resultado: resp
        }

}



gtk_widget_set_sensitive(GTK_WIDGET(cqtdv),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(cbuscaprod),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(cprev),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(ccodtipomov),TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(ccodcli),TRUE);
gtk_widget_set_sensitive(GTK_WIDGET(cbuscaprod),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(cqtdv),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(evalor),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(btfecha),FALSE);
gtk_widget_set_sensitive(GTK_WIDGET(campodata),TRUE);
gtk_entry_set_text(GTK_ENTRY(cvend),"");
gtk_widget_set_sensitive(GTK_WIDGET(cvend),TRUE);
gtk_widget_destroy(GTK_WIDGET(wfdav));
gtk_widget_set_sensitive(GTK_WIDGET(btnovavenda),FALSE);
gtk_entry_set_text(GTK_ENTRY(cqtdv)," ");
gtk_widget_grab_focus(cvend);
gtk_entry_set_text(GTK_ENTRY(ccodcli),"0");

gtk_label_set_markup(GTK_LABEL(lnumdav),"<big><span color='blue'><b> </b></span> </big> ");
gtk_label_set_markup(GTK_LABEL(ltotal), "<big><span color='red' font_size='larger' bgcolor='#FFFFFF' ><b> total </b></span> </big> ");
gtk_list_store_clear(storepro);
gtk_widget_destroy(GTK_WIDGET(view));
gtk_widget_destroy(GTK_WIDGET(storepro));
gtk_widget_show_all(GTK_WIDGET(swprod));


}






















































































































void cheentrege(void){


 if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(checklevouproduto))) {
gtk_widget_set_sensitive(GTK_WIDGET(checkdespachado),FALSE);
}
else {

gtk_widget_set_sensitive(GTK_WIDGET(checkdespachado),TRUE);

}


}






void janelafechadav(GtkWidget *widge,gpointer *poi,int coddav){

//coddavv = coddav;
gtk_init(0,0);
char titulo[200];
//g_print("DAV = %d",coddav);
sprintf(titulo,"fechando dav num %d ",coddav);
wfdav  = gtk_window_new(GTK_WINDOW_TOPLEVEL);
gtk_window_set_default_size(GTK_WINDOW(wfdav), 880, 600);
gtk_window_set_modal(GTK_WINDOW(wfdav),TRUE);
  gtk_window_set_title(GTK_WINDOW(wfdav), titulo);
gtk_window_set_position(GTK_WINDOW(wfdav), GTK_WIN_POS_CENTER);
gtk_window_set_modal(GTK_WINDOW(wfdav),TRUE);
//calendar = gtk_calendar_new();

fixedfdav = gtk_fixed_new();
gtk_container_add(GTK_CONTAINER(wfdav), fixedfdav);

g_signal_connect_swapped(G_OBJECT(wfdav), "destroy",G_CALLBACK(gtk_main_quit), NULL);


letotal = gtk_label_new("Total : ");
gtk_fixed_put(GTK_FIXED(fixedfdav),letotal,10,10);
laddpg = gtk_label_new("Adicionar pagamento ");
gtk_fixed_put(GTK_FIXED(fixedfdav),laddpg,400,05);




const GdkColor RED_COLOR = { 0,65535,0, 0 };
etotal = gtk_entry_new();
  
gtk_widget_set_size_request(GTK_WIDGET(etotal),190,90);
PangoFontDescription *font_desc;
font_desc = pango_font_description_from_string ("Serif Bold 30");
gtk_widget_modify_font (etotal, font_desc);

gtk_widget_modify_text(etotal, GTK_STATE_NORMAL, &RED_COLOR);
//gtk_fixed_put(GTK_FIXED(fixedpdv),cbuscaprod,63,40);
gtk_fixed_put(GTK_FIXED(fixedfdav),etotal,60,10);
gtk_entry_set_text(GTK_ENTRY(etotal),"totalll");
gtk_widget_set_sensitive(GTK_WIDGET(etotal),FALSE);

l3 =gtk_label_new("valor : ");
gtk_fixed_put(GTK_FIXED(fixedfdav),l3,250,50);
evalor = gtk_entry_new();
gtk_entry_set_text(GTK_ENTRY(evalor),"0,00");
gtk_widget_set_size_request(GTK_WIDGET(evalor),120,40);
font_desc = pango_font_description_from_string ("Serif Bold 15");
gtk_widget_modify_font (evalor, font_desc);
gtk_fixed_put(GTK_FIXED(fixedfdav),evalor,300,40);


l1 = gtk_label_new("tipo :");
gtk_fixed_put(GTK_FIXED(fixedfdav),l1,430,50);

cbtppg = gtk_combo_box_new_text();
gtk_widget_set_size_request(GTK_WIDGET(cbtppg),165,40);
font_desc = pango_font_description_from_string ("Serif Bold 15");
gtk_widget_modify_font (cbtppg , font_desc);
listatppg();
gtk_combo_box_set_active(GTK_COMBO_BOX(cbtppg),0);
gtk_fixed_put(GTK_FIXED(fixedfdav),cbtppg,465,40);

l2 = gtk_label_new("parcelas :");
gtk_fixed_put(GTK_FIXED(fixedfdav),l2,630,50);

eparc = gtk_entry_new();
gtk_entry_set_text(GTK_ENTRY(eparc),"1");
gtk_widget_set_size_request(GTK_WIDGET(eparc),50,40);
font_desc = pango_font_description_from_string ("Serif Bold 15");
gtk_widget_modify_font (eparc, font_desc);
gtk_fixed_put(GTK_FIXED(fixedfdav),eparc,700,40);

btaddpg = gtk_button_new_with_label("Adicionar");
gtk_widget_set_size_request(GTK_WIDGET(btaddpg),90,70);
gtk_widget_modify_font (btaddpg, font_desc);
gtk_fixed_put(GTK_FIXED(fixedfdav),btaddpg,780,20);


btfecharcpg = gtk_button_new_with_label("fecha com pagamento");
gtk_widget_set_size_request(GTK_WIDGET(btfecharcpg),160,90);
gtk_widget_modify_font (btfecharcpg, font_desc);
gtk_fixed_put(GTK_FIXED(fixedfdav),btfecharcpg,680,420);
gtk_widget_set_sensitive(GTK_WIDGET(btfecharcpg),FALSE);

btedivalor = gtk_tool_button_new_from_stock(GTK_STOCK_EDIT);
//btedcli = gtk_button_new_with_label("Finalizar");
//gtk_widget_set_size_request(btfecha, , 95);
gtk_fixed_put(GTK_FIXED(fixedfdav),btedivalor, 0,50);
//gtk_widget_set_sensitive(GTK_WIDGET(btfecha),FALSE);

  checkfabriok = gtk_check_button_new_with_label("separado/fabricado");
 gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkfabriok), TRUE);
  GTK_WIDGET_UNSET_FLAGS(checkfabriok, GTK_CAN_FOCUS);
  gtk_fixed_put(GTK_FIXED(fixedfdav), checkfabriok,60,370);
  gtk_widget_set_sensitive(GTK_WIDGET(checkfabriok),FALSE);



  checklevouproduto = gtk_check_button_new_with_label("entrege cli ");
 gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checklevouproduto), TRUE);
  GTK_WIDGET_UNSET_FLAGS(checklevouproduto, GTK_CAN_FOCUS);
  gtk_fixed_put(GTK_FIXED(fixedfdav), checklevouproduto,60,430);

  checkdespachado = gtk_check_button_new_with_label("despachado");
 gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkdespachado), TRUE);
  GTK_WIDGET_UNSET_FLAGS(checkdespachado, GTK_CAN_FOCUS);
  gtk_fixed_put(GTK_FIXED(fixedfdav), checkdespachado,60,410);
  gtk_widget_set_sensitive(GTK_WIDGET(checkdespachado),FALSE);

  checkpago = gtk_check_button_new_with_label("pago");
 gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checkpago), FALSE);
  GTK_WIDGET_UNSET_FLAGS(checkpago, GTK_CAN_FOCUS);
  gtk_fixed_put(GTK_FIXED(fixedfdav), checkpago,60,390);

btfecharspg = gtk_button_new_with_label("fecha opcao");
gtk_widget_set_size_request(GTK_WIDGET(btfecharspg),160,50);
gtk_widget_modify_font (btfecharspg, font_desc);
gtk_fixed_put(GTK_FIXED(fixedfdav),btfecharspg,40,450);
gtk_widget_set_sensitive(GTK_WIDGET(btfecharspg),TRUE);

enumnot = gtk_entry_new();
gtk_entry_set_text(GTK_ENTRY(enumnot),"0");
gtk_widget_set_sensitive(GTK_WIDGET(enumnot),FALSE);
  gtk_fixed_put(GTK_FIXED(fixedfdav),enumnot,360,390);


  checknt = gtk_check_button_new_with_label("nf");
 gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(checknt), FALSE);
  GTK_WIDGET_UNSET_FLAGS(checknt, GTK_CAN_FOCUS);
  gtk_fixed_put(GTK_FIXED(fixedfdav), checknt,360,370);


delpg = gtk_tool_button_new_from_stock(GTK_STOCK_DELETE);
//btedcli = gtk_button_new_with_label("Finalizar");
//gtk_widget_set_size_request(btfecha, , 95);
gtk_fixed_put(GTK_FIXED(fixedfdav),delpg, 840,100);
gtk_widget_set_sensitive(GTK_WIDGET(delpg),FALSE);



btrefpg = gtk_tool_button_new_from_stock(GTK_STOCK_REFRESH);
gtk_fixed_put(GTK_FIXED(fixedfdav),btrefpg,840,140);
 


  swfdav = gtk_scrolled_window_new(NULL,NULL);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW(swfdav),GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
  gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW(swfdav),GTK_SHADOW_ETCHED_IN);
  gtk_widget_set_usize (swfdav , 830, 250);
//gtk_scrolled_window_add_with_viewport(GTK_SCROLLED_WINDOW(swdesp),ldesprod);
  gtk_fixed_put(GTK_FIXED(fixedfdav),swfdav,10,100);


//enum {COL_TPCONTA,COL_PARC,COL_VALOR,COL_DATAI,COL_DATAP,COL_CX,COL_SIT,NUM_COLU};



        listtore = gtk_list_store_new(NUM_COLU,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,GDK_TYPE_PIXBUF,GDK_TYPE_COLOR);
        modelolist = GTK_TREE_MODEL(listtore);
        listview = gtk_tree_view_new_with_model(GTK_TREE_MODEL( modelolist));

        coluna = gtk_tree_view_column_new();
        gtk_tree_view_column_set_title(coluna, "tipo");
        celula= gtk_cell_renderer_text_new();
        gtk_tree_view_column_pack_start(coluna,celula, TRUE);
        gtk_tree_view_column_set_attributes(coluna, celula,
                                            "text", COL_TPCONTA,"cell-background-gdk", COL_COR,NULL);

//gtk_tree_view_column_set_sort_column_id(col,0);

        gtk_tree_view_append_column(GTK_TREE_VIEW(listview), coluna);


///gtk_tree_view_append_column(GTK_TREE_VIEW(view), col);

        coluna = gtk_tree_view_column_new();
        gtk_tree_view_column_set_title(coluna, "parcela");
        celula= gtk_cell_renderer_text_new();
        gtk_tree_view_column_pack_start(coluna, celula, TRUE);
        gtk_tree_view_column_set_attributes(coluna,celula,"text", COL_PARC,"cell-background-gdk", COL_COR,NULL);
//gtk_tree_view_column_set_sort_column_id(col,1);
        gtk_tree_view_append_column(GTK_TREE_VIEW(listview), coluna);

        coluna= gtk_tree_view_column_new();
        gtk_tree_view_column_set_title(coluna, "Valor");
        celula= gtk_cell_renderer_text_new();
        gtk_tree_view_column_pack_start(coluna, celula, TRUE);
        gtk_tree_view_column_set_attributes(coluna,celula,"text", COL_VALOR,"cell-background-gdk", COL_COR,NULL);
//gtk_tree_view_column_set_sort_column_id(col,1);
        gtk_tree_view_append_column(GTK_TREE_VIEW(listview), coluna);

        coluna= gtk_tree_view_column_new();
        gtk_tree_view_column_set_title(coluna, "data i");
        celula= gtk_cell_renderer_text_new();
        gtk_tree_view_column_pack_start(coluna, celula, TRUE);
        gtk_tree_view_column_set_attributes(coluna,celula,"text", COL_DATAI,"cell-background-gdk", COL_COR,NULL);
//gtk_tree_view_column_set_sort_column_id(col,1);
        gtk_tree_view_append_column(GTK_TREE_VIEW(listview), coluna);


        coluna= gtk_tree_view_column_new();
        gtk_tree_view_column_set_title(coluna, "data p");
        celula= gtk_cell_renderer_text_new();
        gtk_tree_view_column_pack_start(coluna, celula, TRUE);
        gtk_tree_view_column_set_attributes(coluna,celula,"text", COL_DATAP,"cell-background-gdk", COL_COR,NULL);
//gtk_tree_view_column_set_sort_column_id(col,1);
        gtk_tree_view_append_column(GTK_TREE_VIEW(listview), coluna);

        coluna= gtk_tree_view_column_new();
        gtk_tree_view_column_set_title(coluna, "caixa");
        celula= gtk_cell_renderer_text_new();
        gtk_tree_view_column_pack_start(coluna, celula, TRUE);
        gtk_tree_view_column_set_attributes(coluna,celula,"text", COL_CX,"cell-background-gdk", COL_COR,NULL);
//gtk_tree_view_column_set_sort_column_id(col,1);
        gtk_tree_view_append_column(GTK_TREE_VIEW(listview), coluna);





        coluna= gtk_tree_view_column_new();
        gtk_tree_view_column_set_title(coluna, "st");
        celula= gtk_cell_renderer_pixbuf_new();
        gtk_tree_view_column_pack_start(coluna, celula, FALSE);
        gtk_tree_view_column_set_attributes(coluna, celula,
                                            "pixbuf", COL_ICO,
                                            NULL);

        gtk_tree_view_append_column(GTK_TREE_VIEW(listview), coluna);

gtk_scrolled_window_add_with_viewport (GTK_SCROLLED_WINDOW(swfdav),listview);


selection = gtk_tree_view_get_selection(GTK_TREE_VIEW(listview));





MYSQL_RES *rep;
MYSQL_ROW ls;

char sqll[1000];
sprintf(sqll,"SELECT * FROM tb_dav WHERE num_dav='%d' ;",coddav);

  if (mysql_query(&conexao,sqll))
      g_print("Erro: %s\n",mysql_error(&conexao));
  else
    {
    rep = mysql_store_result(&conexao);//recebe a consulta
    if (rep) //se houver consulta
        {
           while ((ls=mysql_fetch_row(rep)) != NULL)  //enquanto linhas for diferente de nulo faca 
                {

char *ls5= str_replace(ls[5],".", ",");
                        gtk_entry_set_text(GTK_ENTRY(etotal),ls5);
                        gtk_entry_set_text(GTK_ENTRY(evalor),ls5);
              }


          }
          mysql_free_result(rep);//limpa a variável do resultado: resp
        }

gtk_widget_show_all(wfdav);

g_signal_connect(G_OBJECT(evalor),"key-release-event",G_CALLBACK(enterf),NULL);
g_signal_connect(G_OBJECT(cbtppg),"key-release-event",G_CALLBACK(comboenter),NULL);

g_signal_connect(G_OBJECT(eparc),"key-release-event",G_CALLBACK(parcenter),NULL);

g_signal_connect(G_OBJECT(etotal),"key-release-event",G_CALLBACK(entertotal),NULL);

g_signal_connect(G_OBJECT(enumnot),"key-release-event",G_CALLBACK(enternotao),NULL);



 selection  = gtk_tree_view_get_selection(GTK_TREE_VIEW(listview));
  g_signal_connect(selection, "changed",G_CALLBACK(on_changedpg),evalor);


g_signal_connect(G_OBJECT(btaddpg),"clicked",G_CALLBACK(addpg),NULL);

g_signal_connect(G_OBJECT(checklevouproduto),"clicked",G_CALLBACK(cheentrege),NULL);

g_signal_connect(G_OBJECT(delpg),"clicked",G_CALLBACK(deletepagamento),NULL);
g_signal_connect(G_OBJECT(btfecharcpg),"clicked",G_CALLBACK(fechacpagamento),NULL);
g_signal_connect(G_OBJECT(btrefpg),"clicked",G_CALLBACK(listapagamentos),NULL);

g_signal_connect(G_OBJECT(btfecharspg),"clicked",G_CALLBACK(fechacpagamento),NULL);
g_signal_connect(G_OBJECT(btedivalor),"clicked",G_CALLBACK(edietotal),NULL);

g_signal_connect(G_OBJECT(checknt),"clicked",G_CALLBACK(editanota),NULL);
//g_signal_connect(G_OBJECT(btfecharcpg),"clicked",G_CALLBACK(edietotal),NULL);

listapagamentos();
gtk_widget_grab_focus(GTK_WIDGET(evalor));
gtk_main();

}
