#include <mysql/mysql.h>
#include <stdio.h>
#include<gtk/gtk.h>

enum{ CODCLI_COL,NOMECLI_COL,CPFCLI_COL,CIDCLI_COL,NUM_COLS};
enum{CODCH_COL,CCLI_COL,DTEN_COL,DTS_COL,VCH_COL,SITFINCH,CHCH_COL,DESTCH_COL,NUM_COLSCH};

MYSQL conexao;

void conecta(void)
{

mysql_init(&conexao);
const char *charset = "utf8";
mysql_options(&conexao,MYSQL_SET_CHARSET_NAME,charset);
mysql_real_connect(&conexao,"localhost","root","uc3r2l","tbpb001",0,NULL,0);

g_print("conectado com sucesso \n");
}



void fechafcn(void){
mysql_close(&conexao);

}

int fechacn(void){
fechafcn();
g_print("desconectando ... \n ");
mysql_close(&conexao);
g_print("desconectado ok \n ");
return 0;
}

int scliente(GtkWidget *entri, gpointer treecli){
  gchar *s;
  
  s = (gchar*)gtk_entry_get_text(GTK_ENTRY(entri));
  //g_print("entry texto = %s\n", s);
//limpando treecliente 
  gtk_tree_store_clear(treecli);

   MYSQL_RES *resp;
   MYSQL_ROW linhas;
//   MYSQL_FIELD *campos;
//   int conta; //Contador comum

char sql[ 1000 ];

sprintf(sql,"SELECT * FROM tb_clientes WHERE nomecliente LIKE '%%%s%%';",s);
//g_print("texto passado = %s\n\n",sql);
//g_print("%s\n\n",sql);

GtkTreeIter   iter;

  if (mysql_query(&conexao,sql))
      g_print("Erro: %s\n",mysql_error(&conexao));
  else
    {
    resp = mysql_store_result(&conexao);//recebe a consulta
    if (resp) //se houver consulta
        {
           //passa os dados dos campos para a variável campos
           //escreve na tela os nomes dos campos dando
           //um tab somente
          // campos = mysql_fetch_fields(resp);
            //  g_print("\n");  
              //enquanto retonrnar registros, conta até o
              //número de colunas que a tabela tem e escreve na
              //tela com um tab, depois pula a linha e tenta
              //pegar outro registro
              while ((linhas=mysql_fetch_row(resp)) != NULL)  //enquanto linhas for diferente de nulo faca 
              {

                   gtk_tree_store_append (treecli, &iter, NULL);  //pega interator do tree 

                   gtk_tree_store_set (treecli, &iter,
                             CODCLI_COL, linhas[0],
                             NOMECLI_COL, linhas[1],
                             CPFCLI_COL, linhas[10],
                             CIDCLI_COL,linhas[5],
                             -1);
//g_print("LIha conta %s ",linhas[01]);
//for (conta=0;conta<mysql_num_fields(resp);conta++)
// g_print("%s\t",linhas[conta]);
//g_print("\n");
              }
          }
          mysql_free_result(resp);//limpa a variável do resultado: resp
        }

////////////////////////////////////////////////////////////////////////////////////////////////////////
//procurando pelo cpf 
/////////////////////////////////////////////////////////////////////////////////////////////////////////

sprintf(sql,"SELECT * FROM tb_clientes WHERE cpf LIKE '%%%s%%'AND  nomecliente NOT LIKE '%%%s%%';",s,s);
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



/////////////////////////////////////////////////////////////////////////////////////////
int listcombocx( gpointer combocxd ){

   MYSQL_RES *resp;
   MYSQL_ROW linhas;

char sql[ 1000 ];

sprintf(sql,"SELECT * FROM tb_caixas;");

  if (mysql_query(&conexao,sql))
      g_print("Erro: %s\n",mysql_error(&conexao));
  else
    {
    resp = mysql_store_result(&conexao);//recebe a consulta
    if (resp) //se houver consulta
        {
           while ((linhas=mysql_fetch_row(resp)) != NULL)  //enquanto linhas for diferente de nulo faca 
              {
                gtk_combo_box_append_text(GTK_COMBO_BOX(combocxd), linhas[1]);
              }
          }
          mysql_free_result(resp);//limpa a variável do resultado: resp
        }


return 0;
}

/////////////////////////////////////////////////////////////////////////////////////////





int listchclientecod (gpointer treeclich,char clicod[]){


  gtk_tree_store_clear(treeclich);

   MYSQL_RES *resp;
   MYSQL_ROW linhas;

   MYSQL_RES *respd;
   MYSQL_ROW linhasd;

char sqld[ 1000 ];
char *tcx;
//char ttcx; 

char sql[ 1000 ];

sprintf(sql,"SELECT * FROM tb_cheques WHERE idcliente LIKE '%s';",clicod);
//g_print("texto passado = %s\n\n",sql);
//g_print("%s\n\n",sql);

GtkTreeIter   iter;

  if (mysql_query(&conexao,sql))
      g_print("Erro: %s\n",mysql_error(&conexao));
  else
    {
    resp = mysql_store_result(&conexao);//recebe a consulta
    if (resp) //se houver consulta
        {
           //passa os dados dos campos para a variável campos
           //escreve na tela os nomes dos campos dando
           //um tab somente
          // campos = mysql_fetch_fields(resp);
            //  g_print("\n");  
              //enquanto retonrnar registros, conta até o
              //número de colunas que a tabela tem e escreve na
              //tela com um tab, depois pula a linha e tenta
              //pegar outro registro
              while ((linhas=mysql_fetch_row(resp)) != NULL)  //enquanto linhas for diferente de nulo faca 
              {







sprintf(sqld,"SELECT * FROM tb_caixas WHERE cod_cx LIKE '%s';",linhas[9]);

  if (mysql_query(&conexao,sqld))
      g_print("Erro: %s\n",mysql_error(&conexao));
  else
    {
    respd = mysql_store_result(&conexao);//recebe a consulta
    if (respd) //se houver consulta
        {
           while ((linhasd=mysql_fetch_row(respd)) != NULL)  //enquanto linhas for diferente de nulo faca 
              {
              tcx = linhasd[1];
//              int strcmp (char *tcx, "");

              }
          }
          mysql_free_result(respd);//limpa a variável do resultado: resp
        }

int j,i;
i=0;
//int i, j, k;
// char string1[] = "10 20 30";
//  sscanf(string1, "%d %d %d", &i, &j, &k);
///c/har string1[20]  = dadosche(chequesel,9);
//g_print("%s \n",tcx);
sscanf(linhas[9],"%d",&j);
if (j == 0 ) {

sprintf(tcx,"-");

} 










                   gtk_tree_store_append (treeclich, &iter, NULL);  //pega interator do tree 
//enum{CODCH_COL,CCLI_COL,DTEN_COL,DTS_COL,VCH_COL,SITFINCH,CHCH_COL,NUM_COLSCH};
                   gtk_tree_store_set (treeclich, &iter,
                             CODCH_COL, linhas[0],
                             CCLI_COL, linhas[7],
                             DTEN_COL, linhas[10],
                             DTS_COL,linhas[11],
                             VCH_COL,linhas[6],
                             SITFINCH,linhas[8],
                             CHCH_COL,linhas[1],
                             DESTCH_COL,tcx,
                             -1);
//g_print("LIha conta %s ",linhas[01]);
//for (conta=0;conta<mysql_num_fields(resp);conta++)
// g_print("%s\t",linhas[conta]);
//g_print("\n");
              }
          }
          mysql_free_result(resp);//limpa a variável do resultado: resp
        }


return 0;




}

char* dadoscliente (char codclid[], int campo){
//g_print("codclid e campo = %s\n%d\n",codclid,campo);

   MYSQL_RES *resp;
   MYSQL_ROW linhas;

char sql[1000];
char* tex ="";

sprintf(sql,"SELECT * FROM tb_clientes WHERE codcliente LIKE '%s';",codclid);
//g_print("texto passado = %s\n%d\n",codclid,campo);
//g_print("%s\n\n",sql);
  if (mysql_query(&conexao,sql))
      g_print("Erro: %s\n",mysql_error(&conexao));
  else
    {
    resp = mysql_store_result(&conexao);//recebe a consulta
    if (resp) //se houver consulta
        {

              while ((linhas=mysql_fetch_row(resp)) != NULL)  //enquanto linhas for diferente de nulo faca 
              {

                //   gtk_tree_store_append (treeclich, &iter, NULL);  //pega interator do tree 
//enum{CODCH_COL,CCLI_COL,DTEN_COL,DTS_COL,VCH_COL,SITFINCH,CHCH_COL,NUM_COLSCH};
                  // gtk_tree_store_set (treeclich, &iter,                             CODCH_COL, linhas[0],                             CCLI_COL,linha[7],                             DTEN_COL, linhas[10],                             DTS_COL,linhas[11],                             VCH_COL,linhas[6],                             SITFINCH,linhas[1],                             CHCH_COL,linhas[9],                             -1);
                    //sprintf(tex,"%s",linhas[campo]);
                    //g_print ("\t ddd= %s",linhas[campo]); 
                    tex = linhas[campo];
//g_print("LIha conta %s ",linhas[01]);
//for (conta=0;conta<mysql_num_fields(resp);conta++)
// g_print("%s\t",linhas[conta]);
//g_print("\n");
              }
          }
          mysql_free_result(resp);//limpa a variável do resultado: resp
        }
return (tex);
}


int updatecliente(char dcampo[], char valorup[],char codclic[]){
//  MYSQL_RES *resp;
//  MYSQL_ROW linhas;
char sql[1000];

sprintf(sql,"UPDATE tb_clientes SET %s ='%s' WHERE codcliente='%s';",dcampo,valorup,codclic);
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


char* dadosche(char idchequep[], int campo){
   MYSQL_RES *resp;
   MYSQL_ROW linhas;

char sql[1000];
char* tex ="";

sprintf(sql,"SELECT * FROM tb_cheques WHERE idcheque LIKE '%s';",idchequep);
//g_print("texto passado = %s\n%d\n",codclid,campo);
//g_print("%s\n\n",sql);
  if (mysql_query(&conexao,sql))
      g_print("Erro: %s\n",mysql_error(&conexao));
  else
    {
    resp = mysql_store_result(&conexao);//recebe a consulta
    if (resp) //se houver consulta
        {

              while ((linhas=mysql_fetch_row(resp)) != NULL)  //enquanto linhas for diferente de nulo faca 
              {

                //   gtk_tree_store_append (treeclich, &iter, NULL);  //pega interator do tree 
//enum{CODCH_COL,CCLI_COL,DTEN_COL,DTS_COL,VCH_COL,SITFINCH,CHCH_COL,NUM_COLSCH};
                  // gtk_tree_store_set (treeclich, &iter,                             CODCH_COL, linhas[0],                             CCLI_COL,linha[7],                             DTEN_COL, linhas[10],                             DTS_COL,linhas[11],                             VCH_COL,linhas[6],                             SITFINCH,linhas[1],                             CHCH_COL,linhas[9],                             -1);
                    //sprintf(tex,"%s",linhas[campo]);
                    //g_print ("\t ddd= %s",linhas[campo]); 
                    tex = linhas[campo];
//g_print("LIha conta %s ",linhas[01]);
//for (conta=0;conta<mysql_num_fields(resp);conta++)
// g_print("%s\t",linhas[conta]);
//g_print("\n");
              }
          }
          mysql_free_result(resp);//limpa a variável do resultado: resp
        }
return (tex);






}




char* lastnewcliente(void){
char sql[1000];
char* s;
MYSQL_RES *resp;
MYSQL_ROW linhas;
//int lastid;

sprintf(sql,"INSERT INTO `tb_clientes` (`codcliente` ,`nomecliente` ,`edcliente` ,`numend` ,`bairro` ,`cidade` ,`uf` ,`tel1` ,`tel2` ,`dtnasc` ,`cpf` ,`rg` ,`email` ,`obs`)VALUES (NULL , '','', '', '', '', '', '', '', '', '111.111.111-11', '', '', '');");

mysql_query(&conexao,sql);
//resp = mysql_store_result(&conexao);

//lastid = mysql_insert_id(&conexao);



sprintf(sql,"SELECT * FROM tb_clientes WHERE cpf LIKE '111.111.111-11';");
//g_print("texto passado = %s\n%d\n",codclid,campo);
//g_print("%s\n\n",sql);
  if (mysql_query(&conexao,sql))
      g_print("Erro: %s\n",mysql_error(&conexao));
  else
    {
    resp = mysql_store_result(&conexao);//recebe a consulta
    if (resp) //se houver consulta
        {

              while ((linhas=mysql_fetch_row(resp)) != NULL)  //enquanto linhas for diferente de nulo faca 
              {

                //   gtk_tree_store_append (treeclich, &iter, NULL);  //pega interator do tree 
//enum{CODCH_COL,CCLI_COL,DTEN_COL,DTS_COL,VCH_COL,SITFINCH,CHCH_COL,NUM_COLSCH};
                  // gtk_tree_store_set (treeclich, &iter,                             CODCH_COL, linhas[0],                             CCLI_COL,linha[7],                             DTEN_COL, linhas[10],                             DTS_COL,linhas[11],                             VCH_COL,linhas[6],                             SITFINCH,linhas[1],                             CHCH_COL,linhas[9],                             -1);
                    //sprintf(tex,"%s",linhas[campo]);
                    //g_print ("\t ddd= %s",linhas[campo]); 
                    s = linhas[0];
//g_print("LIha conta %s ",linhas[01]);
//for (conta=0;conta<mysql_num_fields(resp);conta++)
// g_print("%s\t",linhas[conta]);
//g_print("\n");
              }
          }
          mysql_free_result(resp);//limpa a variável do resultado: resp
        }
return (s);

}



int updatechquecampo(char dcampo[], char valorup[],char codch[]){

char sql[1000];

sprintf(sql,"UPDATE tb_cheques SET %s ='%s' WHERE idcheque='%s';",dcampo,valorup,codch);
//g_print("texto passado = %s\n%d\n",codclic,campo);
//g_print("%s\n\n",sql);
  if (mysql_query(&conexao,sql))
      g_print("Erro: %s\n",mysql_error(&conexao));
  else
    { 
sprintf(sql," ");
        }
return 0;
}

char* newcheque(void){
  MYSQL_RES *resp;
  MYSQL_ROW linhas;
char sql[1000];
sprintf(sql,"INSERT INTO `tbpb001`.`tb_cheques` (`idcheque` ,`sitfinche` ,`banco` ,`agencia` ,`cta` ,`ncheque` ,`valor` ,`idcliente` ,`idparc` ,`dest` ,`entdata` ,`saidata`)VALUES (NULL , '', '0','','', '', '0.00', '9999999999', '', ' ', '', '');");
//g_print("texto passado = %s\n%d\n",codclic,campo);
//g_print("%s\n",sql);
  if (mysql_query(&conexao,sql))
      g_print("Erro: %s\n",mysql_error(&conexao));
  else
    { 
sprintf(sql," ");
        }
char* s;
sprintf(sql,"SELECT * FROM tb_cheques WHERE idcliente LIKE '9999999999';");
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

int apagacli(char codcli[]){

char sql[1000];
g_print("cliente numeto  %s  apagado .\n",codcli );
sprintf(sql,"DELETE FROM tb_clientes WHERE `codcliente` LIKE '%s' ",codcli);
//g_print("texto passado = %s\n%d\n",codclic,campo);
//g_print("%s\n",sql);
  if (mysql_query(&conexao,sql))
      g_print("Erro: %s\n",mysql_error(&conexao));
  else
    { 
sprintf(sql," ");
        }

g_print("todos os cheques do cliente  %s  apagados .\n",codcli );
sprintf(sql,"DELETE FROM tb_cheques WHERE `idcliente` LIKE '%s' ",codcli);
//g_print("texto passado = %s\n%d\n",codclic,campo);
//g_print("%s\n",sql);
  if (mysql_query(&conexao,sql))
      g_print("Erro: %s\n",mysql_error(&conexao));
  else
    { 
sprintf(sql," ");
        }











return 0;
}





