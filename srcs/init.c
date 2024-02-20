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
	if (c == 'N')
	{
		game->dirX = 0;
		game->dirY = -1;
	}
	else if (c == 'S')
	{
		game->dirX = 0;
		game->dirY = 1;
	}
	else if (c == 'E')
	{
		game->dirX = 1;
		game->dirY = 0;
	}
	else if (c == 'W')
	{
		game->dirX = -1;
		game->dirY = 0;
	}
}

void	get_posX(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S' ||
				game->map[i][j] == 'E' || game->map[i][j] == 'W')
			{
				game->posX = (double)j;
				game->posY = (double)i;
				get_dir(game, game->map[i][j]);
			}
			j++;
		}
		i++;
	}
}

void	init_info(t_game *game)
{
	get_posX(game);
	// printf("posX = %f, posY = %f, dirX = %f, dirY = %f\n", game->posX, game->posY, game->dirX, game->dirY);
	game->planeX = 0.66;
	game->planeY = 0;
	game->time = 0;
	game->oldtime = 0;
}


t_game	*init_game(void)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (ft_putstr_fd("Bad malloc\n", 2), NULL);
	//--------------------temp-----------------------
	game->map = malloc(sizeof(char *) * (6 + 1));
	game->map[0] = ft_strdup("1111111");
	game->map[1] = ft_strdup("1000001");
	game->map[2] = ft_strdup("1000001");
	game->map[3] = ft_strdup("1000001");
	game->map[4] = ft_strdup("100N001");
	game->map[5] = ft_strdup("1111111");
	game->map[6] = 0;
	//-----------------------------------------------

	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		//faire un fonction free
		exit (1);
	}
	game->screen_w = 600;
	game->screen_h = 400;
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->screen_w, game->screen_h, "cub3D");//revoir taille ecran
	if (!game->win_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		//faire une fonction free
		free(game->mlx_ptr);
		exit (1);
	}
	game->image_base = new_img(600, 400, game);

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
	// preinit_img();
	
	init_info(game);
	init_buf(game);
	return (game);
}