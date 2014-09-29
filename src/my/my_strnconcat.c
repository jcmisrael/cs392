#include "my.h"

/* my_strnconcat.c
pre: Takes 2 char* and 1 unsigned int
post: returns a pointer to a string which is the concatenation of char 1 and the first n chars of char 2
*/
char* my_strnconcat(char* s1, char* s2, unsigned int n){
  int l1 = NULL;
  int l2 = NULL;
  char* s3 = NULL;
  int i = NULL;
  int j = NULL;
  if(s1 && s2){
    l1 = my_strlen(s1);
    l2 = my_strlen(s2);
    if(n > l2)
      n = l2;
    s3 = xmalloc((l1 + n) * sizeof(char) + 1);
    for(i = 0; s1[i]; i++)
      s3[i] = s1[i];
    for(j = 0; j < n; i++, j++)
      s3[i] = s2[j];
    return s3;
  } else if (s1)
    return my_strdup(s1);
  else if (s2) {
    l2 = my_strlen(s2);
    if(n > l2)
      n = l2;
    s3 = xmalloc(n * sizeof(char) + 1);
    for(i = 0; i < n; ++i)
      s3[i] = s2[i];
    return s3;
  } else
    return NULL;
}
