/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 15:59:34 by mlongo            #+#    #+#             */
/*   Updated: 2023/05/10 11:17:24 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;
	int		fd;
	char	string[1000000];
	int		i = 0;
	int		ret;

	if (argc != 2)
	{
		ft_printf("Error\ninserire una mappa");
		exit (1);
	}
	data.img.FRAME = -1;
	data.datamap.widhtblock = 64;
	data.datamap.heightblock = 64;
	fd = open(argv[1], 0);
	ret = read(fd, string, 1000000);
	check_map_name(argv[1], ret);
	data.datamap.splitmap = ft_split(string, '\n');
	check_map(&data);
	render_map(&data);
	mlx_key_hook(data.win_ptr, key_hook, &data);
	mlx_loop_hook(data.mlx_ptr, sprite_animation, &data);
	mlx_loop(data.mlx_ptr);
}
