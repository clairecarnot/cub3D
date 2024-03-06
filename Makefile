NAME = cub3D

BONUS = cub3D_bonus

CFLAGS = -g3 -Wall -Wextra -Werror
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

SRCS_BONUS = main_bonus.c \
srcs_bonus/clear.c srcs_bonus/clear2.c \
srcs_bonus/getcontent1.c srcs_bonus/getcontent2.c srcs_bonus/getcontent_bonus1.c srcs_bonus/getcontent_bonus2.c \
srcs_bonus/parsing.c srcs_bonus/parse_type1.c srcs_bonus/parse_type2.c \
srcs_bonus/parse_map1.c srcs_bonus/parse_map2.c \
srcs_bonus/parse_err_map.c srcs_bonus/parse_err_map2.c srcs_bonus/parse_err_types.c srcs_bonus/parse_err_types2.c \
srcs_bonus/handle.c srcs_bonus/open_close_door.c srcs_bonus/init.c srcs_bonus/init2.c \
srcs_bonus/display.c srcs_bonus/texture.c srcs_bonus/texture2.c srcs_bonus/draw.c srcs_bonus/pixels.c srcs_bonus/sprites.c \
srcs_bonus/move.c srcs_bonus/rotate.c srcs_bonus/move_mouse.c \
srcs_bonus/minimap.c srcs_bonus/minimap2.c srcs_bonus/minimap3.c \
srcs_bonus/free_exit.c 

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

LIBFT = ./libft/libft.a
LIBMLX = ./minilibx-linux/libmlx_Linux.a

$(NAME): $(OBJS)
	make lib
	make mlx
	cc -o $(NAME) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBMLX) $(MLXFLAGS)

$(BONUS): $(OBJS_BONUS)
	make lib
	make mlx
	cc -o $(BONUS) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) $(LIBMLX) $(MLXFLAGS)

all: $(NAME)

%.o:%.c
	cc $(INCL) $(CFLAGS) -o $@ -c $<

mlx:
	make -C ./minilibx-linux/ all

lib:
	make -C ./libft/ bonus

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(BONUS)

bonus: $(BONUS)

re: fclean
	make all

rebonus: fclean
	make bonus

.PHONY: all clean fclean bonus re rebonus