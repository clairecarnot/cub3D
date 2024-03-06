#include "../include/cub3D.h"

void	right_down(t_game *game, int y, int x)
{
	game->pY = game->pos_x + 0;
	game->pX = game->pos_y + 0;
	while (++y < 75)
	{
		x = 39;
		game->pX = game->pos_y;
		while (++x < 75)
		{			
			if (game->pY >= 0 && game->pX >= 0
				&& game->pY < game->rows && game->pX < game->cols)
			{
				if (game->map[(int)(game->pY)][(int)(game->pX)] == '0'
					|| game->map[(int)(game->pY)][(int)(game->pX)] == 'd')
					game->buf[y][x] = game->col_floor;
				else if (game->map[(int)(game->pY)][(int)(game->pX)] == '1')
					game->buf[y][x] = game->col_wall;
				else if (game->map[(int)(game->pY)][(int)(game->pX)] == 'D')
					game->buf[y][x] = game->col_door;
				else
					game->buf[y][x] = game->col_wall;
			}
			else
				game->buf[y][x] = game->col_wall;
			game->pX += 0.1;
		}
		game->pY += 0.1;
	}
}

void	left_down(t_game *game, int y, int x)
{
	game->pY = game->pos_x + 0;
	game->pX = game->pos_y + 0;
	while (++y < 75)
	{
		x = 41;
		game->pX = game->pos_y;
		while (--x > 5)
		{	
			if (game->pY >= 0 && game->pX >= 0
				&& game->pY < game->rows && game->pX < game->cols)
			{
				if (game->map[(int)(game->pY)][(int)(game->pX)] == '0'
					|| game->map[(int)(game->pY)][(int)(game->pX)] == 'd')
					game->buf[y][x] = game->col_floor;
				else if (game->map[(int)(game->pY)][(int)(game->pX)] == '1')
					game->buf[y][x] = game->col_wall;
				else if (game->map[(int)(game->pY)][(int)(game->pX)] == 'D')
					game->buf[y][x] = game->col_door;
				else
					game->buf[y][x] = game->col_wall;
			}
			else
				game->buf[y][x] = game->col_wall;
			game->pX -= 0.1;
		}
		game->pY += 0.1;
	}
}

void	left_up(t_game *game, int y, int x)
{
	game->pY = game->pos_x + 0;
	game->pX = game->pos_y + 0;
	while (--y > 5)
	{
		x = 41;
		game->pX = game->pos_y;
		while (--x > 5)
		{		
			if (game->pY >= 0 && game->pX >= 0
				&& game->pY < game->rows && game->pX < game->cols)
			{
				if (game->map[(int)(game->pY)][(int)(game->pX)] == '0'
					|| game->map[(int)(game->pY)][(int)(game->pX)] == 'd')
					game->buf[y][x] = game->col_floor;
				else if (game->map[(int)(game->pY)][(int)(game->pX)] == '1')
					game->buf[y][x] = game->col_wall;
				else if (game->map[(int)(game->pY)][(int)(game->pX)] == 'D')
					game->buf[y][x] = game->col_door;
				else
					game->buf[y][x] = game->col_wall;
			}
			else
				game->buf[y][x] = game->col_wall;
			game->pX -= 0.1;
		}
		game->pY -= 0.1;
	}
}

void	right_up(t_game *game, int y, int x)
{
	game->pY = game->pos_x + 0;
	game->pX = game->pos_y + 0;
	while (--y > 5)
	{
		x = 39;
		game->pX = game->pos_y;
		while (++x < 75)
		{			
			if (game->pY >= 0 && game->pX >= 0
				&& game->pY < game->rows && game->pX < game->cols)
			{
				if (game->map[(int)(game->pY)][(int)(game->pX)] == '0'
					|| game->map[(int)(game->pY)][(int)(game->pX)] == 'd')
					game->buf[y][x] = game->col_floor;
				else if (game->map[(int)(game->pY)][(int)(game->pX)] == '1')
					game->buf[y][x] = game->col_wall;
				else if (game->map[(int)(game->pY)][(int)(game->pX)] == 'D')
					game->buf[y][x] = game->col_door;
				else
					game->buf[y][x] = game->col_wall;
			}
			else
				game->buf[y][x] = game->col_wall;
			game->pX += 0.1;
		}
		game->pY -= 0.1;
	}
}
