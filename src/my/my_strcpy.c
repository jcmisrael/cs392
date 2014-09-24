#include "my.h"

/* my_strcpy.c
pre: takes two char*
post: copies the second char* into the first, returning a pointer to it
*/
char* my_strcpy(char* s1, char* s2){
  int i;
  if(s1 && s2){
    for(i = 0; s2[i]; s1[i] = s2[i++])
      ;
    s1[i] = '\0';
    return s1;
  } else
    return (s1) ? s1 : NULL;
}
