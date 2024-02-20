#include "cub3D.h"

int	main(int argc, char **argv)
{
	(void)argv;
	t_game	*game;

	if (argc != 2)
		return (ft_putstr_fd("Invalid nb of args\n", 2), 1);
	game = init_game();
	if (!game)
		return (1);

	// if (get_file_content(game, argv) == 1)
	// 	return (free_game(game), 1);
	// if (parse_content(game) == 1)
	// 	return (free_game(game), 1);

	draw_game(game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, &handle_input, game);
	mlx_hook(game->win_ptr, ClientMessage, NoEventMask, &ft_exit, game);
	mlx_loop_hook(game->mlx_ptr, &handle_no_event, game);
	mlx_loop(game->mlx_ptr);

	free_game(game);

	return (0);
}
