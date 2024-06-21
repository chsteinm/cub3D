/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:55:55 by abonnefo          #+#    #+#             */
/*   Updated: 2024/01/16 11:57:21 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	movement_player_up_down(t_data *data)
{
	double	speed;

	speed = SPEED_MOVE;
	if ((data->keys.w || data->keys.s) && (data->keys.a || data->keys.d))
		speed = SPEED_MOVE_DIAG;
	if (data->keys.w == 1 && data->keys.s == 0)
	{
		if (data->valid_map[(int)(data->game->pos_x + data->game->dir_x
				* speed)][(int)(data->game->pos_y)] != '1')
			data->game->pos_x += data->game->dir_x * speed;
		if (data->valid_map[(int)(data->game->pos_x)][(int)(data->game->pos_y
				+ data->game->dir_y * speed)] != '1')
			data->game->pos_y += data->game->dir_y * speed;
	}
	else if (data->keys.s == 1 && data->keys.w == 0)
	{
		if (data->valid_map[(int)(data->game->pos_x - data->game->dir_x
				* speed)][(int)(data->game->pos_y)] != '1')
			data->game->pos_x -= data->game->dir_x * speed;
		if (data->valid_map[(int)(data->game->pos_x)][(int)(data->game->pos_y
				- data->game->dir_y * speed)] != '1')
			data->game->pos_y -= data->game->dir_y * speed;
	}
}

void	movement_player_right_left(t_data *data)
{
	if (data->keys.d == 1 && data->keys.a == 0)
	{
		if (data->valid_map[(int)(data->game->pos_x + data->game->plan_x
				* SPEED_MOVE)]
			[(int)(data->game->pos_y)] != '1')
			data->game->pos_x += data->game->plan_x * SPEED_MOVE;
		if (data->valid_map[(int)(data->game->pos_x)]
			[(int)(data->game->pos_y + data->game->plan_y
					* SPEED_MOVE)] != '1')
			data->game->pos_y += data->game->plan_y * SPEED_MOVE;
	}
	else if (data->keys.a == 1 && data->keys.d == 0)
	{
		if (data->valid_map[(int)(data->game->pos_x - data->game->plan_x
				* SPEED_MOVE)]
			[(int)(data->game->pos_y)] != '1')
			data->game->pos_x -= data->game->plan_x * SPEED_MOVE;
		if (data->valid_map[(int)(data->game->pos_x)]
			[(int)(data->game->pos_y - data->game->plan_y * SPEED_MOVE)] != '1')
			data->game->pos_y -= data->game->plan_y * SPEED_MOVE;
	}
}

void	movement_player_rotation_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	if (data->keys.rot_right == 1
		|| (data->keys.mouse_rot_right == 1 && data->mouse_on == 0))
	{
		old_dir_x = data->game->dir_x;
		data->game->dir_x = data->game->dir_x * cos(-SPEED_ROT)
			- data->game->dir_y * sin(-SPEED_ROT);
		data->game->dir_y = old_dir_x * sin(-SPEED_ROT)
			+ data->game->dir_y * cos(-SPEED_ROT);
		old_plane_x = data->game->plan_x;
		data->game->plan_x = data->game->plan_x * cos(-SPEED_ROT)
			- data->game->plan_y * sin(-SPEED_ROT);
		data->game->plan_y = old_plane_x * sin(-SPEED_ROT) + data->game->plan_y
			* cos(-SPEED_ROT);
	}
}

void	movement_player_rotation_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	if (data->keys.rot_left == 1
		|| (data->keys.mouse_rot_left == 1 && data->mouse_on == 0))
	{
		old_dir_x = data->game->dir_x;
		data->game->dir_x = data->game->dir_x * cos(SPEED_ROT)
			- data->game->dir_y * sin(SPEED_ROT);
		data->game->dir_y = old_dir_x * sin(SPEED_ROT) + data->game->dir_y
			* cos(SPEED_ROT);
		old_plane_x = data->game->plan_x;
		data->game->plan_x = data->game->plan_x * cos(SPEED_ROT)
			- data->game->plan_y * sin(SPEED_ROT);
		data->game->plan_y = old_plane_x * sin(SPEED_ROT) + data->game->plan_y
			* cos(SPEED_ROT);
	}
}

void	movement_player(t_data *data)
{
	movement_player_up_down(data);
	movement_player_right_left(data);
	movement_player_rotation_left(data);
	movement_player_rotation_right(data);
}
