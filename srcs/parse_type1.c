#include "cub3D.h"

int	is_wspc(char c)
{
	if (c == ' ' || (c >= '\t' && c <= '\r'))
		return (1);
	else
		return (0);
}

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

void	swap_ptrs(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

int	ptr_to_swap(char *s)
{
	if (!ft_strncmp(s, "NO", 2) && is_wspc(s[2]))
		return (0);
	else if (!ft_strncmp(s, "SO", 2) && is_wspc(s[2]))
		return (1);
	else if (!ft_strncmp(s, "WE", 2) && is_wspc(s[2]))
		return (2);
	else if (!ft_strncmp(s, "EA", 2) && is_wspc(s[2]))
		return (3);
	else if (!ft_strncmp(s, "F", 1) && is_wspc(s[1]))
		return (4);
	else if (!ft_strncmp(s, "C", 1) && is_wspc(s[1]))
		return (5);
	else
		return (-1);
}

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
