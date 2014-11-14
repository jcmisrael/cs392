#include "myselect.h"

/* moveup.c
pre: takes nothing
post: moves the cursor UP
*/
void moveup(){
#ifdef DEBUG
  my_str("Moving up");
#endif
  refreshout(gl_env.pos);
  /*  gl_env.pos = ((gl_env.pos - 1) % gl_env.nbelems);*/
  --gl_env.pos;
  if(gl_env.pos < 0)
  gl_env.pos = gl_env.nbelems - 1;
  refreshin();
}
