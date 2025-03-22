NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c utils.c swaps.c rotates.c big_sort.c rev_rots.c pushes.c \
		build_stack.c parse_handler1.c parse_handler.c \
		for_5_4.c for_3_2.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) | libft
	@$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)

libft:
	@make -C libft

clean:
	@$(RM) $(OBJS)
	@make -C libft clean

fclean: clean
	@$(RM) $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY: all clean fclean re libft
