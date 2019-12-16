##
## EPITECH PROJECT, 2019
## Makefile my_sokoban
## File description:
## compiles c files with libs and includes to make the sokoban project
##

SRC		=	./src/get_map_from_file/init_map_stats.c	\
			./src/get_map_from_file/get_map.c			\
			./src/get_map_from_file/allocate_maps.c		\
			./src/gameplay/sokoban.c					\
			./src/error_handling/impossible_games.c		\
			./src/error_handling/usage.c				\
			./src/gameplay/print_map/print_map.c		\
			./src/gameplay/movements/get_input.c		\
			./src/gameplay/movements/swap_char.c		\
			./src/gameplay/movements/move_left.c		\
			./src/gameplay/movements/move_right.c		\
			./src/gameplay/movements/move_up.c			\
			./src/gameplay/movements/move_down.c		\
			./src/gameplay/end_game/win_condition.c		\
			./src/gameplay/end_game/free_resources.c

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

