#include "../include/cub3D.h"

double	calculate_player_direction(t_game *game)
{
	return (atan2(game->dirY, game->dirX));
}

void	move_up(t_game *game)// W key
{

	dprintf(2, "-------- move up --------\n");
//	int	cellX;
//	int	cellY;
	double	tmpX;
	double	tmpY;

	dprintf(2, "game->rows = %d\n", game->rows);
	dprintf(2, "game->cols = %d\n", game->cols);
	dprintf(2, "game->dirX = %f\n", game->dirX);
	dprintf(2, "game->dirY = %f\n", game->dirY);
	dprintf(2, "posX = %f\n", game->posX);
	dprintf(2, "posY = %f\n", game->posY);
//	cellX = (int) (game->posX + game->dirX);
//	cellY = (int) (game->posY + game->dirY);
	tmpX = game->posX + game->dirX * game->moveSpeed;
	tmpY = game->posY + game->dirY * game->moveSpeed;
//	cellX = (int) tmpX;
//	cellY = (int) tmpY;
//	dprintf(2, "cellX = %d\n", cellX);
//	dprintf(2, "cellY = %d\n", cellY);
	dprintf(2, "tmpX = %f\n", tmpX);
	dprintf(2, "tmpY = %f\n", tmpY);

	if (tmpX >= 0.25 && tmpX <= game->rows - 1.25)
	{
		if (game->map[(int)tmpX][(int)game->posY] == '0')
			game->posX = tmpX;
		else if (tmpX + 0.25 < game->posX)
			game->posX = tmpX;
		else if (tmpX - 0.25 > game->posX)
			game->posX = tmpX;
	}
	if (tmpY >= 0.25 && tmpY <= game->cols - 1.25)
	{
		if (game->map[(int)game->posX][(int)tmpY] == '0')
			game->posY= tmpY;
		else if (tmpY + 0.25 < game->posY)
			game->posY = tmpY;
		else if (tmpY - 0.25 > game->posY)
			game->posY = tmpY;
	}
	dprintf(2, "posX = %f\n", game->posX);
	dprintf(2, "posY = %f\n", game->posY);
	dprintf(2, "-------- end --------\n");
}

void	move_down(t_game *game)// S key
{
	dprintf(2, "-------- move down --------\n");
//	int	cellX;
//	int	cellY;
	double	tmpX;
	double	tmpY;

	dprintf(2, "game->rows = %d\n", game->rows);
	dprintf(2, "game->cols = %d\n", game->cols);
	dprintf(2, "game->dirX = %f\n", game->dirX);
	dprintf(2, "game->dirY = %f\n", game->dirY);
	dprintf(2, "posX = %f\n", game->posX);
	dprintf(2, "posY = %f\n", game->posY);
//	cellX = (int) (game->posX - game->dirX);
//	cellY = (int) (game->posY - game->dirY);
	tmpX = game->posX - game->dirX * game->moveSpeed;
	tmpY = game->posY - game->dirY * game->moveSpeed;
//	cellX = (int) tmpX;
//	cellY = (int) tmpY;
//	dprintf(2, "cellX = %d\n", cellX);
//	dprintf(2, "cellY = %d\n", cellY);
	dprintf(2, "tmpX = %f\n", tmpX);
	dprintf(2, "tmpY = %f\n", tmpY);
	dprintf(2, "avant boucle X\n");

	if (tmpX >= 0.25 && tmpX <= game->rows - 1.25)
	{
		if (game->map[(int)tmpX][(int)game->posY] == '0')
			game->posX = tmpX;
		else if (tmpX + 0.25 < game->posX)
			game->posX = tmpX;
		else if (tmpX - 0.25 > game->posX)
			game->posX = tmpX;
	}
	if (tmpY >= 0.25 && tmpY <= game->cols - 1.25)
	{
		if (game->map[(int)game->posX][(int)tmpY] == '0')
			game->posY= tmpY;
		else if (tmpY + 0.25 < game->posY)
			game->posY = tmpY;
		else if (tmpY - 0.25 > game->posY)
			game->posY = tmpY;
	}

	dprintf(2, "posX = %f\n", game->posX);
	dprintf(2, "posY = %f\n", game->posY);
	dprintf(2, "-------- end --------\n");
}

