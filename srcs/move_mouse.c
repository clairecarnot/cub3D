#include "../include/cub3D.h"

void	mouse_pos(t_game *game, int x, int y)
{
	if (x > game->screen_w - DIST_MOUSE)
	{
		x = DIST_MOUSE;
		mlx_mouse_move(game->mlx_ptr, game->win_ptr, x, y);
	}
	if (x < DIST_MOUSE)
	{
		x =  game->screen_w - DIST_MOUSE;
		mlx_mouse_move(game->mlx_ptr, game->win_ptr, x, y);
	}
}

int	mouse_mv(int x, int y, t_game *game)
{
	static int	last_x = SCREEN_W / 2;

	mouse_pos(game, x, y);
	if (x == last_x)
		return (0);
	else if (x < last_x)
		rotate_left(game);
	else if (x > last_x)
		rotate_right(game);
	last_x = x;
	return (0);
}
