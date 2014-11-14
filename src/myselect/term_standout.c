#include "myselect.h"

/* term_standout.c
pre: Takes nothing
post: Prints the standout entry to termprint
*/
void term_standout(){
  extern t_env gl_env;
  tputs(gl_env.standout, 1, my_termprint);
}
