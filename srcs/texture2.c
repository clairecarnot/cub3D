#include "../include/cub3D.h"

void	project_sprites_ter(t_game *game)
{
	int				y;
	int				d;
	unsigned int	color;

	game->texX = (int)(256 * (game->stripe - (-game->spriteWidth / 2
					+ game->spriteScreenX)) * game->anim->w
			/ game->spriteWidth) / 256;
	if (game->transformY > 0 && game->stripe > 0
		&& game->stripe < game->screen_w
		&& game->transformY < game->ZBuffer[game->stripe])
	{
		y = game->drawStartY;
		while (y < game->drawEndY)
		{
			d = (y - game->vMoveScreen) * 256 - game->screen_h * 128
				+ game->spriteHeight * 128;
			game->texY = ((d * game->anim->h)
					/ game->spriteHeight) / 256;
			color = game->anim->tex[game->anim->w
				* game->texY + game->texX];
			if ((color & 0x00FFFFFF) != 0)
				game->buf[y][game->stripe] = color;
			y ++;
		}
	}
}

void	project_sprites_bis(t_game *game)
{
	game->drawStartX = -game->spriteWidth / 2 + game->spriteScreenX;
	if (game->drawStartX < 0)
		game->drawStartX = 0;
	game->drawEndX = game->spriteWidth / 2 + game->spriteScreenX;
	if (game->drawEndX >= game->screen_w)
		game->drawEndX = game->screen_w - 1;
	game->stripe = game->drawStartX;
	while (game->stripe < game->drawEndX)
	{
		project_sprites_ter(game);
		game->stripe++;
	}
}

void	project_sprites(t_game *game, int i)
{
	game->spriteX = game->sprite[game->spriteOrder[i]].x - game->posX;
	game->spriteY = game->sprite[game->spriteOrder[i]].y - game->posY;
	game->invDet = 1.0 / (game->planeX * game->dirY
			- game->dirX * game->planeY);
	game->transformX = game->invDet * (game->dirY * game->spriteX
			- game->dirX * game->spriteY);
	game->transformY = game->invDet * (-game->planeY * game->spriteX
			+ game->planeX * game->spriteY);
	game->spriteScreenX = (int)((game->screen_w / 2)
			* (1 + game->transformX / game->transformY));
	game->vMoveScreen = (int)(VMOVE / (game->transformY));
	game->spriteHeight = abs((int)(game->screen_h
				/ (game->transformY))) / VDIV;
	game->drawStartY = -game->spriteHeight / 2
		+ game->screen_h / 2 + game->vMoveScreen;
	if (game->drawStartY < 0)
		game->drawStartY = 0;
	game->drawEndY = game->spriteHeight / 2
		+ game->screen_h / 2 + game->vMoveScreen;
	if (game->drawEndY >= game->screen_h)
		game->drawEndY = game->screen_h - 1;
	game->spriteWidth = abs((int)(game->screen_h
				/ (game->transformY))) / UDIV;
	project_sprites_bis(game);
}

void	pixel_color_sprites(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->numSprites)
	{
		game->spriteOrder[i] = i;
		game->spriteDistance[i] = ((game->posX - game->sprite[i].x)
				* (game->posX - game->sprite[i].x) + (game->posY
					- game->sprite[i].y) * (game->posY - game->sprite[i].y));
		i++;
	}
	sort_sprites(game->sprite, game->spriteDistance, game->numSprites);
	update_sprite(game);
	i = 0;
	while (i < game->numSprites)
	{
		project_sprites(game, i);
		i++;
	}
}
