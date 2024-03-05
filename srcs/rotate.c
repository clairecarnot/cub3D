#include "../include/cub3D.h"

void	rotate_right(t_game *game, double mult)
{
	double	rad;
	double	dX;
	double	pX;

	rad = (mult * 3.14159265358979323846) / 180;
	dX = game->dir_x;
	pX = game->plane_x;
	game->dir_x = game->dir_x * cos(rad) - game->dir_y * sin(rad);
	game->dir_y = dX * sin(rad) + game->dir_y * cos(rad);
	game->plane_x = game->plane_x * cos(rad) - game->plane_y * sin(rad);
	game->plane_y = pX * sin(rad) + game->plane_y * cos(rad);	
}

void	rotate_left(t_game *game, double mult)
{
	double	rad;
	double	dX;
	double	pX;

	rad = (mult * 3.14159265358979323846) / 180;
	dX = game->dir_x;
	pX = game->plane_x;
	game->dir_x = game->dir_x * cos(rad) - game->dir_y * sin(rad);
	game->dir_y = dX * sin(rad) + game->dir_y * cos(rad);
	game->plane_x = game->plane_x * cos(rad) - game->plane_y * sin(rad);
	game->plane_y = pX * sin(rad) + game->plane_y * cos(rad);
}



