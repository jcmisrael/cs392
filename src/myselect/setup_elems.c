#include "myselect.h"

/* setup_elems.c
pre: Takes an int argc and char** argv
post: mallocs the global array and inserts values
*/
void setup_elems(int argc, char** argv){
  int i;
  extern t_env gl_env;
  gl_env.nbelems = argc;
  gl_env.elements = (t_elem*)xmalloc(argc * sizeof(t_elem));
  for(i = 0; i < argc; ++i){
    gl_env.elements[i].elem = my_strdup(argv[i]);
    gl_env.elements[i].size = my_strlen(argv[i]);
    gl_env.elements[i].mode = 0;
  }
}
