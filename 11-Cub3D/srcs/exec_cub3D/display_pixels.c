/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_pixels.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 12:25:32 by abonnefo          #+#    #+#             */
/*   Updated: 2024/01/08 10:36:24 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	update_texture(t_data *data, int line_height)
{
	if (data->game->side == 0)
		data->game->wall_x = data->game->pos_y + data->game->dist_to_wall
			* data->game->ray_dir_y;
	else
		data->game->wall_x = data->game->pos_x + data->game->dist_to_wall
			* data->game->ray_dir_x;
	data->game->wall_x -= floor((data->game->wall_x));
	data->game->texture_x = (int)(data->game->wall_x * 64);
	if (data->game->side == 0 && data->game->ray_dir_x > 0)
		data->game->texture_x = 64 - data->game->texture_x - 1;
	if (data->game->side == 1 && data->game->ray_dir_y < 0)
		data->game->texture_x = 64 - data->game->texture_x - 1;
	data->game->walk = 1.0 * 64 / line_height;
	data->game->texture_pos = \
	(data->game->draw_start - HEIGHT / 2 + line_height / 2) * data->game->walk;
}

void	calcul_wall_drawing_params(t_data *data)
{
	if (data->game->side == 0)
		data->game->dist_to_wall = (data->game->side_dist_x
				- data->game->delta_dist_x);
	else
		data->game->dist_to_wall = (data->game->side_dist_y
				- data->game->delta_dist_y);
	data->game->line_height = (int)(HEIGHT / data->game->dist_to_wall);
	data->game->draw_start = -data->game->line_height / 2 + HEIGHT / 2;
	if (data->game->draw_start < 0)
		data->game->draw_start = 0;
	data->game->draw_end = data->game->line_height / 2 + HEIGHT / 2;
	if (data->game->draw_end >= HEIGHT || data->game->draw_end < 0)
		data->game->draw_end = HEIGHT - 1;
}

void	draw_vertical_column(t_data *data, int x, int y, int line_height)
{
	while (y < data->game->draw_start)
	{
		put_pixel(data, x, y, get_rgb(data, 1));
		y++;
	}
	update_texture(data, line_height);
	while (y <= data->game->draw_end && y >= data->game->draw_start)
	{
		data->game->texture_y = (int)data->game->texture_pos;
		data->game->texture_pos += data->game->walk;
		if (data->game->side == 0 && data->game->ray_dir_x < 0)
			put_pixel(data, x, y, get_color(data, data->texture_north));
		else if (data->game->side == 0 && data->game->ray_dir_x >= 0)
			put_pixel(data, x, y, get_color(data, data->texture_south));
		else if (data->game->side == 1 && data->game->ray_dir_y < 0)
			put_pixel(data, x, y, get_color(data, data->texture_west));
		else if (data->game->side == 1 && data->game->ray_dir_y >= 0)
			put_pixel(data, x, y, get_color(data, data->texture_east));
		y++;
	}
	while (y < HEIGHT)
	{
		put_pixel(data, x, y, get_rgb(data, 0));
		y++;
	}
}
