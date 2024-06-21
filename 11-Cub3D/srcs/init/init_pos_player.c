/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pos_player.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 10:57:41 by abonnefo          #+#    #+#             */
/*   Updated: 2023/12/26 17:03:45 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	init_pos_player(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->valid_map[x])
	{
		y = 0;
		while (data->valid_map[x][y])
		{
			if (data->valid_map[x][y] == 'N' || data->valid_map[x][y] == 'S'
				|| data->valid_map[x][y] == 'E' || data->valid_map[x][y] == 'W')
			{
				data->pos_player_x = x;
				data->pos_player_y = y;
				return (0);
			}
			y++;
		}
		x++;
	}
	return (1);
}
