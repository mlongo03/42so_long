/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:36:39 by mlongo            #+#    #+#             */
/*   Updated: 2023/05/10 18:49:04 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_map(t_data *data)
{
	char	*number;

	data->map.i = 0;
	data->map.y = 0;
	if (data->map.c == 0)
		data->map.splitmap[data->map.re][data->map.ce] = 'E';
	while (data->map.splitmap[data->map.i])
	{
		data->map.j = 0;
		data->map.x = 0;
		create_map2(data);
		data->map.y += 64;
		data->map.i += 1;
	}
	number = ft_itoa(data->map.mosse);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 0, 0, 0xFFFFFF, "MOSSE : ");
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		80, 0, 0xFFFFFF, number);
	free((number));
}

void	create_map2(t_data *data)
{
	while (data->map.splitmap[data->map.i][data->map.j])
	{
		if (data->map.splitmap[data->map.i][data->map.j] == '1')
			mlx_put_image_to_window(data->mlx_ptr,
				data->win_ptr, data->img.one, data->map.x, data->map.y);
		if (data->map.splitmap[data->map.i][data->map.j] == '0')
			mlx_put_image_to_window(data->mlx_ptr,
				data->win_ptr, data->img.zero, data->map.x, data->map.y);
		if (data->map.splitmap[data->map.i][data->map.j] == 'C')
			mlx_put_image_to_window(data->mlx_ptr,
				data->win_ptr, data->img.c, data->map.x, data->map.y);
		if (data->map.splitmap[data->map.i][data->map.j] == 'E')
		{
			data->map.re = data->map.i;
			data->map.ce = data->map.j;
			if (data->map.c == 0)
				mlx_put_image_to_window(data->mlx_ptr,
					data->win_ptr, data->img.e, data->map.x, data->map.y);
			else
				mlx_put_image_to_window(data->mlx_ptr,
					data->win_ptr, data->img.zero, data->map.x, data->map.y);
		}
		create_map3(data);
	}
}

void	create_map3(t_data *data)
{
	if (data->map.splitmap[data->map.i][data->map.j] == 'P')
	{
		data->map.rp = data->map.i;
		data->map.cp = data->map.j;
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->img.p, data->map.x, data->map.y);
	}
	if (data->map.splitmap[data->map.i][data->map.j] == 'N')
		mlx_put_image_to_window(data->mlx_ptr,
			data->win_ptr, data->img.n, data->map.x, data->map.y);
	data->map.x += 64;
	data->map.j += 1;
}

void	render_map(t_data *data)
{
	int	widhtblock;
	int	heightblock;

	widhtblock = 64;
	heightblock = 64;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, (data->map.widht * 64),
			(data->map.height * 64), "so_long");
	data->img.p = mlx_xpm_file_to_image(data->mlx_ptr, "./images/P.xpm",
			&data->map.widhtblock, &data->map.heightblock);
	data->img.c = mlx_xpm_file_to_image(data->mlx_ptr, "./images/C.xpm",
			&data->map.widhtblock, &data->map.heightblock);
	data->img.e = mlx_xpm_file_to_image(data->mlx_ptr, "./images/E.xpm",
			&data->map.widhtblock, &data->map.heightblock);
	data->img.n = mlx_xpm_file_to_image(data->mlx_ptr, "./images/N.xpm",
			&data->map.widhtblock, &data->map.heightblock);
	data->img.zero = mlx_xpm_file_to_image(data->mlx_ptr, "./images/0.xpm",
			&data->map.widhtblock, &data->map.heightblock);
	data->img.one = mlx_xpm_file_to_image(data->mlx_ptr, "./images/1.xpm",
			&data->map.widhtblock, &data->map.heightblock);
	mlx_hook(data->win_ptr, 17, 0, close_window, data);
	create_map(data);
}
