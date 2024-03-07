/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:33:03 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/07 10:33:04 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	get_dir2(t_game *game, char c)
{
	if (c == 'S')
	{
		game->dir_x = 1;
		game->dir_y = 0;
		game->plane_x = 0;
		game->plane_y = -0.66;
		return ;
	}
	if (c == 'N')
	{
		game->dir_x = -1;
		game->dir_y = 0;
		game->plane_x = 0;
		game->plane_y = 0.66;
		return ;
	}
}

void	get_dir(t_game *game, char c)
{
	if (c == 'E')
	{
		game->dir_x = 0;
		game->dir_y = 1;
		game->plane_x = 0.66;
		game->plane_y = 0;
		return ;
	}
	if (c == 'W')
	{
		game->dir_x = 0;
		game->dir_y = -1;
		game->plane_x = -0.66;
		game->plane_y = 0;
		return ;
	}
	get_dir2(game, c);
}
