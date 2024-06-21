/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:07:38 by abonnefo          #+#    #+#             */
/*   Updated: 2024/01/16 10:15:12 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_error_set_color(char *dest, t_parser *parser, char **tab_color)
{
	err("Error\nBad color\n");
	free(dest);
	free_tab(parser->tab);
	free_tab(tab_color);
	exit(1);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_texture_filename_no_so(t_data *data)
{
	if (data->texture_north)
	{
		free(data->texture_north->filename);
		if (data->texture_north->img_ptr)
			mlx_destroy_image(data->img_blank->mlx,
				data->texture_north->img_ptr);
		free(data->texture_north);
	}
	if (data->texture_south)
	{
		free(data->texture_south->filename);
		if (data->texture_south->img_ptr)
			mlx_destroy_image(data->img_blank->mlx,
				data->texture_south->img_ptr);
		free(data->texture_south);
	}
}

void	free_texture_filename_ea_we(t_data *data)
{
	if (data->texture_east)
	{
		free(data->texture_east->filename);
		if (data->texture_east->img_ptr)
			mlx_destroy_image(data->img_blank->mlx,
				data->texture_east->img_ptr);
		free(data->texture_east);
	}
	if (data->texture_west)
	{
		free(data->texture_west->filename);
		if (data->texture_west->img_ptr)
			mlx_destroy_image(data->img_blank->mlx,
				data->texture_west->img_ptr);
		free(data->texture_west);
	}
}

void	free_all(t_data *data)
{
	free_texture_filename_no_so(data);
	free_texture_filename_ea_we(data);
	free_tab(data->valid_map);
	free_tab(data->valid_param);
	free(data->game);
	if (data->img_blank->img_ptr)
		mlx_destroy_image(data->img_blank->mlx, data->img_blank->img_ptr);
	mlx_destroy_window(data->img_blank->mlx, data->img_blank->window);
	mlx_destroy_display(data->img_blank->mlx);
	if (data->img_blank->mlx)
		free(data->img_blank->mlx);
	free(data->img_blank);
}
