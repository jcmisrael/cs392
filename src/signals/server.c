#include "signals.h"

/* server.c */
int main(int argc, char** argv){
  int i;
  extern t_env gl_env;
  my_int(getpid());
  signal(SIGINT, sig_bye);
  signal(SIGQUIT, sig_bye);
  while(1){
    gl_env.done = 0;
    gl_env.clipid = 0;
    signal(SIGUSR1, get_client_pid);
    signal(SIGUSR2, get_client_pid);
#ifdef DEBUG
    my_str("Waiting for client pid.\n");
#endif
    for(i = 0; i < (8 * sizeof(pid_t)); ++i)
      pause();
#ifdef DEBUG
    my_str("Client Pid Recieved: ");
    my_int((int) gl_env.clipid);
    my_str("\nWaiting for Message.\n");
    my_str("MESSAGE RECIEVED: ");
#endif
    signal(SIGUSR1, get_char);
    signal(SIGUSR2, get_char);
    kill(gl_env.clipid, SIGUSR1);
    while(!gl_env.done)
      pause();
#ifdef DEBUG
    my_str("Done printing string.\n");
#endif
    my_str("\n\n");
  }
  return 0;
}
