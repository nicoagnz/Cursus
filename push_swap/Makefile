NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Werror -Wextra
RM          = rm -rf

INCLUDE     = includes
SRC_DIR     = src
UTILS_DIR   = utils
OBJ_DIR     = obj
LIBFT_DIR   = libft
LIBFT       = $(LIBFT_DIR)/libft.a

SRC_FILES   = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(UTILS_DIR)/*.c)
OBJ_FILES   = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(wildcard $(SRC_DIR)/*.c)) \
              $(patsubst $(UTILS_DIR)/%.c, $(OBJ_DIR)/%.o, $(wildcard $(UTILS_DIR)/*.c))

RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
RESET       = \033[0m

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT)
	@echo "$(YELLOW)Creando $(NAME)...$(RESET)"
	@$(CC) $(OBJ_FILES) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "$(GREEN)Creacion de $(NAME) completa $(RESET)"

$(LIBFT):
	@echo "$(YELLOW)Compilando libft...$(RESET)"
	@make -C $(LIBFT_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

$(OBJ_DIR)/%.o: $(UTILS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

clean:
	@echo "$(RED)Eliminando obj...$(RESET)"
	@$(RM) $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@echo "$(RED)Eliminando $(NAME)...$(RESET)"
	@$(RM) $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re