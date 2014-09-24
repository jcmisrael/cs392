#include "my.h"

/*
my_num_base.c
pre: takes an int and a character set representing the number base
post: prints the number in the selected base character set
*/

void my_num_base(int n, char* baseset){
  if(baseset != NULL && *baseset != '\0'){
    unsigned char base = 0;
    unsigned int divisor = 1;
    unsigned int pn;
    while(*baseset != '\0'){
      baseset++;
      base++;
    }
    baseset -= (base * sizeof(char));
    if(n < 0){
      my_char('-');
      pn = -n;
    } else 
      pn = n;
    if(base != 1){
      for(; (n/base) != 0; n /= base)
	divisor *= base;
      for(; divisor != 0; divisor /= base)
	my_char(baseset[((pn / divisor) % base)]);
    } else
      for(; pn > 0; --pn)
	my_char(baseset[0]);
  } else {
    my_str("Invalid number base.");
  }
}
