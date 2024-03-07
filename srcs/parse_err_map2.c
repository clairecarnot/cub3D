/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_err_map2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:33:33 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/07 10:33:34 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	valid_char(char c)
{
	if (c != '0' && c != '1'
		&& c != 'N' && c != 'S'
		&& c != 'E' && c != 'W'
		&& c != '\n')
	{
		return (-1);
	}
	return (0);
}

int	valid_char_bonus(t_game *game, char c)
{
	if (c != '0' && c != '1'
		&& c != 'N' && c != 'S'
		&& c != 'E' && c != 'W'
		&& c != '\n' && c != 'D'
		&& c != 'A')
	{
		return (-1);
	}
	if (c == 'A')
	{
		game->anim_flag = 1;
		game->num_sprites++;
	}
	return (0);
}
