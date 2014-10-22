#include "signals.h"

/* send_message.c
pre: takes a char* str and pid_t serpid
post: sends the binary encoded message to the server
*/
void send_message(char* str, pid_t serpid){
  for(;*str;str += sizeof(char)){
#if 0
    my_str("SENDING CHAR");
#endif
    send_char(*str, serpid);
  }
  send_char('\0', serpid);
}
