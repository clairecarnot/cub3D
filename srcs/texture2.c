#include "../include/cub3D.h"

void	swap_dist(double *a, double *b)
{
	double	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	swap_sprite(t_sprite *a, t_sprite *b)
{
	t_sprite	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sort_sprites(t_sprite *sprite, double *dist, int numspr)
{
	int	i;
	int	j;

	i = 0;
	while (i < numspr - 1)
	{
		j = i + 1;
		while (j < numspr)
		{
			if (dist[i] < dist[j])
			{
				swap_sprite(&sprite[i], &sprite[j]);
				swap_dist(&dist[i], &dist[j]);
			}
			j++;
		}
		i++;
	}
}

/*
void	reorder_sprites(t_pair *sprites, int numspr)
{
	int	i;
	int	j;
	t_pair	tmp;

	i = 0;
	j = 0;
	while (i < numspr)
	{
		while (j < numspr - 1)
		{
			if (sprites[j].first > sprites[j + 1].first)
			{
				tmp.first = sprites[j].first;
				tmp.second = sprites[j].second;
				sprites[j].first = sprites[j + 1].first;
				sprites[j].second = sprites[j + 1].second;
				sprites[j + 1].first = tmp.first;
				sprites[j + 1].second = tmp.second;
			}
			j++;
		}
		i++;
	}
}

void	sort_sprites(t_game *game, int *order, double *dist, int numspr)
{
	int		i;
	t_pair	*sprites;

	sprites = ft_calloc(numspr, sizeof(t_pair));
	if (!sprites)
		(ft_putstr_fd("Bad malloc\n", 2), free_game(game), exit(1));
	i = 0;
	while (i < game->numSprites)
	{
		sprites[i].first = dist[i];
		sprites[i].second = order[i];
		i++;
	}
	reorder_sprites(sprites, numspr);
	i = 0;
	while (i < numspr)
	{
		dist[i] = sprites[numspr - i - 1].first;
		order[i] = sprites[numspr - i - 1].second;
		i++;
	}
	free(sprites);
}
*/

/*
 * sort_sprites
 * first sprite will be the farest to player
 */

void	project_sprites(t_game *game)
{
//	dprintf(2, "PROJECTION\n");
	int	i;
	unsigned int	color;

	//after sorting the sprites, do the projection and draw them
	i = 0;
	while (i < game->numSprites)
	{
		//translate sprite position to relative to camera
//		dprintf(2, "game->sprite[game->spriteOrder[i]].x = %f\n", game->sprite[game->spriteOrder[i]].x);
//		dprintf(2, "game->sprite[game->spriteOrder[i]].y = %f\n", game->sprite[game->spriteOrder[i]].y);
		game->spriteX = game->sprite[game->spriteOrder[i]].x - game->posX;
		game->spriteY = game->sprite[game->spriteOrder[i]].y - game->posY;
		//transform sprite with the inverse camera matrix
		game->invDet = 1.0 / (game->planeX * game->dirY - game->dirX * game->planeY);
		game->transformX = game->invDet * (game->dirY * game->spriteX - game->dirX * game->spriteY);
		game->transformY = game->invDet * (-game->planeY * game->spriteX + game->planeX * game->spriteY);
		game->spriteScreenX = (int)((game->screen_w / 2) * (1 + game->transformX / game->transformY));
		
		
		//calculate height of the sprite on screen
		game->vMoveScreen = (int)(VMOVE / (game->transformY ));
		game->spriteHeight = abs((int)(game->screen_h / (game->transformY))) / VDIV;
		//	game->spriteHeight = abs((int)(game->screen_h / (game->transformY)));
		//calculate lowest and highest pixel to fill in current stripe
		game->drawStartY = -game->spriteHeight / 2 + game->screen_h / 2 + game->vMoveScreen;
		if (game->drawStartY < 0)
			game->drawStartY = 0;
		game->drawEndY = game->spriteHeight / 2 + game->screen_h / 2 + game->vMoveScreen;
		if (game->drawEndY >= game->screen_h)
			game->drawEndY = game->screen_h - 1;
		//calculate width of the sprite
		game->spriteWidth = abs((int)(game->screen_h / (game->transformY))) / UDIV;
		game->drawStartX = -game->spriteWidth / 2 + game->spriteScreenX;
		if (game->drawStartX < 0)
			game->drawStartX = 0;
		game->drawEndX = game->spriteWidth / 2 + game->spriteScreenX;
		if (game->drawEndX >= game->screen_w)
			game->drawEndX = game->screen_w - 1; //MOINS UN ?
		//loop through every vertical stripe of the sprite on screen
		game->stripe = game->drawStartX;
		while (game->stripe < game->drawEndX)
		{
			game->texX = (int)(256 * (game->stripe - (-game->spriteWidth / 2
					+ game->spriteScreenX)) * game->anim->w / game->spriteWidth) / 256;
			//the conditions in the if are:
			//1) it's in front of camera plane so you don't see things behind you
			//2) it's on the screen (left)
			//3) it's on the screen (right)
			//4) ZBuffer, with perpendicular distance
			if (game->transformY > 0 && game->stripe > 0 && game->stripe < game->screen_w
					&& game->transformY < game->ZBuffer[game->stripe])
			{
				int y = game->drawStartY;
				while (y < game->drawEndY)
				{
					//dprintf(2, "y = %d\n", y);
					//dprintf(2, "game->drawEndY = %d\n", game->drawEndY);
					int d = (y - game->vMoveScreen) * 256 - game->screen_h * 128 + game->spriteHeight * 128;
					game->texY = ((d * game->anim->h) / game->spriteHeight) / 256;
					color = game->anim->tex[game->anim->w * game->texY + game->texX];
					if ((color & 0x00FFFFFF) != 0)
						game->buf[y][game->stripe] = color;
					y ++;
				}
			}
			game->stripe++;
		}
		i++;
	}
}

void	pixel_color_sprites(t_game *game)
{
	int	i;

	i = 0;
	/*
	dprintf(2, "premier\n");
	int j = 0;
	while (j < game->numSprites)
	{
		dprintf(2, "j = %d\n", j);
		dprintf(2, "x = %f\n", game->sprite[j].x);
		dprintf(2, "y = %f\n", game->sprite[j].y);
		j++;
	}
	*/
	while (i < game->numSprites)
	{
		game->spriteOrder[i] = i;
		game->spriteDistance[i] = ((game->posX - game->sprite[i].x)
			* (game->posX - game->sprite[i].x) + (game->posY 
			- game->sprite[i].y) * (game->posY - game->sprite[i].y));
		i++;
	}
//	sort_sprites(game, game->spriteOrder, game->spriteDistance, game->numSprites);
	sort_sprites(game->sprite, game->spriteDistance, game->numSprites);
	/*
	dprintf(2, "deuxieme\n");
	int k = 0;
	while (k < game->numSprites)
	{
		dprintf(2, "k = %d\n", k);
		dprintf(2, "x = %f\n", game->sprite[k].x);
		dprintf(2, "y = %f\n", game->sprite[k].y);
		k++;
	}
	*/
	project_sprites(game);
}
