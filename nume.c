#include "nume.h"


int numep (void){
int i;


 FILE *f= fopen("nume.txt", "r");
  size_t len= 2; // valor arbitrário
  char *linha= malloc(len);

if (!f)
  {
    perror("nume.txt");
    exit(1);
  }
  while (getline(&linha, &len, f) > 0)
  {
   // printf("%s", linha);
    sscanf(linha,"%d",&i);
  }
  if (linha)
    free(linha);
  fclose(f);


return i;
}
