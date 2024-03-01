#include "../include/cub3D.h"

int	get_color(int *tab_c)
{
	unsigned int	hexa_color;

	hexa_color = ((unsigned int)tab_c[0] << 16 | \
	(unsigned int)tab_c[1] << 8 | (unsigned int)tab_c[2]);
	return (hexa_color);
}

void	pixel_color_ceiling_floor(t_game *game, int x)
{
	int	y;

	y = 0;
	game->f_color = get_color(game->f);
	game->c_color = get_color(game->c);
	while (y < game->drawStart)
	{
		game->buf[y][x] = game->c_color;
		y++;
	}
	y = game->drawEnd;
	// dprintf(2, "x = %d\n", x);
	while (y < game->screen_h && y >= 0)
	{
		// dprintf(2, "y = %d, x = %d\n", y, x);
		if (x < game->screen_w)
			game->buf[y][x] = game->f_color;
		y++;
	}
}

void	pixel_color_walls(t_game *game, int x)
{
	int				y;
	unsigned int	color;

	y = game->drawStart;
	while (y < game->drawEnd)
	{
		game->texY = (int)game->texPos & (game->tex_h - 1);
		game->texPos += game->step;
		color = game->tex[game->texNum][game->tex_h * game->texY + game->texX];
		game->buf[y][x] = color;
		y++;
	}
}

void	texture_wall_orientation(t_game *game)
{
	if (game->side == 0)
	{
		if (game->stepX == 1)
			game->texNum = 1;
		else if (game->stepX == -1)
			game->texNum = 0;
	}
	else if (game->side == 1)
	{
		if (game->stepY == 1)
			game->texNum = 2;
		else if (game->stepY == -1)
			game->texNum = 3;
	}
}

void	texture(t_game *game, int x)
{
	game->texX = 0;
	game->texY = 0;
	if (game->side == 0)
		game->wallX = game->posY + game->perpWallDist * game->rayDirY;
	else
		game->wallX = game->posX + game->perpWallDist * game->rayDirX;
	game->wallX -= floor(game->wallX);
	game->texX = (int)(game->wallX * (double)(game->tex_w));
	if (game->side == 0 && game->rayDirX > 0)
		game->texX = game->tex_w - game->texX - 1;
	if (game->side == 1 && game->rayDirY < 0)
		game->texX = game->tex_w - game->texX - 1;
	game->step = 1.0 * game->tex_h / game->lineHeight;
	game->texPos = (game->drawStart /*- game->pitch*/
			- game->screen_h / 2 + game->lineHeight / 2) * game->step;
	texture_wall_orientation(game);
	pixel_color_walls(game, x);
	pixel_color_ceiling_floor(game, x);
}

//------------------------------------ bonus minimap -------------------------------------//

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

void	right_down(t_game *game)
{
	int	y;
	int	x;
//	double	pX;
//	double	pY;

	game->pY = game->posX + 0;
	game->pX = game->posY + 0;
	(void) game;
	y = 40;
	while (y < 75)
	{
		x = 40;
		game->pX = game->posY;
		while (x < 75)
		{
			// dprintf(2, "right down .....pY = %f, .....pX = %f\n", game->pY, game->pX);
			// dprintf(2, "right down (int)pY = %d, (int)pX = %d\n", (int)game->pY, (int)game->pX);
			// dprintf(2, "right down ......y = %d, ......x = %d\n", y, x);			
			if (game->pY >= 0 && game->pX >= 0 && 
				game->pY < game->rows && game->pX < game->cols)
			{
				if (game->map && game->map[(int)(game->pY)] && game->map[(int)(game->pY)][(int)(game->pX)] && game->map[(int)(game->pY)][(int)(game->pX)] == '0')
				{
					game->buf[y][x] = game->col_floor;
				}
				else if (game->map && game->map[(int)(game->pY)] && game->map[(int)(game->pY)][(int)(game->pX)] && game->map[(int)(game->pY)][(int)(game->pX)] == '1')
				{
					game->buf[y][x] = game->col_wall;
				}
				else
				{
					game->buf[y][x] = game->col_wall;
				}
			}
			else
			{
				game->buf[y][x] = game->col_wall;
			}
			game->pX += 0.1;
			x++;
		}
		game->pY += 0.1;
		y++;
	}
}

