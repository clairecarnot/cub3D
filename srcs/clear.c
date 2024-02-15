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

int	free_game(t_game *game)
{
	if (game)
		free(game);
	return (0);
}
