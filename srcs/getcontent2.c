#include "../include/cub3D.h"

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
 * delete_types_nl
 * Removes the useless '\n' at the end of the types char*
 */

void	delete_types_nl(t_game *game)
{
	int	i;

	i = 0;
	while (game->type[i])
	{
		if (game->type[i][ft_strlen(game->type[i]) - 1] == '\n')
			game->type[i][ft_strlen(game->type[i]) - 1] = '\0';
		i++;
	}
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
	delete_types_nl(game);
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
	return (0);
}
