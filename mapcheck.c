/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:01:38 by mlongo            #+#    #+#             */
/*   Updated: 2023/05/05 11:12:11 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error()
{
	printf("Errore\nla mappa é sbagliata");
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
			datamap->P += 1;
		else if (str[i] == 'C')
			datamap->C += 1;
		else if (str[i] == 'E')
			datamap->E += 1;
		else if (str[i] != '0' && str[i] != 'N')
			error();
		i++;
	}
	return (i);
}

t_map	check_map(char **map)
{
	t_map	datamap;
	int		i;
	int		widht;

	i = 0;
	widht = 0;
	datamap.E = 0;
	datamap.P = 0;
	datamap.C = 0;

	widht = get_data_row_map(&datamap, map[i]);
	if (widht != datamap.one)
		error();
	datamap.widht = widht;
	i++;
	while (map[i])
	{
		if (widht != get_data_row_map(&datamap, map[i++]))
			error();
	}
	if (widht != datamap.one)
		error();
	if (i == widht || (datamap.C == 0 || datamap.P == 0 || datamap.E == 0))
		error();
	datamap.height = i;
	return (datamap);
}
