##
## EPITECH PROJECT, 2019
## Makefile my_sokoban
## File description:
## compiles c files with libs and includes to make the sokoban project
##

SRC		=	./src/get_map_cases/init_map_stats.c	\
			./src/error_handling/usage.c			\
			./src/get_map_cases/allocate_maps.c		\
			./src/get_map_cases/get_map.c			\
			./src/error_handling/impossible_games.c	\
			./src/gameplay/get_input.c				\
			./src/gameplay/swap_char.c				\
			./src/gameplay/move_left.c				\
			./src/gameplay/move_right.c				\
			./src/gameplay/move_up.c				\
			./src/gameplay/move_down.c				\
			./src/gameplay/sokoban.c				\
			./src/end_game/free_resources.c

MAIN	=	./main.c

CFLAGS	=	-Wall -Wextra -I./include/

NAME	=	my_sokoban

LIB		=	-L./lib/my/ -lmy -lncurses

CRIT	=	--coverage -lcriterion

all:	$(NAME)

$(NAME):
	$(MAKE) -C ./lib/my/
	$(CC) -o $(NAME) $(MAIN) $(SRC) $(LIB) $(CFLAGS)

debug:
	$(MAKE) -C ./lib/my/
	$(CC) -o $(NAME) $(MAIN) $(SRC) $(LIB) $(CFLAGS) -g
	gdb $(NAME)
	$(RM) $(NAME)

tests_run:
	$(MAKE) -C ./lib/my/
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
	$(RM) unit_tests

fclean:	clean
	$(RM) $(NAME)
	$(RM) ./lib/my/*.o
	$(RM) ./lib/my/*.a

re:	fclean all

.PHONY: all debug tests_run coverage clean fclean re

