#include "myselect.h"

/* term_get_cap.c
pre: takes a char*
post: returns the string entry for the passed char*
*/
char* term_get_cap(char* c){
  char* str;
  char area[2048];
  if(!(str = tgetstr(c, (char**)area)))
     my_err("Could not return string entry from tgetstr");
  return str;
}
  
