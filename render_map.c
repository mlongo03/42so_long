/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:36:39 by mlongo            #+#    #+#             */
/*   Updated: 2023/05/10 13:03:47 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_map(t_data *data)
{
	int		i;
	int		j;
	int		x;
	int		y;
	char	*number;

	i = 0;
	j = 0;
	y = 0;
	x = 0;
	if (data->map.c == 0)
		data->map.splitmap[data->map.re][data->map.ce] = 'E';
	while (data->map.splitmap[i])
	{
		j = 0;
		x = 0;
		while (data->map.splitmap[i][j])
		{
			if (data->map.splitmap[i][j] == '1')
				mlx_put_image_to_window(data->mlx_ptr,
					data->win_ptr, data->img.one, x, y);
			if (data->map.splitmap[i][j] == '0')
				mlx_put_image_to_window(data->mlx_ptr,
					data->win_ptr, data->img.zero, x, y);
			if (data->map.splitmap[i][j] == 'C')
				mlx_put_image_to_window(data->mlx_ptr,
					data->win_ptr, data->img.c, x, y);
			if (data->map.splitmap[i][j] == 'E')
			{
				data->map.re = i;
				data->map.ce = j;
				if (data->map.c == 0)
					mlx_put_image_to_window(data->mlx_ptr,
						data->win_ptr, data->img.e, x, y);
				else
					mlx_put_image_to_window(data->mlx_ptr,
						data->win_ptr, data->img.zero, x, y);
			}
			if (data->map.splitmap[i][j] == 'P')
			{
				data->map.rp = i;
				data->map.cp = j;
				mlx_put_image_to_window(data->mlx_ptr,
					data->win_ptr, data->img.p, x, y);
			}
			if (data->map.splitmap[i][j] == 'N')
				mlx_put_image_to_window(data->mlx_ptr,
					data->win_ptr, data->img.n, x, y);
			x += 64;
			j++;
		}
		y += 64;
		i++;
	}
	number = ft_itoa(data->map.mosse);
	mlx_string_put(data->mlx_ptr, data->win_ptr, 0, 0, 0xFFFFFF, "MOSSE : ");
	mlx_string_put(data->mlx_ptr, data->win_ptr,
		80, 0, 0xFFFFFF, number);
	free((number));
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
