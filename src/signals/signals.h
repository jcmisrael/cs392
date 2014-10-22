/* signals
Server and Client for practicing signals */

#ifndef _SIGNALS_H_
#define _SIGNALS_H_

#include <signal.h>
#include "my.h"

typedef struct s_env {
  pid_t clipid;
  char done;
} t_env;

t_env gl_env;

void sig_ack();
void sig_alarm();
void sig_bye();
void send_message(char*, pid_t);
void send_char(char, pid_t);
void send_pid(pid_t, pid_t);
void get_client_pid(int);
void get_char(int);

#endif

