#include "myselect.h"

/* init_caps.c
pre: takes nothing
post: sets all the global string values
*/
void init_caps(){
  char* term;
  char area[2048];
  extern t_env gl_env;
#ifdef DEBUG
  my_str("GETENV and TGETENT\n");
#endif
  if(!(term = getenv("TERM")))
    my_err("Could not getenv");
  if(!(tgetent(area, term)))
    my_err("Could not load entry for term");
#ifdef DEBUG
  my_str("INIT GL_ENV VARS\n");
#endif
  gl_env.left = term_get_cap(LEFT);
  gl_env.right = term_get_cap(RIGHT);
  gl_env.up = term_get_cap(UP);
  gl_env.down = term_get_cap(DOWN);
#ifdef DEBUG
  my_str("INIT ESC CAP\n");
#endif
  /*gl_env.esc = term_get_cap(ESC);*/
#ifdef DEBUG
  my_str("INIT ESC CAP DONE\n");
#endif
  gl_env.underline = term_get_cap(UNDERLINE);
  gl_env.under_end = term_get_cap(UNDER_END);
  gl_env.standout = term_get_cap(STANDOUT);
  gl_env.stand_end = term_get_cap(STAND_END);
  gl_env.move = term_get_cap(MOVE);
  gl_env.clear = term_get_cap(CLEAR);
#ifdef DEBUG
  my_str("INIT CURSOR CAP\n");
#endif
  gl_env.cursoroff = term_get_cap(CURSOROFF);
  gl_env.cursoron = term_get_cap(CURSORON);
#ifdef DEBUG
  my_str("INIT CURSOR CAP DONE\n");
#endif
}
