/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:14:28 by abonnefo          #+#    #+#             */
/*   Updated: 2024/01/11 17:30:58 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	find_map_start(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i] && j < 6)
	{
		if (!ft_strncmp_cub3d(&str[i], "NO ", 3)
			|| !ft_strncmp_cub3d(&str[i], "SO ", 3))
			j++;
		if (!ft_strncmp_cub3d(&str[i], "EA ", 3)
			|| !ft_strncmp_cub3d(&str[i], "WE ", 3))
			j++;
		if (!ft_strncmp_cub3d(&str[i], "F ", 2)
			|| !ft_strncmp_cub3d(&str[i], "C ", 2))
			j++;
		i++;
	}
	while (str[i] && str[i] != '\n')
		i++;
	while (str[i] == '\n')
		i++;
	return (i);
}

int	check_empty_line_in_map(char *str)
{
	int	i;

	i = find_map_start(str) - 1;
	while (i > 0 && str[++i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			err("Error\nEmpty line\n");
		if (str[i] == '\n' && str[i + 1] == '\n')
		{
			free(str);
			exit(1);
		}
	}
	return (0);
}

int	check_no_map(char *str)
{
	int	i;

	i = find_map_start(str) - 1;
	while (i > 0 && str[++i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			err("Error\nNo valid map\n");
		if (str[i] == '\n' && str[i + 1] == '\n')
		{
			free(str);
			exit(1);
		}
	}
	return (0);
}

int	check_dup_args(char *str)
{
	int	i;
	int	count_args;

	i = -1;
	count_args = 0;
	while (str[++i])
	{
		if (ft_strncmp_cub3d(&str[i], "NO", 2) == 0
			|| ft_strncmp_cub3d(&str[i], "SO", 2) == 0
			|| ft_strncmp_cub3d(&str[i], "WE", 2) == 0
			|| ft_strncmp_cub3d(&str[i], "EA", 2) == 0
			|| ft_strncmp_cub3d(&str[i], "F", 1) == 0
			|| ft_strncmp_cub3d(&str[i], "C", 1) == 0)
				count_args++;
		if (count_args > 6)
		{
			err("Error\nDuplicate argument found\n");
			free(str);
			exit(1);
		}
	}
	return (0);
}

void	ft_put_in_tab(char *map, t_parser *parser)
{
	char	*str;

	str = ft_read_and_join(map);
	if (str == NULL)
		exit(1);
	check_dup_args(str);
	check_empty_line_in_map(str);
	parser->tab = ft_split(str, '\n');
	if (parser->tab == NULL)
		return ;
	free(str);
}
