#include "../include/cub3D.h"

int	close_if(int *fd)
{
	if (*fd > 0)
	{
		if (close(*fd) < 0)
			return (-1);
		*fd = -1;
	}
	return (0);
}

void	free_if(char *str)
{
	if (str)
		free(str);
}

void	free_tab_int(unsigned int **tab, int nb_tex)
{
	int	i;

	i = 0;
	while (i < nb_tex)
	{
		if (tab[i])
			free(tab[i]);
		i++;
	}
	free(tab);	
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_img(t_game *game, t_img *img)
{
	mlx_destroy_image(game->mlx_ptr, img->img_ptr);
	img->img_ptr = NULL;
	free(img);
	img = NULL;
}

int	free_game(t_game *game)
{
	if (game->tex)//ajout
		free_tab_int(game->tex, game->nb_tex);
	if (game->type)
		free_tab(game->type);
	if (game->map)
		free_tab(game->map);
	if (game->no)
		free_img(game, game->no);
	if (game->so)
		free_img(game, game->so);
	if (game->we)
		free_img(game, game->we);
	if (game->ea)
		free_img(game, game->ea);
	if (game->f)
		free(game->f);
	if (game->c)
		free(game->c);
	if (game->image)//ajout
		free_img(game, game->image);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
		mlx_destroy_display(game->mlx_ptr);
	if (game->mlx_ptr)
		free(game->mlx_ptr);
	if (game)
		free(game);
	return (0);
}
