##
## EPITECH PROJECT, 2019
## Makefile lib
## File description:
## makefile for lib
##

SRC	=	./my_strlen.c

CFLAGS	=	-Wall -Wextra -Werror -I./../../include/

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) *.o

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
