/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessiolongo <alessiolongo@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 14:58:36 by mlongo            #+#    #+#             */
/*   Updated: 2023/05/09 22:47:41 by alessiolong      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animationright(t_data *data)
{
	data->img.FRAME += 1;
	if (data->img.FRAME <= 15)
		data->img.P = mlx_xpm_file_to_image(data->mlx_ptr, "./images/Personaggio.xpm", &data->datamap.widhtblock, &data->datamap.heightblock);
	if (data->img.FRAME > 15 && data->img.FRAME <= 30)
		data->img.P = mlx_xpm_file_to_image(data->mlx_ptr, "./images/Personaggio2.xpm", &data->datamap.widhtblock, &data->datamap.heightblock);
	if (data->img.FRAME > 30)
		data->img.P = mlx_xpm_file_to_image(data->mlx_ptr, "./images/Personaggio3.xpm", &data->datamap.widhtblock, &data->datamap.heightblock);
	if (data->img.FRAME > 60)
		data->img.FRAME = -1;
	create_map(data);
}

void	animationleft(t_data *data)
{
	data->img.FRAME += 1;
	if (data->img.FRAME <= 15)
		data->img.P = mlx_xpm_file_to_image(data->mlx_ptr, "./images/Personaggiosinistra.xpm", &data->datamap.widhtblock, &data->datamap.heightblock);
	if (data->img.FRAME > 15 && data->img.FRAME <= 30)
		data->img.P = mlx_xpm_file_to_image(data->mlx_ptr, "./images/Personaggio2sinistra.xpm", &data->datamap.widhtblock, &data->datamap.heightblock);
	if (data->img.FRAME > 30)
		data->img.P = mlx_xpm_file_to_image(data->mlx_ptr, "./images/Personaggio3sinistra.xpm", &data->datamap.widhtblock, &data->datamap.heightblock);
	if (data->img.FRAME > 60)
		data->img.FRAME = -1;
	create_map(data);
}

void	animationup(t_data *data)
{
	data->img.FRAME += 1;
	if (data->img.FRAME <= 15)
		data->img.P = mlx_xpm_file_to_image(data->mlx_ptr, "./images/Personaggioalto.xpm", &data->datamap.widhtblock, &data->datamap.heightblock);
	if (data->img.FRAME > 15 && data->img.FRAME <= 30)
		data->img.P = mlx_xpm_file_to_image(data->mlx_ptr, "./images/Personaggio2alto.xpm", &data->datamap.widhtblock, &data->datamap.heightblock);
	if (data->img.FRAME > 30)
		data->img.P = mlx_xpm_file_to_image(data->mlx_ptr, "./images/Personaggio3alto.xpm", &data->datamap.widhtblock, &data->datamap.heightblock);
	if (data->img.FRAME > 60)
		data->img.FRAME = -1;
	create_map(data);
}

void	animationdown(t_data *data)
{
	data->img.FRAME += 1;
	if (data->img.FRAME <= 15)
		data->img.P = mlx_xpm_file_to_image(data->mlx_ptr, "./images/Personaggiogiu.xpm", &data->datamap.widhtblock, &data->datamap.heightblock);
	if (data->img.FRAME > 15 && data->img.FRAME <= 30)
		data->img.P = mlx_xpm_file_to_image(data->mlx_ptr, "./images/Personaggio2giu.xpm", &data->datamap.widhtblock, &data->datamap.heightblock);
	if (data->img.FRAME > 30)
		data->img.P = mlx_xpm_file_to_image(data->mlx_ptr, "./images/Personaggio3giu.xpm", &data->datamap.widhtblock, &data->datamap.heightblock);
	if (data->img.FRAME > 60)
		data->img.FRAME = -1;
	create_map(data);
}

int	sprite_animation(t_data *data)
{
	if (data->datamap.direction == 2)
		animationdown(data);
	else if (data->datamap.direction == 1)
		animationup(data);
	else if (data->datamap.direction == 4)
		animationleft(data);
	else
		animationright(data);
	return (0);
}
