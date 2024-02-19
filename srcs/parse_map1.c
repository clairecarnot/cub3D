#include "cub3D.h"

char	repl_char(t_game *game, int i, int j)
{
	if (j > 0 && game->map[i][j - 1] == '0')
		return ('0');
	else if (i > 0 && game->map[i - 1][j] == '0')
		return ('0');
	else if (game->map[i + 1] && game->map[i + 1][j] == '0')
		return ('0');
	else
		return ('1');
}

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
