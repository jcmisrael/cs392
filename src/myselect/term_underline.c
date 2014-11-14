#include "myselect.h"

/* term_underline.c
pre: Takes nothing
post: Prints the underline entry to termprint
*/
void term_underline(){
  extern t_env gl_env;
  tputs(gl_env.underline, 1, my_termprint);
}
