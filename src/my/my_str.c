#include "my.h"

/*
my_str.c
pre: Take a char *
post: print the char string to standard output
*/
void my_str(char* str){
  if(str != NULL)
    while(*str)
      my_char(*(str++));
}
