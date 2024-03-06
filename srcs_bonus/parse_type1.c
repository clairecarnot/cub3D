#include "../include/cub3D_bonus.h" 

/*
 * is_wspc_excl_nl
 * Checks if the given char is a wpsc (\n excluded)
 */

int	is_wspc_excl_nl(char c)
{
	if (c == ' ' || c == '\t' || c == '\r' || c == '\v' || c == '\f')
		return (1);
	else
		return (0);
}

/*
 * check_types
 * Checks that the char** 's final type order is exactly
 * 	the one defined in the .h
 */

int	check_types(char **new)
{
	if (ft_strncmp(new[0], "NO", 2))
		return (-1);
	if (ft_strncmp(new[1], "SO", 2))
		return (-1);
	if (ft_strncmp(new[2], "WE", 2))
		return (-1);
	if (ft_strncmp(new[3], "EA", 2))
		return (-1);
	if (ft_strncmp(new[4], "F", 1))
		return (-1);
	if (ft_strncmp(new[5], "C", 1))
		return (-1);
	return (0);
}

/*
 * swap_ptrs
 * Swaps 2 pointers
 */

void	swap_ptrs(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

/*
 * ptr_to_swap
 * Util for reordering the types: given the received type,
 * 	it returns the position in which this type is 
 * 	supposed to be as defined in the .h
 * It also checks that the char after the type is a wpsc, to
 * 	separate the identifier from the information
 */

int	ptr_to_swap(char *s)
{
	if (!ft_strncmp(s, "NO", 2) && is_wspc_excl_nl(s[2]))
		return (0);
	else if (!ft_strncmp(s, "SO", 2) && is_wspc_excl_nl(s[2]))
		return (1);
	else if (!ft_strncmp(s, "WE", 2) && is_wspc_excl_nl(s[2]))
		return (2);
	else if (!ft_strncmp(s, "EA", 2) && is_wspc_excl_nl(s[2]))
		return (3);
	else if (!ft_strncmp(s, "F", 1) && is_wspc_excl_nl(s[1]))
		return (4);
	else if (!ft_strncmp(s, "C", 1) && is_wspc_excl_nl(s[1]))
		return (5);
	else
		return (-1);
}

/*
 * search_type
 * Util for check_all_types : checks if a type is present
 * 	in the char**
 */

int	search_type(char *type, char **new)
{
	int	i;

	i = 0;
	while (new[i])
	{
		if (!ft_strncmp(type, new[i], ft_strlen(type)))
			return (0);
		i++;
	}
	return (-1);
}
