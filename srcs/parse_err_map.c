#include "cub3D.h"

/*
 * contains_empty_nl
 * Checks if there is an empty newline in the map
 */

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

/*
 * contains_forbid_chars
 * Checks if there are other characters than 0, 1, N, S, E, W, \n
 */

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

/*
 * wrong_nb_player
 * Checks if the number of players is 1 (no more no less)
 */

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

/*
 * map_not_closed
 * Checks if the map is surrounded by walls (1)
 */

int	map_not_closed(t_game *game)
{
	int	i;

	i = 1;
	while (game->map[i] && i < game->rows - 1)
	{
		if (game->map[i][0] != '1' || game->map[i][game->cols - 1] != '1')
			return (ft_putstr_fd("Error\nMap not closed\n", 2), -1);
		i++;
	}
	i = 1;
	while (i < game->cols - 1)
	{
		if (game->map[0][i] != '1' || game->map[game->rows - 1][i] != '1')
		{
			return (ft_putstr_fd("Error\nMap not closed\n", 2), -1);
		}
		i++;
	}
	return (0);
}

/*
 * check_err_map
 * Handles the following errors:
 * 	1/ if there is an empty newline in the map
 *	2/ if the map contains chars other than 0, 1, N, S, E, W, \n
 *	3/ if the map does not contain 1 player only
 *	4/ if the map is not surrounded by walls
 */

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
