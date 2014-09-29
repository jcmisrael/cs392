#include "my.h"

/* my_strconcat.c
pre: takes two char*
post: returns a pointer to a concatenation of the two char*
 */
char* my_strconcat(char* s1, char* s2){
  if(s1 != NULL && s2 != NULL){
    int l1 = my_strlen(s1);
    int l2 = my_strlen(s2);
    char* s3 = xmalloc((l1 + l2) * sizeof(char) + 1);
    int i;
    int j;
    for(i = 0; s1[i]; i++)
     s3[i] = s1[i];
    for(j = 0; s2[j]; i++, j++)
      s3[i] = s2[j];
    s3[i] = '\0';
    return s3;
  } else
    return (s1) ? my_strdup(s1) : ((s2) ? my_strdup(s2) : NULL);
}
