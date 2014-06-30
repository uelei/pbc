#include "data.h"





/*struct tm *local;
time_t t;
t= time(NULL);
local=localtime(&t);
int dia,mes,ano,hora,min,seg;



dia=local->tm_mday;
mes=local->tm_mon+1;
ano=local->tm_year+1900;
hora = local->tm_hour;
min= local->tm_min;
seg=local->tm_sec;

printf("Data do Sistema: %d-%d-%d %d:%d:%d\n",ano,mes,dia,hora,min,seg); // Retorna a data
*/







void fechajaneladata(GtkWidget *widget,gpointer *poi){

//GtkWidget *widget,gpointer *poi
//gtk_widget_grab_focus(GTK_WIDGET(poi));

gtk_widget_destroy(GTK_WIDGET(calendar));
gtk_widget_destroy(GTK_WIDGET(wdata));

gtk_main_quit();


}
void selecionadata(GtkWidget *widget,gpointer *entry){
gint ano,mes,dia;
char data[11];
gtk_calendar_get_date(GTK_CALENDAR(calendar),&ano,&mes,&dia);
mes ++;
//g_print("%d/%d/%d",dia,mes,ano);
//gtk_entry_set_text
sprintf(data,"%d/%d/%d",dia,mes,ano);
gtk_entry_set_text(GTK_ENTRY(entry),data);

}




void janeladata(GtkWidget *widge,gpointer *poi){

gtk_init(0,0);
wdata = gtk_window_new(GTK_WINDOW_POPUP);
gtk_window_set_default_size(GTK_WINDOW(wdata), 230, 150);
gtk_window_set_modal(GTK_WINDOW(wdata),TRUE);
  gtk_window_set_position(GTK_WINDOW(wdata), GTK_WIN_POS_CENTER);
calendar = gtk_calendar_new();
gtk_container_add(GTK_CONTAINER(wdata), calendar);
g_signal_connect_swapped(G_OBJECT(wdata), "destroy",G_CALLBACK(gtk_main_quit), NULL);
g_signal_connect(G_OBJECT(calendar),"day-selected-double-click",G_CALLBACK(fechajaneladata),poi);
g_signal_connect(G_OBJECT(calendar),"day-selected",G_CALLBACK(selecionadata),widge);
//  g_signal_connect_swapped(G_OBJECT(windowpdv), "destroy",G_CALLBACK(gtk_main_quit), NULL);
gtk_widget_show_all(wdata);
gtk_main();

}


