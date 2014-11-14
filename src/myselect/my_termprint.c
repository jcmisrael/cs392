#include "myselect.h"

/* my_termprint.c
pre: takes a char*
post: writes the char* to the standard output
*/
int my_termprint(int c){
  return write(1, &c, sizeof(char));
}
