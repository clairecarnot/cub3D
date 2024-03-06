#include "../include/cub3D_bonus.h" 

void	perso(t_game *game)
{
	game->buf[39][39] = game->col_perso;
	game->buf[39][40] = game->col_perso;
	game->buf[39][41] = game->col_perso;
	game->buf[40][39] = game->col_perso;
	game->buf[40][40] = game->col_perso;
	game->buf[40][41] = game->col_perso;
	game->buf[41][39] = game->col_perso;
	game->buf[41][40] = game->col_perso;
	game->buf[41][41] = game->col_perso;
}

void	minimap(t_game *game)
{
	right_down(game, 39, 39);
	left_down(game, 39, 41);
	left_up(game, 41, 41);
	right_up(game, 41, 39);
	perso(game);
}
