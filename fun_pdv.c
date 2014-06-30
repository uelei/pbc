#include "lay_pdv.h"
#include "fun_pdv.h"
#include <mysql/mysql.h>
#include "con.h"
#include <string.h>
#include "nume.h"
#include <time.h>
#include <stdlib.h>


char ies[11];
char sprv[14],sprc[14];
int valido;
int gra=0;
int f=0;
enum {COL_I,COL_CODP,COL_DESCP,COL_VALORI,COL_VALORS,COL_QTD,COL_GRADE,COL_COR,COL_CORQT,COL_CORC,NUM_COL };

void verificavendedor(GtkWidget *widget)
{
MYSQL_RES *resp;
MYSQL_ROW linhas;

char cvendedor[11];
sprintf(cvendedor,"%s",gtk_entry_get_text(GTK_ENTRY(widget)));

char sql[1000];
sprintf(sql,"SELECT * FROM tb_vendedores WHERE cod_vend LIKE '%s' AND numemp LIKE '%%%d%%' ;",cvendedor,numep());
if (mysql_query(&conexao,sql))
        g_print("Erro: %s\n",mysql_error(&conexao));
else
        {
                resp = mysql_store_result(&conexao);//recebe a consulta

                                while ((linhas=mysql_fetch_row(resp)) != NULL)  //enquanto linhas for diferente de nulo faca 
                                        {
                                                gtk_label_set_text(GTK_LABEL(lnomevend),linhas[1]);
                                                gtk_widget_set_sensitive(GTK_WIDGET(btnovavenda),TRUE);
                                        }
        if ((int)mysql_num_rows(resp) < 1 )
                {
                        gtk_label_set_text(GTK_LABEL(lnomevend),"nome do vendedor ");
                        gtk_widget_set_sensitive(GTK_WIDGET(btnovavenda),FALSE);
                }
        }
}





void verificacliente(GtkWidget *widget)
{
MYSQL_RES *resp;
MYSQL_ROW linhas;

char codcliente[11];
sprintf(codcliente,"%s",gtk_entry_get_text(GTK_ENTRY(widget)));

char sql[1000];
sprintf(sql,"SELECT * FROM tb_clientes WHERE cod_cliente LIKE '%s';",codcliente);
if (mysql_query(&conexao,sql))
        g_print("Erro: %s\n",mysql_error(&conexao));
else
        {
                resp = mysql_store_result(&conexao);//recebe a consulta

                                while ((linhas=mysql_fetch_row(resp)) != NULL)  //enquanto linhas for diferente de nulo faca 
                                        {
                                                //gtk_label_set_text(GTK_LABEL(lnomecliente),linhas[1]);
                                                char str[]="<b>";
                                                char str2[]="</b>";
                                                strcat(str,linhas[1]);
                                                strcat(str,str2);
                                                gtk_label_set_markup(GTK_LABEL(lnomecliente), str);
                                                //gtk_widget_set_sensitive(GTK_WIDGET(btnovavenda),TRUE);
                                        }
        if ((int)mysql_num_rows(resp) < 1 )
                {
                        gtk_label_set_markup(GTK_LABEL(lnomecliente), "<b> cliente balcão  </b> ");
                        gtk_widget_set_sensitive(GTK_WIDGET(btnovavenda),FALSE);
                }
        }
}

