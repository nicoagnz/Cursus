# PROGRAM NAME
NAME			=	so_long

# COMPILER AND FLAGS
CC				=	cc
CFLAGS			=	-Wall -Werror -Wextra
RM				=	rm -rf
RM_FILE			=	rm -f

# DIRECTORIES
MLX_DIR			=	MLX42
MLX_BUILD_DIR	=	$(MLX_DIR)/build
MLX_INCLUDE		=	-I$(MLX_DIR)/include/MLX
SRC_DIR			=	so_long_src/src
UTILS_DIR		=	so_long_src/utils
LIBFT_DIR		=	libft
OBJ_DIR			=	obj

# INCLUDE PATHS
INCLUDE			=	-I$(MLX_INCLUDE) -Iincludes

# SOURCE FILES
SRC_FILES		=	$(SRC_DIR)/main.c \
					$(SRC_DIR)/render_map.c \
					$(SRC_DIR)/read_map.c \

UTILS_FILES		=	$(UTILS_DIR)/error.c \
					$(UTILS_DIR)/validate_map.c \
					$(UTILS_DIR)/init_list.c \
					$(UTILS_DIR)/is_playable.c \
					$(UTILS_DIR)/free.c \
					$(UTILS_DIR)/load_elements.c \
					$(UTILS_DIR)/keys.c \
					$(UTILS_DIR)/check_path.c \

ALL_SRC			=	$(SRC_FILES) $(UTILS_FILES)

# OBJECT FILES
OBJ_FILES		=	$(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES)) \
					$(patsubst $(UTILS_DIR)/%.c,$(OBJ_DIR)/%.o,$(UTILS_FILES))

# COLORS
RED				=	\033[1;31m
GREEN			=	\033[1;32m
YELLOW			=	\033[1;33m
RESET			=	\033[0m

# RULES
all: $(NAME)

# LIBFT
$(LIBFT_DIR)/libft.a:
	@echo "$(YELLOW)Compiling libft...$(RESET)"
	$(MAKE) -s -C $(LIBFT_DIR)

# MLX42
$(MLX_DIR)/build/libmlx42.a:
	@echo "$(YELLOW)Compiling MLX42...$(RESET)"
	mkdir -p $(MLX_BUILD_DIR)
	cd $(MLX_BUILD_DIR) && cmake .. && make
	@echo "$(GREEN)MLX42 compiled$(RESET)"

# LINK THE PROGRAM
$(NAME): $(LIBFT_DIR)/libft.a $(MLX_DIR)/build/libmlx42.a $(OBJ_FILES)
	@echo "SRC_FILES: $(ALL_SRC)"
	@echo "OBJ_FILES: $(OBJ_FILES)"
	@echo "$(YELLOW)Creating $(NAME)...$(RESET)"
	$(CC) $(CFLAGS) $(OBJ_FILES) -L$(MLX_BUILD_DIR) -lmlx42 -L$(LIBFT_DIR) -lft -lglfw -lm -o $(NAME)
	@echo "$(GREEN)Creation of $(NAME) complete$(RESET)"

# COMPILE .C TO .O
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(OBJ_DIR)/%.o: $(UTILS_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

# CLEAN OBJECT FILES
clean:
	@echo "$(RED)Removing object files (.o)...$(RESET)"
	$(RM) $(OBJ_DIR)
	@echo "$(RED)Removing MLX42 build...$(RESET)"
	$(RM) $(MLX_BUILD_DIR)
	@echo "$(RED)Running clean in libft...$(RESET)"
	$(MAKE) -C $(LIBFT_DIR) clean

# CLEAN ALL (OBJECTS AND EXECUTABLE)
fclean: clean
	@echo "$(RED)Removing the executable $(NAME)...$(RESET)"
	$(RM_FILE) $(NAME) || true
	@echo "$(RED)Running fclean in libft...$(RESET)"
	$(MAKE) -C $(LIBFT_DIR) fclean

# RECOMPILE
re: fclean all

# DECLARE RULES AS PHONY
.PHONY: all clean fclean re