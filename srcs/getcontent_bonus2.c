 #include "cub3D.h" 

int	sprite_init(t_game *game)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'A')
			{
//				dprintf(2, "k = %d\n", k);
//				dprintf(2, "j = %d\n", j);
//				dprintf(2, "i = %d\n", i);
				game->sprite[k].x = j + 0.5;
				game->sprite[k].y = i + 0.5;
				game->sprite[k].anim = game->anim;
				k++;
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	create_sprite_utils(t_game *game)
{
	game->sprite = ft_calloc(game->numSprites, sizeof(t_sprite));
	if (!game->sprite)
		return (ft_putstr_fd("Bad malloc\n", 2), -1);
	sprite_init(game);
//	int i = 0;
//	while (i < game->numSprites)
//	{
//		dprintf(2, "i = %d\n", i);
//		dprintf(2, "x = %f\n", game->sprite[i].x);
//		dprintf(2, "y = %f\n", game->sprite[i].y);
//		i++;
//	}
	game->spriteOrder = ft_calloc(game->numSprites, sizeof(int));
	if (!game->spriteOrder)
		return (ft_putstr_fd("Bad malloc\n", 2), -1);
	game->spriteDistance = ft_calloc(game->numSprites, sizeof(double));
	if (!game->spriteDistance)
		return (ft_putstr_fd("Bad malloc\n", 2), -1);
	return (0);
}
