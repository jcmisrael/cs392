#include "myselect.h"

/* term_standend.c
pre: Takes nothing
post: Prints the standend entry to termprint
*/
void term_standend(){
  extern t_env gl_env;
  tputs(gl_env.stand_end, 1, my_termprint);
}
