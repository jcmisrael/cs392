#include "my.h"

/*
my_strlen.c
pre: takes a character string
post: returns the integer length of the string
*/
int my_strlen(char* c){
  int length = -1;
  if(c != NULL){
    ++length;
    for(; *c != '\0'; c++)
      ++length;
  }
  return length;
}
