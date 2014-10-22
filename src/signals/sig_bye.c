#include "signals.h"

/* sig_bye.c
pre: takes no input
post: calls exit with a goodbye message
*/
void sig_bye(){
  my_str("\nSignal server exiting.\n");
  exit(0);
}
