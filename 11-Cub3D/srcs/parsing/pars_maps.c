/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_maps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:02:00 by abonnefo          #+#    #+#             */
/*   Updated: 2023/12/28 15:57:34 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	verif_borders(t_parser *parser)
{
	int	j;
	int	i;
	int	row_length;

	j = 0;
	while (j < parser->map_width && parser->map[0][j]
		&& parser->map[parser->map_height - 1][j])
	{
		if (parser->map[0][j] == '0'
			|| parser->map[parser->map_height - 1][j] == '0')
			return (1);
		j++;
	}
	i = 1;
	while (i < parser->map_height - 1 && parser->map[i][0])
	{
		row_length = ft_strlen(parser->map[i]);
		if (parser->map[i][0] == '0' || (row_length > parser->map_width - 1
			&& parser->map[i][parser->map_width - 1] == '0'))
			return (1);
		i++;
	}
	return (0);
}

int	verif_inside_zero_close(t_parser *parser, int i, int j)
{
	int	prev_row_len;
	int	next_row_len;

	prev_row_len = 0;
	next_row_len = 0;
	if (parser->map[i][0] == '0')
		return (1);
	if (i > 0)
		prev_row_len = ft_strlen(parser->map[i - 1]);
	if (i < parser->map_height - 1)
		next_row_len = ft_strlen(parser->map[i + 1]);
	if ((i > 0 && j < prev_row_len && (parser->map[i - 1][j] == ' '
			|| !parser->map[i - 1][j]))
			|| (i < parser->map_height - 1 && j < next_row_len
			&& (parser->map[i + 1][j] == ' ' || !parser->map[i + 1][j]))
			|| (j > 0 && parser->map[i][j - 1] == ' ')
			|| (j < parser->map_width - 1 && parser->map[i][j + 1] == ' '))
		return (1);
	if ((i == 0 || i == parser->map_height - 1) && parser->map[i][j] == '0')
		return (1);
	if ((i > 0 && j >= prev_row_len)
		|| (i < parser->map_height - 1 && j >= next_row_len))
		return (1);
	return (0);
}

int	verif_zero_close(t_parser *parser)
{
	int	i;
	int	j;

	i = 0;
	if (verif_borders(parser))
		return (1);
	while (i < parser->map_height)
	{
		j = 0;
		while ((j < parser->map_width) && parser->map[i][j])
		{
			if (parser->map[i][j] == '0')
			{
				if (verif_inside_zero_close(parser, i, j))
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

int	verif_inside_space_close(t_parser *parser, int i, int j)
{
	if ((i > 0) && (j < ft_strlen(parser->map[i - 1]))
		&& ((parser->map[i - 1][j] != '1')
		&& (parser->map[i - 1][j] != ' ')))
		return (1);
	if ((i < parser->map_height - 1)
		&& (j < ft_strlen(parser->map[i + 1]))
		&& ((parser->map[i + 1][j] != '1')
		&& (parser->map[i + 1][j] != ' ')))
		return (1);
	if ((j > 0 && parser->map[i][j - 1])
		&& (parser->map[i][j - 1] != '1'
		&& (parser->map[i][j - 1] != ' ')))
		return (1);
	if ((j < parser->map_width - 1) && (parser->map[i][j + 1])
		&& ((parser->map[i][j + 1] != '1')
		&& (parser->map[i][j + 1] != ' ')))
		return (1);
	return (0);
}

int	verif_space_close(t_parser *parser)
{
	int	i;
	int	j;
	int	row_length;

	i = 0;
	while (i < parser->map_height)
	{
		j = 0;
		row_length = ft_strlen(parser->map[i]);
		while (j < row_length)
		{
			if (parser->map[i][j] == ' ')
			{
				if (verif_inside_space_close(parser, i, j))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
