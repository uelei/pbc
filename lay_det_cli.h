//tela cheque 
//enum{CODCH_COL,CCLI_COL,DTEN_COL,DTS_COL,VCH_COL,SITFINCH,CHCH_COL,DESTCH_COL,NUM_COLSCH};
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


void opencliente(void);
void teladetalecli (void);
void voltateladecliente(void);
void opencamposcliente(void);
void deleclidet(GtkWidget *widget ,gpointer windo);
void editcliente(void);
void salvacliente(void);
