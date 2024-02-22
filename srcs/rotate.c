#include "../include/cub3D.h"

void	rotate_right(t_game *game)
{
	// double	rad;
	// double	dX;
	// double	pX;

	// rad = (- 0.8 * 3.14159265358979323846) / 180;
	// dX = game->dirX;
	// pX = game->planeX;
	// game->dirX = game->dirX * cos(rad) - game->dirY * sin(rad);
	// game->dirY = dX * sin(rad) + game->dirY * cos(rad);
	// game->planeX = game->planeX * cos(rad) - game->planeY * sin(rad);
	// game->planeY = pX * sin(rad) + game->planeY * cos(rad);	
	game->oldDirX = game->dirX;
	game->dirX = game->dirX * cos(-game->rotSpeed) - game->dirY * sin(-game->rotSpeed);
	game->dirY = game->oldDirX * sin(-game->rotSpeed) + game->dirY * cos(-game->rotSpeed);
	game->oldPlaneX = game->planeX;
	game->planeX = game->planeX * cos(-game->rotSpeed) - game->planeY * sin(-game->rotSpeed);
	game->planeY = game->oldPlaneX * sin(-game->rotSpeed) + game->planeY * cos(-game->rotSpeed);
}

void	rotate_left(t_game *game)
{
	// double	rad;
	// double	dX;
	// double	pX;

	// rad = (0.8 * 3.14159265358979323846) / 180;
	// dX = game->dirX;
	// pX = game->planeX;
	// game->dirX = game->dirX * cos(rad) - game->dirY * sin(rad);
	// game->dirY = dX * sin(rad) + game->dirY * cos(rad);
	// game->planeX = game->planeX * cos(rad) - game->planeY * sin(rad);
	// game->planeY = pX * sin(rad) + game->planeY * cos(rad);
	game->oldDirX = game->dirX;
	game->dirX = game->dirX * cos(game->rotSpeed) - game->dirY * sin(game->rotSpeed);
	game->dirY = game->oldDirX * sin(game->rotSpeed) + game->dirY * cos(game->rotSpeed);
	game->oldPlaneX = game->planeX;
	game->planeX = game->planeX * cos(game->rotSpeed) - game->planeY * sin(game->rotSpeed);
	game->planeY = game->oldPlaneX * sin(game->rotSpeed) + game->planeY * cos(game->rotSpeed);
}



