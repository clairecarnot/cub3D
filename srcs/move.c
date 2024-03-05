#include "../include/cub3D.h"

double	calculate_player_direction(t_game *game)
{
	return (atan2(game->dirY, game->dirX));
}

void	move_up(t_game *game)
{
	char	new_posx;
	char	new_posy;

	new_posx = game->map[(int)(game->posX + game->dirX
			* (game->moveSpeed + 0.01))][(int)(game->posY)];
	new_posy = game->map[(int)(game->posX)][(int)(game->posY
			+ game->dirY * (game->moveSpeed + 0.01))];
	if (new_posx != '1' && new_posx != 'D')
		game->posX += game->dirX * game->moveSpeed;
	if (new_posy != '1' && new_posy != 'D')
		game->posY += game->dirY * game->moveSpeed;
}

void	move_down(t_game *game)
{
	char	new_posx;
	char	new_posy;

	new_posx = game->map[(int)(game->posX - game->dirX
			* (game->moveSpeed + 0.01))][(int)(game->posY)];
	new_posy = game->map[(int)(game->posX)][(int)(game->posY
			- game->dirY * (game->moveSpeed + 0.01))];
	if (new_posx != '1' && new_posx != 'D')
		game->posX -= game->dirX * game->moveSpeed;
	if (new_posy != '1' && new_posy != 'D')
		game->posY -= game->dirY * game->moveSpeed;
}

void	move_left(t_game *game)
{
	char	new_posx;
	char	new_posy;
	double	facing_direction;

	facing_direction = calculate_player_direction(game);
	new_posx = game->map[(int)(game->posX + cos(facing_direction + M_PI_2)
			* (game->moveSpeed + 0.01))][(int)(game->posY)];
	new_posy = game->map[(int)(game->posX)][(int)(game->posY
			+ sin(facing_direction + M_PI_2) * (game->moveSpeed + 0.01))];
	if (new_posx != '1' && new_posx != 'D')
		game->posX += cos(facing_direction + M_PI_2) * game->moveSpeed;
	if (new_posy != '1' && new_posy != 'D')
		game->posY += sin(facing_direction + M_PI_2) * game->moveSpeed;
}

void	move_right(t_game *game)
{
	char	new_posx;
	char	new_posy;
	double	facing_direction;

	facing_direction = calculate_player_direction(game);
	new_posx = game->map[(int)(game->posX + cos(facing_direction - M_PI_2)
			* (game->moveSpeed + 0.01))][(int)(game->posY)];
	new_posy = game->map[(int)(game->posX)][(int)(game->posY
			+ sin(facing_direction - M_PI_2) * (game->moveSpeed + 0.01))];
	if (new_posx != '1' && new_posx != 'D')
		game->posX += cos(facing_direction - M_PI_2) * game->moveSpeed;
	if (new_posy != '1' && new_posy != 'D')
		game->posY += sin(facing_direction - M_PI_2) * game->moveSpeed;
}
