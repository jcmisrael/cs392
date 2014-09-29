#include "my.h"

/*
my_strrpos.c
pre: take a char s and char* str
post: return the int corrosponding to the last occurence of s in str
*/
int my_strrpos(char* str, char s){
  int i = -1;
  int j = 0;
  if(str)
    for(; *str != '\0'; str++, j++)
      if(*str == s)
	i = j;
  return i;
}
