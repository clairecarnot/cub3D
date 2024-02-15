#include "../include/cub3D.h"

/*
 * check_extension:
 * Returns 0 if the extension is .cub, else returns 1
 */

int	check_extension(char **argv)
{
	int	i;

	i = ft_strlen(argv[1]) - 1;
	if (argv[1][i--] != 'b')
		return (1);
	if (argv[1][i--] != 'u')
		return (1);
	if (argv[1][i--] != 'c')
		return (1);
	if (argv[1][i--] != '.')
		return (1);
	if (!argv[1][i])
		return (1);
	return (0);
}

/*
 * check_file_errors:
 * Checks if the file exists and can be opened
 * 	(else, return -1 with perror message)
 * Checks if the extension is .cub
 * 	(else, return -1 with an error message)
 * If success: returns the fd number
 */

int	check_file_errors(char **argv)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (perror("open failed :"), -1);
	if (check_extension(argv) == 1)
		return (close_if(&fd), ft_putstr_fd("Wrong extension\n", 2), -1);
	return (fd);
}

/*
 * get_map:
 * First, checks errors related to the source file of the map
 * Second, gets the map content
 *
 */

char	**get_map(t_game *game, char **argv)
{
	int	fd;

	if (!argv || !argv[1])
		return (NULL);
	fd = check_file_errors(argv);
	if (fd == -1)
		return (NULL);
	close_if(&fd);
	(void)game;
	return (NULL); //a changer
}
