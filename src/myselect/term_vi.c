#include "myselect.h"

/* term_vi.c
pre: Takes nothing
post: Prints the vi entry to termprint
*/
void term_vi(){
  extern t_env gl_env;
  tputs(gl_env.cursoroff, 1, my_termprint);
}
