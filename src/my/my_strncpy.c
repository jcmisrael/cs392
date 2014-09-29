#include "my.h"

/* my_strncpy.c
pre: takes two char* and 1 unsigned int
post: copies the first n chars of char2 into char1 and returns a pointer to it 
*/
char* my_strncpy(char* s1, char* s2, unsigned int n){
  int i;
  if(s1 && s2){
    for(i = 0; n > 0 && s2[i]; ++i, --n)
      s1[i] = s2[i];
    if(!s2[i] && n)
      for(; n > 0; ++i, --n)
	s1[i] = '\0';
    return s1;
  } else
    return (s1) ? s1 : NULL;
}
