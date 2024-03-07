/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:35:01 by ccarnot           #+#    #+#             */
/*   Updated: 2024/03/07 10:35:02 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D_bonus.h" 

double	calculate_player_direction(t_game *game)
{
	return (atan2(game->dir_y, game->dir_x));
}

void	move_up(t_game *game)
{
	char	new_pos_x;
	char	new_pos_y;

	new_pos_x = game->map[(int)(game->pos_x + game->dir_x
			* (game->move_speed + 0.01))][(int)(game->pos_y)];
	new_pos_y = game->map[(int)(game->pos_x)][(int)(game->pos_y
			+ game->dir_y * (game->move_speed + 0.01))];
	if (new_pos_x != '1' && new_pos_x != 'D')
		game->pos_x += game->dir_x * game->move_speed;
	if (new_pos_y != '1' && new_pos_y != 'D')
		game->pos_y += game->dir_y * game->move_speed;
}

void	move_down(t_game *game)
{
	char	new_pos_x;
	char	new_pos_y;

	new_pos_x = game->map[(int)(game->pos_x - game->dir_x
			* (game->move_speed + 0.01))][(int)(game->pos_y)];
	new_pos_y = game->map[(int)(game->pos_x)][(int)(game->pos_y
			- game->dir_y * (game->move_speed + 0.01))];
	if (new_pos_x != '1' && new_pos_x != 'D')
		game->pos_x -= game->dir_x * game->move_speed;
	if (new_pos_y != '1' && new_pos_y != 'D')
		game->pos_y -= game->dir_y * game->move_speed;
}

void	move_left(t_game *game)
{
	char	new_pos_x;
	char	new_pos_y;
	double	facing_direction;

	facing_direction = calculate_player_direction(game);
	new_pos_x = game->map[(int)(game->pos_x + cos(facing_direction + M_PI_2)
			* (game->move_speed + 0.01))][(int)(game->pos_y)];
	new_pos_y = game->map[(int)(game->pos_x)][(int)(game->pos_y
			+ sin(facing_direction + M_PI_2) * (game->move_speed + 0.01))];
	if (new_pos_x != '1' && new_pos_x != 'D')
		game->pos_x += cos(facing_direction + M_PI_2) * game->move_speed;
	if (new_pos_y != '1' && new_pos_y != 'D')
		game->pos_y += sin(facing_direction + M_PI_2) * game->move_speed;
}

void	move_right(t_game *game)
{
	char	new_pos_x;
	char	new_pos_y;
	double	facing_direction;

	facing_direction = calculate_player_direction(game);
	new_pos_x = game->map[(int)(game->pos_x + cos(facing_direction - M_PI_2)
			* (game->move_speed + 0.01))][(int)(game->pos_y)];
	new_pos_y = game->map[(int)(game->pos_x)][(int)(game->pos_y
			+ sin(facing_direction - M_PI_2) * (game->move_speed + 0.01))];
	if (new_pos_x != '1' && new_pos_x != 'D')
		game->pos_x += cos(facing_direction - M_PI_2) * game->move_speed;
	if (new_pos_y != '1' && new_pos_y != 'D')
		game->pos_y += sin(facing_direction - M_PI_2) * game->move_speed;
}
