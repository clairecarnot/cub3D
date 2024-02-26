#include "../include/cub3D.h"

void	free_tab_int(unsigned int **tab, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		if (tab[i])
			free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
