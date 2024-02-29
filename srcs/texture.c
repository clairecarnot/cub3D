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
	while (y < game->screen_h)
	{
		// dprintf(2, "y = %d, x = %d\n", y, x);
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

//------------------------------------ bonus -------------------------------------//
void	draw_box(t_game *game, int color, int x, int y)
{
	int	tmp_x;
	int	tmp_y;
	
	tmp_x = x;
	tmp_y = y;

	int yy = y * 10 + 10;//20
	int	xx = x * 10 + 10;//20

	y = tmp_y * 10;//10
	
	// point de reference a x = 35, y = 35 
	// position du joueur par ex map[y] = 6, map[x] = 7

	// dprintf(2, "x = %d, xx = %d\n", x, xx);
	// dprintf(2, "y = %d, yy = %d\n", y, yy);		
	while (y < yy && y < 70)
	{
		// dprintf(2, "-y = %d\n", y);
		x = tmp_x * 10;//10
		while (x < xx && x < 70)
		{
			// dprintf(2, "-x = %d\n", x);
			game->buf[x][y] = color;
			x++;
		}
		y++;
	}
}

void	perso(t_game *game)
{
	game->buf[34][34] = game->col_perso;
	game->buf[34][35] = game->col_perso;
	game->buf[34][36] = game->col_perso;
	game->buf[35][34] = game->col_perso;
	game->buf[35][35] = game->col_perso;
	game->buf[35][36] = game->col_perso;
	game->buf[36][34] = game->col_perso;
	game->buf[36][35] = game->col_perso;
	game->buf[36][36] = game->col_perso;
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
	y = 35;
	while (y < 70)
	{
		x = 35;
		game->pX = game->posY;
		while (x < 70)
		{
			//dprintf(2, "right down .....pY = %f, .....pX = %f\n", game->pY, game->pX);
			//dprintf(2, "right down (int)pY = %d, (int)pX = %d\n", (int)game->pY, (int)game->pX);
			//dprintf(2, "right down ......y = %d, ......x = %d\n", y, x);			
			if (game->map && game->map[(int)(game->pY)] && game->map[(int)(game->pY)][(int)(game->pX)] && game->map[(int)(game->pY)][(int)(game->pX)] == '0')
			{
				game->buf[y][x] = game->col_floor;
			}
			if (game->map && game->map[(int)(game->pY)] && game->map[(int)(game->pY)][(int)(game->pX)] && game->map[(int)(game->pY)][(int)(game->pX)] == '1')
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
	y = 35;
	while (y < 70)
	{
		x = 35;
		game->pX = game->posY;
		while (x > 0)
		{
			//dprintf(2, "left down .....pY = %f, .....pX = %f\n", game->pY, game->pX);
			//dprintf(2, "left down (int)pY = %d, (int)pX = %d\n", (int)game->pY, (int)game->pX);
			//dprintf(2, "left down ......y = %d, ......x = %d\n", y, x);			
			if (game->map && game->map[(int)(game->pY)] && game->map[(int)(game->pY)][(int)(game->pX)] && game->map[(int)(game->pY)][(int)(game->pX)] == '0')
			{
				game->buf[y][x] = game->col_floor;
			}
			if (game->map && game->map[(int)(game->pY)] && game->map[(int)(game->pY)][(int)(game->pX)] && game->map[(int)(game->pY)][(int)(game->pX)] == '1')
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
	y = 35;
	while (y > 0)
	{
		x = 35;
		game->pX = game->posY;
		while (x > 0)
		{
			//dprintf(2, "left up .....pY = %f, .....pX = %f\n", game->pY, game->pX);
			//dprintf(2, "left up (int)pY = %d, (int)pX = %d\n", (int)game->pY, (int)game->pX);
			//dprintf(2, "left up ......y = %d, ......x = %d\n", y, x);			
			if (game->map && game->map[(int)(game->pY)] && game->map[(int)(game->pY)][(int)(game->pX)] && game->map[(int)(game->pY)][(int)(game->pX)] == '0')
			{
				game->buf[y][x] = game->col_floor;
			}
			if (game->map && game->map[(int)(game->pY)] && game->map[(int)(game->pY)][(int)(game->pX)] && game->map[(int)(game->pY)][(int)(game->pX)] == '1')
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
	y = 35;
	while (y > 0)
	{
		x = 35;
		game->pX = game->posY;
		while (x < 70)
		{
			//dprintf(2, "right up .....pY = %f, .....pX = %f\n", game->pY, game->pX);
			//dprintf(2, "right up (int)pY = %d, (int)pX = %d\n", (int)game->pY, (int)game->pX);
			//dprintf(2, "right up ......y = %d, ......x = %d\n", y, x);			
			if (game->map && game->map[(int)(game->pY)] && game->map[(int)(game->pY)][(int)(game->pX)] && game->map[(int)(game->pY)][(int)(game->pX)] == '0')
			{
				game->buf[y][x] = game->col_floor;
			}
			if (game->map && game->map[(int)(game->pY)] && game->map[(int)(game->pY)][(int)(game->pX)] && game->map[(int)(game->pY)][(int)(game->pX)] == '1')
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

void	draw_box_middle(t_game *game)
{
	(void)game;
	// right_down(game);
	// left_down(game);
	// left_up(game);
	// right_up(game);
	// perso(game);
	
}

void	draw_perso(t_game *game, int color, int x, int y)
{
	int	tmp_x;
	int	tmp_y;
	
	tmp_x = x;
	tmp_y = y;

	int yy = y * 10 + 10 - 3;//20
	int	xx = x * 10 + 10 - 3;//20

	y = tmp_y * 10 + 3;//10
	
	// point de reference a x = 35, y = 35 
	// position du joueur par ex map[y] = 6, map[x] = 7

	// dprintf(2, "x = %d, xx = %d\n", x, xx);
	// dprintf(2, "y = %d, yy = %d\n", y, yy);		
	while (y < yy && y < 70)
	{
		// dprintf(2, "-y = %d\n", y);
		x = tmp_x * 10 + 3;//10
		while (x < xx && x < 70)
		{
			// dprintf(2, "-x = %d\n", x);
			game->buf[x][y] = color;
			x++;
		}
		y++;
	}
}

void	minimap(t_game *game)
{
	/*int y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
			{
				// dprintf(2, "< 1 > x = %d, y = %d\n", x, y);
				draw_box(game, game->col_wall, y, x);
			}
			if (game->map[y][x] == '0' || game->map[y][x] == 'N' ||
				game->map[y][x] == 'S' || game->map[y][x] == 'E' ||
				game->map[y][x] == 'W')
			{
				// dprintf(2, "< 0 > x = %d, y = %d\n", x, y);
				draw_box(game, game->col_floor, y, x);
			}
			if (game->map[y][x] == 'N' || game->map[y][x] == 'S' ||
				game->map[y][x] == 'E' || game->map[y][x] == 'W')
			{
				draw_perso(game, game->col_perso, y, x);
			}
			x++;
		}
		y++;
	}*/
	draw_box_middle(game);
}