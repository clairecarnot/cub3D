/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:33:07 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/07 10:33:08 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

void	perso(t_game *game)
{
	game->buf[39][39] = game->col_perso;
	game->buf[39][40] = game->col_perso;
	game->buf[39][41] = game->col_perso;
	game->buf[40][39] = game->col_perso;
	game->buf[40][40] = game->col_perso;
	game->buf[40][41] = game->col_perso;
	game->buf[41][39] = game->col_perso;
	game->buf[41][40] = game->col_perso;
	game->buf[41][41] = game->col_perso;
}

void	minimap(t_game *game)
{
	right_down(game, 39, 39);
	left_down(game, 39, 41);
	left_up(game, 41, 41);
	right_up(game, 41, 39);
	perso(game);
}
