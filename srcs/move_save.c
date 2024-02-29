#include "../include/cub3D.h"

double	calculate_player_direction(t_game *game)
{
	return (atan2(game->dirY, game->dirX));
}

void	move_up(t_game *game)// W key
{

	dprintf(2, "-------- move up --------\n");
	/*
	int	tmpX;
	int	tmpY;

	// dprintf(2, "game->rows = %d\n", game->rows);
	// dprintf(2, "game->cols = %d\n", game->cols);
	// dprintf(2, "game->dirX = %f\n", game->dirX);
	// dprintf(2, "game->dirY = %f\n", game->dirY);
	// dprintf(2, "posX = %f\n", game->posX);
	// dprintf(2, "posY = %f\n", game->posY);
//	if (((int)(game->posX + 0.9) > 1) && (game->posX < game->rows)
//		&& ((int)(game->posY + 0.9) > 1) && (game->posY < game->cols))
	{
		tmpX = (int) (game->posX + game->dirX * game->moveSpeed);
		tmpY = (int) (game->posY + game->dirY * game->moveSpeed);
		// dprintf(2, "1\n");
		// dprintf(2, "tmpX = %d\n", tmpX);
		// dprintf(2, "tmpY = %d\n", tmpY);
		if (!game->map[tmpX])
			return ;
		// dprintf(2, "2\n");
		if (!game->map[tmpX][tmpY])
			return ;
		// dprintf(2, "3\n");
		if (game->map[tmpX][tmpY] == '1')
		{
			// dprintf(2, "MUR\n");
			return ;
		}
		// dprintf(2, "4\n");
		if ((game->posX + game->dirX * game->moveSpeed >= 1.1)
			&& (game->posX + game->dirX * game->moveSpeed <= game->rows - 1.1))
			game->posX += game->dirX * game->moveSpeed;
		if ((game->posY + game->dirY * game->moveSpeed >= 1.1)
			&& (game->posY + game->dirY * game->moveSpeed <= game->cols - 1.1))
			game->posY += game->dirY * game->moveSpeed;
		// dprintf(2, "posX = %f\n", game->posX);
		// dprintf(2, "posY = %f\n", game->posY);
		// dprintf(2, "5\n");
	}
	*/
	int	cellX;
	int	cellY;
	double	tmpX;
	double	tmpY;

	dprintf(2, "game->rows = %d\n", game->rows);
	dprintf(2, "game->cols = %d\n", game->cols);
	dprintf(2, "game->dirX = %f\n", game->dirX);
	dprintf(2, "game->dirY = %f\n", game->dirY);
	dprintf(2, "posX = %f\n", game->posX);
	dprintf(2, "posY = %f\n", game->posY);
	cellX = (int) (game->posX + game->dirX);
	cellY = (int) (game->posY + game->dirY);
	tmpX = game->posX + game->dirX * game->moveSpeed;
	tmpY = game->posY + game->dirY * game->moveSpeed;
	dprintf(2, "cellX = %d\n", cellX);
	dprintf(2, "cellY = %d\n", cellY);
	dprintf(2, "tmpX = %f\n", tmpX);
	dprintf(2, "tmpY = %f\n", tmpY);
	dprintf(2, "avant boucle X\n");
	if ((tmpX >= 1.1) && (tmpX <= game->rows - 1.1))
	{
		dprintf(2, "boucle X\n");
//		dprintf(2, "game->map[cellX][cellY] = %c\n", game->map[cellX][cellY]);
		if ((int) tmpX == 1 || (int) tmpX == game->rows - 2)
		{
			dprintf(2, "X rebord\n");
			game->posX = tmpX;
		}
		if (game->map[cellX][cellY] == '0')
		{
			dprintf(2, "X inside sans mur\n");
//			dprintf(2, "game->map[%d][%d] = %c\n", cellX, cellY, game->map[cellX][cellY]);
			game->posX = tmpX;
		}
		else if (cellX < tmpX && fabs(tmpX - (cellX + 1)) > 0.1)
		{
			dprintf(2, "X inside dir -1\n");
//			dprintf(2, "fabs(tmpX - (cellX + 1)) = %f\n", fabs(tmpX - (cellX + 1)));
			game->posX = tmpX;
		}
		else if (cellX > tmpX && fabs(tmpX - (cellX - 1)) > 0.1)
		{
			dprintf(2, "X inside dir +1\n");
//			dprintf(2, "fabs(tmpX - (cellX - 1)) = %f\n", fabs(tmpX - (cellX - 1)));
			game->posX = tmpX;
		}
	}
	dprintf(2, "avant boucle Y\n");
	if ((tmpY >= 1.1) && (tmpY <= game->cols - 1.1))
	{
		dprintf(2, "boucle Y\n");
//		dprintf(2, "game->map[cellX][cellY] = %c\n", game->map[cellX][cellY]);
		if ((int) tmpY == 1 || (int) tmpY == game->cols - 2)
		{
			dprintf(2, "Y rebord\n");
			game->posY = tmpY;
		}
		if (game->map[cellX][cellY] == '0')
		{
			dprintf(2, "Y inside sans mur\n");
//			dprintf(2, "game->map[%d][%d] = %c\n", cellX, cellY, game->map[cellX][cellY]);
			game->posY = tmpY;
		}
		else if (cellY < tmpY && fabs(tmpY - (cellY + 1)) > 0.1)
		{
			dprintf(2, "Y inside dir -1\n");
//			dprintf(2, "fabs(tmpY - (cellY + 1)) = %f\n", fabs(tmpY - (cellY + 1)));
			game->posY = tmpY;
		}
		else if (cellY > tmpY && fabs(tmpY - (cellY - 1)) > 0.1)
		{
			dprintf(2, "Y inside dir +1\n");
//			dprintf(2, "fabs(tmpY - (cellY - 1)) = %f\n", fabs(tmpY - (cellY - 1)));
			game->posY = tmpY;
		}
	}
	dprintf(2, "posX = %f\n", game->posX);
	dprintf(2, "posY = %f\n", game->posY);
	dprintf(2, "-------- end --------\n");
}

