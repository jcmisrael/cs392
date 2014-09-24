NAME = libmylist.a
SRC = new_node.c add_node.c add_elem.c traverse_string.c traverse_char.c traverse_int.c append.c add_node_at.c remove_node.c remove_node_at.c remove_last.c count_nodes.c node_at.c elem_at.c empty_list.c
OBJ = $(SRC:.c=.o)
RM = rm -f
INCL_PATH = ../../include
LIB_PATH = ../../lib
CFLAGS += -I$(INCL_PATH)
debug : CFLAGS += -DDEBUG

all:	$(OBJ)
	ar -rc $(LIB_PATH)/$(NAME) $(OBJ)
	ranlib $(LIB_PATH)/$(NAME)

debug:	all

clean:
	-$(RM) *~
	-$(RM) \#*
	-$(RM) *.o
	-$(RM) *.core

fclean:	clean
	-$(RM) $(LIB_PATH)/$(NAME)

re: fclean all
