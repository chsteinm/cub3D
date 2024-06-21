/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master_pars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:40:13 by abonnefo          #+#    #+#             */
/*   Updated: 2024/01/16 11:48:44 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	master_verif_args(int ac, char **av)
{
	if (ac != 2)
		return (err("Error\nNeed only two arguments\n"));
	(void)ac;
	if (verif_extensions(av[1], av) != 0)
		return (1);
	if (verif_directory(av[1]) != 0)
		return (1);
	return (0);
}

int	master_verif_textures(char *map, t_parser *parser)
{
	ft_put_in_tab(map, parser);
	parser->index_start_map = find_start_of_map(parser);
	if (verif_parameters(parser) != 0)
		return (1);
	if (verif_textures_wall(parser) != 0)
		return (1);
	if (verif_floor_and_ceiling(parser) != 0)
		return (1);
	return (0);
}

void	free_exit(t_parser *parser, char *str)
{
	free_tab(parser->tab);
	free_tab(parser->map);
	err(str);
	exit(1);
}

int	master_verif_maps(t_parser *parser)
{
	if (convert_tab_in_map(parser))
	{
		free_tab(parser->tab);
		return (err("Error\nInvalid map\n"));
	}
	parms_map_size(parser);
	if (verif_zero_close(parser) || verif_space_close(parser))
		free_exit(parser, "Error\nMap isn't close\n");
	if (verif_char(parser->map))
		free_exit(parser, "Error\nInvalid char\n");
	if (verif_pos_player(parser))
		free_exit(parser, "Error\nInvalid position player\n");
	return (0);
}

int	master_parsing(int ac, char **av, t_parser *parser)
{
	if (master_verif_args(ac, av) != 0)
		return (1);
	if (master_verif_textures(av[1], parser) != 0)
		return (1);
	if (master_verif_maps(parser) != 0)
		return (1);
	return (0);
}
