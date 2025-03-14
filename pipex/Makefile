NAME        = pipex
CC          = cc
CFLAGS      = -Wall -Werror -Wextra
RM          = rm -rf

INCLUDE     = includes
SRC_DIR     = .
UTILS_SRC   = libft
OBJ_DIR     = obj

SRC_FILES   = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(UTILS_SRC)/*.c)
OBJ_FILES   = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

RED         = \033[1;31m
GREEN       = \033[1;32m
BLUE        = \033[1;34m
YELLOW      = \033[1;33m
RESET       = \033[0m

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@echo "$(YELLOW)Creando $(NAME)...$(RESET)"
	@$(CC) $(OBJ_FILES) -o $(NAME)
	@echo "$(GREEN)Creacion de $(NAME) completa $(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@echo "$(BLUE)Copilando  $<...$(RESET)"
	@$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $@

clean:
	@echo "$(RED)Eliminando obj...$(RESET)"
	@$(RM) $(OBJ_DIR)

fclean: clean
	@echo "$(RED)Eliminando $(NAME)...$(RESET)"
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re






