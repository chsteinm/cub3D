NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 #-fsanitize=address
MLXFLAGS = -L ./minilibx-linux -lmlx -lXext -lX11
PATH_SRCS = ./srcs/
SRCS = main.c parse.c
OBJ = $(addprefix $(BUILD_DIR)/,$(SRCS:.c=.o))
BUILD_DIR = .build
LIBFT = ./includes/libft/libft.a
MLX = ./minilibx-linux/libmlx.a ./minilibx-linux/libmlx_Linux.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLXFLAGS) -o $@
	@echo "\ncompile done!\n"
	@echo 'Tape for example "./cub3D Ressources/Maps/classic.ber"'"\n"

$(BUILD_DIR)/%.o: $(PATH_SRCS)%.c Makefile
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@ -I ./includes

-include $(OBJ:.o=.d) $(OBJ_BONUS:.o=.d)

$(LIBFT): FORCE
	@make --no-print-directory -C ./includes/libft bonus

$(MLX): FORCE
	@make --no-print-directory -C ./minilibx-linux

norm:
	norminette ./srcs ./includes

FORCE:

clean:
	@make --no-print-directory -C ./includes/libft clean
	@make --no-print-directory -C ./minilibx-linux clean
	rm -rf $(BUILD_DIR)

fclean: clean
	@make --no-print-directory -C ./includes/libft fclean
	rm -rf $(NAME) $(NAME_BONUS)

re: fclean
	@make --no-print-directory

.PHONY: all clean fclean re FORCE norm