void deleprod(int i){

int coddodav;
sscanf(gtk_label_get_text(GTK_LABEL(lnumdav)),"%d",&coddodav);
char svtv1[14];
char svtc1[14];
char spc1[14];
double vtv1;
double vtc1;
double pecas1;
char svtv2[14];
char svtc2[14];
char spc2[14];
double vtv2;
double vtc2;
double pecas2;
double vtvf;
double vtcf;
double tpcs;

//g_print("\n\naquiiii %d \n",i);

MYSQL_RES *rep1;
MYSQL_ROW lis1;

char sqll1[1000];
sprintf(sqll1,"SELECT * FROM tb_dav WHERE num_dav ='%d';",coddodav);
//g_print("sqll %s \n",sqll1);
if (mysql_query(&conexao,sqll1))
        g_print("Erro: %s\n",mysql_error(&conexao));
else
        {
                rep1 = mysql_store_result(&conexao);//recebe a consulta

                                while ((lis1=mysql_fetch_row(rep1)) != NULL)  //enquanto linhas for diferente de nulo faca 
                                        {
sprintf(svtc1,"%s",lis1[4]);
sprintf(svtv1,"%s",lis1[5]);
sprintf(spc1,"%s",lis1[13]); 
                                        }
        if ((int)mysql_num_rows(rep1) < 1 )
                {
g_print("erro dav nao encontrada\n ");
                }
        }


char *pc1= str_replace(svtc1,".", ",");
char *pv1= str_replace(svtv1,".",",");
char *pec1 = str_replace(spc1,".",",");
vtc1  = strtod(pc1,NULL);
vtv1 = strtod(pv1,NULL);
pecas1 = strtod(pec1,NULL);



MYSQL_RES *rep2;
MYSQL_ROW lis2;

char sqll2[1000];
sprintf(sqll2,"SELECT * FROM tb_ctrl_est WHERE i ='%d';",i);
//g_print("sqll %s \n",sqll2);
if (mysql_query(&conexao,sqll2))
        g_print("Erro: %s\n",mysql_error(&conexao));
else
        {
                rep2 = mysql_store_result(&conexao);//recebe a consulta

                                while ((lis2=mysql_fetch_row(rep2)) != NULL)  //enquanto linhas for diferente de nulo faca 
                                        {
sprintf(svtc2,"%s",lis2[7]);
sprintf(svtv2,"%s",lis2[8]);
sprintf(spc2,"%s",lis2[4]); 
                                        }
        if ((int)mysql_num_rows(rep2) < 1 )
                {
g_print("erro iten nao encontrado\n ve");
                }
        }


char *pc2= str_replace(svtc2,".", ",");
char *pv2= str_replace(svtv2,".",",");
char *pec2 = str_replace(spc2,".",",");
vtc2  = strtod(pc2,NULL);
vtv2 = strtod(pv2,NULL);
pecas2 = strtod(pec2,NULL);




//g_print ("somando %f \n",pecas2);





vtvf = vtv1 - vtv2;
vtcf = vtc1 - vtc2;
tpcs = pecas1 - pecas2;

char svtvf[14],svtcf[14],stpcs[14];
sprintf(svtvf,"%f",vtvf);
char *pvtvf= str_replace(svtvf,",", ".");
sprintf(svtcf,"%f",vtcf);
char *pvtcf= str_replace(svtcf,",", ".");
sprintf(stpcs,"%f",tpcs);
char *ptpcs = str_replace(stpcs,",",".");


char sqlee[1000];

sprintf(sqlee,"UPDATE tb_dav SET vtc ='%s',vtv='%s', pcs='%s' WHERE num_dav ='%d';",pvtcf,pvtvf,ptpcs,coddodav);
//g_print("%s",sqlee);
  if (mysql_query(&conexao,sqlee))
      g_print("Erro: %s\n",mysql_error(&conexao));
  else
    { 
sprintf(sqlee," ");
        }

char latotal[100];
sprintf(latotal,"<big><span color='red' font_size='larger' bgcolor='#FFFFFF' ><b> %s </b></span> </big> ",pvtvf);

gtk_label_set_markup(GTK_LABEL(ltotal),latotal);

char sq[1000];
//g_print("cliente numeto  %s  apagado .\n",codcli );
sprintf(sq,"DELETE FROM tb_ctrl_est WHERE `i` LIKE '%d' ",i);
//g_print("texto passado = %s\n%d\n",codclic,campo);
//g_print("%s\n",sql);
  if (mysql_query(&conexao,sq))
      g_print("Erro: %s\n",mysql_error(&conexao));
  else
    { 
sprintf(sq," ");
        }


















gtk_widget_grab_focus(cbuscaprod);


}





void ler(void){

g_print("numero da empresa = %d \n",numep());








}





