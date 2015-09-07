NAME = testmy
SRC = testmy.c
OBJ = $(SRC:.c=.o)
RM = rm -f
CC = clang
INCLUDE_PATH = ../../include
LIB_PATH = ../../lib
LIBS = -lmy -lcunit

all:
	$(CC) -I $(INCLUDE_PATH) -L $(LIB_PATH) $(SRC) $(LIBS) -o $(NAME)

clean:
	-$(RM) *~
	-$(RM) \#*
	-$(RM) *.o
	-$(RM) *.core

fclean:	clean
	-$(RM) $(NAME)

re: fclean all
