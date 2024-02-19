#include "cub3D.h"

int	contains_empty_nl(t_game *game)
{
	int	i;

	i = 0;
	while (game->map[i])
	{
		if (ft_strlen(game->map[i]) == 1 && !ft_strncmp(game->map[i], "\n", 1))
			return (ft_putstr_fd("Error\nEmpty newline in map\n", 2), -1);
		i++;
	}
	return (0);
}

int	contains_forbid_chars(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] != '0' && game->map[i][j] != '1'
				&& game->map[i][j] != 'N' && game->map[i][j] != 'S'
				&& game->map[i][j] != 'E' && game->map[i][j] != 'W'
				&& game->map[i][j] != '\n')
			{
				ft_putstr_fd("Error\nForbidden chars in the map\n", 2);
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	wrong_nb_player(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S'
				|| game->map[i][j] == 'E' || game->map[i][j] == 'W')
					count++;
			j++;
		}
		i++;
	}
	if (count > 1)
		return (ft_putstr_fd("Error\nMore than 1 player\n", 2), -1);
	if (count == 0)
		return (ft_putstr_fd("Error\nLess than 1 player\n", 2), -1);
	return (0);
}

//reprendre ici
int	map_not_closed(t_game *game)
{
	int	i;

	dprintf(2, "\nici\n");
	i = 1;
	while (game->map[i] && i < game->rows)
	{
		if (game->map[i][0] != '1' || game->map[i][game->cols - 1] == '1')
			return (ft_putstr_fd("Error\nMap not closed\n", 2), -1);
		i++;
	}
	dprintf(2, "ici bis\n");
	i = 1;
	while (i < game->cols)
	{
		if (game->map[0][i] != '1' || game->map[game->rows - 1][i] != '1')
			return (ft_putstr_fd("Error\nMap not closed\n", 2), -1);
		i++;
	}
	dprintf(2, "ici ter\n");
	return (0);
}

int	check_err_map(t_game *game)
{
	if (contains_empty_nl(game) == -1)
		return (-1);
	if (contains_forbid_chars(game) == -1)
		return (-1);
	if (wrong_nb_player(game) == -1)
		return (-1);
	if (map_not_closed(game) == -1)
		return (-1);
	return (0);
}
	//MAP:
	// ligne vide dans la map			ok
	//encadre de murs
	// verifier characteres autorises only		ok
	//presence un seul player			ok
	//taille de la map?
