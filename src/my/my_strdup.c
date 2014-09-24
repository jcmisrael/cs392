#include "my.h"

/* my_strdup.c
pre: Takes a char*
post: returns a char* pointing to a location in memory
*/
char* my_strdup(char* str){
  char* nStr = NULL;
  if(str != NULL){
    int l = my_strlen(str);
    nStr = xmalloc(l * sizeof(char) + 1);
    unsigned int i = 0;
    for(; str[i] != '\0'; nStr[i] = str[i++]);
    nStr[i] = '\0';
  }
  return nStr;
}
