/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 05:50:54 by chrstein          #+#    #+#             */
/*   Updated: 2024/02/23 05:52:22 by chrstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	redraw(void *mlx_ptr, void *win_ptr, t_data *data)
{
	int	x;
	int	y;
	int	tile_size;

	tile_size = 64;
	x = data->map.p_x;
	y = data->map.p_y;
	if (data->map.map[y][x] == 'E')
		mlx_put_image_to_window(mlx_ptr, win_ptr, data->pic.exit, \
		x * tile_size, y * tile_size);
	else if ((x + y) % 2)
		mlx_put_image_to_window(mlx_ptr, win_ptr, data->pic.floor1, \
		x * tile_size, y * tile_size);
	else
		mlx_put_image_to_window(mlx_ptr, win_ptr, data->pic.floor2, \
		x * tile_size, y * tile_size);
	mlx_put_image_to_window(mlx_ptr, win_ptr, data->pic.wall, 128, 0);
}

void	print_moves_on_screen(t_data *data)
{
	char	*count;

	count = ft_utoa(data->count_move);
	if (!count)
	{
		ft_printf("Error\nMalloc failed\n");
		destroy(data);
	}
	mlx_string_put(data->mlx, data->mlx_win, 64, 32, 0xFFFFFF, "Move : ");
	mlx_string_put(data->mlx, data->mlx_win, 128, 32, 0xFFFFFF, count);
	free(count);
}

void	move(t_map *map, t_data *data, int new_x, int new_y)
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = data->mlx;
	win_ptr = data->mlx_win;
	if (map->map[new_y][new_x] == '1')
		return ;
	data->count_move++;
	if (map->map[new_y][new_x] == 'C')
	{
		map->nb_collect--;
		map->map[new_y][new_x] = '0';
	}
	redraw(data->mlx, data->mlx_win, data);
	map->p_x = new_x;
	map->p_y = new_y;
	if (map->map[map->p_y][map->p_x] == 'E' && !map->nb_collect)
	{
		ft_printf("\033[A\033[KYou won with %d moves !\n", data->count_move);
		destroy(data);
	}
	mlx_put_image_to_window(mlx_ptr, win_ptr, data->pic.player, \
	map->p_x * 64 + 7, map->p_y * 64 + 7);
	ft_printf("\033[A\033[KMove : %d\n", data->count_move);
	print_moves_on_screen(data);
}
