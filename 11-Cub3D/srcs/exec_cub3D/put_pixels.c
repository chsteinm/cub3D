/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 11:51:26 by abonnefo          #+#    #+#             */
/*   Updated: 2024/01/01 11:46:23 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	put_pixel(t_data *data, int x, int y, int C_or_F)
{
	char	*dest;

	if (x < 0 || y < 0 || y > HEIGHT - 1 || x > WIDTH - 1)
		return ;
	dest = data->img_blank->data_addr + (y * data->img_blank->size_line) + x
		* (data->img_blank->bits_per_pixels / 8);
	*(int *)dest = C_or_F;
}

int	get_rgb(t_data *data, int C_or_F)
{
	int	color;

	if (C_or_F == 0)
		color = ((data->colors_ceiling.red & MAX_COLOR_VALUE) << 16)
			|((data->colors_ceiling.green & MAX_COLOR_VALUE) << 8)
			|(data->colors_ceiling.blue & MAX_COLOR_VALUE);
	else if (C_or_F == 1)
		color = ((data->colors_floor.red & MAX_COLOR_VALUE) << 16)
			|((data->colors_floor.green & MAX_COLOR_VALUE) << 8)
			|(data->colors_floor.blue & MAX_COLOR_VALUE);
	return (color);
}

int	get_color(t_data *data, t_img *texture)
{
	char	*dest;

	if (data->game->texture_x < 0 || data->game->texture_y < 0
		|| data->game->texture_y > HEIGHT - 1
		|| data->game->texture_x > WIDTH - 1)
		return (0);
	dest = texture->data_addr + (data->game->texture_y
			* texture->size_line + data->game->texture_x
			* (texture->bits_per_pixels / 8));
	return (*(int *)dest);
}
