##
## EPITECH PROJECT, 2017
## for_norme
## File description:
## Makefile
##

NAME	=	tetris

SRCDIR	=	src/

PARSING_DIR	=	$(SRCDIR)parsing/

LIBDIR	=	lib/

SRC	=	$(SRCDIR)main.c \
		$(PARSING_DIR)parsing.c \
		$(PARSING_DIR)parsing2.c \
		$(PARSING_DIR)pars_key_command.c \
		$(PARSING_DIR)pars_key_command2.c \
		$(PARSING_DIR)pars_key_command3.c \
		$(SRCDIR)read_no_block.c \
		$(SRCDIR)score.c \
		$(SRCDIR)pause.c \
		$(SRCDIR)display_tetrominos.c \
		$(SRCDIR)move_tetro.c \
		$(SRCDIR)windows.c \
		$(SRCDIR)next.c \
		$(SRCDIR)check_dir.c \
		$(SRCDIR)map_create.c \
		$(SRCDIR)title.c \
		$(SRCDIR)save_command_game2.c \
		$(SRCDIR)save_command_game.c \
		$(SRCDIR)game_create.c \
		$(SRCDIR)merge_sort.c \
		$(SRCDIR)colors.c \
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
