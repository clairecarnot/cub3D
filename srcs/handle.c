#include "../include/cub3D.h"

int	draw_game(t_game *game)
{
	
}

int	handle_no_event(t_game *game)
{
	(void)game;
	draw_game(game);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, \
	game->image_base.img_ptr, 0, 0);
	// render_rect(game, (t_rect){39, 12, 115, 15, (int)0xffffff});
	// render_rect(game, (t_rect){40, 13, 113, 13, (int)0x000000});
	// mlx_string_put(game->mlx_ptr, game->win_ptr, 42, 23, \
	// (int)0xffffff, "move counter");
	// mlx_string_put(game->mlx_ptr, game->win_ptr, 130, 23, \
	// (int)0xffffff, game->move_nb);
	// free(game->move_nb);
	return (0);
}

int	handle_input(int keysym, t_game *game)
{
	if (keysym == XK_w)
	{	
		dprintf(2, "up\n");
		// move_up(game);
	}
	else if (keysym == XK_s)
	{
		dprintf(2, "down\n");
		// move_down(game);
	}
	else if (keysym == XK_d)
	{
		dprintf(2, "right\n");
		// move_right(game);
	}
	else if (keysym == XK_a)
	{
		dprintf(2, "left\n");
		// move_left(game);
	}
	else if (keysym == XK_Escape)
		ft_exit(game);
	return (0);
}
