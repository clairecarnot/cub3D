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
	return (0);
}

	//TYPES:
	//enlever les espaces en trop
	//verifier que tous les types sont presents
	//reordonner les types et garder juste le chemin
	//verfieir le chemin
	//F ou C: 	chiffre qui manque
	//		virgule en trop
	//		chiffre superieur a 255 ou un inferieur a(?)

	//MAP:
	//remplacer les whitespaces
	//compter la plus grand chaine, completer avec des 1
	//compter les rows et cols
	// ligne vide dans la map
	//encadre de murs
	// verifier characteres autorises only
	//presence un seul player
	//taille de la map?
