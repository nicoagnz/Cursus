NAME = libftprintf.a

PRINTF_DIR = .
LIBFT_DIR = libft
SRC_FILES = $(wildcard $(LIBFT_DIR)/*.c) $(wildcard $(PRINTF_DIR)/*.c)

OBJECTS = $(SOURCES:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJECTS)
	ar  rcs $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all
