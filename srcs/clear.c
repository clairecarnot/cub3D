#include "../include/cub3D.h"

int	close_if(int *fd)
{
	if (*fd > 0)
	{
		if (close(*fd) < 0)
			return (-1);
		*fd = -1;
	}
	return (0);
}

void	free_if(char *str)
{
	if (str)
		free(str);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	free_game(t_game *game)
{
	if (game->type)
		free_tab(game->type);
	if (game->map)
		free_tab(game->map);
	if (game)
		free(game);
	return (0);
}
