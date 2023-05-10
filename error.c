/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlongo <mlongo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 12:41:16 by mlongo            #+#    #+#             */
/*   Updated: 2023/05/10 12:42:11 by mlongo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error(void)
{
	ft_printf("Errore\nla mappa é sbagliata");
	exit (1);
}

void	error_name_map(void)
{
	ft_printf("Errore\nil nome della mappa é sbagliato");
	exit (1);
}
