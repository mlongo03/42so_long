/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:01:38 by mlongo            #+#    #+#             */
/*   Updated: 2023/05/10 12:41:44 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_data_row_map(t_map *map, char *str)
{
	int	i;

	i = 0;
	map->one = 0;
	if (str[0] != '1' || str[ft_strlen(str) - 1] != '1')
		error();
	i = get_data_row_map2(map, str, i);
	return (i);
}

int	get_data_row_map2(t_map *map, char *str, int i)
{
	while (str[i])
	{
		if (str[i] == '1')
			map->one += 1;
		else if (str[i] == 'P')
		{
			if (map->p >= 1)
				str[i] = '0';
			map->p += 1;
		}
		else if (str[i] == 'C')
			map->c += 1;
		else if (str[i] == 'E')
		{
			if (map->e >= 1)
				str[i] = '0';
			map->e += 1;
		}
		else if (str[i] != '0' && str[i] != 'N')
			error();
		i++;
	}
	return (i);
}

void	check_map(t_data *data)
{
	int		i;

	i = 0;
	data->map.widht = get_data_row_map(&data->map,
			data->map.splitmap[i]);
	if (data->map.widht != data->map.one)
		error();
	i++;
	while (data->map.splitmap[i])
	{
		if (data->map.widht != get_data_row_map(&data->map,
				data->map.splitmap[i++]))
			error();
	}
	if (data->map.widht != data->map.one)
		error();
	if (i == data->map.widht || (data->map.c == 0
			|| data->map.p == 0 || data->map.e == 0))
		error();
	data->map.height = i;
}

void	check_map_name(char *str, int ret)
{
	if (ft_strnstr(str, "maps/", 5) == 0 || ret == -1
		|| str[ft_strlen(str) - 1] != 'r' || str[ft_strlen(str) - 2] != 'e'
		|| str[ft_strlen(str) - 3] != 'b' || str[ft_strlen(str) - 4] != '.')
		error_name_map();
}
