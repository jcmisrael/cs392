#include "my.h"

/*
my_str.c
pre: Take a char *
post: print the char string to standard output
*/
ssize_t my_str(char* str){
    ssize_t counter;

    counter = 0;
    if(str != NULL)
        while(*str != '\0')
            counter += my_char(*(str++));
    return counter;
}
