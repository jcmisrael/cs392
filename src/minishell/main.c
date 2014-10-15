#define PATH_MAX 256
#define MAX_HOST_NAME 64
#define MAX_INPUT_BUF 256

#include "my.h"
#include <sys/wait.h>

void writePrompt(){
  char* hostname = NULL;
  char* cwd = NULL;
  cwd = (char*) xmalloc(PATH_MAX * sizeof(char) + 1);
  hostname = (char*) xmalloc(MAX_HOST_NAME * sizeof(char) + 1);
  gethostname(hostname, MAX_HOST_NAME); 
  getcwd(cwd, PATH_MAX);
  
  my_str("\033[32;1m");
  my_str(getlogin());
  my_char('@');
  my_str(hostname);
  my_str("\033[37;1m");
  my_char(':');
  my_str("\033[34;1m");
  my_str(cwd);
  my_str(" $ ");
  my_str("\033[00m");
}

int main(int argc, char** argv){
  pid_t pid;
  char* input = NULL;
  int strLen;
  char** inputVect = NULL;
  input = (char*) xmalloc(MAX_INPUT_BUF * sizeof(char));
  while(1){
    writePrompt();
    strLen = read(0, input,MAX_INPUT_BUF * sizeof(char)) - 1;
    input[strLen] = '\0';
    if(strLen >= 2){
      inputVect = my_str2vect(input);
      if(!my_strcmp(inputVect[0], "exit")){
	my_str("Exiting minishell. Goodbye!\n");
	exit(1);
      } else if(!my_strcmp(inputVect[0], "cd"))
	chdir(inputVect[1]);
      else {
	if((pid = fork()) < 0){
	  my_str("FORK ERROR");
	  exit(1);
	} else if (pid > 0){
	  while(wait(NULL) != pid)
	    ;
	  /*my_freevect(inputVect); */
	} else {
	  if(execvp(inputVect[0], inputVect) < 0){
	    my_str("ERROR: execvp failed.\n");
	    exit(1);
	  }
	}
      }
    }
  }
}
