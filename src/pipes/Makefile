NAME = testpipes
SRC = main.c
OBJ = $(SRC:.c=.o)
RM = rm -f
INCL_PATH = ../../include
LIB_PATH = ../../lib
CFLAGS += -I $(INCL_PATH) -L $(LIB_PATH) -pedantic-errors -Wall
debug : CFLAGS += -DDEBUG

all:	
	gcc $(CFLAGS) $(SRC)  -lmy -o $(NAME)

clean:	
	-$(RM) *~
	-$(RM) \#*
	-$(RM) *.o
	-$(RM) *.core

fclean:	clean
	-$(RM) $(NAME)

re:	fclean all
