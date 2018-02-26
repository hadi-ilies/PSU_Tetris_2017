##
## EPITECH PROJECT, 2017
## for_norme
## File description:
## Makefile
##

NAME	=	a.out

SRCDIR	=	src/
LIBDIR	=	lib/

SRC	=	$(SRCDIR)main.c \
		$(LIBDIR)my_strlen.c \
		$(LIBDIR)my_printf.c \
		$(LIBDIR)my_malloc.c \
		$(LIBDIR)my_malloc2.c \

OBJ	=	$(SRC:.c=.o)

CFLAGS	+=	-I./include
CFLAGS	+=	-W -Wall -Wextra

all	:	$(NAME)

$(NAME)	:	$(OBJ)
		cc -o $(NAME) $(OBJ) $(CFLAGS)

clean	:
		rm -f $(OBJ)

fclean	:	clean
		rm -f $(NAME)

re	:	fclean all
