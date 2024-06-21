/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:39:45 by abonnefo          #+#    #+#             */
/*   Updated: 2024/01/12 14:53:37 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	close_window(t_data *data)
{
	free_all(data);
	exit(0);
}

int	mouse_move_bis(int x, int y, t_data *data)
{
	int	previous_x;

	(void)y;
	data->keys.mouse_x = WIDTH / 2;
	previous_x = data->keys.mouse_x;
	data->keys.mouse_x = x;
	if (data->keys.mouse_x > previous_x)
		data->keys.mouse_rot_right = 1;
	else if (data->keys.mouse_x < previous_x)
		data->keys.mouse_rot_left = 1;
	else
	{
		data->keys.mouse_rot_left = 0;
		data->keys.mouse_rot_right = 0;
	}
	return (0);
}

void	exec_game(t_parser *parser)
{
	t_data	data;

	if (init_data_game(&data, parser) || init_windows(&data))
		return ;
	init_textures_adress(&data);
	mlx_hook(data.img_blank->window, KeyPress, KeyPressMask, key_press, &data);
	mlx_hook(data.img_blank->window, MotionNotify, PointerMotionMask,
		mouse_move_bis, &data);
	mlx_hook(data.img_blank->window,
		KeyRelease, KeyReleaseMask, key_release, &data);
	mlx_hook(data.img_blank->window, 17, 0, close_window, &data);
	mlx_loop_hook(data.img_blank->mlx, &display_game, &data);
	mlx_loop(data.img_blank->mlx);
}