int crianovavenda(void){


int i;
char codvendedor[11];
sprintf(codvendedor,"%s",gtk_entry_get_text(GTK_ENTRY(cvend)));
char sql[1000];

int dia,mes,ano;
char data[14];
char datasql[20];
sprintf(data,"%s",gtk_entry_get_text(GTK_ENTRY(campodata)));
sscanf(data,"%d/%d/%d ",&dia,&mes,&ano);
struct tm *local;
time_t t;
t= time(NULL);
local=localtime(&t);
int hora,min,seg;
//dia=local->tm_mday;
//mes=local->tm_mon+1;
//ano=local->tm_year+1900;
hora = local->tm_hour;
min= local->tm_min;
seg=local->tm_sec;
sprintf(datasql,"%d-%d-%d %d:%d:%d",ano,mes,dia,hora,min,seg);








sprintf(sql,"INSERT INTO `tb_dav` (`num_dav`, `numemp`, `data`, `cod_vend`, `vtc`, `vtv`, `n_not_ext`, `cod_mov`, `v_des`, `cod_cli`, `id_status`, `data_saida`, `cod_transporte`,`pcs`) VALUES (NULL, '%d', '%s', '%s', '0', '0', '', '1', '', '%s', '1', '', '','');",numep(),datasql,codvendedor,gtk_entry_get_text(GTK_ENTRY(ccodcli)));
if (mysql_query(&conexao,sql))
        g_print("Erro: %s\n",mysql_error(&conexao));
else
        {
        //printf("Last inserted record has id %d\n", (int)mysql_insert_id(&conexao));
        i =(int)mysql_insert_id(&conexao);
        g_print("DAV num= %d criado \n",i);
        }

return i;

}


int gradeinterna (char descricaodagrade[70]){
int igrad;
char codbusca[20];
sprintf(codbusca,"%s",gtk_entry_get_text(GTK_ENTRY(cbuscaprod)));
// g_print("Erro: %s\n",descricaodagrade);
MYSQL_RES *rep;
MYSQL_ROW ls;
char strcom[70];
char sqll[1000];
sprintf(sqll,"SELECT * FROM tb_grad WHERE codprod='%s' AND des_grade like '%%%s%%' AND numemp = '%d';",codbusca,descricaodagrade,numep());


//g_print("%s\n\n\n",sqll);
  if (mysql_query(&conexao,sqll))
      g_print("Erro: %s\n",mysql_error(&conexao));
  else
    {
    rep = mysql_store_result(&conexao);//recebe a consulta
    if (rep) //se houver consulta
        {
           while ((ls=mysql_fetch_row(rep)) != NULL)  //enquanto linhas for diferente de nulo faca 
                {
//g_print("i grade %s " ,ls[0]);
sscanf(ls[0],"%d",&igrad);
              }

        if ((int)mysql_num_rows(rep) < 1 )
                {
g_print("erro ao selecionar igrad\n ");
                }
          }
          mysql_free_result(rep);//limpa a variável do resultado: resp
        }




return igrad;

}





