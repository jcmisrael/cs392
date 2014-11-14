#include "myselect.h"

/* term_clear.c
pre: Takes nothing'
post: Clears the terminal screen
*/
void term_clear(){
  extern t_env gl_env;
  tputs(gl_env.clear, 1, my_termprint);
}
