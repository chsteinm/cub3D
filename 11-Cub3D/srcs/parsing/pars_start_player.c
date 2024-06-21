/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_start_player.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:40:33 by abonnefo          #+#    #+#             */
/*   Updated: 2024/01/16 11:56:12 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_valid_and_existing(t_parser *parser, int i, int j)
{
	if (i >= 0 && i < parser->map_height && j >= 0 && j < parser->map_width)
		return (parser->map[i][j] == '1' || parser->map[i][j] == '0');
	return (0);
}

int	verif_inside_pos_player(t_parser *parser, int i, int j)
{
	if (!is_valid_and_existing(parser, i - 1, j)
		|| !is_valid_and_existing(parser, i + 1, j)
		|| !is_valid_and_existing(parser, i, j - 1)
		|| !is_valid_and_existing(parser, i, j + 1))
		return (1);
	return (0);
}

int	verif_pos_player(t_parser *parser)
{
	int	i;
	int	j;

	i = 0;
	while (i < parser->map_height)
	{
		j = 0;
		while ((j < parser->map_width) && parser->map[i][j])
		{
			if (parser->map[i][j] == 'N' || parser->map[i][j] == 'S'
				|| parser->map[i][j] == 'E' || parser->map[i][j] == 'W')
			{
				if (verif_inside_pos_player(parser, i, j))
					return (1);
			}
			j++;
		}
		if (parser->map[i][--j] == '0')
			return (1);
		i++;
	}
	return (0);
}
