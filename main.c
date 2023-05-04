/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:59:34 by mlongo            #+#    #+#             */
/*   Updated: 2023/05/04 18:22:43 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "/Users/mlongo/Desktop/libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include <unistd.h>
#include <fcntl.h>

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 300
#define MLX_ERROR 1
#define GREEN_PIXEL 0xFF00
#define RED_PIXEL 0xFF0000
#define WHITE_PIXEL 0xFFFFFF

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}	t_data;

typedef struct s_rect
{
	int	x;
	int	y;
	int width;
	int height;
	int color;
}	t_rect;

typedef struct s_map
{
	int E;
	int P;
	int C;
	int one;
	int widht;
	int height;
}	t_map;

void	error()
{
	printf("Errore\n");
	exit (1);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(int *)pixel = color;
}

int render_rect(t_img *img, t_rect rect)
{
	int	i;
	int j;

	i = rect.y;
	while (i < rect.y + rect.height)
	{
		j = rect.x;
		while (j < rect.x + rect.width)
			img_pix_put(img, j++, i, rect.color);
		++i;
	}
	return (0);
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
			img_pix_put(img, j++, i, color);
		++i;
	}
}

int	key_hook(int keycode, t_data *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
		free(vars->mlx_ptr);
		exit (1);
	}
	return (0);
}

int render(t_data *data)
{
	render_background(&data->img, WHITE_PIXEL);
	render_rect(&data->img, (t_rect){300, 150, 300, 150, GREEN_PIXEL});
	render_rect(&data->img, (t_rect){0, 0, 100, 100, RED_PIXEL});
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
	return (0);
}

int	get_data_row_map(t_map *datamap, char *str)
{
	int i;

	i = 0;
	datamap->one = 0;
	if (str[0] != '1' && str[ft_strlen(str) - 1] != '1')
		error();
	while (str[i])
	{
		if (str[i] == '1')
			datamap->one += 1;
		else if (str[i] == 'P')
			datamap->P += 1;
		else if (str[i] == 'C')
			datamap->C += 1;
		else if (str[i] == 'E')
			datamap->E += 1;
		else if (str[i] != '0' && str[i] != 'N')
			error();
		i++;
	}
	return (i);
}

t_map	check_map(char **map)
{
	t_map	datamap;
	int		i;
	int		widht;

	i = 0;
	widht = 0;
	datamap.E = 0;
	datamap.P = 0;
	datamap.C = 0;

	widht = get_data_row_map(&datamap, map[i]);
	if (widht != datamap.one)
		error();
	datamap.widht = widht;
	i++;
	while (map[i])
	{
		if (widht != get_data_row_map(&datamap, map[i++]))
			error();
	}
	if (i == widht || (datamap.C == 0 && datamap.P == 0 && datamap.E == 0))
		error();
	datamap.height = i;
	return (datamap);
}

int	main(void)
{
	t_data	data;
	t_map	datamap;
	int		fd;
	char	**splitmap;
	char	string[1000000];
	int i = 0;

	fd = open("./map.ber", 0);
	read(fd, string, 1000000);
	splitmap = ft_split(string, '\n');
	datamap = check_map(splitmap);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "my window");
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);
	render(&data);
	mlx_key_hook(data.win_ptr, key_hook, &data);
	mlx_loop(data.mlx_ptr);
}
