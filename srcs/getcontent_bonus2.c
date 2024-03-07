/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcontent_bonus2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:31:01 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/07 10:31:02 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h" 

void	get_var_door_bonus(t_game *game)
{
	game->m_y = game->map_y;
	game->m_x = game->map_x;
	game->d_y = (int)game->side_dist_y;
	game->d_x = (int)game->side_dist_x;
}

int	sprite_init(t_game *game)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'A')
			{
				game->sprite[k].x = i + 0.5;
				game->sprite[k].y = j + 0.5;
				game->sprite[k].anim = game->anim;
				k++;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	create_sprite_utils(t_game *game)
{
	game->sprite = ft_calloc(game->num_sprites, sizeof(t_sprite));
	if (!game->sprite)
		return (ft_putstr_fd("Bad malloc\n", 2), -1);
	sprite_init(game);
	game->sprite_order = ft_calloc(game->num_sprites, sizeof(int));
	if (!game->sprite_order)
		return (ft_putstr_fd("Bad malloc\n", 2), -1);
	game->sprite_distance = ft_calloc(game->num_sprites, sizeof(double));
	if (!game->sprite_distance)
		return (ft_putstr_fd("Bad malloc\n", 2), -1);
	return (0);
}

int	bonus_contents(t_game *game)
{
	if (game->anim_flag == 1)
	{
		game->spr = xpm_img(game, "./img/nounoursvert.xpm", 160, 20);
		if (!game->spr)
			return (-1);
		game->spr->addr = (char *) game->spr->full_buf;
		game->anim = anim_init(game, 10000);
		if (!game->anim)
			return (-1);
		if (create_sprite_utils(game) == -1)
			return (-1);
	}
	return (0);
}
