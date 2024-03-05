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

t_img	*create_new_img(t_game *game, t_anim *anim)
{
	t_img	*new_img;

	new_img = ft_calloc(1, sizeof(t_img));
	if (!new_img)
		return (ft_putstr_fd("Bad malloc\n", 2), NULL);
	new_img->img_ptr = mlx_new_image(game->mlx_ptr, anim->w, anim->h);
	if (!new_img->img_ptr)
		return (free(new_img), ft_putstr_fd("Img creation failed\n", 2), NULL);
//	new_img->full_buf = (int *)mlx_get_data_addr(new_img->img_ptr,
	new_img->addr = mlx_get_data_addr(new_img->img_ptr,
			&new_img->bpp, &new_img->line_len,
			&new_img->endian);
//	if (!new_img->full_buf)
	if (!new_img->addr)
	{
		mlx_destroy_image(game->mlx_ptr, new_img->img_ptr);
		new_img->img_ptr = NULL;
		free(new_img);
		return (ft_putstr_fd("Bad img adress\n", 2), NULL);
	}
	new_img->full_buf = (int *) new_img->addr;
	new_img->w = anim->w;
	new_img->h = anim->h;
//	dprintf(2, "line len = %d\n", new_img->line_len);
	return (new_img);
}

int	*slice_anim(t_game *game, t_anim *anim, int x, int y)
{
	t_img	*img;
	int	*tex;
	int		i;
	int		j;

	img = create_new_img(game, anim);
	if (!img)
		return (NULL);
	i = 0;
//	dprintf(2, "img->w = %d\n", img->w);
//	dprintf(2, "img->h = %d\n", img->h);
//	dprintf(2, "anim->w = %d\n", anim->w);
//	dprintf(2, "anim->h = %d\n", anim->h);
//	dprintf(2, "x = %d\n", x);
//	dprintf(2, "y = %d\n", y);
	while (i < anim->h)
	{
		j = 0;
		while (j < anim->w)
		{
//			dprintf(2, "i = %d\n", i);
//			dprintf(2, "j = %d\n", j);
			put_pixel_img_anims(*img, j, i,
				get_pixel_img(*(game->spr), x + j, y + i));
			j++;
		}
		i++;
	}
	tex = get_one_img_data(game, img);
	free(img);
	return (tex);
}

t_list	*create_imgs_lst(t_game *game, t_anim *anim)
{
	int		x;
	int		y;
	t_list	*imgs;
	t_list	*tmp;
//	int i = 0;

	x = 0;
	y = 0;
	imgs = NULL;
//	dprintf(2, "game->spr->h = %d\n", game->spr->h);
//	dprintf(2, "game->spr->w = %d\n", game->spr->w);
	while (y < game->spr->h)
	{
//		dprintf(2, "i = %d\n", i);
//		dprintf(2, "x = %d\n", x);
//		dprintf(2, "y = %d\n", y);
		tmp = ft_lstnew(slice_anim(game, anim, x, y));
		if (!tmp)
			return (ft_lstfree_int(&imgs), NULL);
		ft_lstadd_back(&imgs, tmp);
		x += anim->w;
		if (x >= game->spr->w)
		{
			x = 0;
			y += anim->h;
		}
//		i++;
	}
	return (imgs);
}

t_anim	*anim_init(t_game *game, int update_time)
{
	t_anim	*anim;

	anim = ft_calloc(1, sizeof(t_anim));
	if (!anim)
		return (ft_putstr_fd("Bad malloc\n", 2), NULL);
	anim->cur_time = 0;
	anim->update_time = update_time;
	anim->w = 64; //A MODIF
	anim->h = 64; //A MODIF
	anim->imgs = create_imgs_lst(game, anim);
	if (!anim->imgs)
		return (free(anim), NULL);
	anim->tex = (int *)anim->imgs->content;
	anim->cur_nb = 0;
	anim->nb_img = ft_lstsize(anim->imgs);
//	dprintf(2, "anim->nb_img = %d\n", anim->nb_img);
	return (anim);
}

int	bonus_contents(t_game *game)
{
	// if (game->door_flag == 1)
	// {
	// 	game->door = xpm_img(game, "./img/door.xpm", 64, 64);
	// 	if (!game->door)
	// 		return (-1);
	// 	game->door_tex = get_one_img_data(game, game->door);
	// 	if (!game->door_tex)
	// 		return (-1);
	// }
	if (game->anim_flag == 1)
	{
		/* Sprite avec animation */
		game->spr = xpm_img(game, "./img/player.xpm", 1920, 64);
		game->spr->addr = (char *) game->spr->full_buf;
		if (!game->spr)
			return (-1);
		game->anim = anim_init(game, 10000);
		if (!game->anim)
			return (-1);
		/*   */
		/* Sprite sans animation - a suppr
		   game->anim = ft_calloc(1, sizeof(t_anim));
		   game->anim->w = 16;
		   game->anim->h = 16;
		   t_img *img = xpm_img(game, "./img/coin_mario3.xpm", 16, 16);
		   game->anim->tex = get_one_img_data(game, img);
		   free(img);
		   */
		//		dprintf(2, "numSprites = %d\n", game->numSprites);
		if (create_sprite_utils(game) == -1)
			return (-1);
	}
//	dprintf(2, "OK!\n");
	return (0);
}
