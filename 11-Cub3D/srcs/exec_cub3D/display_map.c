/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:18:55 by abonnefo          #+#    #+#             */
/*   Updated: 2024/01/11 14:55:50 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	put_x10(t_data *data, int x, int y, int color)
{
	int	tmp_x;
	int	tmp_y;

	tmp_x = x;
	tmp_y = y;
	while (y < (tmp_y + 6))
	{
		x = tmp_x;
		while (x < (tmp_x + 6))
		{
			put_pixel(data, x, y, color);
			x++;
		}
		y++;
	}
}

int	calcul_size_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	help_display_minimap(t_data *data, int index_tab, int i)
{
	if (data->valid_map[index_tab][i]
	&& (data->valid_map[index_tab][i] == '0'
	|| data->valid_map[index_tab][i] == 'N'
	|| data->valid_map[index_tab][i] == 'S'
	|| data->valid_map[index_tab][i] == 'E'
	|| data->valid_map[index_tab][i] == 'W'))
		return (1);
	return (0);
}

void	display_minimap(t_data *data, int x, int y)
{
	int	i;
	int	index_tab;

	index_tab = 0;
	while (index_tab < calcul_size_tab(data->valid_map))
	{
		i = 0;
		x = 0;
		while (i < ft_strlen(data->valid_map[index_tab]))
		{
			if (i == (int)data->game->pos_y
				&& index_tab == (int)data->game->pos_x)
				put_x10(data, x, y, COLOR_BLACK);
			else if (data->valid_map[index_tab][i]
				&& data->valid_map[index_tab][i] == '1')
				put_x10(data, x, y, COLOR_BRICK);
			else if (help_display_minimap(data, index_tab, i) == 1)
				put_x10(data, x, y, COLOR_FLOOR);
			x += 6;
			i++;
		}
		y += 6;
		index_tab++;
	}
}
