/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rays_directions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 11:43:17 by abonnefo          #+#    #+#             */
/*   Updated: 2024/01/08 10:06:44 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_ray_direction(t_data *data, int x)
{
	data->game->camera_x = 2 * x / (double)WIDTH - 1;
	data->game->ray_dir_x = data->game->dir_x
		+ data->game->plan_x * data->game->camera_x;
	data->game->ray_dir_y = data->game->dir_y
		+ data->game->plan_y * data->game->camera_x;
	if (data->game->ray_dir_x != 0)
		data->game->delta_dist_x = ft_fabs(1 / data->game->ray_dir_x);
	else
		data->game->delta_dist_x = INFINITY_VALUE;
	if (data->game->ray_dir_y != 0)
		data->game->delta_dist_y = ft_fabs(1 / data->game->ray_dir_y);
	else
		data->game->delta_dist_y = INFINITY_VALUE;
}

void	init_side_dist_x(t_data	*data)
{
	data->game->map_x = (int)data->game->pos_x;
	if (data->game->ray_dir_x < 0)
	{
		data->game->step_x = -1;
		data->game->side_dist_x = (data->game->pos_x
				- data->game->map_x) * data->game->delta_dist_x;
	}
	else
	{
		data->game->step_x = 1;
		data->game->side_dist_x = (data->game->map_x + 1
				- data->game->pos_x) * data->game->delta_dist_x;
	}
}

void	init_side_dist_y(t_data	*data)
{
	data->game->map_y = (int)data->game->pos_y;
	if (data->game->ray_dir_y < 0)
	{
		data->game->step_y = -1;
		data->game->side_dist_y = (data->game->pos_y
				- data->game->map_y) * data->game->delta_dist_y;
	}
	else
	{
		data->game->step_y = 1;
		data->game->side_dist_y = (data->game->map_y + 1
				- data->game->pos_y) * data->game->delta_dist_y;
	}
}

void	init_ray(t_data	*data, int x)
{
	init_ray_direction(data, x);
	init_side_dist_x(data);
	init_side_dist_y(data);
}
