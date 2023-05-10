/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:40:58 by mlongo            #+#    #+#             */
/*   Updated: 2023/05/10 12:20:28 by mlongo           ###   ########.fr       */
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

void	update_playerup(t_data *data)
{
	data->map.direction = 1;
	data->img.p = mlx_xpm_file_to_image(data->mlx_ptr, "./images/Palto.xpm",
			&data->map.widhtblock, &data->map.heightblock);
	if (data->map.splitmap[data->map.rp - 1][data->map.cp] == 'E')
	{
		data->map.splitmap[data->map.rp - 1][data->map.cp] = 'P';
		data->map.splitmap[data->map.rp][data->map.cp] = '0';
		data->map.mosse += 1;
		ft_printf("MOSSE :%d\n", data->map.mosse);
		if (data->map.c == 0)
			game_win();
	}
	if (data->map.splitmap[data->map.rp - 1][data->map.cp] == '0')
	{
		data->map.splitmap[data->map.rp - 1][data->map.cp] = 'P';
		data->map.splitmap[data->map.rp][data->map.cp] = '0';
		data->map.mosse += 1;
		ft_printf("MOSSE :%d\n", data->map.mosse);
	}
	if (data->map.splitmap[data->map.rp - 1][data->map.cp] == 'C')
	{
		data->map.splitmap[data->map.rp - 1][data->map.cp] = 'P';
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

void	update_playerdown(t_data *data)
{
	data->map.direction = 2;
	data->img.p = mlx_xpm_file_to_image(data->mlx_ptr, "./images/Pgiu.xpm",
			&data->map.widhtblock, &data->map.heightblock);
	if (data->map.splitmap[data->map.rp + 1][data->map.cp] == 'E')
	{
		data->map.splitmap[data->map.rp + 1][data->map.cp] = 'P';
		data->map.splitmap[data->map.rp][data->map.cp] = '0';
		data->map.mosse += 1;
		ft_printf("MOSSE :%d\n", data->map.mosse);
		if (data->map.c == 0)
			game_win();
	}
	if (data->map.splitmap[data->map.rp + 1][data->map.cp] == '0')
	{
		data->map.splitmap[data->map.rp + 1][data->map.cp] = 'P';
		data->map.splitmap[data->map.rp][data->map.cp] = '0';
		data->map.mosse += 1;
		ft_printf("MOSSE :%d\n", data->map.mosse);
	}
	if (data->map.splitmap[data->map.rp + 1][data->map.cp] == 'C')
	{
		data->map.splitmap[data->map.rp + 1][data->map.cp] = 'P';
		data->map.splitmap[data->map.rp][data->map.cp] = '0';
		data->map.mosse += 1;
		data->map.c -= 1;
		ft_printf("MOSSE :%d\n", data->map.mosse);
	}
	if (data->map.splitmap[data->map.rp + 1][data->map.cp] == 'N')
	{
		data->map.splitmap[data->map.rp][data->map.cp] = '0';
		game_over();
	}
	create_map(data);
}

void	update_playerright(t_data *data)
{
	data->map.direction = 3;
	data->img.p = mlx_xpm_file_to_image(data->mlx_ptr, "./images/P.xpm",
			&data->map.widhtblock, &data->map.heightblock);
	if (data->map.splitmap[data->map.rp][data->map.cp + 1] == 'E')
	{
		data->map.splitmap[data->map.rp][data->map.cp + 1] = 'P';
		data->map.splitmap[data->map.rp][data->map.cp] = '0';
		data->map.mosse += 1;
		ft_printf("MOSSE :%d\n", data->map.mosse);
		if (data->map.c == 0)
			game_win();
	}
	if (data->map.splitmap[data->map.rp][data->map.cp + 1] == '0')
	{
		data->map.splitmap[data->map.rp][data->map.cp + 1] = 'P';
		data->map.splitmap[data->map.rp][data->map.cp] = '0';
		data->map.mosse += 1;
		ft_printf("MOSSE :%d\n", data->map.mosse);
	}
	if (data->map.splitmap[data->map.rp][data->map.cp + 1] == 'C')
	{
		data->map.splitmap[data->map.rp][data->map.cp + 1] = 'P';
		data->map.splitmap[data->map.rp][data->map.cp] = '0';
		data->map.mosse += 1;
		data->map.c -= 1;
		ft_printf("MOSSE :%d\n", data->map.mosse);
	}
	if (data->map.splitmap[data->map.rp][data->map.cp + 1] == 'N')
	{
		data->map.splitmap[data->map.rp][data->map.cp] = '0';
		game_over();
	}
	create_map(data);
}

void	update_playerleft(t_data *data)
{
	data->map.direction = 4;
	data->img.p = mlx_xpm_file_to_image(data->mlx_ptr, "./images/Psinistra.xpm",
			&data->map.widhtblock, &data->map.heightblock);
	if (data->map.splitmap[data->map.rp][data->map.cp - 1] == 'E')
	{
		data->map.splitmap[data->map.rp][data->map.cp - 1] = 'P';
		data->map.splitmap[data->map.rp][data->map.cp] = '0';
		data->map.mosse += 1;
		ft_printf("MOSSE :%d\n", data->map.mosse);
		if (data->map.c == 0)
			game_win();
	}
	if (data->map.splitmap[data->map.rp][data->map.cp - 1] == '0')
	{
		data->map.splitmap[data->map.rp][data->map.cp - 1] = 'P';
		data->map.splitmap[data->map.rp][data->map.cp] = '0';
		data->map.mosse += 1;
		ft_printf("MOSSE :%d\n", data->map.mosse);
	}
	if (data->map.splitmap[data->map.rp][data->map.cp - 1] == 'C')
	{
		data->map.splitmap[data->map.rp][data->map.cp - 1] = 'P';
		data->map.splitmap[data->map.rp][data->map.cp] = '0';
		data->map.mosse += 1;
		data->map.c -= 1;
		ft_printf("MOSSE :%d\n", data->map.mosse);
	}
	if (data->map.splitmap[data->map.rp][data->map.cp - 1] == 'N')
	{
		data->map.splitmap[data->map.rp][data->map.cp] = '0';
		game_over();
	}
	create_map(data);
}
