#include<gtk/gtk.h>


int maskcpf(GtkWidget *widget,GdkEventKey *event,gpointer *poi){
char tt[20];
int bak;
gint *j;
if(event->keyval == 65288){ //g_print("erro");
bak=0;}else {
j = gtk_editable_get_position(GTK_EDITABLE(widget)); 
if( j == 3) { 
sprintf(tt,"%s.",gtk_entry_get_text(GTK_ENTRY(widget)));
gtk_entry_set_text(GTK_ENTRY(widget),tt);
gtk_editable_set_position(GTK_EDITABLE(widget),4); 
}
if( j == 7) { 
sprintf(tt,"%s.",gtk_entry_get_text(GTK_ENTRY(widget)));
gtk_entry_set_text(GTK_ENTRY(widget),tt);
gtk_editable_set_position(GTK_EDITABLE(widget),8); 

}
if( j == 11) { 
sprintf(tt,"%s-",gtk_entry_get_text(GTK_ENTRY(widget)));
gtk_entry_set_text(GTK_ENTRY(widget),tt);
gtk_editable_set_position(GTK_EDITABLE(widget),12); 
}
}
return 0;
}
