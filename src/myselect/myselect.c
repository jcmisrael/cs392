#include "myselect.h"

int main(int argc, char** argv){
  char* buf;
  int i;

  if(argc > 2){
    buf = (char*)xmalloc(BUFMAX * sizeof(char));

    signal(SIGWINCH, win_resize);
    signal(SIGINT, NULL);
    
    setup_elems(argc - 1, &(argv[1]));
    init_caps();
    init_terminal();

    win_resize();
    while(1){
      if((i = read(0, buf, BUFMAX)) > 0){
	buf[i] = '\0';
	i = check_char(buf);
	if(i > 0){
	  term_ve();
	  restore_terminal();
	  if(i > 1)
	    getoutput();
	  return 0;
	}
      } else {
	restore_terminal();
	term_ve();
	return 1;
      }
    }
  } 
  return 0;
}
