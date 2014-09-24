#include "my.h"

/*
xmalloc.x
pre: takes an integer n
post: returns a void* allocated with n bytes
*/
void* xmalloc(int n){
  void* p;
  if((p = malloc(n)) == NULL){
    my_str("Virtual memory exhausted.\n");
    exit(1);
  }
  return p;
}
