#include "cub3D.h"

int	valid_char(char c)
{
	if (c != '0' && c != '1'
		&& c != 'N' && c != 'S'
		&& c != 'E' && c != 'W'
		&& c != '\n')
	{
		return (-1);
	}
	return (0);
}

int	valid_char_bonus(t_game *game, char c)
{
	if (c != '0' && c != '1'
		&& c != 'N' && c != 'S'
		&& c != 'E' && c != 'W'
		&& c != '\n' && c != 'D'
		&& c != 'A')
	{
		return (-1);
	}
	if (c == 'D')
		game->door_flag = 1;
	if (c == 'A')
		game->anim_flag = 1;
	return (0);
}
