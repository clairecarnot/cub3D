#include "cub3D.h"

int	check_alltypes(char **new)
{
	if (search_type("NO", new) == -1)
		return (-1);
	if (search_type("SO", new) == -1)
		return (-1);
	if (search_type("WE", new) == -1)
		return (-1);
	if (search_type("EA", new) == -1)
		return (-1);
	if (search_type("F", new) == -1)
		return (-1);
	if (search_type("C", new) == -1)
		return (-1);
	return (0);
}

int	reorder_new(char **new)
{
	int	i;
	int	swap_val;

	i = 0;
	if (check_alltypes(new) == -1)
		return (ft_putstr_fd("Error\nInvalid type(s)\n", 2), -1);
	while (new[i])
	{
		swap_val = ptr_to_swap(new[i]);
		if (swap_val == -1)
			return (ft_putstr_fd("Error\nInvalid type(s)\n", 2), -1);
		if (swap_val != i)
			swap_ptrs(&new[i], &new[swap_val]);
		else
			i++;
	}
	if (check_types(new) == -1)
		return (ft_putstr_fd("Error\nInvalid type(s)\n", 2), -1);
	return (0);
}

int	clean_types(char **new)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (new[i])
	{
		if (i < 4)
			j = 3;
		else
			j = 2;
		while (is_wspc(new[i][j]))
			j++;
		tmp = ft_strdup(&new[i][j]);
		if (!tmp)
			return (ft_putstr_fd("Bad malloc\n", 2), -1);
		free(new[i]);
		new[i] = tmp;
		i++;
	}
	return (0);
}

char	*init_set(void)
{
	char	*set;

	set = ft_calloc(6, sizeof(char));
	if (!set)
		return (NULL);
	set[0] = ' ';
	set[1] = '\t';
	set[2] = '\v';
	set[3] = '\f';
	set[4] = '\r';
	return (set);
}

int	redef_types(t_game *game)
{
	int		i;
	char	*tmp;
	char	*set;
	char	**new;

	i = 0;
	new = ft_calloc(7, sizeof(char *));
	if (!new)
		return (ft_putstr_fd("Bad malloc\n", 2), -1);
	set = init_set();
	if (!set)
		return (ft_putstr_fd("Bad malloc\n", 2), free_tab(new), -1);
	while (game->type[i])
	{
		tmp = ft_strtrim(game->type[i], set);
		if (!tmp)
			return (ft_putstr_fd("Bad malc\n", 2), free_tab(new), free(set), -1);
		new[i] = tmp;
		i++;
	}
	if (reorder_new(new) == -1)
		return (free_tab(new), free(set), -1);
	if (clean_types(new) == -1)
		return (free_tab(new), free(set), -1);
	return (free(set), free_tab(game->type), game->type = new, 0);
}
