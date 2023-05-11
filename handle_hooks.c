/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 11:42:43 by mlongo            #+#    #+#             */
/*   Updated: 2023/05/11 10:55:44 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	free(data->mlx_ptr);
	exit (1);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
		close_window(data);
	if (keycode == 126 || keycode == 13)
		update_player(data, -1, 0);
	if (keycode == 125 || keycode == 1)
		update_player(data, 1, 0);
	if (keycode == 124 || keycode == 2)
		update_player(data, 0, 1);
	if (keycode == 123 || keycode == 0)
		update_player(data, 0, -1);
	return (0);
}
