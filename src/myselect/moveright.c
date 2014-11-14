#include "myselect.h"

/* moveright.c
pre: Takes nothing
post: moves the cursor right
*/
void moveright(){
  extern t_env gl_env;
  refreshout(gl_env.pos);
  gl_env.pos += gl_env.win.ws_row;
  if(gl_env.pos > gl_env.nbelems)
    gl_env.pos = gl_env.nbelems - 1;
  refreshin();
}
