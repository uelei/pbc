
//menucliente
  GtkWidget *barcli;
  GtkToolItem *ncli;
  GtkToolItem *bdelcli;
  GtkToolItem *ecli;
  GtkToolItem *scli;
  GtkToolItem *ocli;
  GtkToolItem *closecli;
  GtkToolItem *backlcli,*refche;
int handler_id;
//listadecliente
GtkWidget *lebcli;
GtkWidget *ebcli;
GtkWidget *swcli;
GtkTreeStore *treestorecli;
GtkWidget *treewcli;
GtkTreeSelection *selection;
GtkTreeViewColumn *coluna;
GtkCellRenderer *celula;
char clisele[20];
enum{ CODCLI_COL,NOMECLI_COL,CPFCLI_COL,CIDCLI_COL,NUM_COLS};


void telacliente(void);
void upbotaocliente(void);
void listadecliente (void);
void menucliente(void);
void  on_changed(GtkWidget *widget,gpointer ocli);
void limpatelalistaclienteparatelacheque(void);
void limpatelalistacliente(void);
void novcli(GtkWidget *widget,gpointer poniter);
