##
## EPITECH PROJECT, 2019
## Makefile my_sokoban
## File description:
## compiles c files into a lib
##

SRC		=	./src/usage.c				\
			./src/init_map_stats.c		\
			./src/get_map.c				\
			./src/impossible_games.c	\
			./src/sokoban.c				\
			./src/free_resources.c

MAIN	=	./src/main.c

CFLAGS	=	-Wall -Wextra -I./include/

NAME	=	my_sokoban

LIB		=	-L./lib/my/

LDFLAGS	=	-lmy -lncurses

CRIT	=	--coverage -lcriterion

libs:
	$(MAKE) -C ./lib/my/

all:	$(NAME)

$(NAME): libs
	$(CC) -o $(NAME) $(MAIN) $(SRC) $(LIB) $(LDFLAGS) $(CFLAGS)

debug: libs
	$(CC) -g -o $(NAME) $(MAIN) $(SRC) $(LIB) $(LDFLAGS) $(CFLAGS)
	gdb $(NAME)
	$(RM) $(NAME)

valgrind: libs
	$(CC) -g -o $(NAME) $(MAIN) $(SRC) $(LIB) $(LDFLAGS) $(CFLAGS)

tests_run: libs
	$(RM) *.gcda *.gcno
	$(CC) -o unit_tests $(SRC) tests/*.c $(LIB) $(CRIT) $(CFLAGS)
	./unit_tests
	$(RM) unit_tests
	$(RM) test_*

coverage:
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

clean:
	$(RM) $(OBJ)
	$(RM) *.gc*
	$(RM) vgcore*
	$(RM) unit_tests

fclean:	clean
	$(RM) $(NAME)
	$(RM) ./lib/my/*.o
	$(RM) ./lib/my/*.a

re:	fclean all

.PHONY: libs all debug tests_run coverage clean fclean re
