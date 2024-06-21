/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_adress.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 13:43:50 by abonnefo          #+#    #+#             */
/*   Updated: 2024/01/12 15:03:19 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_textures_adress_north(t_data *data)
{
	int	height;
	int	width;

	data->texture_north->img_ptr = mlx_xpm_file_to_image(data->img_blank->mlx,
			data->texture_north->filename, &width, &height);
	if (!data->texture_north->img_ptr)
	{
		err("Error\nNorth mlx_xpm_file_to_image failed\n");
		free_all(data);
		exit(1);
	}
	data->texture_north->data_addr
		= mlx_get_data_addr(data->texture_north->img_ptr,
			&data->texture_north->bits_per_pixels,
			&data->texture_north->size_line,
			&data->texture_north->endian);
}

void	init_textures_adress_south(t_data *data)
{
	int	height;
	int	width;

	data->texture_south->img_ptr = mlx_xpm_file_to_image(data->img_blank->mlx,
			data->texture_south->filename, &width, &height);
	if (!data->texture_south->img_ptr)
	{
		err("Error\nSouth mlx_xpm_file_to_image failed\n");
		free_all(data);
		exit(1);
	}
	data->texture_south->data_addr
		= mlx_get_data_addr(data->texture_south->img_ptr,
			&data->texture_south->bits_per_pixels,
			&data->texture_south->size_line,
			&data->texture_south->endian);
}

void	init_textures_adress_west(t_data *data)
{
	int	height;
	int	width;

	data->texture_west->img_ptr = mlx_xpm_file_to_image(data->img_blank->mlx,
			data->texture_west->filename, &width, &height);
	if (!data->texture_west->img_ptr)
	{
		err("Error\nWest mlx_xpm_file_to_image failed\n");
		free_all(data);
		exit(1);
	}
	data->texture_west->data_addr
		= mlx_get_data_addr(data->texture_west->img_ptr,
			&data->texture_west->bits_per_pixels,
			&data->texture_west->size_line,
			&data->texture_west->endian);
}

void	init_textures_adress_east(t_data *data)
{
	int	height;
	int	width;

	data->texture_east->img_ptr = mlx_xpm_file_to_image(data->img_blank->mlx,
			data->texture_east->filename, &width, &height);
	if (!data->texture_east->img_ptr)
	{
		err("Error\nEast mlx_xpm_file_to_image failed\n");
		free_all(data);
		exit(1);
	}
	data->texture_east->data_addr
		= mlx_get_data_addr(data->texture_east->img_ptr,
			&data->texture_east->bits_per_pixels,
			&data->texture_east->size_line,
			&data->texture_east->endian);
}

void	init_textures_adress(t_data *data)
{
	init_textures_adress_north(data);
	init_textures_adress_south(data);
	init_textures_adress_west(data);
	init_textures_adress_east(data);
}
