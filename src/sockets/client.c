#include "sockets.h"

#define BUF_LEN_MAX 256

int servfd;

void sig_bye(){
  extern int servfd;
  send(servfd, "/exit", 6, 0);
  close(servfd);
  my_str("\nExiting myirc_client.\n");
  exit(0);
}

int main(int argc, char** argv){
  struct addrinfo* ailist;
  struct addrinfo* currai;
  struct addrinfo hint;
  extern int servfd;
  int err;
  char* input = NULL;
  int strLen;
  char** inputVect = NULL;
  if(argc != 3){
    my_str("Usage: ./myirc_client <hostname> <port>\n");
    exit(1);
  }
  signal(SIGINT, sig_bye);
  signal(SIGQUIT, sig_bye);
  input = xmalloc(BUF_LEN_MAX);
  hint.ai_flags = 0;
  hint.ai_family = AF_INET;
  hint.ai_socktype = SOCK_STREAM;
  hint.ai_protocol = 0;
  hint.ai_addrlen = 0;
  hint.ai_canonname = NULL;
  hint.ai_addr = NULL;
  hint.ai_next = NULL;
  if((err = getaddrinfo(argv[1], argv[2], &hint, &ailist)) != 0){
    my_str((char*)gai_strerror(err));
    exit(1);
  }
  for(currai = ailist; currai != NULL; currai = currai->ai_next){
    if((servfd = socket(currai->ai_family, SOCK_STREAM, 0)) >= 0){
      if(connect(servfd, currai->ai_addr, currai->ai_addrlen) == 0){
	my_str("Enter username: ");
	strLen = read(0, input, BUF_LEN_MAX) - 1;
	input[strLen] = '\0';
#ifdef DEBUG
	my_str("Sending username.\n");
#endif
	send(servfd, input, strLen, 0);
	while(1){
	  my_char('>');
	  strLen = read(0, input, BUF_LEN_MAX) - 1;
	  if(strLen >= 1){
#ifdef DEBUG
	    my_str("Input accepted.\n");
#endif
	    input[strLen] = '\0';
	    inputVect = my_str2vect(input);
	    if(!my_strcmp(inputVect[0], "/exit")){
	      send(servfd, inputVect[0], 6, 0);
	      my_str("Exiting myirc_client.\n");
	      close(servfd);
	      exit(0);
	    } else {
	      send(servfd, input, strLen, 0);
	    }
	    my_freevect(inputVect);
	  }
	}
      }
      close(servfd);
      my_err("Connect error");
    }
    close(servfd);
    my_err("Socket error");
  }
  exit(0);
}
