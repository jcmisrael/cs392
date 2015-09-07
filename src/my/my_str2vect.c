#include "my.h"

/* my_str2vect.h
pre: takes a char*
post: returns a char** containing strings composing the inputed char*
*/
char** my_str2vect(char* str){
  int vectS;
  int strLen;
  int i;
  char** vect = NULL;
  char* substringStart = NULL;
  i = 0;
  while(str[i]){
    for(; str[i] == ' ' || str[i] == '\t'; ++i)
      ;
    if(str[i])
      ++vectS;
    for(; str[i] != ' ' && str[i] != '\t' && str[i]; ++i)
      ;
#ifdef DEBUG
    my_str("Count number of strings.\n");
    my_char(str[i]);
    my_char('\n');
#endif
  }
  vect = xmalloc((vectS * sizeof(char*)) + 1);
  i = 0;
  vectS = 0;
  while(str[i]){
    for(; str[i] == ' ' || str[i] == '\t'; ++i)
      ;
    if(str[i]){
      substringStart = &(str[i]);
      for(strLen = 0; str[i] != ' ' && str[i] != '\t' && str[i]; ++i)
          ++strLen;
      vect[vectS] = xmalloc((strLen * sizeof(char)) + 1);
      my_strncpy(vect[vectS], substringStart, strLen);
      vect[vectS][strLen] = '\0';
      ++vectS;
    }
#ifdef DEBUG
    my_str("Init and copying strings.\n");
#endif
  }
  vect[vectS] = NULL;
  return vect;
}
