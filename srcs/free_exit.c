#include "../include/cub3D.h"

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
}

int	ft_exit(t_game *game)
{
	(void)game;
	// free_img(game);
	// if (game->sp_perso.frame)
	// 	ft_free_lst(game, game->sp_perso.frame);
	// if (game->sp_perso_back.frame)
	// 	ft_free_lst(game, game->sp_perso_back.frame);
	// if (game->sp_perso_left.frame)
	// 	ft_free_lst(game, game->sp_perso_left.frame);
	// if (game->sp_perso_right.frame)
	// 	ft_free_lst(game, game->sp_perso_right.frame);
	// if (game->sp_enemy.frame)
	// 	ft_free_lst(game, game->sp_enemy.frame);
	// if (game->win_ptr)
	// 	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	// if (game->mlx_ptr)
	// 	mlx_destroy_display(game->mlx_ptr);
	// if (game->mlx_ptr)
	// 	free(game->mlx_ptr);
	// if (game->map_ptr->content)
	// 	ft_free_map(game->map_ptr->content);
	exit (0);
}