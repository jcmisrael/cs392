NAME = libmy.a
SRC = my_char.c my_str.c my_int.c my_num_base.c my_alpha.c my_digits.c my_strlen.c my_revstr.c my_strpos.c my_strrpos.c xmalloc.c my_strdup.c my_strcmp.c my_strncmp.c my_strconcat.c my_strnconcat.c my_strnconcat.c my_strcat.c my_strcpy.c my_strncpy.c my_strfind.c my_strrfind.c my_vect2str.c my_str2vect.c my_freevect.c my_atoi.c my_err.c
OBJ = $(SRC:.c=.o)
RM = rm -f
INCL_PATH = ../../include
LIB_PATH = ../../lib
CFLAGS += -I$(INCL_PATH) -pedantic-errors -Wall
debug : CFLAGS += -DDEBUG

all:	$(OBJ)
	ar -rc $(LIB_PATH)/$(NAME) $(OBJ)
	ranlib $(LIB_PATH)/$(NAME)

debug:	fclean all

clean:
	-$(RM) *~
	-$(RM) \#*
	-$(RM) *.o
	-$(RM) *.core

fclean:	clean
	-$(RM) $(LIB_PATH)/$(NAME)

re: fclean all

test:
	( cd ../../test/my/ ; make ; ./testmy )
