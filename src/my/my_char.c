#include "my.h"

/*
my_char.c
pre: Take a char
post: Write char to standard output
*/
ssize_t my_char(char c){
  return write(1, &c, 1);
}
