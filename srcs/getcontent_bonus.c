 #include "cub3D.h" 

int	*get_one_img_data(t_game *game, t_img *img)
{
	int	x;
	int	y;
	int	*tex;

	tex = ft_calloc(game->tex_w * game->tex_h, sizeof(int));
	if (!tex)
		return (ft_putstr_fd("Bad malloc\n", 2), NULL);
	y = 0;
	while (y < game->tex_h)
	{
		x = 0;
		while (x < game->tex_w)
		{
			tex[y * game->tex_w + x] = img->full_buf[y * game->tex_w + x];
			x++;
		}
		y++;
	}
	return (tex);
}

t_anim	*sprite_init(t_game *game, t_img *spr, int update_t)
{
	t_anim	*anim;

	anim = ft_calloc(1, sizeof(t_anim));
	if (!anim)
		return (ft_putstr_fd("Bad malloc\n", 2), NULL);

}

int	bonus_contents(t_game *game)
{
	if (game->door_flag == 1)
	{
		game->door = xpm_img(game, "./img/door.xpm", 64, 64);
		if (!game->door)
			return (-1);
		game->door_tex = get_one_img_data(game, game->door);
		if (!game->door_tex)
			return (-1);
	}
	if (game->anim_flag == 1)
	{
		game->spr = xpm_img(game, "./img/sprite.xpm", 2400, 80);
		if (!game->door)
			return (-1);
		game->anim = sprite_init(game, game->spr, 20);
		if (!game->anim)
			return (-1);
	}
	return (0);
}
