#include "myselect.h"

/* moveleft.c
pre: takes nothing
post: moves the cursor left
*/
void moveleft(){
  refreshout(gl_env.pos);
  gl_env.pos -= gl_env.win.ws_row;
  if(gl_env.pos < 0)
    gl_env.pos = 0;
  refreshin();
}
