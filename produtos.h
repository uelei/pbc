
void telaprodutos(void);
void apagatelaprodutos(void);
void buscapro(void);
void arvoreprodutos (void);
void on_changedpro(GtkWidget *widget,gpointer ocli);

GtkWidget *btfechaprodutos;
GtkWidget *swlpro;
GtkWidget *lbuspro;
GtkWidget *ebuspro;
GtkWidget *btabrepro;
GtkWidget *ckcod,*ckbar,*ckdesc,*cklcem;


GtkListStore  *storeprodutos;
GtkWidget  *viewprodutos;
GtkTreeModel      *modelprodutos;
GtkTreeViewColumn *colpro;
GtkCellRenderer   *renderpro;
GtkTreeSelection *selectionpro;

char iesel[6];
