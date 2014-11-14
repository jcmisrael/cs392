#include "myselect.h"

/* term_ve.c
pre: Takes nothing
post: Prints the ve entry to termprint
*/
void term_ve(){
  extern t_env gl_env;
  tputs(gl_env.cursoron, 1, my_termprint);
}
