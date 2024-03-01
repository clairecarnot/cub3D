NAME = cub3D

CFLAGS = -g3 -Wall -Wextra -Werror
#CFLAGS = -g3 -Wall -Wextra -Werror -fsanitize=address
MLXFLAGS = -Lminilibx-linux -lmlx -lXext -lX11 -lm

INCL = -I -I./libft -I./include -I./minilib-linux

SRCS = main.c \
srcs/clear.c srcs/clear2.c \
srcs/getcontent1.c srcs/getcontent2.c srcs/getcontent_bonus.c \
srcs/parsing.c srcs/parse_type1.c srcs/parse_type2.c \
srcs/parse_map1.c srcs/parse_map2.c \
srcs/parse_err_map.c srcs/parse_err_map2.c srcs/parse_err_types.c srcs/parse_err_types2.c \
srcs/handle.c srcs/init.c \
srcs/display.c srcs/texture.c srcs/draw.c srcs/pixels.c\
srcs/move.c srcs/rotate.c srcs/move_mouse.c \
srcs/free_exit.c 

SRCS_BONUS = main.c \
srcs_bonus/clear.c srcs_bonus/clear2.c \
srcs_bonus/getcontent1.c srcs_bonus/getcontent2.c \
srcs_bonus/parsing.c srcs_bonus/parse_type1.c srcs_bonus/parse_type2.c \
srcs_bonus/parse_map1.c srcs_bonus/parse_map2.c \
srcs_bonus/parse_err_map.c srcs_bonus/parse_err_types.c srcs_bonus/parse_err_types2.c \
srcs_bonus/handle.c srcs_bonus/init.c \
srcs_bonus/display.c srcs_bonus/texture.c srcs_bonus/draw.c \
srcs_bonus/move.c srcs_bonus/rotate.c \
srcs_bonus/free_exit.c 

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