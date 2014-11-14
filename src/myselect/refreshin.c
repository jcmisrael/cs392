#include "myselect.h"

/* refreshin.c
pre: Takes nothing
post: Prints underlines selected elem
*/
void refreshin(){
  extern t_env gl_env;
  term_move_to_item(gl_env.pos);
  term_underline();
  if(gl_env.elements[gl_env.pos].mode)
    term_standout();
  my_str(gl_env.elements[gl_env.pos].elem);
  term_standend();
  term_underend();
}
