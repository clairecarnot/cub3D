#include "../include/cub3D.h"

void	rotate_right(t_game *game, double mult)
{
	double	rad;
	double	d_x;
	double	p_x;

	rad = (mult * 3.14159265358979323846) / 180;
	d_x = game->dir_x;
	p_x = game->plane_x;
	game->dir_x = game->dir_x * cos(rad) - game->dir_y * sin(rad);
	game->dir_y = d_x * sin(rad) + game->dir_y * cos(rad);
	game->plane_x = game->plane_x * cos(rad) - game->plane_y * sin(rad);
	game->plane_y = p_x * sin(rad) + game->plane_y * cos(rad);
}

void	rotate_left(t_game *game, double mult)
{
	double	rad;
	double	d_x;
	double	p_x;

	rad = (mult * 3.14159265358979323846) / 180;
	d_x = game->dir_x;
	p_x = game->plane_x;
	game->dir_x = game->dir_x * cos(rad) - game->dir_y * sin(rad);
	game->dir_y = d_x * sin(rad) + game->dir_y * cos(rad);
	game->plane_x = game->plane_x * cos(rad) - game->plane_y * sin(rad);
	game->plane_y = p_x * sin(rad) + game->plane_y * cos(rad);
}
