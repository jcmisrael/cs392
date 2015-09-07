#include "my.h"

/*
my_revstr.c
pre: takes a char*
post: returns the length of the reversed string and reverses it
*/
int my_revstr(char* str){
    int len;
    int i;
    len = my_strlen(str);
    if(len > 1){
        for(i = 0; i < len/2; ++i){
            str[i] ^= str[len-i-1];
            str[len-i-1] ^= str[i];
            str[i] ^= str[len-i-1];
        }
    }
    return len;
}
