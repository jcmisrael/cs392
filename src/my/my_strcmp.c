#include "my.h"

/* my_strcmp.c
pre: takes two char*
post: returns an int comparing the two char*, -1 if less, 0 if equal, 1 if the first parameter is greater than the second
*/
int my_strcmp(char* s1, char* s2){
  if(s1 != NULL && s2 != NULL){
    for(; *s1 != '\0' && *s2 != '\0' && *s1 == *s2; s1++, s2++)
      ;
    if(s1 && s2)
      return *s1 - *s2;
    else
      return (*s1) ? 1 : -1;
  } else if (s1 != s2)
    return (s1) ? 1 : -1;
  return 0;
}
