#include "../include/cub3D.h"

int	init_buf(t_game *game)
{
	int	y;

	y = 0;
	game->buf = ft_calloc(sizeof(unsigned int *), game->screen_h);
	if (!game->buf)
		(free_game(game), exit(1));
	while (y < game->screen_h)
	{
		game->buf[y] = ft_calloc(sizeof(unsigned int), game->screen_w);
		if (!game->buf[y])
			(free_game(game), exit(1));
		y++;
	}
	return (0);
}

void	wall_size(t_game *game)
{
	if (game->side == 0)
		game->perp_wall_dist = (game->side_dist_x - game->delta_dist_x);
	else
		game->perp_wall_dist = (game->side_dist_y - game->delta_dist_y);
	game->line_height = (int)(game->screen_h / game->perp_wall_dist);
	// game->pitch = 100;
	game->draw_start = - game->line_height / 2 + game->screen_h / 2 /*+ game->pitch*/;
	if (game->draw_start < 0)
		game->draw_start = 0;
	game->draw_end = game->line_height / 2 + game->screen_h / 2 /*+ game->pitch*/;
	if (game->draw_end >= game->screen_h)
		game->draw_end = game->screen_h - 1;
}

void	dda_algo(t_game *game)
{
	while (game->hit == 0)
	{
		if (game->side_dist_x < game->side_dist_y)
		{
			game->side_dist_x += game->delta_dist_x;
			game->map_x += game->step_x;
			game->side = 0;
		}
		else
		{
			game->side_dist_y += game->delta_dist_y;
			game->map_y += game->step_y;
			game->side = 1;
		}
		if (game->map[game->map_x][game->map_y] == '1' ||
			game->map[game->map_x][game->map_y] == 'D' )
			game->hit = 1;
	}
}

void	init_side(t_game *game)
{
	game->hit = 0;
	if (game->raydir_x < 0)
	{
		game->step_x = -1;
		game->side_dist_x = (game->pos_x - game->map_x) * game->delta_dist_x;
	}
	else
	{
		game->step_x = 1;
		game->side_dist_x = (game->map_x + 1.0 - game->pos_x) * game->delta_dist_x;
	}
	if (game->raydir_y < 0)
	{
		game->step_y = -1;
		game->side_dist_y = (game->pos_y - game->map_y) * game->delta_dist_y;
	}
	else
	{
		game->step_y = 1;
		game->side_dist_y = (game->map_y + 1.0 - game->pos_y) * game->delta_dist_y;
	}
}

int	display(t_game *game, int x)
{
	init_buf(game);
	while (x < game->screen_w)
	{
		game->camera_x = 2 * x / (double)game->screen_w - 1;
		game->raydir_x = game->dir_x + game->plane_x * game->camera_x;
		game->raydir_y = game->dir_y + game->plane_y * game->camera_x;
		game->map_x = (int)game->pos_x;
		game->map_y = (int)game->pos_y;
		if (game->raydir_x == 0)
			game->delta_dist_x = pow(10, 30);
		else
			game->delta_dist_x = fabs(1 / game->raydir_x);
		if (game->raydir_y == 0)
			game->delta_dist_y = pow(10, 30);
		else
			game->delta_dist_y = fabs(1 / game->raydir_y);
		(init_side(game), dda_algo(game), wall_size(game), texture(game, x));
		if (x == (game->screen_w / 2))
		{
			game->mY = game->map_y;
			game->mX = game->map_x;
			game->dY = (int)game->side_dist_y;
			game->dX = (int)game->side_dist_x;
			// dprintf(2, "dY = %d, dX = %d\n", game->dY, game->dX);
		}
		x++;
	}
	draw(game);
	free_buffer(game);
	return (0);
}
