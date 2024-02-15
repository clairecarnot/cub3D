# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/10 14:57:56 by ccarnot           #+#    #+#              #
#    Updated: 2023/09/05 18:44:25 by ccarnot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror 

SRCS = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_tolower.c ft_toupper.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
	ft_atoi.c ft_strdup.c ft_calloc.c ft_substr.c ft_strjoin.c \
	ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	get_next_line.c ft_printf.c prints.c prints_hexa.c utils.c 

OBJS = $(SRCS:.c=.o)

BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c \
	ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c \
	ft_lstclear.c ft_lstiter.c ft_lstmap.c

BONUS_OBJS = $(BONUS_SRCS:.c=.o)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

all: $(NAME)

%.o:%.c
	cc -I -g3 $(CFLAGS) -o $@ -c $?

clean:
	/bin/rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

bonus: $(OBJS) $(BONUS_OBJS)
	ar -rcs $(NAME) $(OBJS) $(BONUS_OBJS)

rebonus: fclean bonus

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS) $(BONUS_SRCS)
	gcc -nostartfiles -shared -o libft.so $(OBJS) $(BONUS_OBJS)

.PHONY: all clean fclean re bonus rebonus
