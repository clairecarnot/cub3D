#include "../include/cub3D.h"

void	rotate_right(t_game *game, double mult)
{
	double	rad;
	double	dX;
	double	pX;

	rad = (mult * 3.14159265358979323846) / 180;
	dX = game->dirX;
	pX = game->planeX;
	game->dirX = game->dirX * cos(rad) - game->dirY * sin(rad);
	game->dirY = dX * sin(rad) + game->dirY * cos(rad);
	game->planeX = game->planeX * cos(rad) - game->planeY * sin(rad);
	game->planeY = pX * sin(rad) + game->planeY * cos(rad);	
}

void	rotate_left(t_game *game, double mult)
{
	double	rad;
	double	dX;
	double	pX;

	rad = (mult * 3.14159265358979323846) / 180;
	dX = game->dirX;
	pX = game->planeX;
	game->dirX = game->dirX * cos(rad) - game->dirY * sin(rad);
	game->dirY = dX * sin(rad) + game->dirY * cos(rad);
	game->planeX = game->planeX * cos(rad) - game->planeY * sin(rad);
	game->planeY = pX * sin(rad) + game->planeY * cos(rad);
}



