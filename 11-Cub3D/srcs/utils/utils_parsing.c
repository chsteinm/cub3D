/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:01:18 by abonnefo          #+#    #+#             */
/*   Updated: 2024/01/12 14:23:39 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	verif_directory(char *str)
{
	int	fd;

	fd = open(str, O_DIRECTORY);
	if (fd != -1)
	{
		err("Error\n");
		err(str);
		err(" is a directory\n");
		return (1);
	}
	fd = open(str, O_RDONLY);
	if ((fd < 0))
	{
		perror(str);
		return (1);
	}
	close(fd);
	return (0);
}

int	verif_extensions(char *str, char **av)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	i -= 4;
	if (str[i] == '.' && str[i + 1] == 'c' && str[i + 2] == 'u'
		&& str[i + 3] == 'b')
		return (0);
	err("Error\n");
	err(av[1]);
	err(" isn't a .cub file\n");
	return (1);
}

char	*trim_texture_path(char *str)
{
	int	i;

	i = 2;
	ft_memset(str, ' ', 2);
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (trim_start(str));
}

char	*trim_start(char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	return (str);
}

int	verif_char(char **tab)
{
	int	i;
	int	y;
	int	flag_pos;

	i = 0;
	flag_pos = 0;
	while (tab[i])
	{
		y = 0;
		while (tab[i][y])
		{
			if (tab[i][y] != ' ' && tab[i][y] != '0' && tab[i][y] != '1'
				&& tab[i][y] != 'N' && tab[i][y] != 'S' && tab[i][y] != 'E'
				&& tab[i][y] != 'W')
				return (1);
			if (tab[i][y] == 'N' || tab[i][y] == 'S'
				|| tab[i][y] == 'E' || tab[i][y] == 'W')
					flag_pos++;
			y++;
		}
		i++;
	}
	if (flag_pos != 1)
		return (1);
	return (0);
}
