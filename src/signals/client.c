#include "signals.h"

/* client.c */
int main(int argc, char** argv){
  extern t_env gl_env;
  int pid_int;
  pid_t serpid;
  char* str;
  if(argc >= 3){
    gl_env.done = 0;
    pid_int = my_atoi(argv[1]);
    serpid = (pid_t) pid_int;
    signal(SIGUSR1, sig_ack);
    signal(SIGALRM, sig_alarm);
#if 0
    my_str("About to send pid.\n");
#endif
    send_pid(getpid(), serpid);
    if(!gl_env.done){
#ifdef DEBUG
      my_str("Waiting for alarm.\n");
#endif
      alarm(2);
      pause();
    }
    alarm(0);
    str = my_vect2str(&(argv[2]));
#if 0
    my_str(str);
    my_char('\n');
#endif
    send_message(str, serpid);
  }
  return 0;
}
