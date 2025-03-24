NAME = push_swap

# === Source files for push_swap ===
PUSH_SRC = main.c \
	parcing.c \
	error_utils.c

PUSH_OBJ = $(PUSH_SRC:.c=.o)

# === Libft and ft_printf directories ===
PRINTF = ft_printf
PRINTF_NAME = $(PRINTF)/libftprintf.a

LIBFT = libft
LIBFT_NAME = $(LIBFT)/libft.a

# === Compiler config ===
CC = cc
CFLAGS = -Wall -Werror -Wextra
DEL = rm -rf

# === All rule compiles libft, printf, and push_swap ===
all: $(LIBFT_NAME) $(PRINTF_NAME) $(NAME)

$(NAME): $(PUSH_OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(PUSH_OBJ) $(LIBFT_NAME) $(PRINTF_NAME)

$(LIBFT_NAME):
	make -C $(LIBFT)

$(PRINTF_NAME):
	make -C $(PRINTF)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(DEL) $(PUSH_OBJ)
	make clean -C $(LIBFT)
	make clean -C $(PRINTF)

fclean: clean
	$(DEL) $(NAME)
	make fclean -C $(LIBFT)
	make fclean -C $(PRINTF)

re: fclean all

.PHONY: all clean fclean re
