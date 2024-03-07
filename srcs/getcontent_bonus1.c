/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcontent_bonus1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapoirie <mapoirie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:30:58 by mapoirie          #+#    #+#             */
/*   Updated: 2024/03/07 10:30:59 by mapoirie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	*get_one_img_data(t_img *img, t_anim *anim)
{
	int	x;
	int	y;
	int	*tex;

	tex = ft_calloc(anim->w * anim->h, sizeof(int));
	if (!tex)
		return (ft_putstr_fd("Bad malloc\n", 2), NULL);
	y = 0;
	while (y < anim->h)
	{
		x = 0;
		while (x < anim->w)
		{
			tex[y * anim->w + x] = img->full_buf[y * anim->w + x];
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
	new_img->addr = mlx_get_data_addr(new_img->img_ptr,
			&new_img->bpp, &new_img->line_len,
			&new_img->endian);
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
	return (new_img);
}

int	*slice_anim(t_game *game, t_anim *anim, int x, int y)
{
	t_img	*img;
	int		*tex;
	int		i;
	int		j;

	img = create_new_img(game, anim);
	if (!img)
		return (NULL);
	i = 0;
	while (i < anim->h)
	{
		j = 0;
		while (j < anim->w)
		{
			put_pixel_img_anims(*img, j, i,
				get_pixel_img(*(game->spr), x + j, y + i));
			j++;
		}
		i++;
	}
	tex = get_one_img_data(img, anim);
	mlx_destroy_image(game->mlx_ptr, img->img_ptr);
	free(img);
	return (tex);
}

t_list	*create_imgs_lst(t_game *game, t_anim *anim, int x, int y)
{
	int		*tex;
	t_list	*imgs;
	t_list	*tmp;

	imgs = NULL;
	while (y < game->spr->h)
	{
		tex = slice_anim(game, anim, x, y);
		if (!tex)
			return (ft_lstfree_int(&imgs), NULL);
		tmp = ft_lstnew(tex);
		if (!tmp)
			return (ft_putstr_fd("Bad malloc\n", 2), free(tex),
				ft_lstfree_int(&imgs), NULL);
		ft_lstadd_back(&imgs, tmp);
		x += anim->w;
		if (x >= game->spr->w)
		{
			x = 0;
			y += anim->h;
		}
	}
	return (imgs);
}

t_anim	*anim_init(t_game *game, int update_time)
{
	t_anim	*anim;
	int		x;
	int		y;

	x = 0;
	y = 0;
	anim = ft_calloc(1, sizeof(t_anim));
	if (!anim)
		return (ft_putstr_fd("Bad malloc\n", 2), NULL);
	anim->cur_time = 0;
	anim->update_time = update_time;
	anim->w = 20;
	anim->h = 20;
	anim->imgs = create_imgs_lst(game, anim, x, y);
	if (!anim->imgs)
		return (free(anim), NULL);
	anim->tex = (int *)anim->imgs->content;
	anim->cur_nb = 0;
	anim->nb_img = ft_lstsize(anim->imgs);
	return (anim);
}
