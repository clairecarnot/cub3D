#include "../include/cub3D.h"

void	get_dir2(t_game *game, char c)
{
	if (c == 'S')
	{
		game->dir_x = 1;
		game->dir_y = 0;
		game->plane_x = 0;
		game->plane_y = -0.66;
		return ;
	}
	if (c == 'N')
	{
		game->dir_x = -1;
		game->dir_y = 0;
		game->plane_x = 0;
		game->plane_y = 0.66;
		return ;
	}
}

void	get_dir(t_game *game, char c)
{
	if (c == 'E')
	{
		game->dir_x = 0;
		game->dir_y = 1;
		game->plane_x = 0.66;
		game->plane_y = 0;
		return ;
	}
	if (c == 'W')
	{
		game->dir_x = 0;
		game->dir_y = -1;
		game->plane_x = -0.66;
		game->plane_y = 0;
		return ;
	}
	get_dir2(game, c);
}
