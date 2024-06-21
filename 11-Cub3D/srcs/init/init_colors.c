/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 19:10:36 by abonnefo          #+#    #+#             */
/*   Updated: 2024/01/12 14:26:26 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	add_colors(t_data *data, char **tab, char c)
{
	if (c == 'F')
	{
		data->colors_ceiling.red = ft_atoi(tab[0]);
		data->colors_ceiling.green = ft_atoi(tab[1]);
		data->colors_ceiling.blue = ft_atoi(tab[2]);
	}
	else if (c == 'C')
	{
		data->colors_floor.red = ft_atoi(tab[0]);
		data->colors_floor.green = ft_atoi(tab[1]);
		data->colors_floor.blue = ft_atoi(tab[2]);
	}
}

int	init_colors(t_data *data)
{
	int		i;
	char	*trimmed_line;
	char	**color_values;

	i = 0;
	while (data->valid_param[i])
	{
		trimmed_line = trim_start(data->valid_param[i]);
		if (ft_strncmp_cub3d(trimmed_line, "F ", 2) == 0)
		{
			color_values = ft_split(trimmed_line + 2, ',');
			add_colors(data, color_values, 'F');
			free_tab(color_values);
		}
		else if (ft_strncmp_cub3d(trimmed_line, "C ", 2) == 0)
		{
			color_values = ft_split(trimmed_line + 2, ',');
			add_colors(data, color_values, 'C');
			free_tab(color_values);
		}
		i++;
	}
	return (0);
}
