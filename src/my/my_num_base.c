#include "my.h"

/*
my_num_base.c
pre: takes an int and a character set representing the number base
post: prints the number in the selected base character set
*/

char* my_num_base(int n, char* baseset){
    if(baseset != NULL && *baseset != '\0'){
        unsigned char base;
        unsigned int divisor;
        unsigned int temp_divisor;
        unsigned int pn;
        unsigned int strlen;
        unsigned int i;
        char* str = NULL;
        base = 0;
        divisor = 1;
        strlen = 0;
        while(*baseset != '\0'){
            baseset++;
            base++;
        }
        baseset -= (base * sizeof(char));
        if(n < 0){
            ++strlen;
            pn = -n;
        } else
            pn = n;
        if(base != 1){
            for(; (n/base) != 0; n /= base)
                divisor *= base;
            temp_divisor = divisor;
            for(; temp_divisor != 0; temp_divisor /= base)
                ++strlen;
            str = (char*)xmalloc((strlen + 1) * sizeof(char));
            i = 0;
            if(n < 0)
                str[i++] = '-';
            for(; divisor != 0; divisor /= base, ++i)
                str[i] = baseset[((pn / divisor) % base)];
            str[strlen] = '\0';
        } else {
            str = (char*)xmalloc((pn + 1) * sizeof(char));
            i = 0;
            if(n < 0)
                str[i++] = '-';
            for(; pn > 0; --pn, ++i)
                str[i] = baseset[0];
            str[strlen] = '\0';
        }
        return str;
    }
    return NULL;
}
