#include <gtk/gtk.h>
#include "layout.h"
#include<mysql/mysql.h>
#include "con.h"


gint main( gint argc, gchar *argv[]){

  conecta();
  windowmain(&argc,&argv);


  return 0;

}
