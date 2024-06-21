/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:57:37 by abonnefo          #+#    #+#             */
/*   Updated: 2023/12/26 17:19:12 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	throw_rays(t_data *data)
{
	data->game->hit = 0;
	while (data->game->hit == 0)
	{
		if (data->game->side_dist_x < data->game->side_dist_y)
		{
			data->game->side_dist_x += data->game->delta_dist_x;
			data->game->map_x += data->game->step_x;
			data->game->side = 0;
		}
		else
		{
			data->game->side_dist_y += data->game->delta_dist_y;
			data->game->map_y += data->game->step_y;
			data->game->side = 1;
		}
		if (data->valid_map[data->game->map_x][data->game->map_y] == '1')
			data->game->hit = 1;
	}
	return ;
}
