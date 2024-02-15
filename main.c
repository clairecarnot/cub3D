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
		return (ft_pustr_fd("Invalid nb of args\n", 2), 1);
	game = init_game();
	if (!game)
		return (1);
	game->map = get_map(argv);
	if (!game->map)
		return (1); //msg a checker
	if (parse_map(game) == 1)
		return (1); //msg a checker
	//loop
	return (0);
}