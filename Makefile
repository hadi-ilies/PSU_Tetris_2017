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
		$(SRCDIR)check_error.c \
		$(SRCDIR)insert_item.c \
		$(SRCDIR)get_next_line.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-I./include
CFLAGS	+=	-W -Wall -Wextra
CFLAGS	+=	-fdiagnostics-color
CFLAGS	+=	-lncurses

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
