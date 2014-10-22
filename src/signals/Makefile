SERVER_NAME = signal_server
CLIENT_NAME = signal_client
DEP_SRC = send_message.c send_char.c
SERVER_SRC = server.c $(DEP_SRC) get_client_pid.c get_char.c sig_bye.c
CLIENT_SRC = client.c $(DEP_SRC) send_pid.c sig_ack.c sig_alarm.c
RM = rm -f
CC = gcc
INCL_PATH = ../../include
LIB_PATH = ../../lib
CFLAGS += -I $(INCL_PATH) -L $(LIB_PATH) -pedantic-errors -Wall
debug : CFLAGS += -DDEBUG

all:	server client

server:	
	$(CC) $(CFLAGS) $(SERVER_SRC) -lmy -o $(SERVER_NAME)

client:	
	$(CC) $(CFLAGS) $(CLIENT_SRC) -lmy -o $(CLIENT_NAME)

debug:	all

clean:	
	-$(RM) *~
	-$(RM) \#*
	-$(RM) *.o
	-$(RM) *.core

fclean:	clean
	-$(RM) $(SERVER_NAME)
	-$(RM) $(CLIENT_NAME)

re:	fclean all
