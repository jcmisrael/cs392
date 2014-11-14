#include "myselect.h"

/* win_resize.c
pre: Takes nothing
post: Regets the window size and calls show_elems
*/
void win_resize(){
  extern t_env gl_env;
  int term_fd;
  term_fd = 0;
  ioctl(term_fd, TIOCGWINSZ, &(gl_env.win));
  show_elems();
}
