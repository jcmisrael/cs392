SERVER_NAME = myirc_server
CLIENT_NAME = myirc_client
SERVER_SRC = server.c
CLIENT_SRC = client.c
RM = rm -f
CC = gcc
INCL_PATH = ../../include
LIB_PATH = ../../lib
CFLAGS += -I $(INCL_PATH) -L $(LIB_PATH) -pedantic-errors -Wall
GTKFLAGS = `pkg-config --cflags --libs gtk+-2.0`
debug : CFLAGS += -DDEBUG

all:	server client

server:	
	$(CC) $(CFLAGS) $(SERVER_SRC) -lmy -o $(SERVER_NAME)

client:	
	$(CC) $(CFLAGS) $(CLIENT_SRC) -lmy -o $(CLIENT_NAME) $(GTKFLAGS)

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
