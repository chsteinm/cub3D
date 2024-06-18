/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 05:50:43 by chrstein          #+#    #+#             */
/*   Updated: 2024/02/23 05:51:23 by chrstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_p_n_c(void *mlx_ptr, void *win_ptr, t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y <= data->map.y)
	{
		x = -1;
		while (++x <= data->map.x)
		{
			if (data->map.map[y][x] == 'P')
				mlx_put_image_to_window(mlx_ptr, win_ptr, data->pic.player, \
				x * 64 + 7, y * 64 + 7);
			else if (data->map.map[y][x] == 'C' && (x + y) % 2)
				mlx_put_image_to_window(mlx_ptr, win_ptr, data->pic.collect1, \
				x * 64, y * 64);
			else if (data->map.map[y][x] == 'C')
				mlx_put_image_to_window(mlx_ptr, win_ptr, data->pic.collect2, \
				x * 64, y * 64);
		}
	}
	if (!data->count_move)
		data->map.map[data->map.p_y][data->map.p_x] = '0';
}

void	draw_map(void *mlx_ptr, void *win_ptr, t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y <= data->map.y)
	{
		x = -1;
		while (++x <= data->map.x)
		{
			if (data->map.map[y][x] == '1')
				mlx_put_image_to_window(mlx_ptr, win_ptr, data->pic.wall, \
				x * 64, y * 64);
			else if (data->map.map[y][x] == 'E')
				mlx_put_image_to_window(mlx_ptr, win_ptr, data->pic.exit, \
				x * 64, y * 64);
			else if ((x + y) % 2)
				mlx_put_image_to_window(mlx_ptr, win_ptr, data->pic.floor1, \
				x * 64, y * 64);
			else
				mlx_put_image_to_window(mlx_ptr, win_ptr, data->pic.floor2, \
				x * 64, y * 64);
		}
	}
	draw_p_n_c(data->mlx, data->mlx_win, data);
}

int	init_xpm(t_pic *pic, void *mlx_ptr)
{
	pic->wall = mlx_xpm_file_to_image(mlx_ptr, \
	WALL, &pic->img_width, &pic->img_height);
	if (!pic->wall)
		return (0);
	pic->floor1 = mlx_xpm_file_to_image(mlx_ptr, \
	FLOOR1, &pic->img_width, &pic->img_height);
	pic->floor2 = mlx_xpm_file_to_image(mlx_ptr, \
	FLOOR2, &pic->img_width, &pic->img_height);
	if (!pic->floor2 || !pic->floor1)
		return (0);
	pic->player = mlx_xpm_file_to_image(mlx_ptr, \
	PLAYER, &pic->img_width, &pic->img_height);
	if (!pic->player)
		return (0);
	pic->exit = mlx_xpm_file_to_image(mlx_ptr, \
	EXIT, &pic->img_width, &pic->img_height);
	if (!pic->exit)
		return (0);
	pic->collect1 = mlx_xpm_file_to_image(mlx_ptr, \
	COLLECT1, &pic->img_width, &pic->img_height);
	pic->collect2 = mlx_xpm_file_to_image(mlx_ptr, \
	COLLECT2, &pic->img_width, &pic->img_height);
	if (!pic->collect1 || !pic->collect2)
		return (0);
	return (1);
}
