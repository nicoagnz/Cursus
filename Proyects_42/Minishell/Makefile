.SILENT:
NAME		= minishell

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
LDFLAGS		= -lreadline
INCLUDE_DIR	= includes
LIBFT_DIR	= libft
LIBFT_A		= $(LIBFT_DIR)/libft.a

SRC_DIR		= src
OBJ_DIR		= obj

# Core files
CORE_SRCS	= $(SRC_DIR)/core/main.c \
			  $(SRC_DIR)/core/prompt.c \
			  $(SRC_DIR)/core/utils_prompt.c \
			  $(SRC_DIR)/core/utils_main.c \
			  $(SRC_DIR)/core/init_structs.c

# Parsing files
PARSING_SRCS= $(SRC_DIR)/parsing/tokenizer.c \
			  $(SRC_DIR)/parsing/utils_tokenizer.c \
			  $(SRC_DIR)/parsing/utils_tokenizer2.c \
			  $(SRC_DIR)/parsing/parser.c \
			  $(SRC_DIR)/parsing/utils_parser.c \
			  $(SRC_DIR)/parsing/utils_parser2.c \
			  $(SRC_DIR)/parsing/utils_parser3.c \
			  $(SRC_DIR)/parsing/expand_text.c \
			  $(SRC_DIR)/parsing/expand_var.c \
			  $(SRC_DIR)/parsing/expand_word.c \
			  $(SRC_DIR)/parsing/utils_expand.c

# Execution files
EXEC_SRCS	= $(SRC_DIR)/execution/executor.c \
			  $(SRC_DIR)/execution/utils_executor.c \
			  $(SRC_DIR)/execution/utils_executor2.c \
			  $(SRC_DIR)/execution/utils_executor3.c \
			  $(SRC_DIR)/execution/utils_executor4.c

# Builtin files
BUILTIN_SRCS= $(SRC_DIR)/builtins/builtins.c \
			  $(SRC_DIR)/builtins/cd.c \
			  $(SRC_DIR)/builtins/utils_cd.c \
			  $(SRC_DIR)/builtins/echo.c \
			  $(SRC_DIR)/builtins/env.c \
			  $(SRC_DIR)/builtins/pwd.c \
			  $(SRC_DIR)/builtins/unset.c \
			  $(SRC_DIR)/builtins/utils_unset.c \
			  $(SRC_DIR)/builtins/export.c \
			  $(SRC_DIR)/builtins/utils_export.c \
			  $(SRC_DIR)/builtins/utils_export2.c \
			  $(SRC_DIR)/builtins/utils_export3.c \
			  $(SRC_DIR)/builtins/exit.c

# Utils files
UTILS_SRCS	= $(SRC_DIR)/utils/errors.c \
			  $(SRC_DIR)/utils/errors_child.c \
			  $(SRC_DIR)/utils/free.c \
			  $(SRC_DIR)/utils/signals.c \
			  $(SRC_DIR)/utils/signals2.c

# All source files
SRCS		= $(CORE_SRCS) $(PARSING_SRCS) $(EXEC_SRCS) $(BUILTIN_SRCS) $(UTILS_SRCS)

# Object files
OBJS		= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

MINISHELL_H	= $(INCLUDE_DIR)/minishell.h
LIBFT_H		= $(INCLUDE_DIR)/libft.h

IFLAGS		= -I$(INCLUDE_DIR) -I$(LIBFT_DIR)

RED			= \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
RESET		= \033[0m

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_A)
	@echo "$(YELLOW)Compiling minishell...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(LDFLAGS) $(IFLAGS) -o $(NAME)
	@echo "$(GREEN)Compilation complete$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(MINISHELL_H) $(LIBFT_H)
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@

$(LIBFT_A):
	@echo "$(YELLOW)Compiling libft...$(RESET)"
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR)
	@echo "$(GREEN)Compilation complete$(RESET)"

clean:
	@echo "$(RED)Eliminando obj...$(RESET)"
	@rm -rf $(OBJ_DIR)
	@$(MAKE) --no-print-directory -C $(LIBFT_DIR) clean

fclean: clean
	@echo "$(RED)Eliminando $(NAME)...$(RESET)"
	rm -f $(NAME)
	$(MAKE) --no-print-directory -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
