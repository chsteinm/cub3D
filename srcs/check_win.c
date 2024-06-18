/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 05:50:31 by chrstein          #+#    #+#             */
/*   Updated: 2024/02/23 05:50:32 by chrstein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	rec_check(t_map *cpy, int y, int x)
{
	if (cpy->map[y][x] == 'C')
		cpy->nb_collect--;
	else if (cpy->map[y][x] == 'E')
		cpy->exit_access = 1;
	else if (cpy->map[y][x] == '1' || cpy->map[y][x] == '2')
		return (0);
	if (!cpy->nb_collect && cpy->exit_access)
		return (1);
	if (cpy->map[y][x] == '0' || cpy->map[y][x] == 'P' || \
	cpy->map[y][x] == 'C' || cpy->map[y][x] == 'E')
		cpy->map[y][x] = '2';
	if (rec_check(cpy, y, x - 1))
		return (1);
	if (rec_check(cpy, y + 1, x))
		return (1);
	if (rec_check(cpy, y, x + 1))
		return (1);
	if (rec_check(cpy, y - 1, x))
		return (1);
	else
		return (0);
}

int	check_win(t_map cpy)
{
	int	bool;

	cpy.map = ft_split(cpy.one_line_map, '\n');
	if (!cpy.map)
		return (ft_printf("Error\nMalloc failed\n"), 0);
	bool = rec_check(&cpy, cpy.p_y, cpy.p_x);
	ft_free_strings(cpy.map);
	if (!bool)
		return (ft_printf("Error\nMap not winnable\n"), 0);
	return (1);
}
