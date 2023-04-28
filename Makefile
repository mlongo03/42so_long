# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/28 17:09:03 by mlongo            #+#    #+#              #
#    Updated: 2023/04/28 17:43:29 by mlongo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

SRCS_DIR := ./

OBJS := test.o

FLAGS := -Wall -Werror -Wextra

all: $(NAME)

%.o : %.c
	cc $(FLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJS)
	cc $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJS) ${B_OBJS}

fclean: clean
	rm -f $(NAME)

re: fclean all