void verificaproduto(void){
MYSQL_RES *resp;
MYSQL_ROW linhas;

char codbusca[20];
sprintf(codbusca,"%s",gtk_entry_get_text(GTK_ENTRY(cbuscaprod)));

char sql[1000];
sprintf(sql,"SELECT * FROM tb_estoque  WHERE cod_prod LIKE '%s' AND numemp like '%%%d%%';",codbusca,numep());
if (mysql_query(&conexao,sql))
        g_print("Erro: %s\n",mysql_error(&conexao));
else
        {
                resp = mysql_store_result(&conexao);//recebe a consulta

                                while ((linhas=mysql_fetch_row(resp)) != NULL)  //enquanto linhas for diferente de nulo faca 
                                        {
                                                //gtk_label_set_text(GTK_LABEL(lnomecliente),linhas[1]);
                                                char str[]="<big><b>";
                                                char str2[]="</b></big>";
                                                strcat(str,linhas[4]);
                                                strcat(str,str2);
//ldesprod = gtk_label_new("");
//gtk_label_set_markup(GTK_LABEL(ldesprod), "<big><b> produto  </b> </big> ");


char preco[10];
sprintf(ies,"%s",linhas[0]);
sprintf(sprc,"%s",linhas[8]);
//Replace(linhas[7],".",",");
valido = 1;
char *new = str_replace(linhas[7], ".", ",");
gtk_entry_set_text(GTK_ENTRY(cprev),new);
gtk_label_set_markup(GTK_LABEL(ldesprod),str);







MYSQL_RES *rep;
MYSQL_ROW ls;
char strcom[70];
char sqll[1000];
sprintf(sqll,"SELECT * FROM tb_grad WHERE iestoque ='%s';",linhas[0]);



  if (mysql_query(&conexao,sqll))
      g_print("Erro: %s\n",mysql_error(&conexao));
  else
    {
    rep = mysql_store_result(&conexao);//recebe a consulta
    if (rep) //se houver consulta
        {
           while ((ls=mysql_fetch_row(rep)) != NULL)  //enquanto linhas for diferente de nulo faca 
                {
                        sprintf(strcom," ");
                        strcat(strcom,ls[4]);
                        strcat(strcom," = ");
                        strcat(strcom,ls[3]);
                        gtk_combo_box_append_text(GTK_COMBO_BOX(combograde), ls[4]);
                        gra=1;
                        f++;
              }

        if ((int)mysql_num_rows(rep) < 1 )
                {
                        gra=0;
                        while (f> 0)
                                {
                                        gtk_combo_box_remove_text(GTK_COMBO_BOX(combograde),0);
                                        f--;
                                }
                }
          }
          mysql_free_result(rep);//limpa a variável do resultado: resp
        }






                                        }
        if ((int)mysql_num_rows(resp) < 1 )
                {
                        gtk_label_set_markup(GTK_LABEL(ldesprod), "<b> </b> ");
gtk_entry_set_text(GTK_ENTRY(cprev),"");
sprintf(ies,"%s","");
sprintf(sprc,"%s","");
gra = 0;
valido = 0;
                        while (f> 0)
                                {
                                        gtk_combo_box_remove_text(GTK_COMBO_BOX(combograde),0);
                                        f--;
                                }
                        //gtk_widget_set_sensitive(GTK_WIDGET(btnovavenda),FALSE);
                }
        }
}





