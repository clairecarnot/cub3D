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
		perror("open failed");
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

/*
 * get_types
 * The function will get the 6 first non-empty char* which
 * 	supposedly correspond to the 6 expected types
 * In the process of finding the 6 char*, we keep track of the number
 * 	of read lines in game->rows
 * In case of success (= we got 6 char*), the fd of the file is 
 * 	returned, so that the head for read stays put
 * Else ( = not all 6 types were found), -1 is returned
 */

int	get_types(t_game *game, char **argv)
{
	char	*line;
	int		fd;
	int		count;

	count = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (perror("open failed"), -1);
	while (count < 6)
	{
		line = get_next_line(fd, 0);
		if (!line)
			break ;
		if (!(ft_strlen(line) == 1 && !ft_strncmp(line, "\n", 1)))
			game->type[count++] = line;
		else
			free(line);
		game->rows++;
	}
	if (count == 6)
		return (fd);
	else
		return (close_if(&fd),
			ft_putstr_fd("Error\nInvalid nb of types\n", 2), -1);
}

/*
 * is_newline
 * Utils for count_rows, it compares the line content to "\n" to see
 * 	if the line is just an empty newline or not ; it updates the
 * 	int nl and int rows accordingly
 */

void	is_newline(char *line, int *nl, int *rows)
{
	if (ft_strlen(line) == 0)
	{
		*nl = 0;
		free(line);
	}
	else if ((ft_strlen(line) == 1) && !ft_strncmp(line, "\n", 1))
	{
		*nl = 1;
		*rows += 1;
		free(line);
	}
	else
		*nl = 0;
}

/*
 * count_rows
 * rows = nb of lines since the beginning of the file until the first
 * 	line of the map
 * game-rows: nb of lines of the map
 * The read head is already set after the 'types' char* ; we need to
 * 	pass all the empty newlines until we reach the first line of
 * 	the map and to increment rows each time
 * Once a non-empty line is reached, it means it is the first line of
 * 	the map; we then count all the map lines, incrementing game->rows
 */

void	count_rows(t_game *game, int fd, int *rows)
{
	char	*line;
	int		nl;

	nl = 1;
	while (nl)
	{
		line = get_next_line(fd, 0);
		if (!line)
			break ;
		is_newline(line, &nl, rows);
	}
	if (line)
	{
		(free(line), game->rows++);
		while (1)
		{
			line = get_next_line(fd, 0);
			if (!line)
				break ;
			(free(line), game->rows++);
		}
	}
	(get_next_line(fd, 1), close_if(&fd));
}

/*
 * cpy_map_from_file
 * Thanks to the previous functions, we know the nomber of lines (rows)
 * 	to pass before reaching the map, and the number of lines (game->rows)
 * 	of the map itself
 * We just need to re-open the file to reset the read head and count the lines
 */

int	cpy_map_from_file(t_game *game, char **argv, int rows)
{
	int		fd;
	int		i;
	int		j;
	char	*line;

	i = game->rows;
	j = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (perror("open failed"), -1);
	while (rows > 0)
	{
		line = get_next_line(fd, 0);
		free(line);
		rows--;
	}
	while (i > 0)
	{
		game->map[j] = get_next_line(fd, 0);
		i--;
		j++;
	}
	get_next_line(fd, 1);
	close_if(&fd);
	return (0);
}

/*
 * get_map
 * The nb of lines already read was stocked in game->rows. We change and
 * 	now stock this nb in "rows". game->rows is reset to 0 and will 
 * 	now keep count of the nb of lines of the map
 * count_rows: will update 'rows' (lines before the map incl types + empty
 * 	newlines) and 'game->rows' (map lines)
 * If the number of lines for the map is 0, the map is invalid.
 * Once we know how many lines the map is, we can ft_calloc a char**
 * 	and cpy the accurate lines from the file
 * Success: returns 0, else returns -1
 */

int	get_map(t_game *game, int fd, char **argv)
{
	int	rows;

	rows = game->rows;
	game->rows = 0;
	count_rows(game, fd, &rows);
	if (game->rows <= 0)
		return (ft_putstr_fd("Invalid map\n", 2), -1);
	game->map = ft_calloc(game->rows + 1, sizeof(char *));
	if (!game->map)
		return (ft_putstr_fd("Bad malloc\n", 2), -1);
	cpy_map_from_file(game, argv, rows);
	return (0);
}

/*
 * sort_content
 * Calls get_types: we want exactly 6 types so we open the file
 * 	and get the 6 first non-empty char* ; the fd is returned
 * 	so that we can read what's next (the map)
 * Calls get_map: the first is already open and the head for read is
 * 	stopped after the 6 types ; we then get all the rows that come
 * 	after, which correspond supposedly to the map
 */

int	sort_content(t_game *game, char **argv)
{
	int	fd;

	game->type = ft_calloc(7, sizeof(char *));
	if (!game->type)
		return (ft_putstr_fd("Bad malloc\n", 2), -1);
	fd = get_types(game, argv);
	if (fd < 0)
		return (-1);
	if (get_map(game, fd, argv) == -1)
		return (-1);
	return (0);
}

/*
 * get_map:
 * First, checks errors related to the source file of the map
 * Second, sorts the file content: split the types from the map
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
	int i = 0;
	while (game->type[i])
	{
		dprintf(2, "%s", game->type[i]);
		i++;
	}
	dprintf(2, "***\n");
	int j = 0;
	while (game->map[j])
	{
		dprintf(2, "%s", game->map[j]);
		j++;
	}
	dprintf(2, "\n***\n");
	return (0);
}
