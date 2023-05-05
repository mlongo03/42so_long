/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:59:34 by mlongo            #+#    #+#             */
/*   Updated: 2023/05/05 18:06:57 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.one, 0, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.P, 64, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.C, 128, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.N, 192, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.E, 192 + 64, 0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.zero, 192 + 128, 0);
	return (0);
}

int	main(void)
{
	t_data	data;
	t_map	datamap;
	int		fd;
	char	**splitmap;
	char	string[1000000];
	int i = 0;
	int	widhtblock = 64;
	int	heightblock = 64;

	fd = open("./map.ber", 0);
	read(fd, string, 1000000);
	splitmap = ft_split(string, '\n');
	datamap = check_map(splitmap);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, (datamap.widht * 64), (datamap.height * 64), "my window");
	data.img.P = mlx_xpm_file_to_image(data.mlx_ptr, "/Users/mlongo/Desktop/so_long/images/Personaggio.xpm", &widhtblock, &heightblock);
	data.img.C = mlx_xpm_file_to_image(data.mlx_ptr, "/Users/mlongo/Desktop/so_long/images/upallon.xpm", &widhtblock, &heightblock);
	data.img.E = mlx_xpm_file_to_image(data.mlx_ptr, "/Users/mlongo/Desktop/so_long/images/scudetto.xpm", &widhtblock, &heightblock);
	data.img.N = mlx_xpm_file_to_image(data.mlx_ptr, "/Users/mlongo/Desktop/so_long/images/arbitro.xpm", &widhtblock, &heightblock);
	data.img.zero = mlx_xpm_file_to_image(data.mlx_ptr, "/Users/mlongo/Desktop/so_long/images/background.xpm", &widhtblock, &heightblock);
	data.img.one = mlx_xpm_file_to_image(data.mlx_ptr, "/Users/mlongo/Desktop/so_long/images/Wall.xpm", &widhtblock, &heightblock);
	data.img.P = mlx_xpm_file_to_image(data.mlx_ptr, "/Users/mlongo/Desktop/so_long/images/Personaggio.xpm", &widhtblock, &heightblock);
	data.img.addr = mlx_get_data_addr(data.img.P, &data.img.bpp, &data.img.line_len, &data.img.endian);
	render(&data);
	mlx_key_hook(data.win_ptr, key_hook, &data);
	mlx_loop(data.mlx_ptr);
}