void gravainsereproduto(void){

int i;
char sql[1000];
double qtdf;
double pcsu;
double pvs;
double pcu;
double pvu;
double vtv;
double vtc;
double vtvf;
double vtcf;
char svtv[14];
char svtc[14];
char spcc[14];
char sptcc[14];
double dpc,dtpc;

char *nw = str_replace(gtk_entry_get_text(GTK_ENTRY(cprev)), ".", ",");
char *qtd= str_replace(gtk_entry_get_text(GTK_ENTRY(cqtdv)), ".", ",");
char *pt= str_replace(sprc, ".", ",");
double pcustof;

pcustof = strtod(pt,NULL);
qtdf = strtod(qtd,NULL);
pvu = strtod(nw,NULL);
pcsu = pcustof * qtdf;
pvs = pvu * qtdf;
char sqtd[10],spvu[14],spcs[14],spvs[14];
//char *pqtd,*ppvu,*ppcs,*spvs;
sprintf(sqtd,"%f",qtdf);
char *pqtd= str_replace(sqtd,",", ".");
sprintf(spvu,"%f",pvu);
char *ppvu= str_replace(spvu,",", ".");
sprintf(spcs,"%f",pcsu);
char *ppcs= str_replace(spcs,",", ".");
sprintf(spvs,"%f",pvs);
char *ppvs= str_replace(spvs,",", ".");

int coddodav;
sscanf(gtk_label_get_text(GTK_LABEL(lnumdav)),"%d",&coddodav);

MYSQL_RES *rep;
MYSQL_ROW lis;

char sqll[1000];
sprintf(sqll,"SELECT * FROM tb_dav WHERE num_dav ='%d';",coddodav);
//g_print("sqll %s \n",sqll);
if (mysql_query(&conexao,sqll))
        g_print("Erro: %s\n",mysql_error(&conexao));
else
        {
                rep = mysql_store_result(&conexao);//recebe a consulta

                                while ((lis=mysql_fetch_row(rep)) != NULL)  //enquanto linhas for diferente de nulo faca 
                                        {
sprintf(svtc,"%s",lis[4]);
sprintf(svtv,"%s",lis[5]); 
sprintf(spcc,"%s",lis[13]);
                                        }
        if ((int)mysql_num_rows(rep) < 1 )
                {
g_print("erro venda nao encontrada\n ve");
                }
        }


char *pc= str_replace(svtc,".", ",");
char *pv= str_replace(svtv,".",",");
char *pcss = str_replace(spcc,".",",");
vtc  = strtod(pc,NULL);
vtv = strtod(pv,NULL);
dpc = strtod(pcss,NULL);




//g_print ("somando %f \n",vtv);
vtvf = pvs + vtv;
vtcf = pcsu + vtc;
dtpc = dpc + qtdf ;
char svtvf[14],svtcf[14];
sprintf(svtvf,"%f",vtvf);
char *pvtvf= str_replace(svtvf,",", ".");
sprintf(svtcf,"%f",vtcf);
char *pvtcf= str_replace(svtcf,",", ".");
sprintf(sptcc,"%f",dtpc);
char *ppptcc= str_replace(sptcc,",", ".");
char sqlee[1000];

sprintf(sqlee,"UPDATE tb_dav SET vtc ='%s',vtv='%s',pcs='%s' WHERE num_dav ='%d';",pvtcf,pvtvf,ppptcc,coddodav);
  if (mysql_query(&conexao,sqlee))
      g_print("Erro: %s\n",mysql_error(&conexao));
  else
    { 
sprintf(sqlee," ");
        }

char grade[100];

if (gra==1){
//g_print("igrad %d ",);
sprintf(grade,"%d",gradeinterna(gtk_combo_box_get_active_text(GTK_COMBO_BOX(combograde))));

}else {
sprintf(grade,"%d",gra);

}


int dia,mes,ano;
char data[14];
char datasql[20];
sprintf(data,"%s",gtk_entry_get_text(GTK_ENTRY(campodata)));
sscanf(data,"%d/%d/%d ",&dia,&mes,&ano);
struct tm *local;
time_t t;
t= time(NULL);
local=localtime(&t);
int hora,min,seg;
//dia=local->tm_mday;
//mes=local->tm_mon+1;
//ano=local->tm_year+1900;
hora = local->tm_hour;
min= local->tm_min;
seg=local->tm_sec;
sprintf(datasql,"%d-%d-%d %d:%d:%d",ano,mes,dia,hora,min,seg);



sprintf(sql,"INSERT INTO `tb_ctrl_est` (`i`, `numemp`, `n_not_int`, `iestoque`, `qtd_prod`, `pc_u`, `pv_u`, `pc_s`, `pv_s`, `cod_grade_sel`, `cod_mov`, `n_not_ext`, `data_sel`, `operador`, `p_des`, `v_des`) VALUES (NULL, '%d', '%s','%s', '%s', '%s', '%s', '%s', '%s', '%s', '1', '', '%s', '%s', '', '');",numep(),gtk_label_get_text(GTK_LABEL(lnumdav)),ies,pqtd,sprc,ppvu,ppcs,ppvs,grade,datasql,gtk_entry_get_text(GTK_ENTRY(cvend)));

if (mysql_query(&conexao,sql))
        g_print("Erro: %s\n",mysql_error(&conexao));
else
        {
        //printf("Last inserted record has id %d\n", (int)mysql_insert_id(&conexao));
        i =(int)mysql_insert_id(&conexao);
        }

gtk_widget_grab_focus(cbuscaprod);
}


