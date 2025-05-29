# Makefile for philo
NAME		=	philo

CC			=	cc

CFLAGS		=	-Wall -Werror -Wextra -pthread

SRC_DIR		=	src

INCLUDE_DIR	=	includes

SRCS		=	$(SRC_DIR)/main.c \
				$(SRC_DIR)/utils.c \
				$(SRC_DIR)/init.c \
				$(SRC_DIR)/start_simulation.c \
				$(SRC_DIR)/monitor.c \
				$(SRC_DIR)/time.c \
				$(SRC_DIR)/err_utils.c \

OBJS		=	$(SRCS:.c=.o)

HEADERS		=	$(INCLUDE_DIR)/philo.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re