#include "myselect.h"

/* restore_terminal.c
pre: Takes nothing
post: Restores the terminal to its state prior to running myselect
*/
void restore_terminal(){
#ifdef DEBUG
  my_str("Restoring terminal");
#endif
  int term_fd;
  struct termio line;
  extern t_env gl_env;

  term_clear();

  term_fd = 0;
  line = gl_env.line_backup;
  ioctl(term_fd, TCSETA, &line);

  dup2(gl_env.stdio_backup, 1);
}