void totalvenda (void){

   MYSQL_RES *resp;
   MYSQL_ROW linhas;

char sql[1000];
int coddodav;
sscanf(gtk_label_get_text(GTK_LABEL(lnumdav)),"%d",&coddodav);

sprintf(sql,"SELECT * FROM tb_dav WHERE num_dav LIKE '%d';",coddodav);
if (mysql_query(&conexao,sql))
        g_print("Erro: %s\n",mysql_error(&conexao));
else
        {
                resp = mysql_store_result(&conexao);//recebe a consulta
                if (resp) //se houver consulta
                        {
                                while ((linhas=mysql_fetch_row(resp)) != NULL)  //enquanto linhas for diferente de nulo faca 
                                        {
char strind[100];
sprintf(strind,"<big><span color='red' font_size='larger' bgcolor='#FFFFFF' ><b>R$ %s</b></span> </big>",linhas[5]);
                                              //  char str11[] ="<big><span color='red' font_size='larger' bgcolor='#FFFFFF' ><b> ";
                                                //char strff[]="</b></span> </big> ";
                                                //strcat(str11,linhas[5]);
                                                //strcat(str11,strff);
//g_print("marikuo %s ",strind);
                                                gtk_label_set_markup(GTK_LABEL(ltotal), strind);


                                        }
                        }
                mysql_free_result(resp);//limpa a variável do resultado: resp
        }
}



void insereprodudo(GtkWidget *widget,GdkEventKey *event){
//g_print("tecla %d\n ",event->keyval);

if(event->keyval == 65472){
//g_print("fechando venda ");
fechando();


}


if(event->keyval == 65293)
        {
                if(valido > 0 )
                        {
//g_print("gra %d ",gra);

                                if(gra==0)
                                        {
                                                gravainsereproduto();
                                                listadeprodutos(gtk_label_get_text(GTK_LABEL(lnumdav)),storepro);
                                                totalvenda();
                                                gtk_entry_set_text(GTK_ENTRY(cbuscaprod),"");
                                                gtk_entry_set_text(GTK_ENTRY(cqtdv),"1");
                                        }
                                else if(gra == 1) 
                                        {
                                                gint ativadograde = gtk_combo_box_get_active(GTK_COMBO_BOX(combograde));
                                                char testograde[70];
                                                if(ativadograde >=0 )
                                                        {
///venda com grade 
                                                gravainsereproduto();
                                                listadeprodutos(gtk_label_get_text(GTK_LABEL(lnumdav)),storepro);
                                                totalvenda();
                                                gtk_entry_set_text(GTK_ENTRY(cbuscaprod),"");
                                                gtk_entry_set_text(GTK_ENTRY(cqtdv),"1");
                                                                //g_print("igrad %d ",gradeinterna(gtk_combo_box_get_active_text(GTK_COMBO_BOX(combograde))));
                                                        }else{
gtk_widget_grab_focus(combograde);
}
                                        }




                        }
        }
else if (event->keyval == 65421)
        {
                if(valido > 0 )
                        {
                                gravainsereproduto();
                                listadeprodutos(gtk_label_get_text(GTK_LABEL(lnumdav)),storepro);
                                totalvenda();
                                gtk_entry_set_text(GTK_ENTRY(cbuscaprod),"");
                                gtk_entry_set_text(GTK_ENTRY(cqtdv),"1");
                        }
        }

}




