#include "my.h"

/* my_strncmp.c
pre: takes a char* c, char* c2, and int n
post: returns n = <0, 0, >0 corresponding to whether the string at c and c2 are less than one another, equal, or greater than
 */
int my_strncmp(char* s1, char* s2, unsigned int n){
  if(s1 != NULL && s2 != NULL && n != 0){
    for(; *s1 != '\0' && *s2 != '\0' && *s1 == *s2 && n > 1; ++s1, ++s2, --n)
      ;
    if(s1 && s2)
      return *s1 - *s2;
    else
      return (*s1) ? 1 : -1;
  } else if (s1 != s2 && n != 0)
    return (s1) ? 1 : -1;
  return 0;
}
