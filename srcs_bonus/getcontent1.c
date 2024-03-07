/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getcontent1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarnot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:34:18 by ccarnot           #+#    #+#             */
/*   Updated: 2024/03/07 10:34:19 by ccarnot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D_bonus.h" 

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
 * The read head is alread_y set after the 'types' char* ; we need to
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
