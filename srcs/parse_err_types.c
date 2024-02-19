#include "cub3D.h"

t_img	*xpm_img(t_game *game, char *img path)
{
	t_img	new_img;

	new_img.w = 80; //A DEFINIR
	new_img.h = 80; //A DEFINIR
	new_img.img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			img_path, &(new_img.w), &(new_img.h));
	if (!new_img.img_ptr)
		return (ft_putstr_fd("Error\nWrong texture path\n", 2), NULL);
	new_img.addr = mlx_get_data_addr(new_img.img_ptr,
			&new_img.bpp, &new_img.line_len,
			&new_img.endian);
	if (!new_img.addr)
		return (ft_putstr_fd("Bad xpm adress\n", 2), NULL);
	return (new_img);
}

int	check_err_types(t_game *game)
{
	game->no = xpm_image(game, "./img/no.xpm");
	if (!game->no.img_ptr)
		return (-1);
	game->so = xpm_image(game, "./img/so.xpm");
	if (!game->so.img_ptr)
		return (-1);
	game->ea = xpm_image(game, "./img/ea.xpm");
	if (!game->ea.img_ptr)
		return (-1);
	game->we = xpm_image(game, "./img/we.xpm");
	if (!game->we.img_ptr)
		return (-1);
	if (parse_colors(game) == -1)
		return (-1); // reprendre ici
	return (0);
}
//
	//verifier le chemin
	//F ou C: 	chiffre qui manque
	//		virgule en trop
	//		chiffre superieur a 255 ou un inferieur a(?)