void	move_down(t_game *game)// S key
{
	dprintf(2, "-------- move down --------\n");
	/*
	int	tmpX;
	int	tmpY;

	// dprintf(2, "game->rows = %d\n", game->rows);
	// dprintf(2, "game->cols = %d\n", game->cols);
	// dprintf(2, "game->dirX = %f\n", game->dirX);
	// dprintf(2, "game->dirY = %f\n", game->dirY);
	// dprintf(2, "posX = %f\n", game->posX);
	// dprintf(2, "posY = %f\n", game->posY);
//	if ((int)(game->posX + 0.9) > 1)
//		dprintf(2, "ok1\n");
//	if (game->posX < game->rows)
//		dprintf(2, "ok2\n");
//	if ((int)(game->posY + 0.9) > 1)
//		dprintf(2, "ok3\n");
//	if (game->posY < game->cols)
//		dprintf(2, "ok4\n");
//	if (((int)(game->posX + 0.9) > 1) && (game->posX < game->rows)
//		&& ((int)(game->posY + 0.9) > 1) && (game->posY < game->cols))
	{
		tmpX = (int) (game->posX - game->dirX * game->moveSpeed);
		tmpY = (int) (game->posY - game->dirY * game->moveSpeed);
		// dprintf(2, "1\n");
		// dprintf(2, "tmpX = %d\n", tmpX);
		// dprintf(2, "tmpY = %d\n", tmpY);
		if (!game->map[tmpX])
			return ;
		// dprintf(2, "2\n");
		if (!game->map[tmpX][tmpY])
			return ;
		// dprintf(2, "3\n");
		if (game->map[tmpX][tmpY] == '1')
		{
			// dprintf(2, "MUR\n");
			return ;
		}
		// dprintf(2, "4\n");
		if ((game->posX - game->dirX * game->moveSpeed >= 1.1)
			&& (game->posX - game->dirX * game->moveSpeed <= game->rows - 1.1))
			game->posX -= game->dirX * game->moveSpeed;
		if ((game->posY - game->dirY * game->moveSpeed >= 1.1)
			&& (game->posY - game->dirY * game->moveSpeed <= game->cols - 1.1))
			game->posY -= game->dirY * game->moveSpeed;
		// dprintf(2, "posX = %f\n", game->posX);
		// dprintf(2, "posY = %f\n", game->posY);
		// dprintf(2, "5\n");
	}
	*/
	int	cellX;
	int	cellY;
	double	tmpX;
	double	tmpY;

	dprintf(2, "game->rows = %d\n", game->rows);
	dprintf(2, "game->cols = %d\n", game->cols);
	dprintf(2, "game->dirX = %f\n", game->dirX);
	dprintf(2, "game->dirY = %f\n", game->dirY);
	dprintf(2, "posX = %f\n", game->posX);
	dprintf(2, "posY = %f\n", game->posY);
	cellX = (int) (game->posX - game->dirX);
	cellY = (int) (game->posY - game->dirY);
	tmpX = game->posX - game->dirX * game->moveSpeed;
	tmpY = game->posY - game->dirY * game->moveSpeed;
	dprintf(2, "cellX = %d\n", cellX);
	dprintf(2, "cellY = %d\n", cellY);
	dprintf(2, "tmpX = %f\n", tmpX);
	dprintf(2, "tmpY = %f\n", tmpY);
	dprintf(2, "avant boucle X\n");
	if ((tmpX >= 1.1) && (tmpX <= game->rows - 1.1))
	{
		dprintf(2, "boucle X\n");
//		dprintf(2, "game->map[cellX][cellY] = %c\n", game->map[cellX][cellY]);
		if ((int) tmpX == 1 || (int) tmpX == game->rows - 2)
		{
			dprintf(2, "X rebord\n");
			game->posX = tmpX;
		}
		if (game->map[cellX][cellY] == '0')
		{
			dprintf(2, "X inside sans mur\n");
//			dprintf(2, "game->map[%d][%d] = %c\n", cellX, cellY, game->map[cellX][cellY]);
			game->posX = tmpX;
		}
		else if (cellX < tmpX && fabs(tmpX - (cellX + 1)) > 0.1)
		{
			dprintf(2, "X inside dir -1\n");
//			dprintf(2, "fabs(tmpX - (cellX + 1)) = %f\n", fabs(tmpX - (cellX + 1)));
			game->posX = tmpX;
		}
		else if (cellX > tmpX && fabs(tmpX - (cellX - 1)) > 0.1)
		{
//			dprintf(2, "X inside dir +1\n");
//			dprintf(2, "fabs(tmpX - (cellX - 1)) = %f\n", fabs(tmpX - (cellX - 1)));
			game->posX = tmpX;
		}
	}
	dprintf(2, "avant boucle Y\n");
	if ((tmpY >= 1.1) && (tmpY <= game->cols - 1.1))
	{
		dprintf(2, "boucle Y\n");
//		dprintf(2, "game->map[cellX][cellY] = %c\n", game->map[cellX][cellY]);
		if ((int) tmpY == 1 || (int) tmpY == game->cols - 2)
		{
			dprintf(2, "Y rebord\n");
			game->posY = tmpY;
		}
		if (game->map[cellX][cellY] == '0')
		{
			dprintf(2, "Y inside sans mur\n");
//			dprintf(2, "game->map[%d][%d] = %c\n", cellX, cellY, game->map[cellX][cellY]);
			game->posY = tmpY;
		}
		else if (cellY < tmpY && fabs(tmpY - (cellY + 1)) > 0.1)
		{
			dprintf(2, "Y inside dir -1\n");
//			dprintf(2, "fabs(tmpY - (cellY + 1)) = %f\n", fabs(tmpY - (cellY + 1)));
			game->posY = tmpY;
		}
		else if (cellY > tmpY && fabs(tmpY - (cellY - 1)) > 0.1)
		{
			dprintf(2, "Y inside dir +1\n");
//			dprintf(2, "fabs(tmpY - (cellY - 1)) = %f\n", fabs(tmpY - (cellY - 1)));
			game->posY = tmpY;
		}
	}
	dprintf(2, "posX = %f\n", game->posX);
	dprintf(2, "posY = %f\n", game->posY);
	dprintf(2, "-------- end --------\n");
}

