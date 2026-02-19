
NAME = cub3d

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
INCLUDE_DIR	= includes
LIBFT_DIR	= libft
LIBFT_A		= $(LIBFT_DIR)/libft.a

SRC_DIR		= src
OBJ_DIR		= obj

SRC			= $(SRC_DIR)/main.c
OBJ			= $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

clean:

fclean: clean

re: fclean all

.PHONY: all clean fclean re
