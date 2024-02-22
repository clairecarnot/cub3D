NAME = cub3D

CFLAGS = -g3 -Wall -Wextra -Werror
#CFLAGS = -g3 -Wall -Wextra -Werror -fsanitize=address
MLXFLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm

INCL = -I -I./libft -I./include -I./minilib-linux

SRCS = main.c \
srcs/clear.c srcs/getcontent1.c srcs/getcontent2.c \
srcs/parsing.c srcs/parse_type1.c srcs/parse_type2.c \
srcs/parse_map1.c srcs/parse_map2.c \
srcs/parse_err_map.c srcs/parse_err_types.c \
srcs/handle.c srcs/init.c srcs/display.c \
srcs/move.c srcs/rotate.c \
srcs/free_exit.c srcs/img_utils.c

OBJS = $(SRCS:.c=.o)

LIBFT = ./libft/libft.a
LIBMLX = ./minilibx-linux/libmlx_Linux.a

$(NAME): $(OBJS)
	make lib
	make mlx
	cc -o $(NAME) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBMLX) $(MLXFLAGS)

all: $(NAME)

%.o:%.c
	cc $(INCL) $(CFLAGS) -o $@ -c $<

mlx:
	make -C ./minilibx-linux/ all

lib:
	make -C ./libft/ bonus

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean
	make all

.PHONY: all clean fclean re