void	move_left(t_game *game)// A key
{
	dprintf(2, "-------- move left --------\n");
	/*
	double	facing_direction;
	int	tmpX;
	int	tmpY;

	// dprintf(2, "game->rows = %d\n", game->rows);
	// dprintf(2, "game->cols = %d\n", game->cols);
	// dprintf(2, "game->dirX = %f\n", game->dirX);
	// dprintf(2, "game->dirY = %f\n", game->dirY);
	// dprintf(2, "posX = %f\n", game->posX);
	// dprintf(2, "posY = %f\n", game->posY);
	facing_direction = calculate_player_direction(game);
//	if ((int)(game->posX + 0.9) > 1)
//		dprintf(2, "ok1\n");
//	if (game->posX < game->rows)
//		dprintf(2, "ok2\n");
//	if ((int)(game->posY + 0.9) > 1)
//		dprintf(2, "ok3\n");
//	if (game->posY < game->cols)
//		dprintf(2, "ok4\n");
//	if (((int)(game->posX + 0.9) > 1) && (game->posX < game->rows)
//		&& ((int)(game->posY + 0.9) > 1) && (game->posY < game->cols))
	{
		tmpX = (int) (game->posX + cos(facing_direction + M_PI_2) * game->moveSpeed);
		tmpY = (int) (game->posY + sin(facing_direction + M_PI_2) * game->moveSpeed);
		// dprintf(2, "1\n");
		// dprintf(2, "tmpX = %d\n", tmpX);
		// dprintf(2, "tmpY = %d\n", tmpY);
		if (!game->map[tmpX])
			return ;
		// dprintf(2, "2\n");
		if (!game->map[tmpX][tmpY])
			return ;
		// dprintf(2, "3\n");
		if (game->map[tmpX][tmpY] == '1')
		{
			// dprintf(2, "MUR\n");
			return ;
		}
		// dprintf(2, "4\n");
		if ((game->posX + cos(facing_direction + M_PI_2) * game->moveSpeed >= 1.1)
			&& (game->posX + cos(facing_direction + M_PI_2) * game->moveSpeed <= game->rows - 1.1))
			game->posX += cos(facing_direction + M_PI_2) * game->moveSpeed;
		if ((game->posY + sin(facing_direction + M_PI_2) * game->moveSpeed >= 1.1)
			&& (game->posY + sin(facing_direction + M_PI_2) * game->moveSpeed <= game->cols - 1.1))
			game->posY += sin(facing_direction + M_PI_2) * game->moveSpeed;
		// dprintf(2, "posX = %f\n", game->posX);
		// dprintf(2, "posY = %f\n", game->posY);
		// dprintf(2, "5\n");
	}
	*/
	double	facing_direction;
	int	cellX;
	int	cellY;
	double	tmpX;
	double	tmpY;

	dprintf(2, "game->rows = %d\n", game->rows);
	dprintf(2, "game->cols = %d\n", game->cols);
	dprintf(2, "game->dirX = %f\n", game->dirX);
	dprintf(2, "game->dirY = %f\n", game->dirY);
	dprintf(2, "posX = %f\n", game->posX);
	dprintf(2, "posY = %f\n", game->posY);
	facing_direction = calculate_player_direction(game);
	cellX = (int) (game->posX + cos(facing_direction + M_PI_2));
	cellY = (int) (game->posY + sin(facing_direction + M_PI_2));
	tmpX = game->posX + cos(facing_direction + M_PI_2) * game->moveSpeed;
	tmpY = game->posY + sin(facing_direction + M_PI_2) * game->moveSpeed;
	dprintf(2, "cellX = %d\n", cellX);
	dprintf(2, "cellY = %d\n", cellY);
	dprintf(2, "tmpX = %f\n", tmpX);
	dprintf(2, "tmpY = %f\n", tmpY);
	dprintf(2, "avant boucle X\n");
	if ((tmpX >= 1.1) && (tmpX <= game->rows - 1.1))
	{
		dprintf(2, "boucle X\n");
//		dprintf(2, "game->map[cellX][cellY] = %c\n", game->map[cellX][cellY]);
		if ((int) tmpX == 1 || (int) tmpX == game->rows - 2)
		{
			dprintf(2, "X rebord\n");
			game->posX = tmpX;
		}
		if (game->map[cellX][cellY] == '0')
		{
			dprintf(2, "X inside sans mur\n");
//			dprintf(2, "game->map[%d][%d] = %c\n", cellX, cellY, game->map[cellX][cellY]);
			game->posX = tmpX;
		}
		else if (cellX < tmpX && fabs(tmpX - (cellX + 1)) > 0.1)
		{
			dprintf(2, "X inside dir -1\n");
//			dprintf(2, "fabs(tmpX - (cellX + 1)) = %f\n", fabs(tmpX - (cellX + 1)));
			game->posX = tmpX;
		}
		else if (cellX > tmpX && fabs(tmpX - (cellX - 1)) > 0.1)
		{
			dprintf(2, "X inside dir +1\n");
//			dprintf(2, "fabs(tmpX - (cellX - 1)) = %f\n", fabs(tmpX - (cellX - 1)));
			game->posX = tmpX;
		}
	}
	dprintf(2, "avant boucle Y\n");
	if ((tmpY >= 1.1) && (tmpY <= game->cols - 1.1))
	{
		dprintf(2, "boucle Y\n");
//		dprintf(2, "game->map[cellX][cellY] = %c\n", game->map[cellX][cellY]);
		if ((int) tmpY == 1 || (int) tmpY == game->cols - 2)
		{
			dprintf(2, "Y rebord\n");
			game->posY = tmpY;
		}
		if (game->map[cellX][cellY] == '0')
		{
			dprintf(2, "Y inside sans mur\n");
//			dprintf(2, "game->map[%d][%d] = %c\n", cellX, cellY, game->map[cellX][cellY]);
			game->posY = tmpY;
		}
		else if (cellY < tmpY && fabs(tmpY - (cellY + 1)) > 0.1)
		{
			dprintf(2, "Y inside dir -1\n");
//			dprintf(2, "fabs(tmpY - (cellY + 1)) = %f\n", fabs(tmpY - (cellY + 1)));
			game->posY = tmpY;
		}
		else if (cellY > tmpY && fabs(tmpY - (cellY - 1)) > 0.1)
		{
			dprintf(2, "Y inside dir +1\n");
//			dprintf(2, "fabs(tmpY - (cellY - 1)) = %f\n", fabs(tmpY - (cellY - 1)));
			game->posY = tmpY;
		}
	}
	dprintf(2, "posX = %f\n", game->posX);
	dprintf(2, "posY = %f\n", game->posY);
	dprintf(2, "-------- end --------\n");
}

