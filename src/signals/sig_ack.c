#include "signals.h"

/* sig_ack.c
pre: takes nothing
post: sets the done global var when it recieves a signal */
void sig_ack(){
  extern t_env gl_env;
  gl_env.done = 1;
#if 0
  my_str("ack recieved.\n");
#endif
}
