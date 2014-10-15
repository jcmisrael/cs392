#define PATH_MAX 256

#include "my.h"

int main(int argc, char** argv){
  /*  pid_t pid; */
  char* input = NULL;
  char* cwd = NULL;
  int strLen;
  char** inputVect = NULL;
  cwd = xmalloc(PATH_MAX * sizeof(char) + 1);
  input = xmalloc(128 * sizeof(char));
  while(1){
    getcwd(cwd, PATH_MAX+1);
    my_str("\033[32;1m");
    my_str(getlogin());
    my_char(':');
    my_str("\033[34;1m");
    my_str(cwd);
    my_str(" $ ");
    my_str("\033[39m");
    strLen = read(0, input,128 * sizeof(char)) - 1;
    input[strLen] = '\0';
    if(strLen >= 2){
      inputVect = my_str2vect(input);
      if(!my_strcmp(inputVect[0], "exit"))
	exit(1);
      else if(!my_strcmp(inputVect[0], "cd"))
	chdir(inputVect[1]);
    }
  }
}
