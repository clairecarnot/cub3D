#include "../include/cub3D.h"

void	swap_dist(double *a, double *b)
{
	double	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	swap_sprite(t_sprite *a, t_sprite *b)
{
	t_sprite	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/*
 * sort_sprites
 * first sprite will be the farest to player
 */

void	sort_sprites(t_sprite *sprite, double *dist, int numspr)
{
	int	i;
	int	j;

	i = 0;
	while (i < numspr - 1)
	{
		j = i + 1;
		while (j < numspr)
		{
			if (dist[i] < dist[j])
			{
				swap_sprite(&sprite[i], &sprite[j]);
				swap_dist(&dist[i], &dist[j]);
			}
			j++;
		}
		i++;
	}
}

t_list	*ft_lstget(t_list *lst, int index)
{
	int	i;

	if (!lst)
		return (NULL);
	if (!(lst->next))
		return (lst);
	i = 0;
	while (i < index)
	{
		lst = lst->next;
		i++;
	}
	return (lst);
}

void	update_sprite(t_game *game)
{
	t_list	*tmp;

	tmp = game->anim->imgs;
	game->anim->cur_time++;
	if (game->anim->cur_time == game->anim->update_time)
	{
		game->anim->cur_time = 0;
		game->anim->cur_nb++;
		game->anim->cur_nb %= ft_lstsize(game->anim->imgs);
		game->anim->tex = (int *)ft_lstget(tmp, game->anim->cur_nb)->content;
	}
}
