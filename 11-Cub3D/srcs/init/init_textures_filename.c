/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures_filename.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 17:55:15 by abonnefo          #+#    #+#             */
/*   Updated: 2024/01/15 09:37:45 by abonnefo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	init_textures_filename_north(t_data *data)
{
	int		i;
	char	*texture_path;
	char	*trimmed_line;

	i = 0;
	while (data->valid_param[i])
	{
		trimmed_line = trim_start(data->valid_param[i]);
		if (ft_strncmp_cub3d(trimmed_line, "NO ", 3) == 0)
		{
			texture_path = trim_texture_path(trimmed_line);
			data->texture_north = ft_calloc(1, sizeof(t_img));
			if (!data->texture_north)
				return (1);
			data->texture_north->filename = ft_strdup(texture_path);
		}
		i++;
	}
	return (0);
}

int	init_textures_filename_south(t_data *data)
{
	int		i;
	char	*texture_path;
	char	*trimmed_line;

	i = 0;
	while (data->valid_param[i])
	{
		trimmed_line = trim_start(data->valid_param[i]);
		if (ft_strncmp_cub3d(trimmed_line, "SO ", 3) == 0)
		{
			texture_path = trim_texture_path(trimmed_line);
			data->texture_south = ft_calloc(1, sizeof(t_img));
			if (!data->texture_south)
				return (1);
			data->texture_south->filename = ft_strdup(texture_path);
		}
		i++;
	}
	return (0);
}

int	init_textures_filename_east(t_data *data)
{
	int		i;
	char	*texture_path;
	char	*trimmed_line;

	i = 0;
	while (data->valid_param[i])
	{
		trimmed_line = trim_start(data->valid_param[i]);
		if (ft_strncmp_cub3d(trimmed_line, "EA ", 3) == 0)
		{
			texture_path = trim_texture_path(trimmed_line);
			data->texture_east = ft_calloc(1, sizeof(t_img));
			if (!data->texture_east)
				return (1);
			data->texture_east->filename = ft_strdup(texture_path);
		}
		i++;
	}
	return (0);
}

int	init_textures_filename_west(t_data *data)
{
	int		i;
	char	*texture_path;
	char	*trimmed_line;

	i = 0;
	while (data->valid_param[i])
	{
		trimmed_line = trim_start(data->valid_param[i]);
		if (ft_strncmp_cub3d(trimmed_line, "WE ", 3) == 0)
		{
			texture_path = trim_texture_path(trimmed_line);
			data->texture_west = ft_calloc(1, sizeof(t_img));
			if (!data->texture_west)
				return (1);
			data->texture_west->filename = ft_strdup(texture_path);
		}
		i++;
	}
	return (0);
}

int	init_textures_filename(t_data *data)
{
	if ((init_textures_filename_north(data) == 1)
		|| (init_textures_filename_south(data) == 1)
		|| (init_textures_filename_east(data) == 1)
		|| (init_textures_filename_west(data) == 1))
	{
		free_all(data);
		exit(1);
	}
	return (0);
}
