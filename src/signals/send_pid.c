#include "signals.h"

/* send_pid.c
pre: takes a pid_t clipid and t_pid servpid
post: encodes the pid_t clipid in binary and sends it to the server at servpid
*/
void send_pid(pid_t clipid, pid_t serpid){
  pid_t mask;
  unsigned char i;
  mask = 1 << (8*sizeof(pid_t) - 1);
  for(i = 0; i < (8*sizeof(pid_t)); ++i){
    if(clipid & mask)
      kill(serpid, SIGUSR2);
    else
      kill(serpid, SIGUSR1);
    clipid = clipid << 1;
    usleep(2000);
  }
}
