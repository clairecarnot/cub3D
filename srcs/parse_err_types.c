#include "../include/cub3D.h"

int	check_chars(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (!(s[i] == ',' || (s[i] >= '0' && s[i] <= '9')))
			return (-1);
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

t_img	*xpm_img(t_game *game, char *img_path, int w, int h)
{
	t_img	*new_img;

	new_img = ft_calloc(1, sizeof(t_img));
	if (!new_img)
		return (ft_putstr_fd("Bad malloc\n", 2), NULL);
	new_img->w = w;
	new_img->h = h;
	new_img->img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			img_path, &(new_img->w), &(new_img->h));
	if (!new_img->img_ptr)
		return (ft_putstr_fd("Error\nWrong texture path\n", 2),
			free(new_img), NULL);
	new_img->full_buf = (int *)mlx_get_data_addr(new_img->img_ptr,
			&new_img->bpp, &new_img->line_len,
			&new_img->endian);
	if (!new_img->full_buf)
	{
		mlx_destroy_image(game->mlx_ptr, new_img->img_ptr);
		new_img->img_ptr = NULL;
		free(new_img);
		return (ft_putstr_fd("Bad xpm adress\n", 2), NULL);
	}
	return (new_img);
}

int	get_nb(char *color)
{
	int	n;
	int	i;

	i = 0;
	while (color[i] && color[i] != '\n')
	{
		if (!(color[i] >= '0' && color[i] <= '9'))
			return (ft_putstr_fd("Error\nBad RGB color\n", 2), -1);
		i++;
	}
	color[i] = '\0';
	n = ft_atoi(color);
	if (n < 0 || n > 255)
		return (ft_putstr_fd("Error\nBad RGB color\n", 2), -1);
	return (n);
}

/*
 * parse_colors
 * Returns a int* containing the 3 rgb colour numbers
 */

int	*parse_colors(char *identifier)
{
	int		*rgb;
	char	**colours;

	rgb = ft_calloc(3, sizeof(int));
	if (!rgb)
		return (ft_putstr_fd("Bad malloc\n", 2), NULL);
	colours = ft_split(identifier, ',');
	if (!colours)
		return (ft_putstr_fd("Bad malloc\n", 2), free(rgb), NULL);
	if (tab_size(colours) != 3)
		return (ft_putstr_fd("Error\nWrong colours\n", 2),
			free_tab(colours), free(rgb), NULL);
	rgb[0] = get_nb(colours[0]);
	if (rgb[0] == -1)
		return (free_tab(colours), free(rgb), NULL);
	rgb[1] = get_nb(colours[1]);
	if (rgb[1] == -1)
		return (free_tab(colours), free(rgb), NULL);
	rgb[2] = get_nb(colours[2]);
	if (rgb[2] == -1)
		return (free_tab(colours), free(rgb), NULL);
	return (free_tab(colours), rgb);
}

/*
 * check_err_types
 * Checks following errors
 * 	1/ One of the textures (path) does not exist: NO, SO, WE, EA
 * 	2/ Floor or Ceiling:
 * 		- there are 3 rgb numbers split by 2 commas
 * 		- numbers are between 0 and 255
 */

int	check_err_types(t_game *game)
{
	game->no = xpm_img(game, game->type[0], 64, 64);
	if (!game->no)
		return (-1);
	game->so = xpm_img(game, game->type[1], 64, 64);
	if (!game->so)
		return (-1);
	game->we = xpm_img(game, game->type[2], 64, 64);
	if (!game->we)
		return (-1);
	game->ea = xpm_img(game, game->type[3], 64, 64);
	if (!game->ea)
		return (-1);
	game->door = xpm_img(game, "./img/door.xpm", 64, 64);
	if (!game->door)
		return (-1);
	if (get_imgs_data(game) != 0)
		return (-1);
	if (check_chars(game->type[4], ',') != 2
		|| check_chars(game->type[5], ',') != 2)
		return (ft_putstr_fd("Error\nInvalid type format\n", 2), -1);
	game->f = parse_colors(game->type[4]);
	if (!game->f)
		return (-1);
	game->c = parse_colors(game->type[5]);
	if (!game->c)
		return (-1);
	return (0);
}
