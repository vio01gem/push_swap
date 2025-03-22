# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rradin-m <rradin-m@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/08 20:33:51 by rradin-m          #+#    #+#              #
#    Updated: 2025/02/05 12:43:37 by rradin-m         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

SRC = ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memcpy.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c\
		ft_memset.c\
		ft_bzero.c\
		ft_calloc.c\
		ft_memmove.c\
		ft_strchr.c\
		ft_strdup.c\
		ft_strrchr.c\
		ft_striteri.c\
		ft_substr.c\
		ft_strtrim.c\
		ft_strjoin.c\
		ft_strmapi.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_itoa.c\
		ft_split.c\
		ft_lstnew.c \
		ft_lstsize.c \
		ft_lstadd_back.c \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstlast.c \
		ft_lstiter.c \
		ft_lstmap.c \

OBJ = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Werror -Wextra

DEL = rm -rf

AR = ar -rcs

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $@ $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(DEL) $(OBJ)

fclean: clean
	$(DEL) $(NAME)

re: fclean all

.PHONY: all clean fclean re