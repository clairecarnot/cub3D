#include "../include/cub3D.h"

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
	// else if (keysym == XK_Escape)
	// 	ft_exit(game);
	return (0);
}

