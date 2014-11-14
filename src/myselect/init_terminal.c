#include "myselect.h"

/* init_terminal.c
pre: Takes nothing
post: Backups old terminal env, sets new one
*/
void init_terminal(){
  int term_fd;
  struct termio line;
  char* term;
  extern t_env gl_env;
#ifdef DEBUG
  my_str("INIT TERM\n");
#endif
  term_fd = 0;
  ioctl(term_fd, TCGETA, &line);
  gl_env.line_backup = line;

  line.c_lflag &= ~(ICANON | ECHO | ISIG);
  line.c_cc[VTIME] = READTIME;
  line.c_cc[VMIN] = READMIN;
  ioctl(term_fd, TCSETA, &line);
  
  ioctl(term_fd, TIOCGWINSZ, &(gl_env.win));
  
  term = ttyname(term_fd);
  term_fd = open(term, O_WRONLY);
  gl_env.stdio_backup = dup(1);
  dup2(term_fd, 1);
#ifdef DEBUG
  my_str("TERM INIT DONE\n");
#endif
}
