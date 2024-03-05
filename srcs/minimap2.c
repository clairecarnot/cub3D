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
			{
				if (game->map[(int)(game->p_y)][(int)(game->p_x)] == '0'
					|| game->map[(int)(game->p_y)][(int)(game->p_x)] == 'd')
					game->buf[y][x] = game->col_floor;
				else if (game->map[(int)(game->p_y)][(int)(game->p_x)] == '1')
					game->buf[y][x] = game->col_wall;
				else if (game->map[(int)(game->p_y)][(int)(game->p_x)] == 'D')
					game->buf[y][x] = game->col_door;
				else if (game->map[(int)(game->p_y)][(int)(game->p_x)] == 'A')
				{
					// if (y % 10 == 0 && x % 10 == 0)
						game->buf[y][x] = game->col_anim;
					// else
					// 	game->buf[y][x] = game->col_floor;
				}
				else
					game->buf[y][x] = game->col_wall;
			}
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
			{
				if (game->map[(int)(game->p_y)][(int)(game->p_x)] == '0'
					|| game->map[(int)(game->p_y)][(int)(game->p_x)] == 'd')
					game->buf[y][x] = game->col_floor;
				else if (game->map[(int)(game->p_y)][(int)(game->p_x)] == '1')
					game->buf[y][x] = game->col_wall;
				else if (game->map[(int)(game->p_y)][(int)(game->p_x)] == 'D')
					game->buf[y][x] = game->col_door;
				else if (game->map[(int)(game->p_y)][(int)(game->p_x)] == 'A')
				{
					// if (y % 10 == 0 && x % 10 == 0)
						game->buf[y][x] = game->col_anim;
					// else
					// 	game->buf[y][x] = game->col_floor;
				}
				else
					game->buf[y][x] = game->col_wall;
			}
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
			{
				if (game->map[(int)(game->p_y)][(int)(game->p_x)] == '0'
					|| game->map[(int)(game->p_y)][(int)(game->p_x)] == 'd')
					game->buf[y][x] = game->col_floor;
				else if (game->map[(int)(game->p_y)][(int)(game->p_x)] == '1')
					game->buf[y][x] = game->col_wall;
				else if (game->map[(int)(game->p_y)][(int)(game->p_x)] == 'D')
					game->buf[y][x] = game->col_door;
				else if (game->map[(int)(game->p_y)][(int)(game->p_x)] == 'A')
				{
					// if (y % 10 == 0 && x % 10 == 0)
						game->buf[y][x] = game->col_anim;
					// else
					// 	game->buf[y][x] = game->col_floor;
				}
				else
					game->buf[y][x] = game->col_wall;
			}
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
			{
				if (game->map[(int)(game->p_y)][(int)(game->p_x)] == '0'
					|| game->map[(int)(game->p_y)][(int)(game->p_x)] == 'd')
					game->buf[y][x] = game->col_floor;
				else if (game->map[(int)(game->p_y)][(int)(game->p_x)] == '1')
					game->buf[y][x] = game->col_wall;
				else if (game->map[(int)(game->p_y)][(int)(game->p_x)] == 'D')
					game->buf[y][x] = game->col_door;
				else if (game->map[(int)(game->p_y)][(int)(game->p_x)] == 'A')
				{
					// dprintf(2, "x = %d, y + %d\n", x, y);
					// if (y % 10 == 0 && x % 10 == 0)
					// {
					// 	dprintf(2, "hey\n");
						game->buf[y][x] = game->col_anim;
					// }
					// else
					// 	game->buf[y][x] = game->col_floor;
				}
				else
					game->buf[y][x] = game->col_wall;
			}
			else
				game->buf[y][x] = game->col_wall;
			game->p_x += 0.1;
		}
		game->p_y -= 0.1;
	}
}
