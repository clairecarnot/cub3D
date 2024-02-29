#include "../include/cub3D.h"

int	init_buf(t_game *game)
{
	int	y;

	y = 0;
	game->buf = ft_calloc(sizeof(unsigned int *), game->screen_h);
	if (!game->buf)
		(free_game(game), exit(1));
	while (y < game->screen_h)
	{
		game->buf[y] = ft_calloc(sizeof(unsigned int), game->screen_w);
		if (!game->buf[y])
			(free_game(game), exit(1));
		y++;
	}
	return (0);
}

void	wall_size(t_game *game)
{
	if (game->side == 0)
		game->perpWallDist = (game->sideDistX - game->deltaDistX);
	else
		game->perpWallDist = (game->sideDistY - game->deltaDistY);
	game->lineHeight = (int)(game->screen_h / game->perpWallDist);
	// game->pitch = 100;
	game->drawStart = - game->lineHeight / 2 + game->screen_h / 2 /*+ game->pitch*/;
	if (game->drawStart < 0)
		game->drawStart = 0;
	game->drawEnd = game->lineHeight / 2 + game->screen_h / 2 /*+ game->pitch*/;
	if (game->drawEnd >= game->screen_h)
		game->drawEnd = game->screen_h - 1;
}

void	dda_algo(t_game *game)
{
	while (game->hit == 0)
	{
		if (game->sideDistX < game->sideDistY)
		{
			game->sideDistX += game->deltaDistX;
			game->mapX += game->stepX;
			game->side = 0;
		}
		else
		{
			game->sideDistY += game->deltaDistY;
			game->mapY += game->stepY;
			game->side = 1;
		}
		if (game->map[game->mapX][game->mapY] == '1')
			game->hit = 1;
	}
}

void	init_side(t_game *game)
{
	game->hit = 0;
	if (game->rayDirX < 0)
	{
		game->stepX = -1;
		game->sideDistX = (game->posX - game->mapX) * game->deltaDistX;
	}
	else
	{
		game->stepX = 1;
		game->sideDistX = (game->mapX + 1.0 - game->posX) * game->deltaDistX;
	}
	if (game->rayDirY < 0)
	{
		game->stepY = -1;
		game->sideDistY = (game->posY - game->mapY) * game->deltaDistY;
	}
	else
	{
		game->stepY = 1;
		game->sideDistY = (game->mapY + 1.0 - game->posY) * game->deltaDistY;
	}
}

int	display(t_game *game, int x)
{
	init_buf(game);
	while (x < game->screen_w)
	{
		game->cameraX = 2 * x / (double)game->screen_w - 1;
		game->rayDirX = game->dirX + game->planeX * game->cameraX;
		game->rayDirY = game->dirY + game->planeY * game->cameraX;
		game->mapX = (int)game->posX;
		game->mapY = (int)game->posY;
		if (game->rayDirX == 0)
			game->deltaDistX = pow(10, 30);
		else
			game->deltaDistX = fabs(1 / game->rayDirX);
		if (game->rayDirY == 0)
			game->deltaDistY = pow(10, 30);
		else
			game->deltaDistY = fabs(1 / game->rayDirY);
		(init_side(game), dda_algo(game), wall_size(game), texture(game, x));
		
		x++;
	}
	draw(game);
	free_buffer(game);
	return (0);
}
