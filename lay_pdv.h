#include <gtk/gtk.h>
#include "layout.h"
#include<mysql/mysql.h>
#include "con.h"
#include "fun_pdv.h"
#include "str_replace.h"
#include "data.h"
#include "clientefast.h"


char prodsel[15];

GtkWidget *windowpdv;
GtkWidget *fixedpdv;
GtkWidget *campodata,*cvend,*ccodcli,*cbuscaprod,*cqtdv,*cprev,*ccodtipomov;
GtkWidget *ldata,*lvend,*lcodcli,*lbuscaprod,*lqtdv,*lprev,*lnomevend,*lnumdavs,*lnomecliente,*lnomecli,*lcodtpmov;
GtkWidget *lnumdav;
GtkWidget *ldesprod;
GtkWidget *ltotal;
GtkWidget *btnovavenda,*btfecha,*btedcli,*btdelprod;
GtkWidget *combograde;
GtkWidget *swdesp,*swprod;

GtkListStore  *storepro;
GtkWidget  *view;
GtkTreeModel      *model;
GtkTreeViewColumn *col;
GtkCellRenderer   *renderer;
GtkTreeSelection *selectionprod;


void windowpdvc( int argc, char *argv[]);
void telapdv (void);
GdkPixbuf *create_pixbufpdv(const gchar * filename);
void prepraratelapdv(void);



