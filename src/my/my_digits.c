#include "my.h"

/*
my_digits.c
pre: Nothing
post: print out [0-9]
*/
void my_digits(){
  char c;
  for(c = '0'; c < '9'; ++c)
    my_char(c);
}
