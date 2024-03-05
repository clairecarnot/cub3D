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
	// dprintf(2, "game->map[%d][%d] = %c\n", game->map_x, game->map_y, game->map[game->map_x][game->map_y]);
	// int	m_x = game->map_x - 4;
	// int	m_y = game->map_y - 4;

	// dprintf(2, "m_x = %d, m_y = %d\n", m_x, m_y);
	// dprintf(2, "game->map_x = %d, game->map_y = %d\n", game->map_x, game->map_y);
	if (game->map[game->m_x][game->m_y] == 'D' && ((game->d_x <= 2 && game->d_x >= 0) || (game->d_y <= 2 && game->d_y >= 0)))
	{
		// dprintf(2, "---> map_x = %d, map_y = %d\n", game->map_x, game->map_y);
		game->map[game->m_x][game->m_y] = 'd';
	}
	// else if (game->map[game->m_x][game->m_y] == 'd' && game->map[low(game->pos_x)][low(game->pos_y)] != 'd')
	// {
	// 	// dprintf(2, "---> map_x = %d, map_y = %d\n", game->map_x, game->map_y);
	// 	game->map[game->m_x][game->m_y] = 'D';
	// }

}



void	close_door(t_game *game)
{
	int	m_x = 0;
	int	m_y;

	// dprintf(2, "---> m_x = %d, m_y = %d\n", game->m_x, game->m_y);
	while (game->map[m_x])
	{
		m_y = 0;
		while (game->map[m_x][m_y])
		{
			// dprintf(2, "---> pos_x = %f, pos_y = %f\n", game->pos_x, game->pos_y);
			// dprintf(2, "---> (return)pos_x = %d, (return)pos_y = %d\n", return_low(game->pos_x), return_low(game->pos_y));
			if (game->map[m_x][m_y] == 'd' && game->map[low(game->pos_x)][low(game->pos_y)] != 'd')
			{
				game->map[m_x][m_y] = 'D';
			}
			m_y++;
		}	
		m_x++;
	}
	// if (game->map[game->m_x][game->m_y] == 'd' && game->map[low(game->pos_x)][low(game->pos_y)] != 'd')
	// {
	// 	// dprintf(2, "---> map_x = %d, map_y = %d\n", game->map_x, game->map_y);
	// 	game->map[game->m_x][game->m_y] = 'D';
	// }

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
		rotate_right(game, -1);
	if (game->key_left)
		rotate_left(game, 1);
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

