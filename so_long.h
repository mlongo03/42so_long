/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:01:30 by mlongo            #+#    #+#             */
/*   Updated: 2023/05/10 19:20:25 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_map
{
	int		e;
	int		p;
	int		c;
	int		one;
	int		widht;
	int		height;
	char	**splitmap;
	int		rp;
	int		cp;
	int		mosse;
	int		ce;
	int		re;
	int		widhtblock;
	int		heightblock;
	int		direction;
	int		j;
	int		x;
	int		i;
	int		y;
}	t_map;

typedef struct s_img
{
	int		frame;
	void	*p;
	void	*c;
	void	*e;
	void	*n;
	void	*zero;
	void	*one;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_map	map;
}	t_data;

int		get_data_row_map(t_map *datamap, char *str);
void	check_map(t_data *data);
void	check_map_name(char *str, int ret);
int		key_hook(int keycode, t_data *data);
void	render_map(t_data *data);
void	create_map(t_data *data);
int		close_window(t_data *data);
void	update_player(t_data *data, int x, int y);
// void	update_playerdown(t_data *data);
// void	update_playerright(t_data *data);
// void	update_playerleft(t_data *data);
int		sprite_animation(t_data *data);
int		get_data_row_map2(t_map *map, char *str, int i);
void	error(void);
void	error_name_map(void);
void	create_map2(t_data *data);
void	create_map3(t_data *data);

#endif
