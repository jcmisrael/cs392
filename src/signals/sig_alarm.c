#include "signals.h"

/* sig_alarm.c
pre: takes nothing
post: exits the program with a bye message
*/
void sig_alarm(){
  my_str("Attempt to contact server timed out.\n");
  exit(1);
}
