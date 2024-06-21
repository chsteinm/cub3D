/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:40:20 by abonnefo          #+#    #+#             */
/*   Updated: 2024/01/16 10:42:44 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	err(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	return (1);
}

int	find_start_of_map(t_parser *parser)
{
	int	i;
	int	j;
	int	is_map_line;

	i = 0;
	while (parser->tab[i])
	{
		j = 0;
		is_map_line = 1;
		while (parser->tab[i][j])
		{
			if (parser->tab[i][j] != '1' && parser->tab[i][j] != ' ')
			{
				is_map_line = 0;
				break ;
			}
			j++;
		}
		if (is_map_line && j > 0)
			return (i);
		i++;
	}
	return (1);
}

int	is_all_space(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (!(input[i] >= 9 && input[i] <= 13) && input[i] != 32)
			return (0);
		i++;
	}
	return (1);
}

float	ft_fabs(float i)
{
	if (i < 0)
		return (i *= -1);
	return (i);
}
