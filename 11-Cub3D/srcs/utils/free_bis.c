/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:14:31 by bfresque          #+#    #+#             */
/*   Updated: 2024/01/16 11:57:33 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_no_mlx(t_data *data)
{
	free_texture_filename_no_so(data);
	free_texture_filename_ea_we(data);
	free_tab(data->valid_map);
	free_tab(data->valid_param);
	free(data->game);
	if (data->img_blank->img_ptr)
		mlx_destroy_image(data->img_blank->mlx, data->img_blank->img_ptr);
	if (data->img_blank->mlx)
		free(data->img_blank->mlx);
	free(data->img_blank);
}
