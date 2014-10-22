#include "signals.h"

/* get_client_pid.c
pre: takes a signal
post: updates the client pid
*/
void get_client_pid(int sig){
  static unsigned char count = 0;
  static pid_t pid = 0;
  extern t_env gl_env;
  if(count != 0)
    pid = pid << 1;
  if(sig == SIGUSR1){
    pid |= 0;
  } else if(sig == SIGUSR2){
    pid |= 1;
  }
  ++count;
  if(count >= (8 * sizeof(pid_t))){
    gl_env.clipid = pid;
    count = 0;
    pid = 0;
  }
#if 0
  my_int((int) pid);
  my_char('\n');
#endif
}
