#include "../include/cub3D.h"

void	right_down(t_game *game, int y, int x)
{
	game->p_y = game->pos_x + 0;
	game->p_x = game->pos_y + 0;
	while (++y < 75)
	{
		x = 39;
		game->p_x = game->pos_y;
		while (++x < 75)
		{			
			if (game->p_y >= 0 && game->p_x >= 0
				&& game->p_y < game->rows && game->p_x < game->cols)
				right_down_2(game, y, x);
			else
				game->buf[y][x] = game->col_wall;
			game->p_x += 0.1;
		}
		game->p_y += 0.1;
	}
}

void	left_down(t_game *game, int y, int x)
{
	game->p_y = game->pos_x + 0;
	game->p_x = game->pos_y + 0;
	while (++y < 75)
	{
		x = 41;
		game->p_x = game->pos_y;
		while (--x > 5)
		{	
			if (game->p_y >= 0 && game->p_x >= 0
				&& game->p_y < game->rows && game->p_x < game->cols)
				left_down_2(game, y, x);
			else
				game->buf[y][x] = game->col_wall;
			game->p_x -= 0.1;
		}
		game->p_y += 0.1;
	}
}

void	left_up(t_game *game, int y, int x)
{
	game->p_y = game->pos_x + 0;
	game->p_x = game->pos_y + 0;
	while (--y > 5)
	{
		x = 41;
		game->p_x = game->pos_y;
		while (--x > 5)
		{		
			if (game->p_y >= 0 && game->p_x >= 0
				&& game->p_y < game->rows && game->p_x < game->cols)
				left_up_2(game, y, x);
			else
				game->buf[y][x] = game->col_wall;
			game->p_x -= 0.1;
		}
		game->p_y -= 0.1;
	}
}

void	right_up(t_game *game, int y, int x)
{
	game->p_y = game->pos_x + 0;
	game->p_x = game->pos_y + 0;
	while (--y > 5)
	{
		x = 39;
		game->p_x = game->pos_y;
		while (++x < 75)
		{			
			if (game->p_y >= 0 && game->p_x >= 0
				&& game->p_y < game->rows && game->p_x < game->cols)
				right_up_2(game, y, x);
			else
				game->buf[y][x] = game->col_wall;
			game->p_x += 0.1;
		}
		game->p_y -= 0.1;
	}
}
