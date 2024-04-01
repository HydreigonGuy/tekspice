##
## EPITECH PROJECT, 2022
## nanoteckspice
## File description:
## Makefile
##

SRC		=	src/Brain.cpp	\
			src/Component.cpp	\
			src/Pin.cpp	\
			src/operations.cpp	\
			src/C4001.cpp	\
			src/main.cpp	\
			src/C4011.cpp	\
			src/C4030.cpp	\
			src/C4069.cpp	\
			src/C4071.cpp	\
			src/C4081.cpp	\
			src/Ctrue.cpp	\
			src/Cfalse.cpp	\
			src/C4008.cpp	\
			src/Clock.cpp	\

OBJ		=	$(SRC:.cpp=.o)

NAME	=	nanotekspice

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY:	NAME all $(NAME) clean fclean re