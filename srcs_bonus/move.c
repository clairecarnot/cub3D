#include "../include/cub3D.h"

double	calculate_player_direction(t_game *game)
{
	return (atan2(game->dirY, game->dirX));
}

void	move_up(t_game *game)// W key
{
	// char	charX;
	// char	charY;
	//charX et charY prenne la valeur de la case ou se trouvera le joueur apres avoir
	//fait les deplacement qui suivent, si char = 1 c'est qu'on va dans un mur donc
	//on fait les deplacements 
	// charX = game->map[(int)(game->posY)][(int)(game->posX + game->dirX * game->moveSpeed)];
	// charY = game->map[(int)(game->posY - game->dirY * (game->moveSpeed))][(int)(game->posX)];

	// if (charX != '1')
		game->posX += game->dirX * game->moveSpeed;
	// if (charY != '1')
		game->posY += game->dirY * game->moveSpeed;
}

void	move_down(t_game *game)// S key
{
	// char	charX;
	// char	charY;

	// charX = game->map[(int)(game->posY)][(int)(game->posX - game->dirX * (game->moveSpeed))];
	// charY = game->map[(int)(game->posY + game->dirY * (game->moveSpeed))][(int)(game->posX)];

	// if (charX != '1')
		game->posX -= game->dirX * game->moveSpeed;
	// if (charY != '1')
		game->posY -= game->dirY * game->moveSpeed;
}

void	move_left(t_game *game)// A key
{
	// char	charX;
	// char	charY;
	double	facing_direction;

	facing_direction = calculate_player_direction(game);

	// charX = game->map[(int)game->posY][(int)(game->posX + cos(facing_direction + M_PI_2) * game->moveSpeed)];
	// charY = game->map[(int)(game->posY + sin(facing_direction + M_PI_2) * game->moveSpeed)][(int)game->posX];

	game->posX += cos(facing_direction + M_PI_2) * game->moveSpeed;
	game->posY += sin(facing_direction + M_PI_2) * game->moveSpeed;

	// game->posY += game->planeY * game->moveSpeed;
	// game->posX -= game->planeX * game->moveSpeed;
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
