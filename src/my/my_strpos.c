#include "my.h"

/*
my_strpos.c
pre: takes a char and a char*
post: returns an int designating the index of the first occurence of the char in the char*
*/
int my_strpos(char* str, char s){
  int i = -1;
  if(str){
    for(i = 0; str[i] != s && str[i] != '\0'; i++);
    if(str[i] == '\0')
      i = -1;
  }
  return i;
}
