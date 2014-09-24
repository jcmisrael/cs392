NAME = testmylist
SRC = testmylist.c
OBJ = $(SRC:.c=.o)
RM = rm -f
INCLUDE_PATH = ../../include
LIB_PATH = ../../lib

all:
	gcc -I $(INCLUDE_PATH) -L $(LIB_PATH) $(SRC) -lmylist -lmy -o $(NAME)

clean:
	-$(RM) *~
	-$(RM) \#*
	-$(RM) *.o
	-$(RM) *.core

fclean:	clean
	-$(RM) $(NAME)

re: fclean all


