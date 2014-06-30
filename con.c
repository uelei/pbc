#include<mysql/mysql.h>
#include<stdio.h>



MYSQL conexao;

void conecta(void)
{
mysql_init(&conexao);
const char *charset = "utf8";
mysql_options(&conexao,MYSQL_SET_CHARSET_NAME,charset);
mysql_real_connect(&conexao,"localhost","root","uc3r2l","mmm",0,NULL,0);

}

void fechafcn(void){

mysql_close(&conexao);

}

int fechacn(void){

fechafcn();
mysql_close(&conexao);

return 0;
}

