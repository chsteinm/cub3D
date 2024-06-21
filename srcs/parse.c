/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <chrstein@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 03:47:15 by chrstein          #+#    #+#             */
/*   Updated: 2024/06/21 13:43:59 by chrstein         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// int	check_valid_char(char c)
// {
// 	if (c != 'P' && \
// 			c != 'E' && \
// 			c != 'C' && \
// 			c != '1' && \
// 			c != '0' && \
// 			c != '\n')
// 		return (0);
// 	else
// 		return (1);
// }

// int	check_nbrs(t_game *game)
// {
// 	int	start;
// 	int	exit;
// 	int	i;

// 	game->nb_collect = 0;
// 	start = 0;
// 	exit = 0;
// 	i = -1;
// 	while (game->one_data->line_map[++i])
// 	{
// 		if (game->one_data->line_map[i] == 'C')
// 			game->nb_collect++;
// 		else if (game->one_data->line_map[i] == 'P')
// 			start++;
// 		else if (game->one_data->line_map[i] == 'E')
// 			exit++;
// 		if (!check_valid_char(game->one_data->line_map[i]))
// 			return (ft_printf("Error\nInvalid char\n"), 0);
// 	}
// 	if (!(start == 1 && exit == 1 && game->nb_collect))
// 		return (ft_printf("Error\nInvalid number of E, P or C\n"), 0);
// 	return (check_win(*map));
// }

// int	check_rectangle(t_game *game)
// {
// 	int	i;

// 	game->x = ft_strlen(game->map[0]) - 1;
// 	game->y = 0;
// 	while (game->map[++game->y])
// 		if (ft_strlen(game->map[game->y]) - 1 != (size_t)game->x)
// 			return (ft_printf("Error\nMap not rectangular\n"), 0);
// 	game->y--;
// 	i = -1;
// 	while (game->map[0][++i])
// 		if (game->map[0][i] != '1')
// 			return (ft_printf("Error\nMap not surrounded by walls\n"), 0);
// 	i = -1;
// 	while (game->map[0][++i])
// 		if (game->map[game->y][i] != '1')
// 			return (ft_printf("Error\nMap not surrounded by walls\n"), 0);
// 	i = -1;
// 	while (game->map[++i])
// 		if (game->map[i][0] != '1')
// 			return (ft_printf("Error\nMap not surrounded by walls\n"), 0);
// 	i = -1;
// 	while (game->map[++i])
// 		if (game->map[i][game->x] != '1')
// 			return (ft_printf("Error\nMap not surrounded by walls\n"), 0);
// 	return (check_nbrs(map));
// }

int	fill_p_pos(t_game *game)
{
	if (!game->map)
		return (ft_printf("Error\nMalloc failed\n"), 0);
	game->player_y = 0;
	while (game->map[++game->player_y])
	{
		game->player_x = 0;
		while (game->map[game->player_y][++game->player_x])
			if (game->map[game->player_y][game->player_x] == 'P')
				return (1);
	}
	return (0);
}

void	xpm_load(t_data *data, void *xpm_ptr, int xpm_index)
{
	char	*line_ptr;

	line_ptr = data->line + 3;
	while (*line_ptr == ' ')
		line_ptr++;
	if (*line_ptr = '\0')
	{
		ft_printf("Error\nNothing after %s\n", data->line);
		return (free_all(data), exit(1));
	}
	//test access
	//xpm_to_img(...)
	// if error...
}

void	fill_color(t_data *data, char *color)
{
	char	*line_ptr;

	line_ptr = data->line + 2;
	while (*line_ptr == ' ')
		line_ptr++;
	if (*line_ptr = '\0')
	{
		ft_printf("Error\nNothing after %s\n", data->line);
		return (free_all(data), exit(1));
	}
	//if c = c
	//data->f = ...
	//else c = floor
	//data->c = ...
	//check_error
}


void	fill_identifier(t_data *data)
{
	char	*line_ptr;

	if (!ft_strncmp(data->line, "NO ", 3))
		xpm_load(data, data->xpm_ptr, _NO);
	else if (ft_strncmp(data->line, "SO ", 3))
		xpm_load(data, data->xpm_ptr, _SO);
	else if (ft_strncmp(data->line, "EA ", 3))
		xpm_load(data, data->xpm_ptr, _EA);
	else if (ft_strncmp(data->line, "WE ", 3))
		xpm_load(data, data->xpm_ptr, _WE);
	else if (ft_strncmp(data->line, "F ", 2))
		fill_color(data, 'F');
	else if (ft_strncmp(data->line, "C ", 2))
		fill_color(data, 'C');
	else if (*data->line != '\n')
	{
		line_ptr = data->line;
		while (*line_ptr == ' ')
			line_ptr++;
		if (*data->line != '\n')
		{
			ft_printf("Error\n%s : Incorrect identifer\n", data->line);
			return (free_all(data), exit(1));
		}
	}
}

void	parse(t_data *data)
{
	char	*tmp_ptr;

	data->line = get_next_line(data->fd);
	if (!data->line)
		return (ft_printf("Error\nEmpty file\n"), 0);
	while (data->line)
	{
		fill_identifier(data);
		free(data->line);
		data->line = get_next_line(data->fd);
	}
	if (!fill_p_pos(&data->game) || !check_rectangle(data))
		return (0);
	return (1);
}
