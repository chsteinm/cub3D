/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:55:31 by abonnefo          #+#    #+#             */
/*   Updated: 2024/01/16 10:14:09 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_key_press(t_data *data)
{
	data->keys.w = 0;
	data->keys.a = 0;
	data->keys.s = 0;
	data->keys.d = 0;
	data->keys.rot_left = 0;
	data->keys.rot_right = 0;
	data->keys.mouse_rot_right = 0;
	data->keys.mouse_rot_left = 0;
	data->keys.mouse_x = 0;
	data->mouse_on = 1;
}

int	init_windows(t_data *data)
{
	data->img_blank = ft_calloc(1, sizeof(t_img));
	if (!data->img_blank)
		return (1);
	data->img_blank->mlx = mlx_init();
	if (!data->img_blank->mlx)
	{
		free_no_mlx(data);
		exit(err("Error\nInit mlx failed\n"));
	}
	data->img_blank->window = mlx_new_window(data->img_blank->mlx,
			WIDTH, HEIGHT, "cub3D");
	if (!data->img_blank->window)
		return (err("Error\nInit window failed\n"));
	data->img_blank->img_ptr = mlx_new_image(data->img_blank->mlx,
			WIDTH, HEIGHT);
	data->img_blank->data_addr = mlx_get_data_addr(data->img_blank->img_ptr,
			&(data->img_blank->bits_per_pixels),
			&(data->img_blank->size_line), &(data->img_blank->endian));
	return (0);
}
