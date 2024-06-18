/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <chrstein@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 03:46:35 by chrstein          #+#    #+#             */
/*   Updated: 2024/06/18 20:46:05 by chrstein         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_all(t_data *data)
{
	free(data->map.one_line_map);
	ft_free_strings(data->map.map);
	if (data->pic.wall)
		mlx_destroy_image(data->mlx, data->pic.wall);
	if (data->pic.floor1)
		mlx_destroy_image(data->mlx, data->pic.floor1);
	if (data->pic.floor2)
		mlx_destroy_image(data->mlx, data->pic.floor2);
	if (data->pic.exit)
		mlx_destroy_image(data->mlx, data->pic.exit);
	if (data->pic.player)
		mlx_destroy_image(data->mlx, data->pic.player);
	if (data->pic.collect1)
		mlx_destroy_image(data->mlx, data->pic.collect1);
	if (data->pic.collect2)
		mlx_destroy_image(data->mlx, data->pic.collect2);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	if (data->map.fd != -1)
		close(data->map.fd);
	free(data->mlx);
}

int	set_data(t_data *data, char *path)
{
	data->map.map = NULL;
	data->map.one_line_map = NULL;
	data->mlx = NULL;
	data->mlx_win = NULL;
	ft_bzero((char *)&data->pic, sizeof(data->pic));
	data->map.exit_access = 0;
	data->pic.img_height = 64;
	data->pic.img_width = 64;
	data->count_move = 0;
	data->map.fd = open(path, __O_DIRECTORY);
	if (data->map.fd != -1)
		return (ft_printf("Error\n%s: is a directory", path), 0);
	data->map.fd = open(path, O_RDONLY);
	if (data->map.fd == -1)
		return (ft_printf("Error\n%s: ", path), perror(""), 0);
	return (1);
}

int	destroy(t_data *data)
{
	return (free_all(data), exit(0), 0);
}

int	key_press(int key_code, t_data *data)
{
	if (key_code == ESC)
		return (destroy(data));
	else if (key_code == A)
		move(&data->map, data, data->map.p_x - 1, data->map.p_y);
	else if (key_code == D)
		move(&data->map, data, data->map.p_x + 1, data->map.p_y);
	else if (key_code == S)
		move(&data->map, data, data->map.p_x, data->map.p_y + 1);
	else if (key_code == W)
		move(&data->map, data, data->map.p_x, data->map.p_y - 1);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2 || !ft_strnstr(argv[1], ".cub", ft_strlen(argv[1])))
		return (ft_printf("Error\narg not valide\n"), 1);
	if (!set_data(&data, argv[1]) || !parse(&data.map))
		return (free_all(&data), 1);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (free_all(&data), 1);
	data.mlx_win = mlx_new_window(data.mlx, \
			64 * (data.map.x + 1), 64 * (data.map.y + 1), "map");
	if (!data.mlx_win)
		return (free_all(&data), 1);
	if (!init_xpm(&data.pic, data.mlx))
		return (free_all(&data), 1);
	draw_map(data.mlx, data.mlx_win, &data);
	mlx_hook(data.mlx_win, 17, 0, &destroy, &data);
	mlx_hook(data.mlx_win, 2, (1L << 0), &key_press, &data);
	mlx_loop(data.mlx);
	free_all(&data);
	return (0);
}
