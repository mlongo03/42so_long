/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 12:36:39 by mlongo            #+#    #+#             */
/*   Updated: 2023/05/09 11:16:08 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_map(t_data *data)
{
	int i;
	int j;
	int x;
	int y;

	i = 0;
	j = 0;
	y = 0;
	x = 0;
	if (data->datamap.C == 0)
		data->datamap.splitmap[data->datamap.ROWE][data->datamap.COLUMNE] = 'E';
	while (data->datamap.splitmap[i])
	{
		j = 0;
		x = 0;
		while (data->datamap.splitmap[i][j])
		{
			if (data->datamap.splitmap[i][j] == '1')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.one, x, y);
			if (data->datamap.splitmap[i][j] == '0')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.zero, x, y);
			if (data->datamap.splitmap[i][j] == 'C')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.C, x, y);
			if (data->datamap.splitmap[i][j] == 'E')
			{
				data->datamap.ROWE = i;
				data->datamap.COLUMNE = j;
				if (data->datamap.C == 0)
					mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.E, x, y);
				else
					mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.zero, x, y);
			}
			if (data->datamap.splitmap[i][j] == 'P')
			{
				data->datamap.ROWP = i;
				data->datamap.COLUMNP = j;
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.P, x, y);
			}
			if (data->datamap.splitmap[i][j] == 'N')
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.N, x, y);
			x += 64;
			j++;
		}
		y += 64;
		i++;
	}
}

void	render_map(t_data *data)
{
	int	widhtblock;
	int	heightblock;

	widhtblock = 64;
	heightblock = 64;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, (data->datamap.widht * 64), (data->datamap.height * 64), "so_long");
	data->img.P = mlx_xpm_file_to_image(data->mlx_ptr, "./images/Personaggio.xpm", &data->datamap.widhtblock, &data->datamap.heightblock);
	data->img.C = mlx_xpm_file_to_image(data->mlx_ptr, "./images/upallon.xpm",  &data->datamap.widhtblock, &data->datamap.heightblock);
	data->img.E = mlx_xpm_file_to_image(data->mlx_ptr, "./images/scudetto.xpm",  &data->datamap.widhtblock, &data->datamap.heightblock);
	data->img.N = mlx_xpm_file_to_image(data->mlx_ptr, "./images/arbitro.xpm",  &data->datamap.widhtblock, &data->datamap.heightblock);
	data->img.zero = mlx_xpm_file_to_image(data->mlx_ptr, "./images/background.xpm",  &data->datamap.widhtblock, &data->datamap.heightblock);
	data->img.one = mlx_xpm_file_to_image(data->mlx_ptr, "./images/Wall.xpm",  &data->datamap.widhtblock, &data->datamap.heightblock);
	data->img.P = mlx_xpm_file_to_image(data->mlx_ptr, "./images/Personaggio.xpm",  &data->datamap.widhtblock, &data->datamap.heightblock);
	mlx_hook(data->win_ptr, 17, 0, close_window, data);
	create_map(data);
}