void	move_right(t_game *game)// D key
{
	dprintf(2, "-------- move right --------\n");
	/*
	double	facing_direction;
	int	tmpX;
	int	tmpY;

	dprintf(2, "game->rows = %d\n", game->rows);
	dprintf(2, "game->cols = %d\n", game->cols);
	dprintf(2, "game->dirX = %f\n", game->dirX);
	dprintf(2, "game->dirY = %f\n", game->dirY);
	dprintf(2, "posX = %f\n", game->posX);
	dprintf(2, "posY = %f\n", game->posY);
	facing_direction = calculate_player_direction(game);
//	if ((int)(game->posX + 0.9) > 1)
//		dprintf(2, "ok1\n");
//	if (game->posX < game->rows)
//		dprintf(2, "ok2\n");
//	if ((int)(game->posY + 0.9) > 1)
//		dprintf(2, "ok3\n");
//	if (game->posY < game->cols)
//		dprintf(2, "ok4\n");
//	if (((int)(game->posX + 0.9) > 1) && (game->posX < game->rows)
//		&& ((int)(game->posY + 0.9) > 1) && (game->posY < game->cols))
	{
		tmpX = (int) (game->posX + cos(facing_direction - M_PI_2) * game->moveSpeed);
		tmpY = (int) (game->posY + sin(facing_direction - M_PI_2) * game->moveSpeed);
		dprintf(2, "1\n");
		dprintf(2, "tmpX = %d\n", tmpX);
		dprintf(2, "tmpY = %d\n", tmpY);
		if (!game->map[tmpX])
			return ;
		dprintf(2, "2\n");
		if (!game->map[tmpX][tmpY])
			return ;
		dprintf(2, "3\n");
		if (game->map[tmpX][tmpY] == '1')
		{
			dprintf(2, "MUR\n");
			return ;
		}
		dprintf(2, "4\n");
		if ((game->posX + cos(facing_direction - M_PI_2) * game->moveSpeed >= 1.1)
			&& (game->posX + cos(facing_direction - M_PI_2) * game->moveSpeed <= game->rows - 1.1))
			game->posX += cos(facing_direction - M_PI_2) * game->moveSpeed;
		if ((game->posY + sin(facing_direction - M_PI_2) * game->moveSpeed >= 1.1)
			&& (game->posY + sin(facing_direction - M_PI_2) * game->moveSpeed <= game->cols - 1.1))
			game->posY += sin(facing_direction - M_PI_2) * game->moveSpeed;
		dprintf(2, "posX = %f\n", game->posX);
		dprintf(2, "posY = %f\n", game->posY);
		dprintf(2, "5\n");
	}
	*/
	double	facing_direction;
	int	cellX;
	int	cellY;
	double	tmpX;
	double	tmpY;

	dprintf(2, "game->rows = %d\n", game->rows);
	dprintf(2, "game->cols = %d\n", game->cols);
	dprintf(2, "game->dirX = %f\n", game->dirX);
	dprintf(2, "game->dirY = %f\n", game->dirY);
	dprintf(2, "posX = %f\n", game->posX);
	dprintf(2, "posY = %f\n", game->posY);
	facing_direction = calculate_player_direction(game);
	cellX = (int) (game->posX + cos(facing_direction - M_PI_2));
	cellY = (int) (game->posY + sin(facing_direction - M_PI_2));
	tmpX = game->posX + cos(facing_direction - M_PI_2) * game->moveSpeed;
	tmpY = game->posY + sin(facing_direction - M_PI_2) * game->moveSpeed;
	dprintf(2, "cellX = %d\n", cellX);
	dprintf(2, "cellY = %d\n", cellY);
	dprintf(2, "tmpX = %f\n", tmpX);
	dprintf(2, "tmpY = %f\n", tmpY);
	dprintf(2, "avant boucle X\n");
	if ((tmpX >= 1.1) && (tmpX <= game->rows - 1.1))
	{
		dprintf(2, "boucle X\n");
//		dprintf(2, "game->map[cellX][cellY] = %c\n", game->map[cellX][cellY]);
		if ((int) tmpX == 1 || (int) tmpX == game->rows - 2)
		{
			dprintf(2, "X rebord\n");
			game->posX = tmpX;
		}
		if (game->map[cellX][cellY] == '0')
		{
			dprintf(2, "X inside sans mur\n");
//			dprintf(2, "game->map[%d][%d] = %c\n", cellX, cellY, game->map[cellX][cellY]);
			game->posX = tmpX;
		}
		else if (cellX < tmpX && fabs(tmpX - (cellX + 1)) > 0.1)
		{
			dprintf(2, "X inside dir -1\n");
//			dprintf(2, "fabs(tmpX - (cellX + 1)) = %f\n", fabs(tmpX - (cellX + 1)));
			game->posX = tmpX;
		}
		else if (cellX > tmpX && fabs(tmpX - (cellX - 1)) > 0.1)
		{
			dprintf(2, "X inside dir +1\n");
//			dprintf(2, "fabs(tmpX - (cellX - 1)) = %f\n", fabs(tmpX - (cellX - 1)));
			game->posX = tmpX;
		}
	}
	dprintf(2, "avant boucle Y\n");
	if ((tmpY >= 1.1) && (tmpY <= game->cols - 1.1))
	{
		dprintf(2, "boucle Y\n");
//		dprintf(2, "game->map[cellX][cellY] = %c\n", game->map[cellX][cellY]);
		if ((int) tmpY == 1 || (int) tmpY == game->cols - 2)
		{
			dprintf(2, "Y rebord\n");
			game->posY = tmpY;
		}
		if (game->map[cellX][cellY] == '0')
		{
			dprintf(2, "Y inside sans mur\n");
//			dprintf(2, "game->map[%d][%d] = %c\n", cellX, cellY, game->map[cellX][cellY]);
			game->posY = tmpY;
		}
//		else if ((cellY - tmpY) < 0 && fabs(tmpY - (cellY + 1)) > 0.1)
		else if (cellY - tmpY < 0.1)
		{
			dprintf(2, "cellY = %d\n", cellY);
			dprintf(2, "tmpY = %f\n", tmpY);
			dprintf(2, "Y inside dir -1\n");
			dprintf(2, "fabs(tmpY - (cellY + 1)) = %f\n", fabs(tmpY - (cellY + 1)));
			game->posY = tmpY;
		}
//		else if ((cellY - tmpY) > 0 && fabs(tmpY - (cellY - 1)) > 0.1)
		else if (cellY - tmpY > 0.1)
		{
			dprintf(2, "Y inside dir +1\n");
//			dprintf(2, "fabs(tmpY - (cellY - 1)) = %f\n", fabs(tmpY - (cellY - 1)));
			game->posY = tmpY;
		}
	}
	dprintf(2, "posX = %f\n", game->posX);
	dprintf(2, "posY = %f\n", game->posY);
	dprintf(2, "-------- end --------\n");
}