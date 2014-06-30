
//enum{ CODCLI_COL,NOMECLI_COL,CPFCLI_COL,CIDCLI_COL,NUM_COLS};



int popularlistadecliente();
int scliente(GtkWidget *entri, gpointer treecli);
char* dadoscliente (char codclid[], int campo);
int updatecliente(char dcampo[], char valorup[],char codclic[]);
char* lastnewcliente(void);
int apagacli(char codcli[]);
int listpgclientecod (gpointer swp,char clicod[]);
