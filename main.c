#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (ft_putstr_fd("Invalid nb of args\n", 2), 1);
	game = init_game();
	if (!game)
		return (1);
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		(free_game(game), exit(1));
	if (get_file_content(game, argv) == 1)
		return (free_game(game), 1);
	if (parse_content(game) == 1)
		return (free_game(game), 1);
	// dprintf(2, "All is OK\n");
	init_mlx(game);
	get_pos(game);
	// dprintf(2, "All is OK2\n");
	display(game, 0);
	// dprintf(2, "All is OK3\n");
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, &handle_keypress, game);
	mlx_hook(game->win_ptr, KeyRelease, KeyReleaseMask, &handle_keyrelease, game);
	mlx_hook(game->win_ptr, ClientMessage, NoEventMask, &ft_exit, game);
	mlx_loop_hook(game->mlx_ptr, &handle_no_event, game);
	// dprintf(2, "All is OK4\n");
	mlx_loop(game->mlx_ptr);
	free_game(game);
	return (0);
}
