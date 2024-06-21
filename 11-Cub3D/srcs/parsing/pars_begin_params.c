/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_begin_params.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 15:21:16 by abonnefo          #+#    #+#             */
/*   Updated: 2024/01/16 10:47:52 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	begin_digit(char *line)
{
	int	i;

	i = 1;
	while (line[i] == ' ')
		i++;
	if (ft_isdigit(line[i]) == 0)
		return (1);
	return (0);
}
