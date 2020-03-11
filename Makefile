##
## EPITECH PROJECT, 2019
## makefile
## File description:
## project makefile
##

ECHO    =       /bin/echo -e

DEFAULT =       "\e[0m"
BOLD    =       "\e[1m"
DIM     =       "\e[2m"
UNDLN   =       "\e[4m"
SHINE   =       "\e[5;37m"
RODE    =       "\e[9;37m"

BLACK   =       "\e[30m"
RED     =       "\e[31m"
GREEN   =       "\e[32m"
YELLOW  =       "\e[33m"
BLUE    =       "\e[34m"
MAGEN   =       "\e[35m"
CYAN    =       "\e[36m"
WHITE   =       "\e[1;37m"

LIGHT_RED       =       "\e[91m"
LIGHT_GREEN     =       "\e[92m"
LIGHT_YELLOW    =       "\e[93m"
LIGHT_BLUE      =       "\e[94m"
LIGHT_MAGEN     =       "\e[95m"
LIGHT_CYAN      =       "\e[96m"

SRC_GEN =   generator/src/filler_maze.c		\
			generator/src/dante_gen.c		\
			generator/src/not_perfect.c		\
			generator/src/not_perfect_tools_gen.c		\
			generator/src/generator.c
SRC_SOL =   solver/src/dante_sol.c 			\
			solver/src/result.c 			\
			solver/src/map.c 			\
			solver/src/main.c

OBJ_GEN =   $(SRC_GEN:.c=.o)
OBJ_SOL =   $(SRC_SOL:.c=.o)

NAME_GEN	=   ./generator/generator
NAME_SOL	=   ./solver/solver

CFLAGS  +=  -I include -Wall -Wextra
LDFLAGS +=  -L lib/my -lmy

TEST = @gcc -o unit_tests solver/src/dante_sol.c solver/src/map.c solver/src/result.c tests/tests_solver.c $(LDFLAGS) $(CFLAGS) --coverage -lcriterion

all:    $(NAME_GEN) $(NAME_SOL)

$(NAME_GEN):    $(OBJ_GEN)
		@$(ECHO)
		@gcc -o $(NAME_GEN) $(OBJ_GEN) \
		&& $(ECHO) $(BOLD) $(GREEN)"► BUILD SUCCESS !"$(DEFAULT) || $(ECHO) $(BOLD) $(RED)"► BUILD FAILED"$(DEFAULT)

$(NAME_SOL):    $(OBJ_SOL)
		@$(ECHO)
		@make -s -C lib/my --no-print-directory
		@gcc -o $(NAME_SOL) $(OBJ_SOL) $(LDFLAGS) \
		&& $(ECHO) $(BOLD) $(GREEN)"► BUILD SUCCESS !"$(DEFAULT) || $(ECHO) $(BOLD) $(RED)"► BUILD FAILED"$(DEFAULT)

clean:
		@rm -f $(OBJ_GEN)
		@rm -f $(OBJ_SOL)
		@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE)" CLEAN "$(DEFAULT))

fclean: clean
		@rm -f $(OBJ_GEN)
		@rm -f $(OBJ_SOL)
		@rm -f $(NAME_GEN)
		@rm -f $(NAME_SOL)
		@($(ECHO) $(BOLD) $(GREEN)✓$(LIGHT_BLUE)" FCLEAN "$(DEFAULT))

re: fclean all

tests_run:
	make -C lib/my
	$(TEST)
	./unit_tests

debug: CFLAGS += -g
debug: re

%.o :		%.c
		@gcc -c -o $@ $^ $(CFLAGS) && $(ECHO) -n $(BOLD) $(GREEN)"  [OK] "$(WHITE) || $(ECHO) -n $(BOLD) $(RED)"  [KO] "$(WHITE) && $(ECHO) $(BOLD) $< | rev | cut -d'/' -f 1 | rev

.PHONY: all clean fclean