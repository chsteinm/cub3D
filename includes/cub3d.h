/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <chrstein@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:05:40 by chrstein          #+#    #+#             */
/*   Updated: 2024/06/27 14:24:37 by chrstein         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "./libft/libft.h"
# include "../minilibx-linux/mlx.h"

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>

# define W 119
# define S 115
# define A 97
# define D 100
# define ESC 65307 //voir meilleur solution pour compatibilite

# define ERRCHARC "Error\nIncorrect char in %c colors : \"%c\"\n"
# define ERRCHARM "Error\nIncorrect char in map : \"%c\"\n"
# define ERREMPTYLINE "Error\nMap can not be separated by empty line(s)\n"

typedef struct s_game
{
	char				**map;
	int					player_x;
	int					player_y;
	int					ceiling_color;
	int					floor_color;
	char				spawning_orientation;
}					t_game;

typedef struct s_data
{
	int		fd;
	char	*line;
	t_game	game;
	void	*mlx;
	void	*mlx_win;
	void	*no_xpm;
	void	*so_xpm;
	void	*ea_xpm;
	void	*we_xpm;
	int		c_red;
	int		c_green;
	int		c_blue;
	int		f_red;
	int		f_green;
	int		f_blue;
	t_list	*lst_map;
}					t_data;

void	free_all(t_data *data);
void	parse(t_data *data);
void	xpm_load(t_data *data, void **xpm_ptr);
void	fill_color(t_data *data, char color);
void	check_map(t_data *data, char **map, int i);
bool	is_player(char c);
bool	is_void(char c);
bool	map_is_not_finished(char **map, int j);

#endif