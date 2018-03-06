##
## EPITECH PROJECT, 2017
## for_norme
## File description:
## Makefile
##

NAME	=	tetris

SRCDIR	=	src/
LIBDIR	=	lib/

SRC	=	$(SRCDIR)main.c \
		$(SRCDIR)check_dir.c \
		$(SRCDIR)save_command_game2.c \
		$(SRCDIR)save_command_game.c \
		$(SRCDIR)game_create.c \
		$(SRCDIR)pars_key_command.c \
		$(SRCDIR)pars_key_command2.c \
		$(SRCDIR)merge_sort.c \
		$(SRCDIR)pars_key_command3.c \
		$(SRCDIR)parsing2.c \
		$(SRCDIR)parsing.c \
		$(SRCDIR)insert_item.c \
		$(SRCDIR)get_next_line.c \
		$(SRCDIR)help.c \
		$(SRCDIR)debug_mode.c \
		$(SRCDIR)load_info_from_map.c \
		$(SRCDIR)map.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-I./include
CFLAGS	+=	-W -Wall -Wextra
CFLAGS	+=	-fdiagnostics-color
CFLAGS	+=	-lncurses
CFLAGS	+=	-g

LDFLAGS	=	-L $(LIBDIR) -lmy

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		make -C $(LIBDIR)
		cc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean	:
		make clean -C $(LIBDIR)
		rm -f $(OBJ)

fclean	:	clean
		make fclean -C $(LIBDIR)
		rm -f $(NAME)

re	:	fclean all
