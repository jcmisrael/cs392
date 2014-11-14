#include "myselect.h"

/* getoutput.c
pre: takes nothing
post: outputs all the highlighted elems to stdio
*/
void getoutput(){
  int i;
  extern t_env gl_env;
  for(i = 0; i < gl_env.nbelems; ++i)
    if(gl_env.elements[i].mode){
      my_str(gl_env.elements[i].elem);
      my_char(' ');
    }
}
