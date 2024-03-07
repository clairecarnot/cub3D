/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:33:15 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/07 10:33:16 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	right_down_2(t_game *game, int y, int x)
{
	if (game->map[(int)(game->p_y)][(int)(game->p_x)] == '0'
		|| game->map[(int)(game->p_y)][(int)(game->p_x)] == 'd')
		game->buf[y][x] = game->col_floor;
	else if (game->map[(int)(game->p_y)][(int)(game->p_x)] == '1')
		game->buf[y][x] = game->col_wall;
	else if (game->map[(int)(game->p_y)][(int)(game->p_x)] == 'D')
		game->buf[y][x] = game->col_door;
	else if (game->map[(int)(game->p_y)][(int)(game->p_x)] == 'A')
		game->buf[y][x] = game->col_anim;
	else
		game->buf[y][x] = game->col_wall;
}

void	left_down_2(t_game *game, int y, int x)
{
	if (game->map[(int)(game->p_y)][(int)(game->p_x)] == '0'
		|| game->map[(int)(game->p_y)][(int)(game->p_x)] == 'd')
		game->buf[y][x] = game->col_floor;
	else if (game->map[(int)(game->p_y)][(int)(game->p_x)] == '1')
		game->buf[y][x] = game->col_wall;
	else if (game->map[(int)(game->p_y)][(int)(game->p_x)] == 'D')
		game->buf[y][x] = game->col_door;
	else if (game->map[(int)(game->p_y)][(int)(game->p_x)] == 'A')
		game->buf[y][x] = game->col_anim;
	else
		game->buf[y][x] = game->col_wall;
}

void	left_up_2(t_game *game, int y, int x)
{
	if (game->map[(int)(game->p_y)][(int)(game->p_x)] == '0'
		|| game->map[(int)(game->p_y)][(int)(game->p_x)] == 'd')
		game->buf[y][x] = game->col_floor;
	else if (game->map[(int)(game->p_y)][(int)(game->p_x)] == '1')
		game->buf[y][x] = game->col_wall;
	else if (game->map[(int)(game->p_y)][(int)(game->p_x)] == 'D')
		game->buf[y][x] = game->col_door;
	else if (game->map[(int)(game->p_y)][(int)(game->p_x)] == 'A')
		game->buf[y][x] = game->col_anim;
	else
		game->buf[y][x] = game->col_wall;
}

void	right_up_2(t_game *game, int y, int x)
{
	if (game->map[(int)(game->p_y)][(int)(game->p_x)] == '0'
		|| game->map[(int)(game->p_y)][(int)(game->p_x)] == 'd')
		game->buf[y][x] = game->col_floor;
	else if (game->map[(int)(game->p_y)][(int)(game->p_x)] == '1')
		game->buf[y][x] = game->col_wall;
	else if (game->map[(int)(game->p_y)][(int)(game->p_x)] == 'D')
		game->buf[y][x] = game->col_door;
	else if (game->map[(int)(game->p_y)][(int)(game->p_x)] == 'A')
		game->buf[y][x] = game->col_anim;
	else
		game->buf[y][x] = game->col_wall;
}
