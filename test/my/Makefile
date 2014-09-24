NAME = testmy
SRC = testmy.c
OBJ = $(SRC:.c=.o)
RM = rm -f
INCLUDE_PATH = ../../include
LIB_PATH = ../../lib

all:
	gcc -I $(INCLUDE_PATH) -L $(LIB_PATH) -DT1 -DT2 $(SRC) -lmy -o $(NAME)

t1:
	gcc -I $(INCLUDE_PATH) -L $(LIB_PATH) -DT1 $(SRC) -lmy -o $(NAME)1

t2:
	gcc -I $(INCLUDE_PATH) -L $(LIB_PATH) -DT2 $(SRC) -lmy -o $(NAME)2

clean:
	-$(RM) *~
	-$(RM) \#*
	-$(RM) *.o
	-$(RM) *.core

fclean:	clean
	-$(RM) $(NAME)

re: fclean all


