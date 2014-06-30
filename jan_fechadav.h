//#include <gtk/gtk.h>
//#include "nume.h"
//#include<mysql/mysql.h>
//#include "con.h"
#include "lay_pdv.h"
#include <string.h>

char sipay[12];

GtkWidget *wfdav;
GtkWidget *fixedfdav;
GtkWidget *swfdav;
GtkWidget *etotal,*evalor,*eparc;
GtkWidget *letotal,*laddpg,*l1,*l2,*l3;
GtkWidget *cbtppg;
GtkWidget *btaddpg;
GtkWidget *btfecharcpg;
GtkWidget *btedivalor;
GtkWidget *checklevouproduto;
GtkWidget *checkfabriok;
GtkWidget *checkdespachado;
GtkWidget *checkpago;
GtkWidget *btfecharspg;
GtkWidget *enumnot;
GtkWidget *checknt;
GtkTreeSelection *selection;
GtkWidget *delpg;

GtkListStore  *listtore;
GtkWidget  *listview;
GtkTreeModel      *modelolist;
GtkTreeViewColumn *coluna;
GtkCellRenderer   *celula;
GtkTreeSelection *selection;

GtkWidget *btrefpg;


void janelafechadav(GtkWidget *widge,gpointer *poi,int coddav);
