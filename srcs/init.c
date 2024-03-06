#include "../include/cub3D.h"

void	get_pos(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'N' || game->map[y][x] == 'S' ||
				game->map[y][x] == 'E' || game->map[y][x] == 'W')
			{
				game->pos_y = (double)x + 0.5 ;
				game->pos_x = (double)y + 0.5 ;
				get_dir(game, game->map[y][x]);
				game->map[y][x] = '0';
			}
			x++;
		}
		y++;
	}
}

void	init_mlx(t_game *game)
{
	game->win_ptr = mlx_new_window(game->mlx_ptr,
			game->screen_w, game->screen_h, "cub3D");
	if (!game->win_ptr)
		(free_game(game), exit(1));
	game->image = ft_calloc(sizeof(t_img), 1);
	if (!game->image)
		(free_game(game), exit(1));
	game->image->img_ptr = mlx_new_image(game->mlx_ptr,
			game->screen_w, game->screen_h);
	if (!game->image->img_ptr)
		(free_game(game), exit(1));
	game->image->full_buf = (int *)mlx_get_data_addr(game->image->img_ptr,
			&game->image->bpp, &game->image->size, &game->image->endian);
	if (!game->image->full_buf)
		(free_game(game), exit (1));
}

void	init_game_bonus(t_game *game)
{
	game->col_perso = 0xf000ff;
	game->col_floor = 0xededed;
	game->col_wall = 0x3d3d3d;
	game->col_door = 0x726b73;
	game->col_anim = 0x02ff00;
	game->box_size = 100;
	game->x_mmap = 0;
	game->y_mmap = 0;
	game->click = -1;
}

t_game	*init_game(void)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (ft_putstr_fd("Bad malloc\n", 2), NULL);
	game->screen_w = 640;
	game->screen_h = 480;
	game->tex_w = 64;
	game->tex_h = 64;
	game->nb_tex = 5;
	game->move_speed = 0.01;
	game->key_w = 0;
	game->key_s = 0;
	game->key_a = 0;
	game->key_d = 0;
	game->key_left = 0;
	game->key_right = 0;
	game->key_q = 0;
	game->key_e = 0;
	if (BONUS)
		init_game_bonus(game);
	return (game);
}
