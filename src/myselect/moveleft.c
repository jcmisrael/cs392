#include "myselect.h"

/* moveleft.c
pre: takes nothing
post: moves the cursor left
*/
void moveleft(){
  extern t_env gl_env;
  refreshout(gl_env.pos);
  gl_env.pos -= gl_env.win.ws_row;
  if(gl_env.pos < 0)
    gl_env.pos = 0;
  refreshin();
}
