#include "myselect.h"

/* term_move_to_item.c
pre: Takes an int signify index in element array
post: Puts the tty cursor over the index
*/
void term_move_to_item(int i){
  tputs(tgoto(gl_env.move, gl_env.elements[i].x, gl_env.elements[i].y), 1, my_termprint);
}
