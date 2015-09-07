#include "my.h"
/*
my_int.c
pre: Take an int
post: print the integer to screen
*/
ssize_t my_int(int i){
    unsigned int base;
    unsigned int n;
    ssize_t counter;
    counter = 0;
    base = 1;
    if(i < 0){
        my_char('-');
        n = -i;
        counter++;
    } else
        n = i;
    for(; i/10 != 0; i /= 10)
      base *= 10;
    for(; base != 0; base /= 10){
        my_char('0' + ((n / base) % 10));
        counter++;
    }
    return counter;
}
