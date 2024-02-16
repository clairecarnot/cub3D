#include "cub3D.h"

int	len_max(char **tab)
{
	int	i;
	int	len;
	int	lmax;

	i = 0;
	len = 0;
	lmax = 0;
	while (new[i])
	{
		len = ft_strlen(new[i]);
		if (len > lmax)
			lmax = len;
		i++;
	}
	return (lmax);
}

//reprendre ici
char	*redef_rows(char *map, int lmax)
{
	int		i;
	char	*new;

	i = 0;
	while (map[i])
	{
		if (is_wspc(new[i]))
			new[i] = '1';
		else
			new[i] = map[i];
		i++;
	}
	while (i < lmax)
	{
		new[i] = '1';
		i++;
	}
	return (new);
}

int	redef_map(t_game *game)
{
	char	**new;
	int	lmax;
	int	i;

	i = 0;
	lmax = len_max(new);
	new = ft_calloc(game->rows + 1, sizeof(char *));
	if (!new)
		return (ft_putstr_fd("Bad malloc\n", 2), -1);
	while (game->map[i])
	{
		new[i] = ft_calloc(lmax + 1, sizeof(char));
		if (!new[i])
			return (ft_putstr_fd("Bad malloc\n", 2), free_tab(new), -1);
		new[i] = redef_rows(game->map[i], lmax);
		i++;
	}
	free(game->map);
	game->map = new;
	return (0);
}
