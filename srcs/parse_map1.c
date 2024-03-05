#include "cub3D.h"

/*
 * repl_char
 * The rule for replacing "empty chars" is : if this empty char
 * 	is next to a '0' (at its left, above or below row),
 * 	it will be replaced by a '0', because it means that 
 * 	the map is not closed somewhere. Else it will be replaced
 * 	by a '1' (wall = closed). Ex ('e' for 'empty') :
 * 	1111  will give 1111
 * 	1001		1001
 * 	1eee		1000
 * 	1111		1111
 *
 * The rule is decomposed below:
 * 	1/ if the absciss (j) is not 0, and the char before (j-1)
 * 		is char '0', 'D' or 'A', replace by char '0'
 * 	2/ if the ordinate (i) is not 0, and the char on the above
 * 		row (i-1) at absciss j is '0', 'D' or 'A', replace by '0'
 * 	3/ if we are not on the last row and the char on the below
 * 		row (i+1) at absciss j is '0', 'D' or 'A', replace by '0'
 * 	4/ else, replace by '1'
 */

char	repl_char(t_game *game, int i, int j)
{
	if (j > 0 && (game->map[i][j - 1] == '0' || game->map[i][j - 1] == 'D'
			|| game->map[i][j - 1] == 'A'))
		return ('0');
	else if (i > 0 && (game->map[i - 1][j] == '0' || game->map[i - 1][j] == 'D'
			|| game->map[i - 1][j] == 'A'))
		return ('0');
	else if (game->map[i + 1] && (game->map[i + 1][j] == '0'
		|| game->map[i + 1][j] == 'D' || game->map[i + 1][j] == 'A'))
		return ('0');
	else
		return ('1');
}

/*
 * replace_empty_chars
 * When a row of the map was not of length max, all "empty
 * 	chars" have been previously filled with value '2'
 * These empty chars will now be replaced by a '1' (wall) or a '0'
 * 	(floor) in the function above
 */

int	replace_empty_chars(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == '2')
				game->map[i][j] = repl_char(game, i, j);
			j++;
		}
		i++;
	}
	return (0);
}
