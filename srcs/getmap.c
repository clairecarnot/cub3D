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
	{
		ft_putstr_fd("Error\n", 2);
		perror("open failed:");
		return (-1);
	}
	close_if(&fd);
	if (check_extension(argv) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Wrong extension\n", 2);
		return (-1);
	}
	return (0);
}

/*
int	is_wspc(char c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (1);
	else
		return (0);
}
*/

int	get_types(t_game *game, char **argv)
{
	char	*line;
	int		fd;
	int		count;

	count = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (perror("open failed:"), -1);
	while (count < 6)
	{
		line = get_next_line(fd, 0);
		if (!line)
			break ;
		if (ft_strlen(line) != 0)
			game->type[count] = line;
		else
			free(line);
		game->rows++;
	}
	(free(line), get_next_line(fd, 1));
	if (count == 6)
		return (fd);
	else
		return (close_if(&fd),
			ft_putstr_fd("Error\nInvalid nb of types\n", 2), -1);
}

int	count_rows(t_game *game, int fd)
{
	char	*line;
	int		rows;

	rows = game->rows;
	game->rows = 0;
	while (1)
	{
		line = get_next_line(fd, 0);
		if (!line || ft_strlen(line) == 0)
			break ;
		(free(line), rows++);
	}
	if (line)
	{
		game->rows++;
		while (1)
		{
			line = get_next_line(fd, 0);
			if (!line)
				break ;
			(free(line), game->rows++);
		}
	}
	return (get_next_line(fd, 1), close_if(&fd), rows);
}

int	get_map(t_game *game, int fd, char **argv)
{
	int	rows;

	rows = count_rows(game, fd);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (perror("open failed:"), -1);
	game->	
}

int	sort_content(t_game *game, char **argv)
{
	int	fd;

	game->type = ft_calloc(6, sizeof(char *));
	if (!game->type)
		return (-1);
	fd = get_types(game, argv);
	if (fd < 0)
		return (-1);
	if (get_map(game, fd, argv) == -1)
		return (-1);
}

/*
 * get_map:
 * First, checks errors related to the source file of the map
 * Second, gets the map content
 *
 */

int	get_file_content(t_game *game, char **argv)
{
	if (!argv || !argv[1])
		return (1);
	if (check_file_errors(argv) == -1)
		return (1);
	if (sort_content(game, argv) == -1)
		return (1);
	return (0);
}
