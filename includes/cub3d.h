/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <chrstein@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:05:40 by chrstein          #+#    #+#             */
/*   Updated: 2024/06/21 11:50:11 by chrstein         ###   ########lyon.fr   */
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

enum e_xpm
{
	_NO,
	_SO,
	_EA,
	_WE,
};

typedef struct s_game
{
	void				*xpm_ptr;
	int					img_width;
	int					img_height;
	int					x;
	int					y;
	char				**map;
	char				*f_color;
	char				*c_color;
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
	void	*xpm_ptr[4];
	size_t	count_move;
}					t_data;

void	free_all(t_data *data);
void	parse(t_data *data);
int		check_win(t_game cpy);
void	draw_map(void *mlx_ptr, void *win_ptr, t_data *data);
void	move(t_game *map, t_data *data, int new_x, int new_y);
int		destroy(t_data *data);

#endif