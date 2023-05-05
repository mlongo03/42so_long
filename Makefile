# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/28 17:09:03 by mlongo            #+#    #+#              #
#    Updated: 2023/05/05 11:07:21 by mlongo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

OBJS := main.o mapcheck.o

LIBFT_PATH = ./libft

LIBFT = ${LIBFT_PATH}/libft.a

FLAGS := -Wall -Werror -Wextra

all: $(NAME)

%.o : %.c
	cc -Imlx -c $< -o $@

$(NAME): $(OBJS)
	make -C libft
	cc $(OBJS) ${LIBFT} -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	rm -f $(OBJS) ${B_OBJS} $(LIBFT)

fclean: clean
	rm -f $(NAME)

re: fclean all
