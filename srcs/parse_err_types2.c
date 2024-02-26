#include "../include/cub3D.h"

int	get_each_img_data(t_game *game, t_img *img, int i)
{
	int	x;
	int	y;

	game->tex[i] = ft_calloc(sizeof(int), (game->tex_w * game->tex_h));
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
	game->tex = ft_calloc(sizeof(int *), 4);
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
	return (0);
}