void	left_down(t_game *game)
{
	int	y;
	int	x;
//	double	pX;
//	double	pY;

	game->pY = game->posX + 0;
	game->pX = game->posY + 0;
	(void) game;
	y = 40;
	while (y < 75)
	{
		x = 40;
		game->pX = game->posY;
		while (x > 5)
		{
			//dprintf(2, "left down .....pY = %f, .....pX = %f\n", game->pY, game->pX);
			//dprintf(2, "left down (int)pY = %d, (int)pX = %d\n", (int)game->pY, (int)game->pX);
			//dprintf(2, "left down ......y = %d, ......x = %d\n", y, x);			
			if (game->pY >= 0 && game->pX >= 0 && 
				game->pY < game->rows && game->pX < game->cols)
			{
				if (game->map && game->map[(int)(game->pY)] && game->map[(int)(game->pY)][(int)(game->pX)] && game->map[(int)(game->pY)][(int)(game->pX)] == '0')
				{
					game->buf[y][x] = game->col_floor;
				}
				else if (game->map && game->map[(int)(game->pY)] && game->map[(int)(game->pY)][(int)(game->pX)] && game->map[(int)(game->pY)][(int)(game->pX)] == '1')
				{
					game->buf[y][x] = game->col_wall;
				}
				else
					game->buf[y][x] = game->col_wall;
			}
			else
			{
				game->buf[y][x] = game->col_wall;
			}
			game->pX -= 0.1;
			x--;
		}
		game->pY += 0.1;
		y++;
	}
}

void	left_up(t_game *game)
{
	int	y;
	int	x;
//	double	pX;
//	double	pY;

	game->pY = game->posX + 0;
	game->pX = game->posY + 0;
	(void) game;
	y = 40;
	while (y > 5)
	{
		x = 40;
		game->pX = game->posY;
		while (x > 5)
		{
			//dprintf(2, "left up .....pY = %f, .....pX = %f\n", game->pY, game->pX);
			//dprintf(2, "left up (int)pY = %d, (int)pX = %d\n", (int)game->pY, (int)game->pX);
			//dprintf(2, "left up ......y = %d, ......x = %d\n", y, x);			
			if (game->pY >= 0 && game->pX >= 0 && 
				game->pY < game->rows && game->pX < game->cols)
			{
				if (game->map && game->map[(int)(game->pY)] && game->map[(int)(game->pY)][(int)(game->pX)] && game->map[(int)(game->pY)][(int)(game->pX)] == '0')
				{
					game->buf[y][x] = game->col_floor;
				}
				else if (game->map && game->map[(int)(game->pY)] && game->map[(int)(game->pY)][(int)(game->pX)] && game->map[(int)(game->pY)][(int)(game->pX)] == '1')
				{
					game->buf[y][x] = game->col_wall;
				}
				else
					game->buf[y][x] = game->col_wall;
			}
			else
			{
				game->buf[y][x] = game->col_wall;
			}
			game->pX -= 0.1;
			x--;
		}
		game->pY -= 0.1;
		y--;
	}
}

void	right_up(t_game *game)
{
	int	y;
	int	x;
//	double	pX;
//	double	pY;

	game->pY = game->posX + 0;
	game->pX = game->posY + 0;
	(void) game;
	y = 40;
	while (y > 5)
	{
		x = 40;
		game->pX = game->posY;
		while (x < 75)
		{
			//dprintf(2, "right up .....pY = %f, .....pX = %f\n", game->pY, game->pX);
			//dprintf(2, "right up (int)pY = %d, (int)pX = %d\n", (int)game->pY, (int)game->pX);
			//dprintf(2, "right up ......y = %d, ......x = %d\n", y, x);			
			if (game->pY >= 0 && game->pX >= 0 && 
				game->pY < game->rows && game->pX < game->cols)
			{
				if (game->map && game->map[(int)(game->pY)] && game->map[(int)(game->pY)][(int)(game->pX)] && game->map[(int)(game->pY)][(int)(game->pX)] == '0')
				{
					game->buf[y][x] = game->col_floor;
				}
				else if (game->map && game->map[(int)(game->pY)] && game->map[(int)(game->pY)][(int)(game->pX)] && game->map[(int)(game->pY)][(int)(game->pX)] == '1')
				{
					game->buf[y][x] = game->col_wall;
				}
				else
					game->buf[y][x] = game->col_wall;
			}
			else
			{
				game->buf[y][x] = game->col_wall;
			}
			game->pX += 0.1;
			x++;
		}
		game->pY -= 0.1;
		y--;
	}
}

void	minimap(t_game *game)
{
	(void)game;
	right_down(game);
	left_down(game);
	left_up(game);
	right_up(game);
	perso(game);
}