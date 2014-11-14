#include "myselect.h"

/* term_underend.c
pre: Takes nothing
post: Prints the underend entry to termprint
*/
void term_underend(){
  extern t_env gl_env;
  tputs(gl_env.under_end, 1, my_termprint);
}
