#include "../include/cub3D_bonus.h"

void	draw(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	if (BONUS)
		minimap(game);
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
