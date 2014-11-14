#include "myselect.h"

/* show_elems.c
pre: Takes nothing
post: prints everything in the global elements array to the screen
*/
void show_elems(){
  int i;
  int x;
  int y;
  int max;
  extern t_env gl_env;
  term_clear();
  gl_env.flag = 0;
  for(i = 0, y = 0, x = 0, max = 0; i <  gl_env.nbelems; ++i, ++y){
    if(y >= gl_env.win.ws_row){
      y = 0;
      x += max + 3;
      max = 0;
    }
    if(max < gl_env.elements[i].size)
      max = gl_env.elements[i].size;
    if(max + x > gl_env.win.ws_col){
      term_clear();
      my_str("Please enlarge window");
      gl_env.flag = 1;
      break;
    }
    gl_env.elements[i].x = x;
    gl_env.elements[i].y = y;
    refreshout(i);
  }
  if(!gl_env.flag)
    refreshin();
}
