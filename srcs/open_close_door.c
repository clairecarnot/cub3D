/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_close_door.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:33:25 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/07 10:33:26 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	low(double nb)
{
	double	i;

	i = 0;
	while (i < nb)
	{
		i += 1;
	}
	i -= 1;
	return ((int)i);
}

void	open_door(t_game *game)
{
	if (game->map[game->m_x][game->m_y] == 'D'
	&& ((game->d_x <= 2 && game->d_x >= 0)
	|| (game->d_y <= 2 && game->d_y >= 0)))
		game->map[game->m_x][game->m_y] = 'd';
}

void	close_door(t_game *game)
{
	int	m_x;
	int	m_y;

	m_x = 0;
	while (game->map[m_x])
	{
		m_y = 0;
		while (game->map[m_x][m_y])
		{
			if (game->map[m_x][m_y] == 'd'
			&& game->map[low(game->pos_x)][low(game->pos_y)] != 'd')
			{
				game->map[m_x][m_y] = 'D';
			}
			m_y++;
		}	
		m_x++;
	}
}
