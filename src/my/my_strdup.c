#include "my.h"

/* my_strdup.c
pre: Takes a char*
post: returns a char* pointing to a location in memory
*/
char* my_strdup(char* str){
  char* nStr = NULL;
  int l;
  unsigned int i;
  if(str){
    l = my_strlen(str);
    nStr = xmalloc(l * sizeof(char) + 1);
    i = 0;
    for(; str[i] != '\0'; i++)
      nStr[i] = str[i];
    nStr[i] = '\0';
  }
  return nStr;
}
