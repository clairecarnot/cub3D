#include "../include/cub3D.h"

void	move_up(t_game *game)// W key
{
		game->posX += game->dirX * game->moveSpeed;
		game->posY += game->dirY * game->moveSpeed;
}

void	move_down(t_game *game)// S key
{
		game->posX -= game->dirX * game->moveSpeed;
		game->posY -= game->dirY * game->moveSpeed;
}

void	move_left(t_game *game)// A key
{
		game->posY += game->planeY * game->moveSpeed;
		game->posX -= game->planeX * game->moveSpeed;
}

void	move_right(t_game *game)// D key
{
		game->posY -= game->planeY * game->moveSpeed;//va a gauche mais se decale quand rotate
		game->posX += game->planeX * game->moveSpeed;

}
