# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abonnefo <abonnefo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/17 10:44:39 by abonnefo          #+#    #+#              #
#    Updated: 2024/01/18 10:57:40 by abonnefo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g3

RED=\033[1;31m
GREEN=\033[1;32m
YELLOW=\033[1;33m
BLUE=\033[1;34m
MAGENTA=\033[1;35m
CYAN=\033[1;36m
RESET=\033[0m

OBJ_DIR_CUB3D = objs_cub3D

MLX_FLAG = -L ./includes/minilibx-linux/ -lmlx -lX11 -lXext -g3 -lm
MLX_REPO = https://github.com/42Paris/minilibx-linux.git
MLX_DIR = ./includes/minilibx-linux/
MLX_FILE = libmlx.a
MLX_EXE = $(addprefix $(MLX_DIR), $(MLXFILE)) $(MLX_FLAG)

LIBFT_DIR = ./libft/
LIBFT_FILE = libft.a
LIBFT_EXE = $(addprefix $(LIBFT_DIR), $(LIBFT_FILE))

GNL_DIR = ./libft/GNL/
GNL_FILE = libftGNL.a
GNL_EXE = $(addprefix $(GNL_DIR), $(GNL_FILE))

PRINTF_DIR = ./libft/ft_printf/
PRINTF_FILE = libftprintf.a
PRINTF_EXE = $(addprefix $(PRINTF_DIR), $(PRINTF_FILE))

SRCS_MAIN = srcs/main/main.c

SRCS_EXEC_CUB3D = srcs/exec_cub3D/cub3d.c \
	srcs/exec_cub3D/display_game.c \
	srcs/exec_cub3D/display_map.c \
	srcs/exec_cub3D/display_pixels.c \
	srcs/exec_cub3D/key_press.c \
	srcs/exec_cub3D/player_move.c \
	srcs/exec_cub3D/put_pixels.c \
	srcs/exec_cub3D/rays.c \

SRCS_INIT = srcs/init/init_colors.c \
	srcs/init/init_pos_directions.c \
	srcs/init/init_pos_player.c \
	srcs/init/init_rays_directions.c \
	srcs/init/init_textures_adress.c \
	srcs/init/init_textures_filename.c \
	srcs/init/init_window.c \
	srcs/init/master_init.c \

SRCS_PARSING = srcs/parsing/master_pars.c \
	srcs/parsing/pars_begin_params.c \
	srcs/parsing/pars_floor_and_ceiling.c \
	srcs/parsing/pars_textures.c \
	srcs/parsing/pars_maps.c \
	srcs/parsing/pars_start_player.c \

SRCS_UTILS = srcs/utils/copy_char.c \
	srcs/utils/create_map.c \
	srcs/utils/free_bis.c \
	srcs/utils/free.c \
	srcs/utils/libft_modify.c \
	srcs/utils/put_in_tab.c \
	srcs/utils/read_and_join.c \
	srcs/utils/utils_parsing.c \
	srcs/utils/utils.c \

OBJS =	$(SRCS_MAIN:%.c=$(OBJ_DIR_CUB3D)/%.o) \
		$(SRCS_EXEC_CUB3D:%.c=$(OBJ_DIR_CUB3D)/%.o) \
		$(SRCS_INIT:%.c=$(OBJ_DIR_CUB3D)/%.o) \
		$(SRCS_PARSING:%.c=$(OBJ_DIR_CUB3D)/%.o) \
		$(SRCS_UTILS:%.c=$(OBJ_DIR_CUB3D)/%.o) \

RM = rm -rf

mlx :
	@echo "$(CYAN)\nCloning MinilibX repository...\n$(RESET)"
	@$(RM) $(MLX_DIR)  > /dev/null
	@git clone $(MLX_REPO) ./includes/minilibx-linux/ > /dev/null 2>&1
	@$(MAKE) -sC $(MLX_DIR) 
	@echo "\n\n$(BLUE)gcc *.c minilibx done$(RESET)"

lib:
	@$(MAKE) -sC $(LIBFT_DIR)
	@echo "$(BLUE)gcc *.c libft done$(RESET)"

gnl:
	@$(MAKE) -sC $(GNL_DIR)
	@echo "$(BLUE)gcc *.c get_next_line done$(RESET)"

printf:
	@$(MAKE) -sC $(PRINTF_DIR)
	@echo "$(BLUE)gcc *.c ft_printf done$(RESET)"

all : mlx lib gnl printf $(NAME)

$(OBJ_DIR_CUB3D)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS) Makefile includes/minilibx-linux/mlx.h includes/libft.h includes/ft_printf.h includes/get_next_line.h
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_EXE) $(PRINTF_EXE) $(GNL_EXE) $(MLX_EXE) -o $(NAME)
	@echo "$(BLUE)gcc *.c cub3D done\n$(RESET)"
	@echo "$(GREEN)[Make : 'cub3D' is done]$(RESET)"

clean :
	@$(MAKE) -sC $(LIBFT_DIR) clean
	@$(MAKE) -sC $(PRINTF_DIR) clean
	@$(MAKE) -sC $(GNL_DIR) clean
	@$(RM) $(OBJS)
	@$(RM) $(OBJ_DIR_CUB3D)
	@echo "$(YELLOW)Object files and directories removed$(RESET)"

fclean : clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT_EXE)
	@$(RM) $(GNL_EXE)
	@$(RM) $(PRINTF_EXE)
	@echo "$(YELLOW)Binary file removed$(RESET)"

re : fclean all