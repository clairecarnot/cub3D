#include "cub3D.h"

void	init_img(t_game *game)
{
	game->image_base = new_img(600, 400, game);
}

t_game	*init_game(void)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (ft_putstr_fd("Bad malloc\n", 2), NULL);
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
	//--------------------temp-----------------------
	game->map = malloc(sizeof(char *) * (6 + 1));
	game->map[0] = ft_strdup("111111");
	game->map[1] = ft_strdup("100001");
	game->map[2] = ft_strdup("100001");
	game->map[3] = ft_strdup("100001");
	game->map[4] = ft_strdup("10N001");
	game->map[5] = ft_strdup("111111");
	game->map[6] = 0;
	//-----------------------------------------------
	init_img(game);
	return (game);
}

int	main(int argc, char **argv)
{
	(void)argv;
	t_game	*game;

	if (argc != 2)
		return (ft_putstr_fd("Invalid nb of args\n", 2), 1);
	game = init_game();
	if (!game)
		return (1);

	if (get_file_content(game, argv) == 1)
		return (free_game(game), 1);
	if (parse_content(game) == 1)
		return (free_game(game), 1);

	mlx_loop_hook(game->mlx_ptr, &handle_no_event, game);
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, &handle_input, game);
	mlx_hook(game->win_ptr, ClientMessage, NoEventMask, &ft_exit, game);
	mlx_loop(game->mlx_ptr);

	free_game(game);

	return (0);
}
