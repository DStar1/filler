# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/11 15:20:50 by hasmith           #+#    #+#              #
#    Updated: 2018/01/21 22:47:48 by hasmith          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = tmp.a

GIT = test

FILLER =	parse.c
			

NAME = filler.a

MAIN = main.c

PLAYER = hasmith.filler

TEST = <argv[1]>

SRC = 	srcs/$(FILLER) \
		srcs/place.c \
		$(MAIN) \
		srcs/compare.c

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	make all -C libft
	gcc -g -c $(SRC)
	cp libft/libft.a $(NAME) 
	ar rcs $(NAME) *.o
	gcc $(FALGS) -g -o $(PLAYER) $(NAME) minilibx/libmlx.a libft/libft.a -framework OpenGL -framework AppKit
#	gcc -g -o $(PLAYER) $(NAME) $(MAIN)
#	make clean

cmain:
	make re
	cp $(PLAYER) resources/players
	./resources/filler_vm -f resources/maps/map00 -p1 resources/players/abanlin.filler -p2 resources/players/$(PLAYER)
#	./resources/filler_vm -f resources/maps/map00 -p1 resources/players/abanlin.filler -p2 hasmith.filler > resources/test.txt
#./resources/filler_vm -f resources/maps/map00 -p1 resources/

clean:
	/bin/rm -f *.o
	make clean -C libft

fclean: clean
	make fclean -C libft
	/bin/rm -f $(NAME)
	/bin/rm -f $(PLAYER)
	/bin/rm -f filler.trace
#	maybe?

re: fclean all

rhe: fclean H

git:
	make fclean
	git add *
	git commit -m '$(GIT)'
	git push
