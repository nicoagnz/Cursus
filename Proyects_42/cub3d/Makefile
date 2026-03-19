
NAME = cub3d

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDE_DIR	= includes
LIBFT_DIR	= libft
LIBFT_A		= $(LIBFT_DIR)/libft.a
MLX42_DIR	= MLX42
MLX42_BUILD	= $(MLX42_DIR)/build
MLX42_A		= $(MLX42_BUILD)/libmlx42.a

SRC_DIR		= src
OBJ_DIR		= obj

SRC			= $(shell find $(SRC_DIR) -name "*.c" -type f)
OBJ			= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

INCLUDES	= -I$(INCLUDE_DIR) -I$(MLX42_DIR)/include
LIBS		= $(LIBFT_A) $(MLX42_A) -ldl -lglfw -lm

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT_A):
	@$(MAKE) -s --no-print-directory -C $(LIBFT_DIR)

$(MLX42_A):
	@cmake -B $(MLX42_BUILD) -S $(MLX42_DIR) > /dev/null
	@cmake --build $(MLX42_BUILD) -- -s > /dev/null

$(NAME): $(LIBFT_A) $(MLX42_A) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)
	@printf "\033[0;32m✓ %s compiled successfully\033[0m\n" "$(NAME)"

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -s --no-print-directory -C $(LIBFT_DIR) clean
	@printf "\033[0;32m✓ Objects cleaned\033[0m\n"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -s --no-print-directory -C $(LIBFT_DIR) fclean
	@rm -rf $(MLX42_BUILD)
	@printf "\033[0;32m✓ Everything cleaned\033[0m\n"

re: fclean all

.PHONY: all clean fclean re
