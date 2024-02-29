#include "../include/cub3D.h"

void	draw(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	minimap(game);//bonus
	while (y < game->screen_h)
	{
		x = 0;
		while (x < game->screen_w)
		{
			game->image->full_buf[y * game->screen_w + x] = game->buf[y][x];
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->image->img_ptr, 0, 0);
}
