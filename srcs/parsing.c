#include "cub3D.h"

int	parse_content(t_game *game)
{
	/*
	int i = 0;
	while (game->type[i])
	{
		dprintf(2, "%s", game->type[i]);
		i++;
	}
	dprintf(2, "\n");
	*/
	if (redef_types(game) == -1)
		return (1);
	/*
	i = 0;
	while (game->type[i])
	{
		dprintf(2, "%s", game->type[i]);
		i++;
	}
	*/
	/*
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
	*/
	if (redef_map(game) == -1)
		return (1);
	/*
	j = 0;
	while (game->map[j])
	{
		dprintf(2, "%s", game->map[j]);
		j++;
	}
	*/
	if (check_err_map(game) == -1)
		return (1);
	return (0);
}

	//TYPES:
	//enlever les espaces en trop				OK
	//verifier que tous les types sont presents		OK
	//reordonner les types et garder juste le chemin	OK
	//verifier le chemin
	//F ou C: 	chiffre qui manque
	//		virgule en trop
	//		chiffre superieur a 255 ou un inferieur a(?)

	//MAP:
	//remplacer les whitespaces				OK
	//compter la plus grand chaine, completer avec des 1	OK
	//compter les rows et cols				OK
	// ligne vide dans la map
	//encadre de murs
	// verifier characteres autorises only
	//presence un seul player
	//taille de la map?
