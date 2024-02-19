#include "cub3D.h"

/*
 * len_max
 * Calculates the longest char* of a char**
 */

int	len_max(char **tab)
{
	int	i;
	int	len;
	int	lmax;

	i = 0;
	len = 0;
	lmax = 0;
	while (tab[i])
	{
		len = ft_strlen(tab[i]);
		if (len > lmax)
			lmax = len;
		i++;
	}
	return (lmax);
}

/*
 * redef_rows_bis
 * Malloc a char* of lenmax chars and fill it with the current 
 * 	map char* until the next newline :
 * 		if current char is a whitespace, replace it with 1
 *		else copy the char in the map
 * If the len of the new char* is not lenmax chars, fill all 
 * 	remaining chars with a 1 (wall) until the next newline
 * 	or EOF
 * If the end of line is \n, input \n, else if it is EOF, input EOF
 */

char	*redef_rows_bis(char *map, int lmax)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	new = ft_calloc(lmax + 1, sizeof(char));
	if (!new)
		return (ft_putstr_fd("Bad malloc\n", 2), NULL);
	while (map[i] && map[i] != '\n')
	{
		if (is_wspc_excl_nl(map[i]))
			new[i] = '1';
		else
			new[i] = map[i];
		i++;
	}
	j = i;
	while (i < lmax - 1)
	{
		new[i] = '1';
		i++;
	}
	if (map[j] && map[j] == '\n')
		new[i] = '\n';
	return (new);
}

/*
 * redef_rows
 * If the map row is just an empty newline, return the copy of
 * 	an empty newline, else go to the 2nd part of the function
 */

char	*redef_rows(char *map, int lmax)
{
	char	*new;

	if (ft_strlen(map) == 1 && !ft_strncmp(map, "\n", 1))
	{
		new = ft_strdup(map);
		if (!new)
			return (ft_putstr_fd("Bad malloc\n", 2), NULL);
		return (new);
	}
	else
		return (redef_rows_bis(map, lmax));
}

/*
 * redef_map
 * First calculates the len of the row with the most characters in the map
 * Then redefines all rows compared to this len (all rows will be
 * 	len-characters long) with the above functions
 */

int	redef_map(t_game *game)
{
	char	**new;
	int		lmax;
	int		i;

	i = 0;
	lmax = len_max(game->map);
	new = ft_calloc(game->rows + 1, sizeof(char *));
	if (!new)
		return (ft_putstr_fd("Bad malloc\n", 2), -1);
	while (game->map[i])
	{
		new[i] = redef_rows(game->map[i], lmax);
		if (!new[i])
			return (free_tab(new), -1);
		i++;
	}
	game->cols = lmax;
	free_tab(game->map);
	game->map = new;
	return (0);
}
