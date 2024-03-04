#include "../include/cub3D.h"

int	low(double nb)
{
	double i;

	i = 0;
	while (i < nb)
	{
		i += 1;
	}
	i -= 1;
	return ((int)i);
}

void	open_door(t_game *game)
{
	// int y = 0;
	// while(game->map[y])
	// {
	// 	dprintf(2, "%s", game->map[y]);
	// 	y++;
	// }
	// dprintf(2, "game->map[%d][%d] = %c\n", game->mapX, game->mapY, game->map[game->mapX][game->mapY]);
	// int	mX = game->mapX - 4;
	// int	mY = game->mapY - 4;

	// dprintf(2, "mX = %d, mY = %d\n", mX, mY);
	// dprintf(2, "game->mapX = %d, game->mapY = %d\n", game->mapX, game->mapY);
	if (game->map[game->mX][game->mY] == 'D' && ((game->dX <= 2 && game->dX >= 0) || (game->dY <= 2 && game->dY >= 0)))
	{
		// dprintf(2, "---> mapX = %d, mapY = %d\n", game->mapX, game->mapY);
		game->map[game->mX][game->mY] = 'd';
	}
	else if (game->map[game->mX][game->mY] == 'd' && game->map[low(game->posX)][low(game->posY)] != 'd')
	{
		// dprintf(2, "---> mapX = %d, mapY = %d\n", game->mapX, game->mapY);
		game->map[game->mX][game->mY] = 'D';
	}

}



void	close_door(t_game *game)
{
	int	mX = 0;
	int	mY;

	// dprintf(2, "---> mX = %d, mY = %d\n", game->mX, game->mY);
	while (game->map[mX])
	{
		mY = 0;
		while (game->map[mX][mY])
		{
			// dprintf(2, "---> posX = %f, posY = %f\n", game->posX, game->posY);
			// dprintf(2, "---> (return)posX = %d, (return)posY = %d\n", return_low(game->posX), return_low(game->posY));
			if (game->map[mX][mY] == 'd' && game->map[low(game->posX)][low(game->posY)] != 'd')
			{
				game->map[mX][mY] = 'D';
			}
			mY++;
		}	
		mX++;
	}	
}

int	handle_no_event(t_game *game)
{
	if (game->key_w)
		move_up(game);
	if (game->key_s)
		move_down(game);
	if (game->key_d)
		move_right(game);
	if (game->key_a)
		move_left(game);
	if (game->key_right)
		rotate_right(game);
	if (game->key_left)
		rotate_left(game);
	if (BONUS)
	{
		if (game->key_q)
			open_door(game);
		if (game->key_e)
			close_door(game);
	}
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	display(game, 0);
	return (0);
}

int	handle_keypress(int keysym, t_game *game)
{
	if (keysym == XK_w)
		game->key_w = 1;
	if (keysym == XK_s)
		game->key_s = 1;
	if (keysym == XK_d)
		game->key_d = 1;
	if (keysym == XK_a)
		game->key_a = 1;
	if (keysym == 65363)
		game->key_right = 1;
	if (keysym == 65361)
		game->key_left = 1;
	if (BONUS)
	{	
		if (keysym == XK_q)
			game->key_q = 1;
		if (keysym == XK_e)
			game->key_e = 1;
	}
	if (keysym == XK_Escape)
		ft_exit(game);
	return (0);
}

int	handle_keyrelease(int keysym, t_game *game)
{
	if (keysym == XK_w)
		game->key_w = 0;
	if (keysym == XK_s)
		game->key_s = 0;
	if (keysym == XK_d)
		game->key_d = 0;
	if (keysym == XK_a)
		game->key_a = 0;
	if (keysym == 65363)
		game->key_right = 0;
	if (keysym == 65361)
		game->key_left = 0;
	if (BONUS)
	{
		if (keysym == XK_q)
			game->key_q = 0;
		if (keysym == XK_e)
			game->key_e = 0;
	}
	// else if (keysym == XK_Escape)
	// 	ft_exit(game);
	return (0);
}

