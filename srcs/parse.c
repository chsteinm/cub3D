/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 03:47:15 by chrstein          #+#    #+#             */
/*   Updated: 2024/02/16 03:48:00 by chrstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_valid_char(char c)
{
	if (c != 'P' && \
			c != 'E' && \
			c != 'C' && \
			c != '1' && \
			c != '0' && \
			c != '\n')
		return (0);
	else
		return (1);
}

int	check_nbrs(t_map *map)
{
	int	start;
	int	exit;
	int	i;

	map->nb_collect = 0;
	start = 0;
	exit = 0;
	i = -1;
	while (map->one_line_map[++i])
	{
		if (map->one_line_map[i] == 'C')
			map->nb_collect++;
		else if (map->one_line_map[i] == 'P')
			start++;
		else if (map->one_line_map[i] == 'E')
			exit++;
		if (!check_valid_char(map->one_line_map[i]))
			return (ft_printf("Error\nInvalid char\n"), 0);
	}
	if (!(start == 1 && exit == 1 && map->nb_collect))
		return (ft_printf("Error\nInvalid number of E, P or C\n"), 0);
	return (check_win(*map));
}

int	check_rectangle(t_map *map)
{
	int	i;

	map->x = ft_strlen(map->map[0]) - 1;
	map->y = 0;
	while (map->map[++map->y])
		if (ft_strlen(map->map[map->y]) - 1 != (size_t)map->x)
			return (ft_printf("Error\nMap not rectangular\n"), 0);
	map->y--;
	i = -1;
	while (map->map[0][++i])
		if (map->map[0][i] != '1')
			return (ft_printf("Error\nMap not surrounded by walls\n"), 0);
	i = -1;
	while (map->map[0][++i])
		if (map->map[map->y][i] != '1')
			return (ft_printf("Error\nMap not surrounded by walls\n"), 0);
	i = -1;
	while (map->map[++i])
		if (map->map[i][0] != '1')
			return (ft_printf("Error\nMap not surrounded by walls\n"), 0);
	i = -1;
	while (map->map[++i])
		if (map->map[i][map->x] != '1')
			return (ft_printf("Error\nMap not surrounded by walls\n"), 0);
	return (check_nbrs(map));
}

int	fill_p_pos(t_map *map)
{
	if (!map->map)
		return (ft_printf("Error\nMalloc failed\n"), 0);
	map->p_y = 0;
	while (map->map[++map->p_y])
	{
		map->p_x = 0;
		while (map->map[map->p_y][++map->p_x])
			if (map->map[map->p_y][map->p_x] == 'P')
				return (1);
	}
	return (0);
}

int	parse(t_map *map)
{
	char	*tmp_ptr;
	char	*next_line;

	next_line = get_next_line(map->fd);
	if (!next_line || *next_line != '1')
		return (free(next_line), ft_printf("Error\nWall not found\n"), 0);
	map->one_line_map = next_line;
	while (1)
	{
		tmp_ptr = map->one_line_map;
		next_line = get_next_line(map->fd);
		if (!next_line)
			break ;
		map->one_line_map = ft_strjoin(tmp_ptr, next_line);
		free(tmp_ptr);
		free(next_line);
		if (!map->one_line_map)
			return (ft_printf("Error\nMalloc failed\n"), 0);
	}
	if (ft_strnstr(map->one_line_map, "\n\n", ft_strlen(map->one_line_map)))
		return (ft_printf("Error\nToo much \\n\n"), 0);
	map->map = ft_split(map->one_line_map, '\n');
	if (!fill_p_pos(map) || !check_rectangle(map))
		return (0);
	return (1);
}
