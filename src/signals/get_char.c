#include "signals.h"

/* get_char.c
pre: takes a signal
post: gets a character and either eventually prints it or signals its done printing
*/
void get_char(int sig){
  static unsigned char count = 0;
  static char c = 0;
  extern t_env gl_env;
#if 0
  my_str("Recieved Signal for Char.\n");
#endif
  if(sig == SIGUSR1)
    c |= 0;
  else if(sig == SIGUSR2)
    c |= 1;
  ++count;
  if(count >= (8 * sizeof(char))){
    if(c == '\0'){
      my_str("Setting done flag.\n");
      gl_env.done = 1;
    }else {
      my_char(c);
      count = 0;
      c = 0;
    }
  } else
    c = c << 1;
  kill(gl_env.clipid, SIGUSR1);
}
