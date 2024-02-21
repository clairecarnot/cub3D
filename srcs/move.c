#include "../include/cub3D.h"

void	move_up(t_game *game)
{
	if (game->map[(int)game->posY][(int)game->posX] != '1')
	{
		game->posX += game->dirX * game->moveSpeed;
		game->posY += game->dirY * game->moveSpeed;
	}
}

void	move_down(t_game *game)
{
	if (game->map[(int)game->posY][(int)game->posX] != '1')
	{
		game->posX -= game->dirX * game->moveSpeed;
		game->posY -= game->dirY * game->moveSpeed;
	}
}

void	move_right(t_game *game)
{
	// if (game->map[(int)game->posY][(int)game->posX] != '1')
	// {
		game->oldDirX = game->dirX;
		game->dirX = game->dirX * cos(game->rotSpeed) - game->dirY * sin(game->rotSpeed);
		game->dirY = game->oldDirX * sin(game->rotSpeed) + game->dirY * cos(game->rotSpeed);
		game->oldPlaneX = game->planeX;
		game->planeX = game->planeX * cos(game->rotSpeed) - game->planeY * sin(game->rotSpeed);
		game->planeY = game->oldPlaneX * sin(game->rotSpeed) + game->planeY * cos(game->rotSpeed);	
	// }
}

void	move_left(t_game *game)
{
	// if (game->map[(int)game->posY][(int)game->posX] != '1')
	// {
		game->oldDirX = game->dirX;
		game->dirX = game->dirX * cos(-game->rotSpeed) - game->dirY * sin(-game->rotSpeed);
		game->dirY = game->oldDirX * sin(-game->rotSpeed) + game->dirY * cos(-game->rotSpeed);
		game->oldPlaneX = game->planeX;
		game->planeX = game->planeX * cos(-game->rotSpeed) - game->planeY * sin(-game->rotSpeed);
		game->planeY = game->oldPlaneX * sin(-game->rotSpeed) + game->planeY * cos(-game->rotSpeed);
	// }
}