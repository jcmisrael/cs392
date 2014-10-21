#include "my.h"

/* my_atoi.c
pre: takes a char*
post: Converts the char* to its representive integer and returns that
*/
int my_atoi(char* str){
  int r;
  int base;
  int i;
  if(str){
    for(i = 0; str[i] == ' ' || str[i] == '\t'; ++i)
      ;
    if(str[i] == '-' || (str[i] >= '0' && str[i] <= '9')){
      if(str[i] == '-'){
	base = -1;
	++i;
      } else
	base = 1;
      for(r = 0; str[i+r] >= '0' && str[i+r] <= '9'; ++r){
	base *= 10;
#ifdef DEBUG
	my_int(base);
	my_char('\n');
#endif
      }
      base /= 10;
      r = 0;
      for(; str[i] >= '0' && str[i] <= '9'; ++i){
	r += (str[i] - '0') * base;
	base /= 10;
      }
    }
  }
  return r;
}
