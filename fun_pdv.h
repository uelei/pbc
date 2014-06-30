#include "str_replace.h"



GtkWidget * criar_treeview(char n_not_int[]);
void verificavendedor(GtkWidget *widget);
void verificacliente(GtkWidget *widget);
int finprod(void);
int verificaproduto(void);
int listaprodutostree (gpointer swp ,gchar n_not_int[]);
void insereprodudo(GtkWidget *widget,GdkEventKey *event);
void listadeprodutos(char n_not_int[],gpointer stor);
void deleprod(int i);
void ler(void);
