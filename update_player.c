/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 18:40:58 by mlongo            #+#    #+#             */
/*   Updated: 2023/05/10 11:17:24 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_over()
{
	ft_printf("GAME OVER\nhai perso il campionato");
	exit (1);
}

void	game_win()
{
	ft_printf("GAME WIN\nhai vinto il campionato");
	exit (1);
}

void	update_playerup(t_data *data)
{
	data->datamap.direction = 1;
	data->img.P = mlx_xpm_file_to_image(data->mlx_ptr, "./images/Personaggioalto.xpm", &data->datamap.widhtblock, &data->datamap.heightblock);
	if (data->datamap.splitmap[data->datamap.ROWP - 1][data->datamap.COLUMNP] == 'E')
	{
		data->datamap.splitmap[data->datamap.ROWP - 1][data->datamap.COLUMNP] = 'P';
		data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP] = '0';
		data->datamap.mosse += 1;
		ft_printf("MOSSE :%d\n", data->datamap.mosse);
		if (data->datamap.C == 0)
			game_win();
	}
	if (data->datamap.splitmap[data->datamap.ROWP - 1][data->datamap.COLUMNP] == '0')
	{
		data->datamap.splitmap[data->datamap.ROWP - 1][data->datamap.COLUMNP] = 'P';
		data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP] = '0';
		data->datamap.mosse += 1;
		ft_printf("MOSSE :%d\n", data->datamap.mosse);
	}
	if (data->datamap.splitmap[data->datamap.ROWP - 1][data->datamap.COLUMNP] == 'C')
	{
		data->datamap.splitmap[data->datamap.ROWP - 1][data->datamap.COLUMNP] = 'P';
		data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP] = '0';
		data->datamap.mosse += 1;
		data->datamap.C -= 1;
		ft_printf("MOSSE :%d\n", data->datamap.mosse);
		mlx_string_put(data->mlx_ptr, data->win_ptr, 0, 0, 0xFFFFFF, "MOSSE : ");
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
	data->datamap.direction = 2;
	data->img.P = mlx_xpm_file_to_image(data->mlx_ptr, "./images/Personaggiogiu.xpm", &data->datamap.widhtblock, &data->datamap.heightblock);
	if (data->datamap.splitmap[data->datamap.ROWP + 1][data->datamap.COLUMNP] == 'E')
	{
		data->datamap.splitmap[data->datamap.ROWP + 1][data->datamap.COLUMNP] = 'P';
		data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP] = '0';
		data->datamap.mosse += 1;
		ft_printf("MOSSE :%d\n", data->datamap.mosse);
		if (data->datamap.C == 0)
			game_win();
	}
	if (data->datamap.splitmap[data->datamap.ROWP + 1][data->datamap.COLUMNP] == '0')
	{
		data->datamap.splitmap[data->datamap.ROWP + 1][data->datamap.COLUMNP] = 'P';
		data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP] = '0';
		data->datamap.mosse += 1;
		ft_printf("MOSSE :%d\n", data->datamap.mosse);
	}
	if (data->datamap.splitmap[data->datamap.ROWP + 1][data->datamap.COLUMNP] == 'C')
	{
		data->datamap.splitmap[data->datamap.ROWP + 1][data->datamap.COLUMNP] = 'P';
		data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP] = '0';
		data->datamap.mosse += 1;
		data->datamap.C -= 1;
		ft_printf("MOSSE :%d\n", data->datamap.mosse);
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
	data->datamap.direction = 3;
	data->img.P = mlx_xpm_file_to_image(data->mlx_ptr, "./images/Personaggio.xpm", &data->datamap.widhtblock, &data->datamap.heightblock);
	if (data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP + 1] == 'E')
	{
		data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP + 1] = 'P';
		data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP] = '0';
		data->datamap.mosse += 1;
		ft_printf("MOSSE :%d\n", data->datamap.mosse);
		if (data->datamap.C == 0)
			game_win();
	}
	if (data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP + 1] == '0')
	{
		data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP + 1] = 'P';
		data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP] = '0';
		data->datamap.mosse += 1;
		ft_printf("MOSSE :%d\n", data->datamap.mosse);
	}
	if (data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP + 1] == 'C')
	{
		data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP + 1] = 'P';
		data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP] = '0';
		data->datamap.mosse += 1;
		data->datamap.C -= 1;
		ft_printf("MOSSE :%d\n", data->datamap.mosse);
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
	data->datamap.direction = 4;
	data->img.P = mlx_xpm_file_to_image(data->mlx_ptr, "./images/Personaggiosinistra.xpm", &data->datamap.widhtblock, &data->datamap.heightblock);
	if (data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP - 1] == 'E')
	{
		data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP - 1] = 'P';
		data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP] = '0';
		data->datamap.mosse += 1;
		ft_printf("MOSSE :%d\n", data->datamap.mosse);
		if (data->datamap.C == 0)
			game_win();
	}
	if (data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP - 1] == '0')
	{
		data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP - 1] = 'P';
		data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP] = '0';
		data->datamap.mosse += 1;
		ft_printf("MOSSE :%d\n", data->datamap.mosse);
	}
	if (data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP - 1] == 'C')
	{
		data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP - 1] = 'P';
		data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP] = '0';
		data->datamap.mosse += 1;
		data->datamap.C -= 1;
		ft_printf("MOSSE :%d\n", data->datamap.mosse);
	}
	if (data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP - 1] == 'N')
	{
		data->datamap.splitmap[data->datamap.ROWP][data->datamap.COLUMNP] = '0';
		game_over();
	}
	create_map(data);
}
