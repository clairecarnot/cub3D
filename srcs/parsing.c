#include "cub3D.h"

int	tab_size(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	parse_content(t_game *game)
{
	/****************************************
	int i = 0;
	while (game->type[i])
	{
		dprintf(2, "%s", game->type[i]);
		i++;
	}
	dprintf(2, "\n");
	**************************************/
	if (redef_types(game) == -1)
		return (1);
	/**************************************
	i = 0;
	while (game->type[i])
	{
		dprintf(2, "%s\n", game->type[i]);
		i++;
	}
	**************************************/
	if (check_err_types(game) == -1)
		return (1);
	/**************************************
	int j = 0;
	while (game->map[j])
	{
		int y = 0;
		while (game->map[j][y])
		{
			if (game->map[j][y] == ' ')
				dprintf(2, "x");
			else
				dprintf(2, "%c", game->map[j][y]);
			y++;
		}
		j++;
	}
	dprintf(2, "\n");
	dprintf(2, "\n");
	**************************************/
	if (redef_map(game) == -1)
		return (1);
	/**************************************
	int j = 0;
	while (game->map[j])
	{
		dprintf(2, "%s", game->map[j]);
		j++;
	}
	**************************************/
	dprintf(2, "\ngame->rows = %d\n", game->rows);
	dprintf(2, "game->cols = %d\n", game->cols);
	if (check_err_map(game) == -1)
		return (1);
	return (0);
}

	//TYPES:
	//enlever les espaces en trop				OK
	//verifier que tous les types sont presents		OK
	//reordonner les types et garder juste le chemin	OK
	//verifier le chemin					OK
	//F ou C: 	chiffre qui manque			OK
	//		virgule en trop				OK
	//		chiffre >255 ou <0			OK

	//MAP:
	//remplacer les whitespaces				OK
	//compter la plus grand chaine, completer avec des 1	OK
	//compter les rows et cols				OK
	// ligne vide dans la map				OK	
	//encadre de murs					OK
	// verifier characteres autorises only			OK
	//presence un seul player				OK
	//taille de la map?
