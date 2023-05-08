/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:40:58 by mlongo            #+#    #+#             */
/*   Updated: 2023/05/08 19:29:09 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_over()
{
	printf("GAME OVER\nhai perso il campionato");
	exit (1);
}

void	game_win()
{
	printf("GAME WIN\nhai vinto il campionato");
	exit (1);
}

void	update_playerup(t_data *data)
{
	if (data->datamap.splitmap[data->datamap.ROWP - 1][data->datamap.COLUMNP] == 'E')
	{
		data->datamap.splitmap[data->datamap.ROWP - 1][data->datamap.COLUMNP] = 'P';
		data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP] = '0';
		data->datamap.mosse += 1;
		printf("MOSSE :%d\n", data->datamap.mosse);
		if (data->datamap.C == 0)
			game_win();
	}
	if (data->datamap.splitmap[data->datamap.ROWP - 1][data->datamap.COLUMNP] == '0')
	{
		data->datamap.splitmap[data->datamap.ROWP - 1][data->datamap.COLUMNP] = 'P';
		data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP] = '0';
		data->datamap.mosse += 1;
		printf("MOSSE :%d\n", data->datamap.mosse);
	}
	if (data->datamap.splitmap[data->datamap.ROWP - 1][data->datamap.COLUMNP] == 'C')
	{
		data->datamap.splitmap[data->datamap.ROWP - 1][data->datamap.COLUMNP] = 'P';
		data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP] = '0';
		data->datamap.mosse += 1;
		data->datamap.C -= 1;
		printf("MOSSE :%d\n", data->datamap.mosse);
	}
	if (data->datamap.splitmap[data->datamap.ROWP - 1][data->datamap.COLUMNP] == 'N')
	{
		data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP] = '0';
		game_over();
	}
	create_map(data);
}

void	update_playerdown(t_data *data)
{
	if (data->datamap.splitmap[data->datamap.ROWP + 1][data->datamap.COLUMNP] == 'E')
	{
		data->datamap.splitmap[data->datamap.ROWP + 1][data->datamap.COLUMNP] = 'P';
		data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP] = '0';
		data->datamap.mosse += 1;
		printf("MOSSE :%d\n", data->datamap.mosse);
		if (data->datamap.C == 0)
			game_win();
	}
	if (data->datamap.splitmap[data->datamap.ROWP + 1][data->datamap.COLUMNP] == '0')
	{
		data->datamap.splitmap[data->datamap.ROWP + 1][data->datamap.COLUMNP] = 'P';
		data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP] = '0';
		data->datamap.mosse += 1;
		printf("MOSSE :%d\n", data->datamap.mosse);
	}
	if (data->datamap.splitmap[data->datamap.ROWP + 1][data->datamap.COLUMNP] == 'C')
	{
		data->datamap.splitmap[data->datamap.ROWP + 1][data->datamap.COLUMNP] = 'P';
		data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP] = '0';
		data->datamap.mosse += 1;
		data->datamap.C -= 1;
		printf("MOSSE :%d\n", data->datamap.mosse);
	}
	if (data->datamap.splitmap[data->datamap.ROWP + 1][data->datamap.COLUMNP] == 'N')
	{
		data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP] = '0';
		game_over();
	}
	create_map(data);
}

void	update_playerright(t_data *data)
{
	if (data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP + 1] == 'E')
	{
		data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP + 1] = 'P';
		data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP] = '0';
		data->datamap.mosse += 1;
		printf("MOSSE :%d\n", data->datamap.mosse);
		if (data->datamap.C == 0)
			game_win();
	}
	if (data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP + 1] == '0')
	{
		data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP + 1] = 'P';
		data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP] = '0';
		data->datamap.mosse += 1;
		printf("MOSSE :%d\n", data->datamap.mosse);
	}
	if (data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP + 1] == 'C')
	{
		data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP + 1] = 'P';
		data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP] = '0';
		data->datamap.mosse += 1;
		data->datamap.C -= 1;
		printf("MOSSE :%d\n", data->datamap.mosse);
	}
	if (data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP + 1] == 'N')
	{
		data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP] = '0';
		game_over();
	}
	create_map(data);
}

void	update_playerleft(t_data *data)
{
	if (data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP - 1] == 'E')
	{
		data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP - 1] = 'P';
		data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP] = '0';
		data->datamap.mosse += 1;
		printf("MOSSE :%d\n", data->datamap.mosse);
		if (data->datamap.C == 0)
			game_win();
	}
	if (data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP - 1] == '0')
	{
		data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP - 1] = 'P';
		data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP] = '0';
		printf("MOSSE :%d\n", data->datamap.mosse);
	}
	if (data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP - 1] == 'C')
	{
		data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP - 1] = 'P';
		data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP] = '0';
		data->datamap.mosse += 1;
		data->datamap.C -= 1;
		printf("MOSSE :%d\n", data->datamap.mosse);
	}
	if (data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP - 1] == 'N')
	{
		data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP] = '0';
		game_over();
	}
	create_map(data);
}
