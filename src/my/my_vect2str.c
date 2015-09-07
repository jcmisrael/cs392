#include "my.h"

/* my_vect2str.c
Pre: Takes a char** pointing to an array of strings
Post: Returns a char* pointing a string of the concatenation of all strings found in the supplied char**
*/
char* my_vect2str(char** stringArray){
  char* rString = NULL;
  char* rStringInc = NULL;
  int length;
  int i;
  if(stringArray){
    for(length = 0, i = 0; stringArray[i]; ++i)
      length += my_strlen(stringArray[i]) + 1;
    rString = (char*)xmalloc(length * sizeof(char));
    rStringInc = rString;
    for(i = 0; stringArray[i]; ++i){
      my_strcpy(rStringInc, stringArray[i]);
      rStringInc += (my_strlen(stringArray[i]) * sizeof(char));
      *rStringInc = ' ';
      rStringInc += sizeof(char);
    }
    *(--rStringInc) = '\0';
#ifdef DEBUG
    my_str("Length: ");
    my_int(length);
    my_char('\n');
#endif
  }
  return rString;
}
