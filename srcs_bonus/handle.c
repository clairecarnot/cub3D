#include "../include/cub3D.h"

int	handle_no_event(t_game *game)
{
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	display(game, 0);
	return (0);
}

int	handle_keypress(int keysym, t_game *game)
{
	if (keysym == XK_w)
		move_up(game);
	else if (keysym == XK_s)
		move_down(game);
	else if (keysym == XK_d)
		move_right(game);
	else if (keysym == XK_a)
		move_left(game);
	else if (keysym == 65363)
		rotate_right(game);
	else if (keysym == 65361)
		rotate_left(game);
	else if (keysym == XK_Escape)
		ft_exit(game);
	return (0);
}
