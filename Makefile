NAME = push_swap

PUSH_SRC = main.c\
	parcing.c


PUSH_OBJ = $(PUSH_SRC:.c=.o)
PRINTF_DIR = ft_printf
PRINTF_NAME = $(PRINTF_DIR)/libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
DEL = rm -rf
AR = ar -rcs

all: $(PRINTF_NAME) $(NAME)

$(NAME): $(PUSH_OBJ) $(PRINTF_NAME)
	$(CC) $(CFLAGS) -o $(NAME) $(PUSH_OBJ) $(PRINTF_NAME)

$(PRINTF_NAME):
	make -C $(PRINTF_DIR)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(DEL) $(PUSH_OBJ)
	make clean -C $(PRINTF_DIR)

fclean: clean
	$(DEL) $(NAME)
	make fclean -C $(PRINTF_DIR)

re: fclean all

.PHONY: all clean fclean re
