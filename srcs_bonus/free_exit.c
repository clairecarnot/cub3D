/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:34:14 by ccarnot           #+#    #+#             */
/*   Updated: 2024/03/07 10:34:15 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D_bonus.h"

void	free_buffer(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->screen_h && game->buf && game->buf[i])
	{
		free(game->buf[i]);
		i++;
	}
	free(game->buf);
	game->buf = NULL;
}

int	ft_exit(t_game *game)
{
	free_game(game);
	exit (0);
}
