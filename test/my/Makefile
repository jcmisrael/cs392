NAME = testmy
SRC = testmy.c
OBJ = $(SRC:.c=.o)
RM = rm -f
CC = clang
INCLUDE_PATH = ../../include
LIB_PATH = ../../lib
LIBS = -lmy -lcunit

all:
	$(CC) -I $(INCLUDE_PATH) -L $(LIB_PATH) -DT1 -DT2 $(SRC) $(LIBS) -o $(NAME)

t1:
	$(CC) -I $(INCLUDE_PATH) -L $(LIB_PATH) -DT1 $(SRC) $(LIBS) -o $(NAME)1

t2:
	$(CC) -I $(INCLUDE_PATH) -L $(LIB_PATH) -DT2 $(SRC) $(LIBS) -o $(NAME)2

clean:
	-$(RM) *~
	-$(RM) \#*
	-$(RM) *.o
	-$(RM) *.core

fclean:	clean
	-$(RM) $(NAME)

re: fclean all
