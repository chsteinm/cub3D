/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <chrstein@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:05:40 by chrstein          #+#    #+#             */
/*   Updated: 2024/06/24 11:08:03 by chrstein         ###   ########lyon.fr   */
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

# define W 119
# define S 115
# define A 97
# define D 100
# define ESC 65307 //voir meilleur solution pour compatibilite

// enum e_xpm
// {
// 	_NO,
// 	_SO,
// 	_EA,
// 	_WE,
// };

typedef struct s_game
{
	int					x;
	int					y;
	char				**map;
	int					player_x;
	int					player_y;
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
	int		c_blue;
	int		c_green;
	int		f_red;
	int		f_blue;
	int		f_green;
	t_list	*lst_map;
}					t_data;

void	free_all(t_data *data);
void	parse(t_data *data);

#endif