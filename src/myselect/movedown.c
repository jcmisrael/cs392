#include "myselect.h"

/* movedown.c
pre: takes nothing
post: moves the cursor down
*/
void movedown(){
  extern t_env gl_env;
#ifdef DEBUG
  my_str("Moving down");
#endif
  refreshout(gl_env.pos);
  gl_env.pos = ((gl_env.pos + 1) % gl_env.nbelems);
  refreshin();
}
