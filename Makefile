NAME = cub3D

CFLAGS = -g3 -Wall -Wextra -Werror
#CFLAGS = -g3 -Wall -Wextra -Werror -fsanitize=address
MLXFLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm

INCL = -I -I./libft -I./include -I./minilib-linux

SRCS = main.c \
srcs/clear.c srcs/clear2.c \
srcs/getcontent1.c srcs/getcontent2.c srcs/getcontent_bonus1.c srcs/getcontent_bonus2.c \
srcs/parsing.c srcs/parse_type1.c srcs/parse_type2.c \
srcs/parse_map1.c srcs/parse_map2.c \
srcs/parse_err_map.c srcs/parse_err_map2.c srcs/parse_err_types.c srcs/parse_err_types2.c \
srcs/handle.c srcs/open_close_door.c srcs/init.c srcs/init2.c \
srcs/display.c srcs/texture.c srcs/texture2.c srcs/draw.c srcs/pixels.c srcs/sprites.c \
srcs/move.c srcs/rotate.c srcs/move_mouse.c \
srcs/minimap.c srcs/minimap2.c srcs/minimap3.c \
srcs/free_exit.c 

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