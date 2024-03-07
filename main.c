/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:38:56 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/07 10:38:57 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/cub3D.h"

void	init_loop(t_game *game)
{
	if (BONUS)
	{
		mlx_mouse_move(game->mlx_ptr, game->win_ptr, game->screen_w / 2,
			game->screen_h / 2);
		mlx_mouse_hook(game->win_ptr, mouse_click, game);
		mlx_hook(game->win_ptr, MotionNotify, PointerMotionMask, mouse_mv,
			game);
	}
	mlx_hook(game->win_ptr, KeyPress, KeyPressMask, &handle_keypress, game);
	mlx_hook(game->win_ptr, KeyRelease, KeyReleaseMask,
		&handle_keyrelease, game);
	mlx_hook(game->win_ptr, ClientMessage, NoEventMask, &ft_exit, game);
	mlx_loop_hook(game->mlx_ptr, &handle_no_event, game);
	mlx_loop(game->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
		return (ft_putstr_fd("Invalid nb of args\n", 2), 1);
	game = init_game();
	if (!game)
		return (1);
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		(free_game(game), exit(1));
	if (get_file_content(game, argv) == 1)
		return (free_game(game), 1);
	if (parse_content(game) == 1)
		return (free_game(game), 1);
	init_mlx(game);
	get_pos(game);
	display(game, 0);
	init_loop(game);
	free_game(game);
	return (0);
}
