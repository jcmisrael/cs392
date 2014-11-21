#include "sockets.h"

#define QUEUELENGTH 16

int servfd;
pid_t pid;

void sig_bye(){
  extern pid_t pid;
  extern int servfd;
  if(pid != 0){
    close(servfd);
    my_str("\nmyirc_server shutting down.\n");
  }
  exit(0);
}

int main(int argc, char** argv){
  struct addrinfo *ailist = NULL;
  struct addrinfo *currai = NULL;
  struct addrinfo hint;
  extern int servfd;
  int clientfd;
  int err;
  extern pid_t pid;
  char* username = NULL;
  char* input = NULL;
  char** inputVect = NULL;
  int strLen;
  if(argc != 2){
    my_str("usage: ./myirc <port>\n");
    exit(1);
  }
  signal(SIGINT, sig_bye);
  signal(SIGQUIT, sig_bye);
  input = xmalloc(BUF_LEN_MAX);
  hint.ai_flags = AI_PASSIVE;
  hint.ai_family = AF_INET;
  hint.ai_socktype = SOCK_STREAM;
  hint.ai_protocol = 0;
  hint.ai_addrlen = 0;
  hint.ai_canonname = NULL;
  hint.ai_addr = NULL;
  if((err = getaddrinfo(NULL, argv[1], &hint, &ailist)) != 0){
    my_str((char*)gai_strerror(err));
    exit(1);
  }
  for(currai = ailist; currai != NULL; currai = currai->ai_next){
    
    if((servfd = socket(currai->ai_addr->sa_family, currai->ai_socktype, 0)) >= 0){
      if(bind(servfd, currai->ai_addr, currai->ai_addrlen) >= 0){
	if(listen(servfd, QUEUELENGTH) >= 0){
	  while(1){
#ifdef DEBUG
	    my_str("Waiting for client.\n");
#endif
	    clientfd = accept(servfd, NULL, NULL);
	    if((pid = fork()) < 0)
	      my_err("Fork error");
	    if(pid == 0){
#ifdef DEBUG
	      my_str("Client connected.\n");
#endif
	      while((strLen = recv(clientfd, input, BUF_LEN_MAX, 0)) <= 0)
		;
	      my_str(input);
	      input[strLen] = '\0';
	      inputVect = my_str2vect(input);
	      username = my_strdup(inputVect[0]);
	      my_freevect(inputVect);
	      my_str(" has connected.\n");
	    }
	    for(;pid == 0;){
	      strLen = recv(clientfd, input, BUF_LEN_MAX, 0);
	      if(strLen >= 0){
#ifdef DEBUG
	      my_str("Client input read.\n");
#endif
		input[strLen] = '\0';
		inputVect = my_str2vect(input);
		if(!my_strcmp(inputVect[0], "/exit")){
		  close(clientfd);
		  my_str(username);
		  my_str(" has disconnected.\n");
		  exit(0);
		} else if (!my_strcmp(inputVect[0], "/me")){
		  my_str(username);
		  my_char(' ');
		  my_str(my_vect2str(&(inputVect[1])));
 		} else if (!my_strcmp(inputVect[0], "/nick")){
		  if(inputVect[1]){
		    my_str(username);
		    my_str(" changed name to: ");
		    free(username);
		    username = my_strdup(inputVect[1]);
		    my_str(username);
		  }
		} else {
		  my_str(username);
		  my_str(": ");
		  my_str(input);
		}
		my_char('\n');
	      }
	    }
	  }
	  exit(0);
	}
	close(servfd);
	my_err("Listen error");
      }
      close(servfd);
      my_err("Bind error");
    }
    close(servfd);
    my_err("Socket error");
  }
#ifdef DEBUG
  my_str("EXITING AT END.\n");
#endif
  exit(1);
}
  
