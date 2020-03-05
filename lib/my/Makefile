##
## EPITECH PROJECT, 2019
## makefile
## File description:
## projects makefile
##

SRC	=	src/my_strlen.c	\
		src/my_str_to_array.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS  +=  -I ../../include -Wall -Wextra

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean