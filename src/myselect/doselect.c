#include "myselect.h"

/* doselect.c
pre: takes nothing
post: updates the mode of the current item
*/
void doselect(){
  extern t_env gl_env;
  if(gl_env.elements[gl_env.pos].mode){
    gl_env.elements[gl_env.pos].mode = 0;
    refreshin();
  } else {
    gl_env.elements[gl_env.pos].mode = 1;
    movedown();
  }
}
