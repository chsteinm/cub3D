/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chrstein <chrstein@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:05:40 by chrstein          #+#    #+#             */
/*   Updated: 2024/06/18 23:33:01 by chrstein         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./libft/libft.h"
# include "get_next_line.h"
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
# define ESC 65307
# define FLOOR1 "Ressources/Pics/floor1.xpm"
# define FLOOR2 "Ressources/Pics/floor2.xpm"
# define WALL "Ressources/Pics/wall.xpm"
# define PLAYER "Ressources/Pics/player.xpm"
# define COLLECT1 "Ressources/Pics/collect1.xpm"
# define COLLECT2 "Ressources/Pics/collect2.xpm"
# define EXIT "Ressources/Pics/exit.xpm"

typedef struct s_pic
{
	void	*wall;
	void	*floor1;
	void	*floor2;
	void	*player;
	void	*collect1;
	void	*collect2;
	void	*exit;
	int		img_width;
	int		img_height;
}					t_pic;

typedef struct s_map
{
	int					x;
	int					y;
	int					nb_collect;
	int					exit_access;
	int					fd;
	char				*one_line_map;
	char				**map;
	int					p_x;
	int					p_y;
}					t_map;

typedef struct s_data
{
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	t_map	map;
	void	*mlx;
	void	*mlx_win;
	t_pic	pic;
	size_t	count_move;
}					t_data;

int		parse(t_map *map);
int		check_win(t_map cpy);
int		init_xpm(t_pic *pic, void *mlx_ptr);
void	draw_map(void *mlx_ptr, void *win_ptr, t_data *data);
void	move(t_map *map, t_data *data, int new_x, int new_y);
int		destroy(t_data *data);

#endif
