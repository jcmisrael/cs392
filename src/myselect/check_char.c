#include "myselect.h"

/* check_char.c
pre: Takes a char* c
post: Takes action based upon what key is pressed
*/
char check_char(char* str){
  if(str){
    if(!(my_strcmp(str, "\n\0")))
      return 2;
    else if(!(my_strcmp(str, ESC)))
      return 1;
    else if (!(my_strcmp(str, KU)))
      moveup();
    else if (!(my_strcmp(str, KD)))
      movedown();
    else if (!(my_strcmp(str, KL)))
      moveleft();
    else if (!(my_strcmp(str, KR)))
      moveright();
    else if (!(my_strcmp(str, " \0")))
      doselect();
    return 0;
  }
  return -1;
}
