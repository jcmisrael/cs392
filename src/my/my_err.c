#include "my.h"

/* my_err.c
pre: Takes a char*
post: Prints out the error using perror and exits the program
*/
void my_err(char* c){
  perror(c);
  exit(-1);
}
