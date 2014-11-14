#include "myselect.h"

/* refreshout.c
pre: Takes an element index to print out
post: Prints the element to screen
*/
void refreshout(int i){
  extern t_env gl_env;
  term_move_to_item(i);
  if(gl_env.elements[i].mode)
    term_standout();
  my_str(gl_env.elements[i].elem);
  term_standend();
}
