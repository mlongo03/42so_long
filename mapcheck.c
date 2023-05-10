/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:01:38 by mlongo            #+#    #+#             */
/*   Updated: 2023/05/10 11:17:24 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error()
{
	ft_printf("Errore\nla mappa é sbagliata");
	exit (1);
}

void	error_name_map()
{
	ft_printf("Errore\nil nome della mappa é sbagliato");
	exit (1);
}

int	get_data_row_map(t_map *datamap, char *str)
{
	int i;

	i = 0;
	datamap->one = 0;
	if (str[0] != '1' || str[ft_strlen(str) - 1] != '1')
		error();
	while (str[i])
	{
		if (str[i] == '1')
			datamap->one += 1;
		else if (str[i] == 'P')
		{
			if (datamap->P >= 1)
				str[i] = '0';
			datamap->P += 1;
		}
		else if (str[i] == 'C')
			datamap->C += 1;
		else if (str[i] == 'E')
		{
			if (datamap->E >= 1)
				str[i] = '0';
			datamap->E += 1;
		}
		else if (str[i] != '0' && str[i] != 'N')
			error();
		i++;
	}
	return (i);
}

void	check_map(t_data *data)
{
	t_map	datamap;
	int		i;

	i = 0;
	data->datamap.widht = get_data_row_map(&data->datamap, data->datamap.splitmap[i]);
	if (data->datamap.widht != data->datamap.one)
		error();
	i++;
	while (data->datamap.splitmap[i])
	{
		if (data->datamap.widht != get_data_row_map(&data->datamap, data->datamap.splitmap[i++]))
			error();
	}
	if (data->datamap.widht != data->datamap.one)
		error();
	if (i == data->datamap.widht || (data->datamap.C == 0 || data->datamap.P == 0 || data->datamap.E == 0))
		error();
	data->datamap.height = i;
}

void	check_map_name(char *str, int ret)
{
	if (ft_strnstr(str, "maps/", 5) == 0 || ret == -1
	|| str[ft_strlen(str) - 1] != 'r' || str[ft_strlen(str) - 2] != 'e'
	|| str[ft_strlen(str) - 3] != 'b' || str[ft_strlen(str) - 4] != '.')
		error_name_map();
}
