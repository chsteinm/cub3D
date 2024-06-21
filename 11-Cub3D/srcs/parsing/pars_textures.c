/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:53:17 by abonnefo          #+#    #+#             */
/*   Updated: 2024/01/16 11:57:07 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_error_textures(t_parser *parser, char *str)
{
	char	*dest;

	dest = copy_after_space(str);
	if (!dest)
	{
		err("Error\nBad texture\n");
		free_tab(parser->tab);
		exit(1);
	}
	if (access(dest, F_OK) != 0 || access(dest, R_OK) != 0)
	{
		err("Error\nBad texture\n");
		free(dest);
		free_tab(parser->tab);
		exit(1);
	}
	free(dest);
	return (0);
}

int	validate_line(char *line)
{
	char	**split_line;
	int		count;

	split_line = ft_split(line, ' ');
	count = 0;
	while (split_line[count])
		count++;
	if (count != 2)
	{
		free_tab(split_line);
		return (1);
	}
	free_tab(split_line);
	return (0);
}

int	set_texture(t_parser *parser, char *line,
	char *cardinal_point, int *flag)
{
	if (ft_strncmp_cub3d(line, cardinal_point, 2) == 0)
	{
		if (validate_line(line))
		{
			err("Error\nBad texture\n");
			free_tab(parser->tab);
			exit(1);
		}
		if (check_error_textures(parser, line) == 0)
			(*flag)++;
	}
	return (1);
}

int	verif_textures_wall(t_parser *parser)
{
	int		i;
	char	*trimmed_line;

	i = 0;
	while (i < parser->index_start_map)
	{
		trimmed_line = trim_start(parser->tab[i]);
		if (!set_texture(parser, trimmed_line, "NO", &parser->flag_north)
			|| !set_texture(parser, trimmed_line, "SO", &parser->flag_south)
			|| !set_texture(parser, trimmed_line, "WE", &parser->flag_west)
			|| !set_texture(parser, trimmed_line, "EA", &parser->flag_east))
			return (0);
		i++;
	}
	if (parser->flag_north == 1 && parser->flag_south == 1
		&& parser->flag_west == 1 && parser->flag_east == 1)
		return (0);
	else
	{
		free_tab(parser->tab);
		return (err("Error\nBad texture\n"));
	}
}

int	verif_parameters(t_parser *parser)
{
	int		i;
	char	**split_line;
	char	*trimmed_line;

	i = 0;
	while (i < parser->index_start_map)
	{
		trimmed_line = trim_start(parser->tab[i]);
		split_line = ft_split(trimmed_line, ' ');
		if (split_line[0] && (ft_strcmp_cub3d(split_line[0], "NO") != 0
				&& ft_strcmp_cub3d(split_line[0], "SO") != 0
				&& ft_strcmp_cub3d(split_line[0], "WE") != 0
				&& ft_strcmp_cub3d(split_line[0], "EA") != 0
				&& ft_strcmp_cub3d(split_line[0], "F") != 0
				&& ft_strcmp_cub3d(split_line[0], "C") != 0))
		{
			free_tab(split_line);
			free_tab(parser->tab);
			return (err("Error\nBad texture\n"));
		}
		free_tab(split_line);
		i++;
	}
	return (0);
}
