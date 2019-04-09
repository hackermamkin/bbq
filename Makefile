# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfreddie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/20 20:48:53 by gfreddie          #+#    #+#              #
#    Updated: 2019/03/20 20:52:20 by gfreddie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq
FILES = bsq.c ft_atoi.c error.c algo.c main.c reading.c validness.c

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(FILES)
	gcc -o $(NAME) *.o

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
