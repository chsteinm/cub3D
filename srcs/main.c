/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <chrstein@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 03:46:35 by chrstein          #+#    #+#             */
/*   Updated: 2024/06/27 10:03:21 by chrstein         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_all(t_data *data)
{
	free(data->line);
	free(data->game.map);
	ft_lstclear(&data->lst_map, &free);
	if (data->no_xpm)
		mlx_destroy_image(data->mlx, data->no_xpm);
	if (data->so_xpm)
		mlx_destroy_image(data->mlx, data->so_xpm);
	if (data->ea_xpm)
		mlx_destroy_image(data->mlx, data->ea_xpm);
	if (data->we_xpm)
		mlx_destroy_image(data->mlx, data->we_xpm);
	if (data->mlx_win)
		mlx_destroy_window(data->mlx, data->mlx_win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	if (data->fd != -1)
		close(data->fd);
	free(data->mlx);
}

void	set_data(t_data *data, char *path)
{
	data->mlx = NULL;
	data->mlx_win = NULL;
	ft_bzero((char *)data, sizeof(t_data));
	ft_bzero((char *)&data->game, sizeof(data->game));
	data->fd = open(path, __O_DIRECTORY);
	if (data->fd != -1)
	{
		ft_dprintf(2, "Error\n%s: is a directory", path);
		return (free_all(data), exit(1));
	}
	data->fd = open(path, O_RDONLY);
	if (data->fd == -1)
	{
		ft_dprintf(2, "Error\n%s: ", path), perror("");
		return (free_all(data), exit(1));
	}
	data->c_blue = -1;
	data->c_red = -1;
	data->c_green = -1;
	data->f_blue = -1;
	data->f_red = -1;
	data->f_green = -1;
}

int	destroy(t_data *data)
{
	return (free_all(data), exit(0), 0);
}

// int	key_press(int key_code, t_data *data)
// {
// 	if (key_code == ESC)
// 		return (destroy(data));
// 	else if (key_code == A)
// 		move(&data->game, data, data->game.player_x - 1, data->game.player_y);
// 	else if (key_code == D)
// 		move(&data->game, data, data->game.player_x + 1, data->game.player_y);
// 	else if (key_code == S)
// 		move(&data->game, data, data->game.player_x, data->game.player_y + 1);
// 	else if (key_code == W)
// 		move(&data->game, data, data->game.player_x, data->game.player_y - 1);
// 	return (1);
// }

void	print_debug(t_data *data)
{
	ft_dprintf(2, "\nC_red %d\nC_green %d\nC_blue %d\n\nF_red %d\nF_green %d\nF_blue %d\n\nP_x %d\nP_y %d\norientation %c\n\n", \
	data->c_red, data->c_green, data->c_blue, data->f_red, data->f_green, data->f_blue, \
	data->game.player_x, data->game.player_y, data->game.spawning_orientation);
	ft_printstrs(data->game.map, 2);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2 || ft_strlen(argv[1]) < 5 || \
	!ft_rstrnstr(argv[1], ".cub", 4))
		return (ft_dprintf(2, "Error\narg not valide\n"), 1);
	set_data(&data, argv[1]);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (free_all(&data), 1);
	parse(&data);
	print_debug(&data);
	// data.mlx_win = mlx_new_window(data.mlx, \
	// 		64 * (data.game.x + 1), 64 * (data.game.y + 1), "game");
	// if (!data.mlx_win)
	// 	return (free_all(&data), 1);
	// // draw_game(data.mlx, data.mlx_win, &data);
	// mlx_hook(data.mlx_win, 17, 0, &destroy, &data);
	// // mlx_hook(data.mlx_win, 2, (1L << 0), &key_press, &data);
	// mlx_loop(data.mlx);
	free_all(&data);
	return (0);
}
