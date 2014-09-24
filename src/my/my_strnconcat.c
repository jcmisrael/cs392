#include "my.h"

/* my_strnconcat.c
pre: Takes 2 char* and 1 unsigned int
post: returns a pointer to a string which is the concatenation of char 1 and the first n chars of char 2
*/
char* my_strnconcat(char* s1, char* s2, unsigned int n){
  if(s1 && s2){
    int l1 = my_strlen(s1);
    int l2 = my_strlen(s2);
    if(n > l2)
      n = l2;
    char* s3 = xmalloc((l1 + n) * sizeof(char) + 1);
    int i;
    int j;
    for(i = 0; s1[i]; s3[i] = s1[i++])
      ;
    for(j = 0; j < n; s3[i++] = s2[j++])
      ;
    return s3;
  } else if (s1)
    return my_strdup(s1);
  else if (s2) {
    int l2 = my_strlen(s2);
    if(n > l2)
      n = l2;
    char* s3 = xmalloc(n * sizeof(char) + 1);
    int i;
    for(i = 0; i < n; s3[i] = s2[i++])
      ;
    return s3;
  } else
    return NULL;
}
