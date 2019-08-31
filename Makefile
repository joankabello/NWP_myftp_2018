##
## EPITECH PROJECT, 2018
## joan
## File description:
## joan
##

SRC	=	server.c	\
		auth.c		\
		chdir_pwd.c	\
		parser.c	\
		my_sockets.c\
		remover.c

NAME	=	myftp

OBJ	=	$(SRC:.c=.o)

LDFLAGS	=	-I include

CFLAGS =	-ggdb -g3 -W -Wall -Wextra

all:	$(NAME) $(NAME2)

$(NAME):	$(OBJ)
	gcc -o $(NAME)  $(OBJ) $(CFLAGS) $(LDFLAGS)
	@echo -n "["
	@echo -n " \e[1;32mOK\e[0m "
	@echo -n "] "
	@echo "\e[1;31m --Build Completed. \e[0m"
	@echo -n "["
	@echo -n " \e[1;32mOK\e[0m "
	@echo -n "] "
	@echo "\e[1;31m --Compile Completed\e[0m"

clean:
	rm -f $(OBJ)
	rm -f $(OBJ2)

fclean:	clean
	rm -f $(NAME)
	rm *~ -f $(NAME)
	rm *# -f $(NAME)
	rm -f $(NAME2)
	rm *~ -f $(NAME2)
	rm *# -f $(NAME2)

re:	fclean all

c:	fclean clean
	@echo -n "["
	@echo -n " \e[1;32mOK\e[0m "
	@echo -n "] "
	@echo "\e[1;31m -- Clean Completed. \e[0m"