void listadeprodutos(char n_not_int[],gpointer stor)
{
GdkColor color,colorqtd,colorc;
GtkTreeIter    iter2;
char ie[15];
char p[18];
int ii;
int igradeee;
sprintf(p,"%s", gtk_label_get_text(GTK_LABEL(lnumdav)));
sscanf(p,"%d ",&ii);

 //g_print("linha\n");
gtk_list_store_clear(stor);
//enum {COL_CODP,COL_DESCP,COL_VALORI,COL_VALORS,COL_GRADE,COL_COR,NUM_COL };
//g_print("1->%s \n",s);

MYSQL_RES *resp;
MYSQL_ROW linhas;

char sql[ 1000 ];
char ft[50];

sprintf(sql,"SELECT * FROM tb_ctrl_est WHERE n_not_int LIKE '%%%d%%' AND numemp LIKE '%%%d%%' ;",ii,numep());


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
                char codprodutonaempresa[10];
                char descdoprodutonaempresa[200];
                char gradedoproduto[50];
                //int codmov;
                //codmov = linhas[11];
                //sscanf(linhas[11],"%d",&codmov);
                //char data[20],datae[20];
                //int ano,mes,dia,hora,min,seg;
char iestoque[12];
sprintf( iestoque,"%s",linhas[3]);
sprintf(ft,"%s",linhas[9]);
             
                //sscanf(linhas[8],"%d-%d-%d %d:%d:%d",&ano,&mes,&dia,&hora,&min,&seg);
                //sprintf(data,"%d/%d/%d",dia,mes,ano);
                //sscanf(linhas[7],"%d-%d-%d %d:%d:%d",&ano,&mes,&dia,&hora,&min,&seg);
                //sprintf(datae,"%d/%d/%d",dia,mes,ano);

                MYSQL_RES *respe;
                MYSQL_ROW linhase;

                char sqle[1000];


                sprintf(sqle,"SELECT * FROM tb_estoque WHERE ie LIKE '%s';",linhas[3]);

//g_print("ssquel 2 = %s\n",sqle);


int t;


                if (mysql_query(&conexao,sqle))
                        g_print("Erro: %s\n",mysql_error(&conexao));
                else
                        {
                                respe = mysql_store_result(&conexao);//recebe a consulta
                                if (respe) //se houver consulta
                                        {
                                                while ((linhase=mysql_fetch_row(respe)) != NULL)  //enquanto linhas for diferente de nulo faca 
                                                        {
                                                                
sprintf( codprodutonaempresa,"%s",linhase[2]);
sprintf(descdoprodutonaempresa,"%s",linhase[4]);
                                                        }
                                        }
                                mysql_free_result(respe);//limpa a variável do resultado: resp
                        }



                                color.red = 62194;
                                color.blue = 63232;
                                color.green = 63232;

                                colorc.red = 0;
                                colorc.blue = 0;
                                colorc.green = 63232;
double qtfloat;
char sqt[14];
sprintf(sqt,"%s",linhas[4]);
char *pqt= str_replace(sqt,".",",");
qtfloat  = strtod(pqt,NULL);


//g_print("qtdf %f\n",qtfloat);

if (qtfloat < 0 ){
//g_print("qtdf menor que zero ");
                                colorqtd.red = 62194;
                                colorqtd.blue = 0;
                                colorqtd.green = 0;


}else{
                                colorqtd.red = 0;
                                colorqtd.blue = 0;
                                colorqtd.green = 0;

}



sscanf(ft,"%d",&igradeee);

if (igradeee ==0){


sprintf(gradedoproduto," ");
//gradedoproduto =" ";





}else {

MYSQL_RES *repe;
                MYSQL_ROW lise;

                char se[1000];


                sprintf(se,"SELECT * FROM tb_grad WHERE igrad LIKE '%s';",linhas[9]);

//g_print("ssquel 2 = %s\n",sqle);


                if (mysql_query(&conexao,se))
                        g_print("Erro: %s\n",mysql_error(&conexao));
                else
                        {
                                repe = mysql_store_result(&conexao);//recebe a consulta
                                if (repe) //se houver consulta
                                        {
                                                while ((lise=mysql_fetch_row(repe)) != NULL)  //enquanto linhas for diferente de nulo faca 
                                                        {
                                                                
sprintf( gradedoproduto,"%s",lise[4]);
//sprintf(descdoprodutonaempresa,"%s",linhase[4]);
                                                        }
                                        }
                                mysql_free_result(repe);//limpa a variável do resultado: resp
                        }


}




gtk_list_store_append(storepro, &iter2);
gtk_list_store_set(storepro, &iter2,COL_I,linhas[0],COL_CODP,codprodutonaempresa,COL_DESCP,descdoprodutonaempresa,COL_VALORI,linhas[6],COL_VALORS,linhas[8],COL_QTD,linhas[4],COL_GRADE,gradedoproduto,COL_COR,&color,COL_CORQT,&colorqtd,COL_CORC,&colorc,-1);


              }
          }
          mysql_free_result(resp);//limpa a variável do resultado: resp
        }

}



int listaprodutostree (gpointer swp ,gchar n_not_int[]){



return 0;

}

