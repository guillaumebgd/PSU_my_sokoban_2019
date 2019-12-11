##
## EPITECH PROJECT, 2019
## Makefile my_sokoban
## File description:
## compiles c files with libs and includes to make the sokoban project
##

SRCDEST	=	./src/

LIBMY	=	./lib/my/

TESTDIR	=	./tests/

VALTEST	=	./map_test

SRC		=	$(SRCDEST)init_map_stats.c				\
			$(SRCDEST)usage.c						\
			$(SRCDEST)get_map.c						\
			$(SRCDEST)impossible_games.c			\
			$(SRCDEST)sokoban.c						\
			$(SRCDEST)free_resources.c

MAIN	=	./main.c

CFLAGS	=	-Wall -Wextra -I./include/

SYMB	=	$(CFLAGS) -g

NAME	=	my_sokoban

LDFLAGS	=	-lmy -lncurses

CRIT	=	--coverage -lcriterion

libs:
	$(MAKE) -C $(LIBMY)

cc:
	$(CC) -o $(NAME) $(MAIN) $(SRC) -L$(LIBMY) $(LDFLAGS) $(CFLAGS)

ccsymb:
	$(CC) -o $(NAME) $(MAIN) $(SRC) -L$(LIBMY) $(LDFLAGS) $(SYMB)

all:	$(NAME)

$(NAME): libs cc

debug: libs ccsymb
	gdb $(NAME)
	$(RM) $(NAME)

valgrind: libs ccsymb
	valgrind ./$(NAME) $(VALTEST)
	$(RM) $(NAME)
	$(RM) vgcore*

tests_run: libs
	$(RM) *.gcda *.gcno
	$(CC) -o unit_tests $(SRC) $(TESTDIR)*.c -L$(LIBMY) $(CRIT) $(CFLAGS)
	./unit_tests
	$(RM) unit_tests
	$(RM) test_*

coverage:
	gcovr --exclude $(TESTDIR)
	gcovr --exclude $(TESTDIR) --branches

clean:
	$(RM) $(OBJ)
	$(RM) *.gcda *.gcno
	$(RM) vgcore*
	$(RM) unit_tests

fclean:	clean
	$(RM) $(NAME)
	$(RM) $(LIBMY)*.o
	$(RM) $(LIBMY)*.a

re:	fclean all

.PHONY: libs cc ccsymb all debug tests_run coverage clean fclean re
