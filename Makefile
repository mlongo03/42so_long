# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/28 17:09:03 by mlongo            #+#    #+#              #
#    Updated: 2023/05/11 11:40:25 by mlongo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := so_long

OBJS := main.o mapcheck.o render_map.o handle_hooks.o update_player.o animation.o error.o

LIBFT_PATH = ./libft

LIBFT = ${LIBFT_PATH}/libft.a

FT_PRINTF_PATH = ./ft_printf

FT_PRINTF = ${FT_PRINTF_PATH}/libftprintf.a

FLAGS := -Wall -Werror -Wextra

all: $(NAME)

%.o : %.c
	cc $(FLAGS) -Imlx -c $< -o $@

$(NAME): $(OBJS)
	make -C libft
	make -C ft_printf
	cc $(OBJS) ${LIBFT} $(FT_PRINTF) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	make clean -C libft
	make clean -C ft_printf
	rm -f $(OBJS) ${B_OBJS} $(LIBFT)

fclean: clean
	make fclean -C libft
	make fclean -C ft_printf
	rm -f $(NAME)

re: fclean all
