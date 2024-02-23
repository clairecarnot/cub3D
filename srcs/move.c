#include "../include/cub3D.h"

double	calculate_player_direction(t_game *game)
{
	return (atan2(game->dirY, game->dirX));
}

void	move_up(t_game *game)// W key
{
	static int	i;
	int	tmpX;
	int	tmpY;

	tmpX = (int) round(game->posX + game->dirX * game->moveSpeed);
	tmpY = (int) round(game->posY + game->dirY * game->moveSpeed);
	dprintf(2, "i = %d\n", i);
	dprintf(2, "1\n");
	dprintf(2, "posX = %f\n", game->posX);
	dprintf(2, "posY = %f\n", game->posY);
	dprintf(2, "tmpX = %d\n", tmpX);
	dprintf(2, "tmpY = %d\n", tmpY);
	if (!game->map[tmpY])
		return ;
	dprintf(2, "2\n");
	if (!game->map[tmpY][tmpX])
		return ;
	dprintf(2, "3\n");
	if (game->map[tmpY][tmpX] == '1'
		&& ((double)tmpX - (game->posX + game->dirX * game->moveSpeed) <= 0))
	{
		dprintf(2, "diffX = %f\n", (double)tmpX - (game->posX + game->dirX * game->moveSpeed));
		return ;
	}
	if (game->map[tmpY][tmpX] == '1'
		&& ((double)tmpY - (game->posY + game->dirY * game->moveSpeed) <= 0))
	{
		dprintf(2, "diffY = %f\n", (double)tmpY - (game->posY + game->dirY * game->moveSpeed));
		return ;
	}
	dprintf(2, "4\n");
	game->posX += game->dirX * game->moveSpeed;
	game->posY += game->dirY * game->moveSpeed;
	dprintf(2, "posX = %f\n", game->posX);
	dprintf(2, "posY = %f\n", game->posY);
	i++;
	dprintf(2, "5\n");
}

void	move_down(t_game *game)// S key
{
	int	tmpX;
	int	tmpY;
	static int	j;

	tmpX = (int) round(game->posX - game->dirX * game->moveSpeed);
	tmpY = (int) round(game->posY - game->dirY * game->moveSpeed);
	dprintf(2, "j = %d\n", j);
	dprintf(2, "1\n");
	dprintf(2, "posX = %f\n", game->posX);
	dprintf(2, "posY = %f\n", game->posY);
	dprintf(2, "tmpX = %d\n", tmpX);
	dprintf(2, "tmpY = %d\n", tmpY);
	if (!game->map[tmpY])
		return ;
	dprintf(2, "2\n");
	if (!game->map[tmpY][tmpX])
		return ;
	dprintf(2, "3\n");
	if (game->map[tmpY][tmpX] == '1'
		&& ((double)tmpX - (game->posX - game->dirX * game->moveSpeed) <= 0))
	{
		dprintf(2, "diffX = %f\n", (double)tmpX - (game->posX - game->dirX * game->moveSpeed));
		return ;
	}
	if (game->map[tmpY][tmpX] == '1'
		&& ((double)tmpY - (game->posY - game->dirY * game->moveSpeed) <= 0))
	{
		dprintf(2, "diffY = %f\n", (double)tmpY - (game->posY - game->dirY * game->moveSpeed));
		return ;
	}
	dprintf(2, "4\n");
	game->posX -= game->dirX * game->moveSpeed;
	game->posY -= game->dirY * game->moveSpeed;
	dprintf(2, "posX = %f\n", game->posX);
	dprintf(2, "posY = %f\n", game->posY);
	j++;
	dprintf(2, "5\n");
}

//************************ICI**********************************
void	move_left(t_game *game)// A key
{
	double	facing_direction;
	int	tmpX;
	int	tmpY;
	static int	k;

	facing_direction = calculate_player_direction(game);
	tmpX = (int) round(game->posX + cos(facing_direction + M_PI_2) * game->moveSpeed);
	tmpY = (int) round(game->posY + sin(facing_direction + M_PI_2) * game->moveSpeed);
	int z = 0;
	while (game->map[tmpY][z])
	{
		dprintf(2, "%c", game->map[tmpY][z]);
		z++;
	}
	dprintf(2, "\n");
	dprintf(2, "k = %d\n", k);
	dprintf(2, "1\n");
	dprintf(2, "posX = %f\n", game->posX);
	dprintf(2, "posY = %f\n", game->posY);
	dprintf(2, "tmpX = %d\n", tmpX);
	dprintf(2, "tmpY = %d\n", tmpY);
	if (!game->map[tmpY])
		return ;
	dprintf(2, "2\n");
	if (!game->map[tmpY][tmpX])
		return ;
	dprintf(2, "3\n");
	if (game->map[tmpY][tmpX] == '1'
		&& ((double)tmpX - (game->posX + cos(facing_direction + M_PI_2) * game->moveSpeed) <= 0))
	{
		dprintf(2, "diffX = %f\n", (double)tmpX - (game->posX + cos(facing_direction + M_PI_2) * game->moveSpeed));
		return ;
	}
	if (game->map[tmpY][tmpX] == '1'
		&& ((double)tmpY - (game->posY + sin(facing_direction + M_PI_2) * game->moveSpeed) <= 0))
	{
		dprintf(2, "diffY = %f\n", (double)tmpY - (game->posY + sin(facing_direction + M_PI_2) * game->moveSpeed));
		return ;
	}
	dprintf(2, "4\n");
	game->posX += cos(facing_direction + M_PI_2) * game->moveSpeed;
	game->posY += sin(facing_direction + M_PI_2) * game->moveSpeed;
	dprintf(2, "posX = %f\n", game->posX);
	dprintf(2, "posY = %f\n", game->posY);
	k++;
	dprintf(2, "5\n");

}

void	move_right(t_game *game)// D key
{
	// char	charX;
	// char	charY;
	double	facing_direction;

	facing_direction = calculate_player_direction(game);

	// charX = game->map[(int)game->posY][(int)(game->posX + cos(facing_direction - M_PI_2) * game->moveSpeed)];
	// charY = game->map[(int)(game->posY + sin(facing_direction - M_PI_2) * game->moveSpeed)][(int)game->posX];

	game->posX += cos(facing_direction - M_PI_2) * game->moveSpeed;
	game->posY += sin(facing_direction - M_PI_2) * game->moveSpeed;

	// game->posY -= game->planeY * game->moveSpeed;//va a gauche mais se decale quand rotate
	// game->posX += game->planeX * game->moveSpeed;
}
