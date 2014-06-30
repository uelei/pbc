#include <gtk/gtk.h>
#include<mysql/mysql.h>
#include "con.h"
GtkWidget *wcli;
GtkWidget *vbox;
GtkWidget *hbox;
GtkWidget *entry;
GtkWidget *lnome;





GtkWidget *swcli;

GtkListStore  *listestore;
GtkWidget  *treeview;
GtkTreeModel      *modelo;
GtkTreeViewColumn *colu;
GtkCellRenderer   *cel;
GtkTreeSelection *slee;
int coddav;





void janelaclifast(GtkWidget *widge,gpointer *poi,int coddav);
