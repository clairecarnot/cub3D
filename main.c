#include "cub3D.h"

void	init_img(t_game *game)
{
	game->image_base = new_img(600, 400, game);
}

t_game	*init_game()
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (NULL);
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		//faire un fonction free
		exit (1);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, 600, 400, "cub3D");//revoir taille ecran
	if (!game->win_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		//faire une fonction free
		free(game->mlx_ptr);
		exit (1);
	}
	// preinit_img();
	init_img(game);
	return (game);
}

int main(int argc, char **argv)
{
	(void)argv;
	t_game	*game;

	if (argc != 2)
		return (ft_putstr_fd("Invalid nb of args\n", 2), 1);
	game = init_game();
	if (!game)
		return (1);
	// game->map = get_map(argv);
	// if (!game->map)
		// return (1); //msg a checker
	// if (parse_map(game) == 1)
		// return (1); //msg a checker
	//loop
	mlx_loop_hook(game->mlx_ptr, &handle_no_event, game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, &handle_input, game);
	mlx_hook(game->win_ptr, ClientMessage, NoEventMask, &ft_exit, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}
