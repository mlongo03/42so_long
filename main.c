/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:59:34 by mlongo            #+#    #+#             */
/*   Updated: 2023/05/05 11:15:04 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	img_pix_put(t_img *img, int x, int y, int color)
// {
// 	char	*pixel;

// 	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
// 	*(int *)pixel = color;
// }

// int render_rect(t_img *img, t_rect rect)
// {
// 	int	i;
// 	int j;

// 	i = rect.y;
// 	while (i < rect.y + rect.height)
// 	{
// 		j = rect.x;
// 		while (j < rect.x + rect.width)
// 			img_pix_put(img, j++, i, rect.color);
// 		++i;
// 	}
// 	return (0);
// }

// void	render_background(t_img *img, int color)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < WINDOW_HEIGHT)
// 	{
// 		j = 0;
// 		while (j < WINDOW_WIDTH)
// 			img_pix_put(img, j++, i, color);
// 		++i;
// 	}
// }

// int	key_hook(int keycode, t_data *vars)
// {
// 	if (keycode == 53)
// 	{
// 		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
// 		free(vars->mlx_ptr);
// 		exit (1);
// 	}
// 	return (0);
// }

// int render(t_data *data)
// {
// 	render_background(&data->img, WHITE_PIXEL);
// 	render_rect(&data->img, (t_rect){300, 150, 300, 150, GREEN_PIXEL});
// 	render_rect(&data->img, (t_rect){0, 0, 100, 100, RED_PIXEL});
// 	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.mlx_img, 0, 0);
// 	return (0);
// }

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
	// data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	// data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);
	// render(&data);
	// mlx_key_hook(data.win_ptr, key_hook, &data);
	// mlx_loop(data.mlx_ptr);
}
