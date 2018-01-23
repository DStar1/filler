# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hasmith <hasmith@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/11 15:20:50 by hasmith           #+#    #+#              #
#    Updated: 2018/01/22 22:12:51 by hasmith          ###   ########.fr        #
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
		srcs/draw.c \
		srcs/validation.c \
		srcs/compare.c

FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	make all -C libft
	gcc -g -c $(SRC)
	cp libft/libft.a $(NAME) 
	ar rcs $(NAME) *.o
	gcc $(FALGS) -g -o $(PLAYER) $(MAIN) $(NAME) minilibx/libmlx.a libft/libft.a -framework OpenGL -framework AppKit

cmain:
	make re
	cp $(PLAYER) resources/players
	./resources/filler_vm -f resources/maps/map00 -p1 resources/players/$(PLAYER) -p2 resources/players/abanlin.filler
#	./resources/filler_vm -f resources/maps/map00 -p1 resources/players/$(PLAYER) -p2 resources/players/abanlin.filler > test.txt

clean:
	/bin/rm -f *.o
	make clean -C libft

fclean: clean
	make fclean -C libft
	/bin/rm -f $(NAME)
	/bin/rm -f $(PLAYER)
	/bin/rm -f filler.trace

re: fclean all

rhe: fclean H

git:
	make fclean
	git add *
	git commit -m '$(GIT)'
	git push
