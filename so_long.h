/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:01:30 by mlongo            #+#    #+#             */
/*   Updated: 2023/05/09 11:13:42 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include "/Users/mlongo/Desktop/libft/libft.h"
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>

# define WINDOW_WIDTH 600
# define WINDOW_HEIGHT 300
# define MLX_ERROR 1
# define GREEN_PIXEL 0xFF00
# define RED_PIXEL 0xFF0000
# define WHITE_PIXEL 0xFFFFFF

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
}	t_map;

typedef struct s_img
{
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

#endif
