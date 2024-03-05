#include "../include/cub3D.h"

int	get_color(int *tab_c)
{
	unsigned int	hexa_color;

	hexa_color = ((unsigned int)tab_c[0] << 16 | \
	(unsigned int)tab_c[1] << 8 | (unsigned int)tab_c[2]);
	return (hexa_color);
}

void	pixel_color_ceiling_floor(t_game *game, int x)
{
	int	y;

	y = 0;
	game->f_color = get_color(game->f);
	game->c_color = get_color(game->c);
	while (y < game->draw_start)
	{
		game->buf[y][x] = game->c_color;
		y++;
	}
	y = game->draw_end;
	// dprintf(2, "x = %d\n", x);
	while (y < game->screen_h && y >= 0)
	{
		// dprintf(2, "y = %d, x = %d\n", y, x);
		if (x < game->screen_w)
			game->buf[y][x] = game->f_color;
		y++;
	}
}

void	pixel_color_walls(t_game *game, int x)
{
	int				y;
	unsigned int	color;

	y = game->draw_start;
	while (y < game->draw_end)
	{
		game->tex_y = (int)game->tex_pos & (game->tex_h - 1);
		game->tex_pos += game->step;
		color = game->tex[game->tex_num][game->tex_h * game->tex_y + game->tex_x];
		game->buf[y][x] = color;
		y++;
	}
}

void	texture_wall_orientation(t_game *game)
{
	if (game->map[game->map_x][game->map_y] == 'D')
	{
		// dprintf(2, "---> map_x = %d, map_y = %d\n", game->map_x, game->map_y);
		game->tex_num = 4;
	}
	else if (game->side == 0)
	{
		if (game->step_x == 1)
			game->tex_num = 1;
		else if (game->step_x == -1)
			game->tex_num = 0;
	}
	else if (game->side == 1)
	{
		if (game->step_y == 1)
			game->tex_num = 2;
		else if (game->step_y == -1)
			game->tex_num = 3;
	}
}

void	texture(t_game *game, int x)
{
	game->tex_x = 0;
	game->tex_y = 0;
	if (game->side == 0)
		game->wall_x = game->pos_y + game->perp_wall_dist * game->raydir_y;
	else
		game->wall_x = game->pos_x + game->perp_wall_dist * game->raydir_x;
	game->wall_x -= floor(game->wall_x);
	game->tex_x = (int)(game->wall_x * (double)(game->tex_w));
	if (game->side == 0 && game->raydir_x > 0)
		game->tex_x = game->tex_w - game->tex_x - 1;
	if (game->side == 1 && game->raydir_y < 0)
		game->tex_x = game->tex_w - game->tex_x - 1;
	game->step = 1.0 * game->tex_h / game->line_height;
	game->tex_pos = (game->draw_start /*- game->pitch*/
			- game->screen_h / 2 + game->line_height / 2) * game->step;
	texture_wall_orientation(game);
		
	pixel_color_walls(game, x);
	pixel_color_ceiling_floor(game, x);
	game->z_buffer[x] = game->perp_wall_dist;
	pixel_color_sprites(game);
}
