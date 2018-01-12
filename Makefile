# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/11 15:20:50 by hasmith           #+#    #+#              #
#    Updated: 2018/01/11 17:25:55 by hasmith          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = tmp.a

GIT = test

FILLER =	parse.c
			

NAME = filler.a

MAIN = main.c

EXE = filler

TEST = <argv[1]>

SRC = $(FILLER)

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	make all -C libft
	gcc -g -c $(SRC)
	cp libft/libft.a $(NAME) 
	ar rcs $(NAME) *.o

cmain:
	make re
	gcc -g -o $(EXE) $(NAME) $(MAIN)
	make clean
	./$(EXE)

clean:
	/bin/rm -f *.o
	make clean -C libft

fclean: clean
	make fclean -C libft
	/bin/rm -f $(NAME)

re: fclean all

rhe: fclean H

git:
	make fclean
	git add *
	git commit -m '$(GIT)'
	git push