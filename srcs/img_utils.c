#include "../include/cub3D.h"

t_img	new_img(int w, int h, t_game *game)
{
	t_img	image;

	image.img_ptr = mlx_new_image(game->mlx_ptr, w, h);
	if (!image.img_ptr)
	{
		write (2, "Error\nFailed to create an image\n", 32);
		ft_exit(game);
	}
	// image.addr = mlx_get_data_addr(image.img_ptr, &(image.bpp),
			// &(image.line_len), &(image.endian));
	// if (!image.addr)
	// {
		// write (2, "Error\nFailed to create an address for an img\n", 44);
		// mlx_destroy_image(game->mlx_ptr, image.img_ptr);
		// image.img_ptr = NULL;
		// ft_exit(game);
	// }
	image.w = w;
	image.h = h;
	return (image);
}