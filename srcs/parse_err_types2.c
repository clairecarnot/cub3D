/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_err_types2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:33:48 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/07 10:33:49 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

int	get_each_img_data(t_game *game, t_img *img, int i)
{
	int	x;
	int	y;

	game->tex[i] = ft_calloc((game->tex_w * game->tex_h), sizeof(int));
	if (!game->tex[i])
		return (ft_putstr_fd("Bad malloc\n", 2), -1);
	y = 0;
	while (y < game->tex_h)
	{
		x = 0;
		while (x < game->tex_w)
		{
			game->tex[i][y * game->tex_w + x]
				= img->full_buf[y * game->tex_w + x];
			x++;
		}
		y++;
	}
	return (0);
}

int	get_imgs_data(t_game *game)
{
	game->tex = ft_calloc(5, sizeof(int *));
	if (!game->tex)
		return (ft_putstr_fd("Bad malloc\n", 2), -1);
	if (get_each_img_data(game, game->no, 0) != 0)
		return (-1);
	if (get_each_img_data(game, game->so, 1) != 0)
		return (-1);
	if (get_each_img_data(game, game->ea, 2) != 0)
		return (-1);
	if (get_each_img_data(game, game->we, 3) != 0)
		return (-1);
	if (get_each_img_data(game, game->door, 4) != 0)
		return (-1);
	return (0);
}

/*
 * check_err_types
 * Checks following errors
 * 	1/ One of the textures (path) does not exist: NO, SO, WE, EA
 * 	2/ Floor or Ceiling:
 * 		- there are 3 rgb numbers split by 2 commas
 * 		- numbers are between 0 and 255
 */

int	check_err_types_bis(t_game *game)
{
	game->f = parse_colors(game->type[4]);
	if (!game->f)
		return (-1);
	game->c = parse_colors(game->type[5]);
	if (!game->c)
		return (-1);
	return (0);
}

int	check_err_types(t_game *game)
{
	game->no = xpm_img(game, game->type[0], 64, 64);
	if (!game->no)
		return (-1);
	game->so = xpm_img(game, game->type[1], 64, 64);
	if (!game->so)
		return (-1);
	game->we = xpm_img(game, game->type[2], 64, 64);
	if (!game->we)
		return (-1);
	game->ea = xpm_img(game, game->type[3], 64, 64);
	if (!game->ea)
		return (-1);
	game->door = xpm_img(game, "./img/door.xpm", 64, 64);
	if (!game->door)
		return (-1);
	if (get_imgs_data(game) != 0)
		return (-1);
	if (check_chars(game->type[4], ',') != 2
		|| check_chars(game->type[5], ',') != 2)
		return (ft_putstr_fd("Error\nInvalid type format\n", 2), -1);
	return (check_err_types_bis(game));
}
