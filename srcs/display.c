#include "../include/cub3D.h"

void	draw(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->screen_h)
	{
		x = 0;
		while (x < game->screen_w)
		{
			game->image.full_buf[y * game->screen_w + x] = game->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->image.img_ptr, 0, 0);
}

void	save_pixel(t_game *game, int x, int color)
{
	int	y;

	y = game->drawStart;
	// dprintf(2, "drawStart = %d\n", game->drawStart);
	// dprintf(2, "drawEnd = %d\n", game->drawEnd);
	while (y <= game->drawEnd)
	{
		// mlx_pixel_put(game->mlx_ptr, game->win_ptr, x, y, (int)color);
		game->buf[y][x] = color;
		// dprintf(2, "y\n");
		y++;
	}
}

int	display(t_game *game)
{
	int	x;

	x = 0;
	init_buf(game);//ajouter protection + free a la fin
	while (x < game->screen_w)//x < largeur ecran
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
		//init side
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
		//dda algorithme
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
		//wall size
		if (game->side == 0)
			game->perpWallDist = (game->sideDistX - game->deltaDistX);
		else
			game->perpWallDist = (game->sideDistY - game->deltaDistY);
		
		game->lineHeight = (int)(game->screen_h / game->perpWallDist);
		
		game->drawStart = - game->lineHeight / 2 + game->screen_h / 2;
		if (game->drawStart < 0)
			game->drawStart = 0;
		
		game->drawEnd = game->lineHeight / 2 + game->screen_h / 2;
		if (game->drawEnd >= game->screen_h)
			game->drawEnd = game->screen_h - 1;
		
		int	color = 0xffffff;
		if (game->side == 0)
			color = color / 2;
		
		save_pixel(game, x, color);//verLine
		x++;
		// dprintf(2, "0\n");
	}
	draw(game);
	free_buffer(game);
	return (0);
}