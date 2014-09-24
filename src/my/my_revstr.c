#include "my.h"

/*
my_revstr.c
pre: takes a char*
post: returns the length of the reversed string and reverses it
*/
int my_revstr(char* str){
  int l = my_strlen(str) - 1;
  int i = 0;
  if(l > 1){
    for(; i < l/2; ++i){
      str[i] ^= str[l-i];
      str[l-i] ^= str[i];
      str[i] ^= str[l-i];
    }
  }
  return l + 1;
}
