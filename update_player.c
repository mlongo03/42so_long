/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:40:58 by mlongo            #+#    #+#             */
/*   Updated: 2023/05/11 11:01:46 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_over(void)
{
	ft_printf("GAME OVER\nhai perso il campionato");
	exit (1);
}

void	game_win(void)
{
	ft_printf("GAME WIN\nhai vinto il campionato");
	exit (1);
}

void	update_player(t_data *data, int x, int y)
{
	if (x == -1)
		data->map.direction = 1;
	if (x == 1)
		data->map.direction = 2;
	if (y == -1)
		data->map.direction = 4;
	if (y == 1)
		data->map.direction = 3;
	if (data->map.splitmap[data->map.rp + x][data->map.cp + y] == 'E')
	{
		data->map.splitmap[data->map.rp + x][data->map.cp + y] = 'P';
		data->map.splitmap[data->map.rp][data->map.cp] = '0';
		data->map.mosse += 1;
		ft_printf("MOSSE :%d\n", data->map.mosse);
		if (data->map.c == 0)
			game_win();
	}
	if (data->map.splitmap[data->map.rp + x][data->map.cp + y] == '0')
	{
		data->map.splitmap[data->map.rp + x][data->map.cp + y] = 'P';
		data->map.splitmap[data->map.rp][data->map.cp] = '0';
		data->map.mosse += 1;
		ft_printf("MOSSE :%d\n", data->map.mosse);
	}
	update_player2(data, x, y);
}

void	update_player2(t_data *data, int x, int y)
{
	if (data->map.splitmap[data->map.rp + x][data->map.cp + y] == 'C')
	{
		data->map.splitmap[data->map.rp + x][data->map.cp + y] = 'P';
		data->map.splitmap[data->map.rp][data->map.cp] = '0';
		data->map.mosse += 1;
		data->map.c -= 1;
		ft_printf("MOSSE :%d\n", data->map.mosse);
		mlx_string_put(data->mlx_ptr, data->win_ptr, 0, 0,
			0xFFFFFF, "MOSSE : ");
	}
	if (data->map.splitmap[data->map.rp - 1][data->map.cp] == 'N')
	{
		data->map.splitmap[data->map.rp][data->map.cp] = '0';
		game_over();
	}
	create_map(data);
}
