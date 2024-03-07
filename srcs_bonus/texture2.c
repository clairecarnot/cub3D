/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:35:55 by ccarnot           #+#    #+#             */
/*   Updated: 2024/03/07 10:35:56 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D_bonus.h" 

void	project_sprites_ter(t_game *game)
{
	int				y;
	int				d;
	unsigned int	color;

	game->tex_x = (int)(256 * (game->stripe - (-game->sprite_width / 2
					+ game->sprite_screen_x)) * game->anim->w
			/ game->sprite_width) / 256;
	if (game->transform_y > 0 && game->stripe > 0
		&& game->stripe < game->screen_w
		&& game->transform_y < game->z_buffer[game->stripe])
	{
		y = game->draw_start_y;
		while (y < game->draw_end_y)
		{
			d = (y - game->vmove_screen) * 256 - game->screen_h * 128
				+ game->sprite_height * 128;
			game->tex_y = ((d * game->anim->h)
					/ game->sprite_height) / 256;
			color = game->anim->tex[game->anim->w
				* game->tex_y + game->tex_x];
			if ((color & 0x00FFFFFF) != 0)
				game->buf[y][game->stripe] = color;
			y ++;
		}
	}
}

void	project_sprites_bis(t_game *game)
{
	game->draw_start_x = -game->sprite_width / 2 + game->sprite_screen_x;
	if (game->draw_start_x < 0)
		game->draw_start_x = 0;
	game->draw_end_x = game->sprite_width / 2 + game->sprite_screen_x;
	if (game->draw_end_x >= game->screen_w)
		game->draw_end_x = game->screen_w - 1;
	game->stripe = game->draw_start_x;
	while (game->stripe < game->draw_end_x)
	{
		project_sprites_ter(game);
		game->stripe++;
	}
}

void	project_sprites(t_game *game, int i)
{
	game->sprite_x = game->sprite[game->sprite_order[i]].x - game->pos_x;
	game->sprite_y = game->sprite[game->sprite_order[i]].y - game->pos_y;
	game->inv_det = 1.0 / (game->plane_x * game->dir_y
			- game->dir_x * game->plane_y);
	game->transform_x = game->inv_det * (game->dir_y * game->sprite_x
			- game->dir_x * game->sprite_y);
	game->transform_y = game->inv_det * (-game->plane_y * game->sprite_x
			+ game->plane_x * game->sprite_y);
	game->sprite_screen_x = (int)((game->screen_w / 2)
			* (1 + game->transform_x / game->transform_y));
	game->vmove_screen = (int)(VMOVE / (game->transform_y));
	game->sprite_height = abs((int)(game->screen_h
				/ (game->transform_y))) / VDIV;
	game->draw_start_y = -game->sprite_height / 2
		+ game->screen_h / 2 + game->vmove_screen;
	if (game->draw_start_y < 0)
		game->draw_start_y = 0;
	game->draw_end_y = game->sprite_height / 2
		+ game->screen_h / 2 + game->vmove_screen;
	if (game->draw_end_y >= game->screen_h)
		game->draw_end_y = game->screen_h - 1;
	game->sprite_width = abs((int)(game->screen_h
				/ (game->transform_y))) / UDIV;
	project_sprites_bis(game);
}

void	pixel_color_sprites(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->num_sprites)
	{
		game->sprite_order[i] = i;
		game->sprite_distance[i] = ((game->pos_x - game->sprite[i].x)
				* (game->pos_x - game->sprite[i].x) + (game->pos_y
					- game->sprite[i].y) * (game->pos_y - game->sprite[i].y));
		i++;
	}
	sort_sprites(game->sprite, game->sprite_distance, game->num_sprites);
	update_sprite(game);
	i = 0;
	while (i < game->num_sprites)
	{
		project_sprites(game, i);
		i++;
	}
}
