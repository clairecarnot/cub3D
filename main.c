#include "cub3D.h"

t_game	*init_game()
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	if (!game)
		return (NULL);
	return (game);
}

int main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (ft_putstr_fd("Invalid nb of args\n", 2), 1);
	game = init_game();
	if (!game)
		return (1);
	game->map = get_map(game, argv);
	if (!game->map)
		return (free_game(game), 1); //msg a checker
//	if (parse_map(game) == 1)
//		return (1); //msg a checker
//	loop
	free_game(game);
	return (0);
}