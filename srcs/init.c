#include "../include/cub3D.h"

void	get_dir2(t_game *game, char c)
{
	if (c == 'S')
	{
		game->dirX = 1;
		game->dirY = 0;
		game->planeX = 0;
		game->planeY = -0.66;
		return ;
	}
	if (c == 'N')
	{
		game->dirX = -1;
		game->dirY = 0;
		game->planeX = 0;
		game->planeY = 0.66;
		return ;
	}
}

void	get_dir(t_game *game, char c)
{
	if (c == 'E')
	{
		game->dirX = 0;
		game->dirY = 1;
		game->planeX = 0.66;
		game->planeY = 0;
		return ;
	}
	if (c == 'W')
	{
		game->dirX = 0;
		game->dirY = -1;
		game->planeX = -0.66;
		game->planeY = 0;
		return ;
	}
	get_dir2(game, c);
}

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
				game->posY = (double)x + 0.5 ;
				game->posX = (double)y + 0.5 ;
				// game->posX = (double)x + 0.5 ;
				// game->posY = (double)y + 0.5 ;
				// dprintf(2, "posX= %f  posY = %f\n", game->posX, game->posY);
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
	// game->img_map = ft_calloc(sizeof(t_img), 1);
	// if (!game->img_map)
	// 	(free_game(game), exit(1));
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
	game->nb_tex = 4;
	game->moveSpeed = 0.1;
	game->rotSpeed = 0.1;
	game->key_w = 0;
	game->key_s = 0;
	game->key_a = 0;
	game->key_d = 0;
	game->key_left = 0;
	game->key_right = 0;
	// ----------------- bonus ---------------- //
	game->col_perso = 0xf000ff;
	game->col_floor = 0xededed;
	game->col_wall = 0x3d3d3d;
	game->box_size = 100;
	game->x_mmap = 0;
	game->y_mmap = 0;
	// ---------------------------------------- //
	return (game);
}
