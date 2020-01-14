##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## c
##

SRC = 	main.c	\
		my_getnbr.c	\
		my_putstr.c	\
		malloc_str.c	\
		loop.c	\
		my_strlen.c	\
		my_int_to_str.c	\
		put.c	\
		ia.c	\
		end.c	\
		nb_line.c	\
		op.c	\

NAME = matchstick

all: 	$(NAME)

$(NAME):
	gcc -o $(NAME) $(SRC)

clean:
	rm -f $(OBJ)
	rm -f vgcore*

fclean: clean
		rm -f $(NAME)

re:		fclean all

debug:
	gcc -g -o $(NAME) $(SRC)
