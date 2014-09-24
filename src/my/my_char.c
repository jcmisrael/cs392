#include "my.h"

/*
my_char.c
pre: Take a char
post: Write char to standard output
*/
void my_char(char c){
  write(1, &c, 1);
}
