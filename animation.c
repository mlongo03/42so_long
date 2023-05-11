/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:58:36 by mlongo            #+#    #+#             */
/*   Updated: 2023/05/10 12:25:09 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animationright(t_data *data)
{
	data->img.frame += 1;
	if (data->img.frame <= 10)
		data->img.p = mlx_xpm_file_to_image(data->mlx_ptr, "./images/P.xpm",
				&data->map.widhtblock, &data->map.heightblock);
	if (data->img.frame > 10 && data->img.frame <= 20)
		data->img.p = mlx_xpm_file_to_image(data->mlx_ptr, "./images/P2.xpm",
				&data->map.widhtblock, &data->map.heightblock);
	if (data->img.frame > 20)
		data->img.p = mlx_xpm_file_to_image(data->mlx_ptr, "./images/P3.xpm",
				&data->map.widhtblock, &data->map.heightblock);
	if (data->img.frame > 30)
		data->img.frame = -1;
	create_map(data);
}

void	animationleft(t_data *data)
{
	data->img.frame += 1;
	if (data->img.frame <= 10)
		data->img.p = mlx_xpm_file_to_image(data->mlx_ptr,
				"./images/Psinistra.xpm",
				&data->map.widhtblock, &data->map.heightblock);
	if (data->img.frame > 10 && data->img.frame <= 20)
		data->img.p = mlx_xpm_file_to_image(data->mlx_ptr,
				"./images/P2sinistra.xpm", &data->map.widhtblock,
				&data->map.heightblock);
	if (data->img.frame > 20)
		data->img.p = mlx_xpm_file_to_image(data->mlx_ptr,
				"./images/P3sinistra.xpm", &data->map.widhtblock,
				&data->map.heightblock);
	if (data->img.frame > 30)
		data->img.frame = -1;
	create_map(data);
}

void	animationup(t_data *data)
{
	data->img.frame += 1;
	if (data->img.frame <= 10)
		data->img.p = mlx_xpm_file_to_image(data->mlx_ptr, "./images/Palto.xpm",
				&data->map.widhtblock, &data->map.heightblock);
	if (data->img.frame > 10 && data->img.frame <= 20)
		data->img.p = mlx_xpm_file_to_image(data->mlx_ptr,
				"./images/P2alto.xpm", &data->map.widhtblock,
				&data->map.heightblock);
	if (data->img.frame > 20)
		data->img.p = mlx_xpm_file_to_image(data->mlx_ptr,
				"./images/P3alto.xpm", &data->map.widhtblock,
				&data->map.heightblock);
	if (data->img.frame > 30)
		data->img.frame = -1;
	create_map(data);
}

void	animationdown(t_data *data)
{
	data->img.frame += 1;
	if (data->img.frame <= 10)
		data->img.p = mlx_xpm_file_to_image(data->mlx_ptr, "./images/Pgiu.xpm",
				&data->map.widhtblock, &data->map.heightblock);
	if (data->img.frame > 10 && data->img.frame <= 20)
		data->img.p = mlx_xpm_file_to_image(data->mlx_ptr, "./images/P2giu.xpm",
				&data->map.widhtblock, &data->map.heightblock);
	if (data->img.frame > 20)
		data->img.p = mlx_xpm_file_to_image(data->mlx_ptr, "./images/P3giu.xpm",
				&data->map.widhtblock, &data->map.heightblock);
	if (data->img.frame > 30)
		data->img.frame = -1;
	create_map(data);
}

int	sprite_animation(t_data *data)
{
	if (data->map.direction == 2)
		animationdown(data);
	else if (data->map.direction == 1)
		animationup(data);
	else if (data->map.direction == 4)
		animationleft(data);
	else
		animationright(data);
	return (0);
}
