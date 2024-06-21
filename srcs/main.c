/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <chrstein@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 03:46:35 by chrstein          #+#    #+#             */
/*   Updated: 2024/06/21 13:31:35 by chrstein         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_all(t_data *data)
{
	free(data->line);
	ft_free_strings(data->game.map);
	if (data->xpm_ptr[_NO])
		mlx_destroy_image(data->mlx, data->xpm_ptr[_NO]);
	if (data->xpm_ptr[_SO])
		mlx_destroy_image(data->mlx, data->xpm_ptr[_SO]);
	if (data->xpm_ptr[_EA])
		mlx_destroy_image(data->mlx, data->xpm_ptr[_EA]);
	if (data->xpm_ptr[_WE])
		mlx_destroy_image(data->mlx, data->xpm_ptr[_WE]);
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
	ft_bzero((char *)data->xpm_ptr, 4);
	ft_bzero((char *)&data->game, sizeof(data->game));
	data->fd = open(path, __O_DIRECTORY);
	if (data->fd != -1)
	{
		ft_printf("Error\n%s: is a directory", path);
		return (free_all(data), exit(1));
	}
	data->fd = open(path, O_RDONLY);
	if (data->fd == -1)
	{
		ft_printf("Error\n%s: ", path), perror("");
		return (free_all(data), exit(1));
	}	
	data->game.img_height = 64;
	data->game.img_width = 64;
	data->game.xpm_ptr = data->xpm_ptr;
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

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2 || ft_strlen(argv[1]) < 5 || \
	!ft_rstrnstr(argv[1], ".cub", 4))
		return (ft_printf("Error\narg not valide\n"), 1);
	set_data(&data, argv[1]);
	parse(&data);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (free_all(&data), 1);
	data.mlx_win = mlx_new_window(data.mlx, \
			64 * (data.game.x + 1), 64 * (data.game.y + 1), "game");
	if (!data.mlx_win)
		return (free_all(&data), 1);
	if (!init_xpm(&data, data.mlx))
		return (free_all(&data), 1);
	// draw_game(data.mlx, data.mlx_win, &data);
	mlx_hook(data.mlx_win, 17, 0, &destroy, &data);
	// mlx_hook(data.mlx_win, 2, (1L << 0), &key_press, &data);
	mlx_loop(data.mlx);
	free_all(&data);
	return (0);
}
