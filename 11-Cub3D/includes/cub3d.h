/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:11:23 by abonnefo          #+#    #+#             */
/*   Updated: 2024/01/16 11:58:28 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <stdbool.h>
# include <unistd.h>

# include "../includes/ft_printf.h"
# include "../includes/get_next_line.h"
# include "../includes/libft.h"
# include "../includes/minilibx-linux/mlx.h"

# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"

# define WIDTH 1280
# define HEIGHT 960

# define COLOR_BLACK 0x000000 
# define COLOR_BRICK 0xa62c01
# define COLOR_FLOOR 0xEAE8B4

# define KEY_ESCAPE 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_C 99
# define KEY_LEFT 65361
# define KEY_RIGHT 65363

# define SPEED_MOVE 0.009
# define SPEED_ROT 0.009
# define SPEED_MOVE_DIAG 0.0045

# define INFINITY_VALUE 1e30
# define MAX_COLOR_VALUE 0xFF

typedef struct s_keys
{
	int			w;
	int			a;
	int			s;
	int			d;
	int			rot_left;
	int			rot_right;
	int			mouse_rot_right;
	int			mouse_rot_left;
	int			mouse_x;
}	t_keys;

typedef struct s_colors
{
	int			red;
	int			green;
	int			blue;
}	t_colors;

typedef struct s_game
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plan_x;
	double		plan_y;
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		side_dist_x;
	double		side_dist_y;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	double		dist_to_wall;
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		wall_x;
	int			texture_x;
	int			texture_y;
	double		texture_pos;
	double		walk;
}	t_game;

typedef struct s_img
{
	void		*mlx;
	void		*window;
	char		*filename;
	char		*data_addr;
	void		*img_ptr;
	int			bits_per_pixels;
	int			size_line;
	int			endian;
}	t_img;

typedef struct s_parser
{
	char		**tab;
	char		**map;
	int			index_start_map;
	int			flag_north;
	int			flag_south;
	int			flag_east;
	int			flag_west;
	int			flag_floor;
	int			flag_ceiling;
	int			map_width;
	int			map_height;
}	t_parser;

typedef struct s_data
{
	char		**valid_map;
	char		**valid_param;
	int			pos_player_x;
	int			pos_player_y;
	int			line_height;
	bool		mouse_on;
	t_parser	*parser;
	t_img		*img_blank;
	t_img		*texture_north;
	t_img		*texture_south;
	t_img		*texture_east;
	t_img		*texture_west;
	t_colors	colors_ceiling;
	t_colors	colors_floor;
	t_game		*game;
	t_keys		keys;
}	t_data;

/*******************************   EXEC_CUB3D   ******************************/

void	exec_game(t_parser *parser);

int		display_game(t_data *data);

void	display_minimap(t_data *data, int x, int y);

void	calcul_wall_drawing_params(t_data *data);
void	draw_vertical_column(t_data *data, int x, int y, int line_height);

int		key_release(int key, t_data *data);
int		key_press(int key, t_data *data);

void	movement_player(t_data *data);

void	put_pixel(t_data *data, int x, int y, int C_or_F);
int		get_rgb(t_data *data, int C_or_F);
int		get_color(t_data *data, t_img *texture);

void	throw_rays(t_data *data);

/*********************************   INIT   *********************************/

int		init_colors(t_data *data);

void	init_pos_directions(t_data *data);

int		init_pos_player(t_data *data);

void	init_ray(t_data	*data, int x);

void	init_textures_adress(t_data *data);

int		init_textures_filename(t_data *data);

void	init_key_press(t_data *data);
int		init_windows(t_data *data);

int		init_data_game(t_data *data, t_parser *parser);

/********************************   PARSING   ********************************/

int		convert_tab_in_map(t_parser *parser);
void	parms_map_size(t_parser *parser);

int		begin_at_texture(char *str);
int		begin_digit(char *line);

int		verif_floor_and_ceiling(t_parser *parser);

int		verif_zero_close(t_parser *parser);
int		verif_space_close(t_parser *parser);

int		verif_pos_player(t_parser *parser);

int		validate_line(char *line);
int		verif_textures_wall(t_parser *parser);
int		verif_parameters(t_parser *parser);

int		master_parsing(int ac, char **av, t_parser *parser);

int		check_no_map(char *str);
void	ft_put_in_tab(char *map, t_parser *parser);

/********************************   UTILS   *********************************/

void	free_no_mlx(t_data *data);

void	free_texture_filename_ea_we(t_data *data);
void	free_texture_filename_no_so(t_data *data);
void	free_error_set_color(char *dest, t_parser *parser, char **tab_color);
void	free_tab(char **tab);
void	free_all(t_data *data);

int		ft_strncmp_cub3d(char *s1, char *s2, int n);
int		ft_strcmp_cub3d(char *s1, char *s2);

char	*ft_read_and_join(char *map);

int		verif_directory(char *str);
int		verif_extensions(char *str, char **av);
char	*trim_texture_path(char *str);
char	*trim_start(char *str);
int		verif_char(char **tab);

int		err(char *str);
char	*copy_after_space(char *str);
char	*copy_from(char *str, char c_start);
int		find_start_of_map(t_parser *parser);
int		is_all_space(char *input);
float	ft_fabs(float i);

#endif
