/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:30:49 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/07 10:30:50 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	draw(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	if (BONUS)
		minimap(game);
	while (y < game->screen_h)
	{
		x = 0;
		while (x < game->screen_w)
		{
			game->image->full_buf[y * game->screen_w + x] = game->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->image->img_ptr, 0, 0);
}
