#include "my.h"

/* my_strcat.h
pre: takes two chars
post: returns char1 with char2 appended to the end
*/
char* my_strcat(char* s1, char* s2){
  if(s1 && s2){
    int i;
    int l1 = my_strlen(s1);
    for(i = 0; s2[i]; s1[l1++] = s2[i++])
      ;
    s1[l1] = '\0';
    return s1;
  } else
    return (s1) ? s1 : NULL;
}
