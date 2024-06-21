/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 14:42:27 by abonnefo          #+#    #+#             */
/*   Updated: 2023/12/22 14:45:52 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	calcul_alloc_size_str(t_parser *parser, int i, int tmp)
{
	if ((ft_strlen(parser->tab[tmp]) == 0)
		|| is_all_space(parser->tab[tmp]))
	{
		while (i > 0)
			free(parser->map[--i]);
		free(parser->map);
		return (1);
	}
	parser->map[i] = malloc(sizeof(char) * (ft_strlen(parser->tab[tmp]) + 1));
	if (parser->map[i] == NULL)
	{
		while (i > 0)
			free(parser->map[--i]);
		free(parser->map);
		return (1);
	}
	return (0);
}

int	calcul_alloc_size_tab(t_parser *parser, int i)
{
	i = 0;
	while (parser->tab[i])
		i++;
	parser->map = malloc(sizeof(char *) * (i + 1));
	if (parser->map == NULL)
		return (1);
	return (0);
}

int	convert_tab_in_map(t_parser *parser)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	if (calcul_alloc_size_tab(parser, i))
		return (1);
	tmp = parser->index_start_map;
	i = 0;
	while (parser->tab[tmp])
	{
		j = 0;
		if (calcul_alloc_size_str(parser, i, tmp))
			return (1);
		while (parser->tab[tmp][j])
		{
			parser->map[i][j] = parser->tab[tmp][j];
			j++;
		}
		parser->map[i][j] = '\0';
		tmp++;
		i++;
	}
	parser->map[i] = NULL;
	return (0);
}

void	parms_map_size(t_parser *parser)
{
	int	i;
	int	j;
	int	max_width;
	int	cur_width;

	i = 0;
	max_width = 0;
	while (parser->map[i])
	{
		cur_width = 0;
		j = 0;
		while (parser->map[i][j])
			j++;
		cur_width = j;
		if (cur_width > max_width)
			max_width = cur_width;
		i++;
	}
	parser->map_height = i;
	parser->map_width = max_width;
}
