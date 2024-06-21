/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pos_directions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 16:47:43 by abonnefo          #+#    #+#             */
/*   Updated: 2024/01/08 10:06:20 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_pos_dir_w_and_e(t_data *data)
{
	if (data->valid_map[(int)data->game->pos_x][(int)data->game->pos_y] == 'W')
	{
		data->game->dir_x = 0;
		data->game->dir_y = -1;
		data->game->plan_x = -0.66;
		data->game->plan_y = 0;
	}
	else if (data->valid_map[(int)data->game->pos_x][(int)data->game->pos_y]
		== 'E')
	{
		data->game->dir_x = 0;
		data->game->dir_y = 1;
		data->game->plan_x = 0.66;
		data->game->plan_y = 0;
	}
	return ;
}

void	init_pos_dir_n_and_s(t_data *data)
{
	if (data->valid_map[(int)data->game->pos_x][(int)data->game->pos_y] == 'N')
	{
		data->game->dir_x = -1;
		data->game->dir_y = 0;
		data->game->plan_x = 0;
		data->game->plan_y = 0.66;
	}
	else if (data->valid_map[(int)data->game->pos_x][(int)data->game->pos_y]
		== 'S')
	{
		data->game->dir_x = 1;
		data->game->dir_y = 0;
		data->game->plan_x = 0;
		data->game->plan_y = -0.66;
	}
}

void	init_pos_directions(t_data *data)
{
	init_pos_dir_n_and_s(data);
	init_pos_dir_w_and_e(data);
}
