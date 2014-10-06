#include "my.h"

int main(int agrc, char** argv){
  int fds[2];
  pid_t pid;
  int mSize = 4;
  char* messageSent = my_strdup("TEST");
  char* messageRecieved = xmalloc((mSize + 1) * sizeof(char));
  messageRecieved[mSize + 1] = '\0';

  if(pipe(fds) < 0)
    my_str("PIPE ERROR");
  if((pid = fork()) < 0)
    my_str("Fork Error");
  else if (pid > 0){
    close(fds[0]);
    write(fds[1], messageSent, mSize);
  } else {
    close(fds[1]);
    read(fds[0], messageRecieved, mSize);
    my_str(messageRecieved);
  }

  my_char('\n');
  return 1;
}