void	move_left(t_game *game)// A key
{
	dprintf(2, "-------- move left --------\n");
	double	facing_direction;
//	int	cellX;
//	int	cellY;
	double	tmpX;
	double	tmpY;

	dprintf(2, "game->rows = %d\n", game->rows);
	dprintf(2, "game->cols = %d\n", game->cols);
	dprintf(2, "game->dirX = %f\n", game->dirX);
	dprintf(2, "game->dirY = %f\n", game->dirY);
	dprintf(2, "posX = %f\n", game->posX);
	dprintf(2, "posY = %f\n", game->posY);
	facing_direction = calculate_player_direction(game);
//	cellX = (int) (game->posX + cos(facing_direction + M_PI_2));
//	cellY = (int) (game->posY + sin(facing_direction + M_PI_2));
	tmpX = game->posX + cos(facing_direction + M_PI_2) * game->moveSpeed;
	tmpY = game->posY + sin(facing_direction + M_PI_2) * game->moveSpeed;
//	cellX = (int) tmpX;
//	cellY = (int) tmpY;
//	dprintf(2, "cellX = %d\n", cellX);
//	dprintf(2, "cellY = %d\n", cellY);
	dprintf(2, "tmpX = %f\n", tmpX);
	dprintf(2, "tmpY = %f\n", tmpY);
	dprintf(2, "avant boucle X\n");

	if (tmpX >= 0.25 && tmpX <= game->rows - 1.25)
	{
		if (game->map[(int)tmpX][(int)game->posY] == '0')
			game->posX = tmpX;
		else if (tmpX + 0.25 < game->posX)
			game->posX = tmpX;
		else if (tmpX - 0.25 > game->posX)
			game->posX = tmpX;
	}
	if (tmpY >= 0.25 && tmpY <= game->cols - 1.25)
	{
		if (game->map[(int)game->posX][(int)tmpY] == '0')
			game->posY= tmpY;
		else if (tmpY + 0.25 < game->posY)
			game->posY = tmpY;
		else if (tmpY - 0.25 > game->posY)
			game->posY = tmpY;
	}

	dprintf(2, "posX = %f\n", game->posX);
	dprintf(2, "posY = %f\n", game->posY);
	dprintf(2, "-------- end --------\n");
}

void	move_right(t_game *game)// D key
{
	dprintf(2, "-------- move right --------\n");
	double	facing_direction;
//	int	cellX;
//	int	cellY;
	double	tmpX;
	double	tmpY;

	dprintf(2, "game->rows = %d\n", game->rows);
	dprintf(2, "game->cols = %d\n", game->cols);
	dprintf(2, "game->dirX = %f\n", game->dirX);
	dprintf(2, "game->dirY = %f\n", game->dirY);
	dprintf(2, "posX = %f\n", game->posX);
	dprintf(2, "posY = %f\n", game->posY);
	facing_direction = calculate_player_direction(game);
//	cellX = (int) (game->posX + cos(facing_direction - M_PI_2));
//	cellY = (int) (game->posY + sin(facing_direction - M_PI_2));
	tmpX = game->posX + cos(facing_direction - M_PI_2) * game->moveSpeed;
	tmpY = game->posY + sin(facing_direction - M_PI_2) * game->moveSpeed;
//	cellX = (int) tmpX;
//	cellY = (int) tmpY;
//	dprintf(2, "cellX = %d\n", cellX);
//	dprintf(2, "cellY = %d\n", cellY);
	dprintf(2, "tmpX = %f\n", tmpX);
	dprintf(2, "tmpY = %f\n", tmpY);
	dprintf(2, "avant boucle X\n");

	if (tmpX >= 0.25 && tmpX <= game->rows - 1.25)
	{
		if (game->map[(int)tmpX][(int)game->posY] == '0')
			game->posX = tmpX;
		else if (tmpX + 0.25 < game->posX)
			game->posX = tmpX;
		else if (tmpX - 0.25 > game->posX)
			game->posX = tmpX;
	}
	if (tmpY >= 0.25 && tmpY <= game->cols - 1.25)
	{
		if (game->map[(int)game->posX][(int)tmpY] == '0')
			game->posY= tmpY;
		else if (tmpY + 0.25 < game->posY)
			game->posY = tmpY;
		else if (tmpY - 0.25 > game->posY)
			game->posY = tmpY;
	}

	dprintf(2, "posX = %f\n", game->posX);
	dprintf(2, "posY = %f\n", game->posY);
	dprintf(2, "-------- end --------\n");
}