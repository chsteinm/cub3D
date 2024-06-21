/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:57:41 by abonnefo          #+#    #+#             */
/*   Updated: 2024/01/11 14:12:40 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	update_movement_keyboard_and_mouse(t_data *data)
{
	if (data->keys.w == 1)
		movement_player(data);
	if (data->keys.s == 1)
		movement_player(data);
	if (data->keys.d == 1)
		movement_player(data);
	if (data->keys.a == 1)
		movement_player(data);
	if (data->keys.rot_left == 1)
		movement_player(data);
	if (data->keys.rot_right == 1)
		movement_player(data);
	if (data->keys.mouse_rot_right == 1)
		movement_player(data);
	if (data->keys.mouse_rot_left == 1)
		movement_player(data);
}

int	display_game(t_data *data)
{
	int	x;

	x = 0;
	update_movement_keyboard_and_mouse(data);
	while (x < WIDTH)
	{
		init_ray(data, x);
		throw_rays(data);
		calcul_wall_drawing_params(data);
		draw_vertical_column(data, x, 0, data->game->line_height);
		x++;
	}
	display_minimap(data, 0, 0);
	if (data->mouse_on == 0)
	{
		mlx_mouse_move(data->img_blank->mlx, data->img_blank->window,
			WIDTH / 2, HEIGHT / 2);
	}
	mlx_put_image_to_window(data->img_blank->mlx, data->img_blank->window,
		data->img_blank->img_ptr, 0, 0);
	return (0);
}

/* int	display_game(t_data *data)
{
	int	x;

	x = 0;
	update_movement_keyboard_and_mouse(data);
	while (x < WIDTH)
	{
		init_ray(data, x);
		throw_rays(data);
		calcul_wall_drawing_params(data);
		draw_vertical_column(data, x, 0, data->game->line_height);
		x++;
	}
	display_minimap(data, 0, 0);
	if (data->mouse_on == 0)
	{
		mlx_mouse_move(data->img_blank->mlx, data->img_blank->window,
			WIDTH / 2, HEIGHT / 2);
		mlx_mouse_hide(data->img_blank->mlx, data->img_blank->window);
	}
	else if (data->mouse_on == 1)
		mlx_mouse_show(data->img_blank->mlx, data->img_blank->window);
	mlx_put_image_to_window(data->img_blank->mlx, data->img_blank->window,
		data->img_blank->img_ptr, 0, 0);
	return (0);
} */