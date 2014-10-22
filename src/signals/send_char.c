#include "signals.h"

/* send_char.c
pre: takes a char c and t_pid servpid
post: encodes the char c in binary and sends it to the server at servpid
*/
void send_char(char c, pid_t serpid){
  unsigned char mask;
  unsigned char i;
  mask = 0x80;
  for(i = 0; i < (8 * sizeof(char)); ++i){
    if(c & mask)
      kill(serpid, SIGUSR2);
    else
      kill(serpid, SIGUSR1);
    c =  c << 1;
    pause();
  }
}
