NAME = myselect
SRC = myselect.c init_terminal.c restore_terminal.c win_resize.c term_clear.c my_termprint.c term_get_cap.c init_caps.c setup_elems.c show_elems.c check_char.c term_ve.c term_vi.c term_move_to_item.c term_standend.c term_standout.c term_underend.c term_underline.c refreshout.c refreshin.c moveup.c movedown.c moveleft.c moveright.c doselect.c getoutput.c
RM = rm -f
CC = clang
INCL_PATH = ../../include
LIB_PATH = ../../lib
CFLAGS += -I $(INCL_PATH) -L $(LIB_PATH) -Wall
debug : CFLAGS += -DDEBUG

all:	
	$(CC) $(CFLAGS) $(SRC) -lmy -ltermcap -o $(NAME)

debug:	all

clean:	
	-$(RM) *~
	-$(RM) \#*
	-$(RM) *.o
	-$(RM) *.core

fclean:	clean
	-$(RM) $(NAME)

re:	fclean all
