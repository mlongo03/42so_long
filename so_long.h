/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessiolongo <alessiolongo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:01:30 by mlongo            #+#    #+#             */
/*   Updated: 2023/05/09 22:37:11 by alessiolong      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
// # include <mlx.h>
# include "./minilibx_opengl_20191021/mlx.h"
# include <unistd.h>
# include <fcntl.h>

typedef struct s_map
{
	int 	E;
	int 	P;
	int 	C;
	int 	one;
	int 	widht;
	int 	height;
	char	**splitmap;
	int		ROWP;
	int		COLUMNP;
	int		mosse;
	int		COLUMNE;
	int		ROWE;
	int		widhtblock;
	int		heightblock;
	int		direction; //1 = up, 2 = down, 3 = right, 4 = left
}	t_map;

typedef struct s_img
{
	int		FRAME;
	void	*P;
	void	*C;
	void	*E;
	void	*N;
	void	*zero;
	void	*one;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	t_map	datamap;
}	t_data;

int		get_data_row_map(t_map *datamap, char *str);
void	check_map(t_data *data);
void	check_map_name(char *str, int ret);
int		key_hook(int keycode, t_data *data);
void	render_map(t_data *data);
void	create_map(t_data *data);
int		close_window(t_data *data);
void	update_playerup(t_data *data);
void	update_playerdown(t_data *data);
void	update_playerright(t_data *data);
void	update_playerleft(t_data *data);
int		sprite_animation(t_data *data);

#endif
