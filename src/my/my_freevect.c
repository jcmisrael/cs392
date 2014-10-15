#include "my.h"

/* my_freevect.c
pre: takes a char** vectir
post: frees all of the pointers in the vector, and frees the vector itself.
*/
void my_freevect(char** vect){
  int i;
  for(i = 0; vect[i]; ++i)
    free(vect[i]);
  free(vect);
}
