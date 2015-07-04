##
## Makefile for trade in /home/levy_b/rendu/trade
## 
## Made by LEVY Alexandre
## Login   <levy_b@epitech.net>
## 
## Started on  Sun Jun  7 14:02:34 2015 LEVY Alexandre
## Last update Thu Jun 11 13:54:30 2015 LEVY Alexandre
##

SRC	=	Trade.cpp \

OBJ	=	$(SRC:.cpp=.o)

NAME	=	trade

CC	=	g++ -o

FLAGS	=	-W -Wall -Werror

RM	=	rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
		$(CC) $(NAME) $(OBJ) $(FLAGS)

clean:
		$(RM) $(OBJ)

fclean:		clean
		$(RM) $(NAME)

re:		fclean all
