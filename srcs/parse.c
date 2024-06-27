/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <chrstein@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 03:47:15 by chrstein          #+#    #+#             */
/*   Updated: 2024/06/27 10:10:19 by chrstein         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_xpm(t_data *data, char *line_ptr)
{
	int	fd;
	
	if (*line_ptr == '\0' || *line_ptr == '\n')
	{
		ft_dprintf(2, "Error\nNothing after %s\n", data->line);
		return (free_all(data), exit(1));
	}
	if (!ft_rstrnstr(line_ptr, ".xpm\n", 5))
	{
		ft_dprintf(1, "Error\nNeed a .xpm file : %s\n", data->line);
		return (free_all(data), exit(1));
	}
	fd = ft_strlen(line_ptr) - 1;
	line_ptr[fd] = '\0';
	fd = open(line_ptr, O_RDONLY);
	if (fd == -1)
	{
		ft_dprintf(2, "Error\n%s", line_ptr), perror("");
		return (free_all(data), exit(1));
	}
	close(fd);
}

void	xpm_load(t_data *data, void **xpm_ptr)
{
	char	*line_ptr;
	int		width;
	int		height;

	if (*xpm_ptr)
	{
		ft_dprintf(2, "Error\nMultiple indentifier %c%c found\n", *data->line, data->line[1]);
		return (free_all(data), exit(1));
	}
	line_ptr = data->line + 3;
	while (*line_ptr == ' ')
		line_ptr++;
	check_xpm(data, line_ptr);
	*xpm_ptr = mlx_xpm_file_to_image(data->mlx, line_ptr, &width, &height);
    if (*xpm_ptr == NULL)
	{
		ft_dprintf(2, "Error\nCan't load %s\n", line_ptr);
		return (free_all(data), exit(1));
	}
}

void	check_color(t_data *data, char *line_ptr)
{
	size_t	i;
	int		nb_of_color;
	
	nb_of_color = 0;
	i = -1;
	while (line_ptr[++i] && line_ptr[i] != '\n')
	{
		if (ft_isdigit(line_ptr[i]))
		{
			nb_of_color++;
			while (ft_isdigit(line_ptr[i]))
				i++;
		}
		if (!ft_isdigit(line_ptr[i]) && line_ptr[i] != ',' && line_ptr[i] != '\n' && line_ptr[i] != ' ')
		{
			ft_dprintf(2, "Error\nIncorrect char in %c colors : \"%c\"\n", *data->line, line_ptr[i]);
			return (free_all(data), exit(1));
		}
	}
	if (nb_of_color != 3)
	{
		ft_dprintf(2, "Error\nNeed R,G,B and R,G,B only !\n");
		return (free_all(data), exit(1));
	}
}

int		special_atoi(t_data *data, char **line_ptr)
{
	int		res;
	char	*ptr;

	ptr = *line_ptr;
	while (*ptr == ' ')
		ptr++;
	res = 0;
	while (*ptr && *ptr != ',' && *ptr != '\n')
	{
		res = res * 10 + (*ptr - 48);
		if (res > 255)
		{
			ft_dprintf(2, "Error\nR,G,B need value <= 255\n");
			free_all(data);
			exit(1);
		}
		ptr++;
	}
	while (*ptr == ',')
		ptr++;
	*line_ptr = ptr;
	return (res);
}

void	double_check_color(t_data *data, char color)
{
	if (color == 'C' && data->c_blue != -1)
	{
		ft_dprintf(2, "Error\nMultiple identifier %c\n", color);
		return (free_all(data), exit(1));
	}
	if (color == 'F' && data->f_blue != -1)
	{
		ft_dprintf(2, "Error\nMultiple identifier %c\n", color);
		return (free_all(data), exit(1));
	}
}

void	fill_color(t_data *data, char color)
{
	char	*line_ptr;

	line_ptr = data->line + 2;
	while (*line_ptr == ' ')
		line_ptr++;
	if (*line_ptr == '\n' || *line_ptr == '\0')
	{
		ft_dprintf(2, "Error\nNothing after %s\n", data->line);
		return (free_all(data), exit(1));
	}
	check_color(data, line_ptr);
	double_check_color(data, color);
	if (color == 'C')
		data->c_red = special_atoi(data, &line_ptr);
	else
		data->f_red = special_atoi(data, &line_ptr);
	if (color == 'C')
		data->c_green = special_atoi(data, &line_ptr);
	else
		data->f_green = special_atoi(data, &line_ptr);
	if (color == 'C')
		data->c_blue = special_atoi(data, &line_ptr);
	else
		data->f_blue = special_atoi(data, &line_ptr);
}

void	check_all_identifer(t_data *data)
{
	if (!data->ea_xpm || !data->no_xpm || !data->ea_xpm || !data->we_xpm)
	{
		ft_dprintf(2, "Error\nNeed all the identifiers before the map\n");
		return (free_all(data), exit(1));
	}
	if (data->c_blue == -1 || data->c_green == -1 || data->c_red == -1)
	{
		ft_dprintf(2, "Error\nNeed the ceiling colors\n");
		return (free_all(data), exit(1));
	}
	if (data->f_blue == -1 || data->f_green == -1 || data->f_red == -1)
	{
		ft_dprintf(2, "Error\nNeed the floor colors\n");
		return (free_all(data), exit(1));
	}
}

bool	is_player(char c)
{
	if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
		return (true);
	return (false);
}

bool	is_void(char c)
{
	if (c == '1' || c == '0' || is_player(c))
		return (false);
	return (true);
}

void	check_if_surround(t_data *data, char **map, int j, int i)
{
	if (!j || !i || !map[j+1] || \
	is_void(map[j-1][i]) || is_void(map[j+1][i]) || is_void(map[j][i-1]) || is_void(map[j][i+1]))
	{
		ft_dprintf(2, "Error\nThe map must be closed/surrounded by walls\n");
		return (free_all(data), exit(1));
	}
}

void	fill_player(t_data *data, char orientation, int j, int i)
{
	if (data->game.spawning_orientation)
	{
		ft_dprintf(2, "Error\nThe map must be composed by only one player\n");
		return (free_all(data), exit(1));
	}
	data->game.spawning_orientation = orientation;
	data->game.player_y = j;
	data->game.player_x = i;
}

bool	map_is_not_finished(char **map, int j)
{
	int j_cpy = j;
	
	while (map[j] && map[j][0] == '\n')
		j++;
	if (map[j])
		return (true);
	map[j_cpy] = NULL;
	return (false);
}

//check si un seul spawn. check si entourer par des murs. check si char non autoriser. check si ligne vide. 
void	check_map(t_data *data, char **map)
{
	int	i;
	int	j;

	j = -1;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
		{
			if (map[j][i] == '0' || is_player(map[j][i]))
				check_if_surround(data, map, j, i);
			else if (map[j][i] != '1' && map[j][i] != ' ' && map[j][i] != '\n')
			{
				ft_dprintf(2, "Error\nIncorrect char in map : \"%c\"\n", map[j][i]);
				return (free_all(data), exit(1));
			}
			if (is_player(map[j][i]))
				fill_player(data, map[j][i], j, i);
		}
		if (map[j+1][0] == '\n' && map_is_not_finished(map, j+1))
		{
			ft_dprintf(2, "Error\nMap can not be separated by one or more empty line(s)\n");
			return (free_all(data), exit(1));
		}
	}	
}

void	fill_map(t_data *data)
{
	char	*line_ptr;
	t_list	*new;

	line_ptr = data->line;
	while (*line_ptr == ' ')
		line_ptr++;
	if (*line_ptr != '1')
	{
		ft_dprintf(2, "Error\n%s : Incorrect line\n", data->line);
		return (free_all(data), exit(1));
	}
	check_all_identifer(data);
	while (data->line)
	{
		new = ft_lstnew(data->line);
		if (!new)
			return (free_all(data), exit(1));
		ft_lstadd_back(&data->lst_map, new);
		data->line = get_next_line(data->fd);
	}
	data->game.map = ft_lst_to_strs(data->lst_map);
	if (!data->game.map)
			return (free_all(data), exit(1));
}

void	fill_identifier(t_data *data)
{
	if (!ft_strncmp(data->line, "NO ", 3))
		xpm_load(data, &data->no_xpm);
	else if (!ft_strncmp(data->line, "SO ", 3))
		xpm_load(data, &data->so_xpm);
	else if (!ft_strncmp(data->line, "EA ", 3))
		xpm_load(data, &data->ea_xpm);
	else if (!ft_strncmp(data->line, "WE ", 3))
		xpm_load(data, &data->we_xpm);
	else if (!ft_strncmp(data->line, "F ", 2))
		fill_color(data, 'F');
	else if (!ft_strncmp(data->line, "C ", 2))
		fill_color(data, 'C');
	else if (*data->line != '\n')
	{
		fill_map(data);
	}
}

void	parse(t_data *data)
{
	data->line = get_next_line(data->fd);
	if (!data->line)
	{
		ft_dprintf(2, "Error\nEmpty file\n");
		return (free_all(data), exit(1));
	}
	while (data->line)
	{
		fill_identifier(data);
		free(data->line);
		data->line = get_next_line(data->fd);
	}
	check_map(data, data->game.map);
}
