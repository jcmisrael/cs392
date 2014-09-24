#include "my.h"

/* my_strrfind.c
pre: takes a char* and a char to search for in char*
post: returns a char* pointing to the last found occurence of char in char*
*/
char* my_strrfind(char* s1, char c){
  char* r = NULL;
  if(s1)
    for(;*s1; s1++)
      if(*s1 == c)
	r = s1;
  return r;
}
