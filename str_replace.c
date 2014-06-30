
#include "str_replace.h"

char * str_replace(char *str, char *old,char *new) {
  int i, count = 0;
  int newlen = strlen(new);
  int oldlen = strlen(old);
 
  for (i = 0; str[i]; ++i)
    if (strstr(&str[i], old) == &str[i])
      ++count, i += oldlen - 1;
 
  char *ret = (char *) calloc(i + 1 + count * (newlen - oldlen), sizeof(char));
  if (!ret) return;
 
  i = 0;
  while (*str)
    if (strstr(str, old) == str)
      strcpy(&ret[i], new),
      i += newlen,
      str += oldlen;
    else
      ret[i++] = *str++;
   
  ret[i] = '\0';

  return ret;
}

