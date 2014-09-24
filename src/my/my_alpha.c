#include "my.h"

/*
my_alpha.c
pre: Nothing
post: print out [a-z]
*/
void my_alpha(){
  char c;
  for(c = 'a'; c < 'z'; ++c)
    my_char(c);
}
