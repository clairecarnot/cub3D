#include "../include/cub3D.h"

int	init_buf(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	game->buf = malloc(sizeof(unsigned int *) * game->screen_h);
	if (!game->buf)
		return (1);//a verifier
	while (y < game->screen_h)
	{
		x = 0;
		game->buf[y] = ft_calloc(sizeof(unsigned int), game->screen_w);
		if (!game->buf[x])
			return (1);//faire une fonction free buffer et verifier
		y++;
	}
	return (0);
}

void	get_dir(t_game *game, char c)
{
	if (c == 'E')//regarde a l'ouest
	{
		game->dirX = 0;
		game->dirY = 1;
		game->planeX = 0.66;
		game->planeY = 0;
	}
	else if (c == 'W')//regarde a l'est
	{
		game->dirX = 0;
		game->dirY = -1;
		game->planeX = -0.66;
		game->planeY = 0;
	}
	else if (c == 'S')//regarde au sud
	{
		game->dirX = 1;
		game->dirY = 0;
		game->planeX = 0;
		game->planeY = -0.66;
	}
	else if (c == 'N')//regarde au nord 
	{
		game->dirX = -1;
		game->dirY = 0;
		game->planeX = 0;
		game->planeY = 0.66;
	}
}

void	get_posX(t_game *game)
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
				dprintf(2, "posX= %f  posY = %f\n", game->posX, game->posY);
				get_dir(game, game->map[y][x]);
			}
			x++;
		}
		y++;
	}
}

void	init_info(t_game *game)
{
	get_posX(game);
	// printf("posX = %f, posY = %f, dirX = %f, dirY = %f\n", game->posX, game->posY, game->dirX, game->dirY);
	game->time = 0;
	game->oldtime = 0;
}

void	init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		//faire un fonction free
		exit (1);
	}
	
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->screen_w, game->screen_h, "cub3D");//revoir taille ecran
	if (!game->win_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		//faire une fonction free
		free(game->mlx_ptr);
		exit (1);
	}
	// game->image_base = new_img(game->screen_w, game->screen_h, game);
	game->image.img_ptr = mlx_new_image(game->mlx_ptr, game->screen_w, game->screen_h);
	if (!game->image.img_ptr)
	{
		//a proteger
		exit(1);
	}
	game->image.full_buf = (int *)mlx_get_data_addr(game->image.img_ptr, &game->image.bpp, &game->image.size, &game->image.endian);
	if (!game->image.full_buf)
	{
		//a proteger
		exit (1);
	}
}

t_game	*init_game(void)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (ft_putstr_fd("Bad malloc\n", 2), NULL);
	//--------------------temp-----------------------
	game->map = malloc(sizeof(char *) * (7 + 1));
	game->screen_w = 600;
	game->screen_h = 400;
	game->moveSpeed = 0.1;
	game->rotSpeed = 0.1;
	return (game);
}
