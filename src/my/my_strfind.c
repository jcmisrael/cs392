#include "my.h"

/* my_strfind.c
pre: takes a char* and a char
post: returns a char* pointing to the first instance of char found in char* 
*/
char* my_strfind(char* s1, char c){
  if(s1){
    for(; *s1 && *s1 != c; s1++)
      ;
    return (*s1 == c) ? s1 : NULL;
  } else
    return NULL;
}
