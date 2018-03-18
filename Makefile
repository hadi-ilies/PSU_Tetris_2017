##
## EPITECH PROJECT, 2017
## for_norme
## File description:
## Makefile
##

NAME	=	tetris

SRCDIR	=	src/
LIBDIR	=	lib/
MAPDIR	=	$(SRCDIR)map/
PARSDIR	=	$(SRCDIR)parsing/
DEBUGDIR =	$(SRCDIR)DebugMode/
GAMEDIR =	$(SRCDIR)Game/

SRC	=	$(GAMEDIR)main.c \
		$(GAMEDIR)insert_in_to_map.c \
		$(GAMEDIR)line_game.c \
		$(GAMEDIR)colisions.c \
		$(DEBUGDIR)debug_sorting.c \
		$(DEBUGDIR)take_filename.c \
		$(GAMEDIR)item_rotate_right.c \
		$(GAMEDIR)command.c \
		$(GAMEDIR)exit.c \
		$(PARSDIR)parsing.c \
		$(PARSDIR)parsing2.c \
		$(PARSDIR)pars_key_command.c \
		$(PARSDIR)pars_key_command2.c \
		$(PARSDIR)pars_key_command3.c \
		$(MAPDIR)map_create.c \
		$(DEBUGDIR)read_no_block.c \
		$(GAMEDIR)score.c \
		$(GAMEDIR)game_over.c \
		$(GAMEDIR)pause.c \
		$(GAMEDIR)display_tetrominos.c \
		$(GAMEDIR)move_tetro.c \
		$(GAMEDIR)windows.c \
		$(GAMEDIR)next.c \
		$(DEBUGDIR)check_dir.c \
		$(GAMEDIR)title.c \
		$(DEBUGDIR)save_command_game2.c \
		$(DEBUGDIR)save_command_game.c \
		$(GAMEDIR)game_create.c \
		$(GAMEDIR)colors.c \
		$(GAMEDIR)get_next_line.c \
		$(GAMEDIR)help.c \
		$(DEBUGDIR)debug_mode.c \
		$(DEBUGDIR)load_info_from_map.c \
		$(DEBUGDIR)map.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-I./include
CFLAGS	+=	-W -Wall -Wextra
CFLAGS	+=	-fdiagnostics-color
CFLAGS	+=	-lncurses

LDFLAGS	=	-L $(LIBDIR) -lmy

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		@make -C $(LIBDIR)
		@cc -o $(NAME) $(OBJ) $(CFLAGS) $(LDFLAGS)

clean	:
		@make clean -C $(LIBDIR)
		@rm -f $(OBJ)

fclean	:	clean
		@make fclean -C $(LIBDIR)
		@rm -f $(NAME)

re	:	fclean all
