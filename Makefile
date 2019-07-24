# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fmarckma <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/21 10:40:36 by fmarckma          #+#    #+#              #
#    Updated: 2019/07/22 16:04:21 by fmarckma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		=	gcc	

SRC		=	$(wildcard *.c)

OBJ		=	$(SRC:%.c=%.o)

CFLAGS	+=	-Wall -Wextra -Werror 

NAME	=	bsq

HEADER	=	ft.h

all:	$(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f *~

$(NAME): $(OBJ)
		$(CC) -c $(SRC) $(HEADER)
		$(CC) -o $(NAME) $(OBJ)

re: fclean $(NAME)

.PHONY: all clean fclean re
