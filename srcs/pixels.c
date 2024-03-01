#include "cub3D.h"

unsigned int	get_pixel_img(t_img src, int x, int y)
{
//	return (*(unsigned int *)((src.full_buf
	return (*(unsigned int *)((src.addr
			+ (y * src.line_len) + (x * src.bpp / 8))));
}

void	put_pixel_img(t_img dst, int x, int y, int color)
{
//	int	*img;
	char	*img;

	if (color == (int)0xFF000000)
		return ;
	if (x >= 0 && y >= 0 && x < dst.w && y < dst.h)
	{
//		img = dst.full_buf + (y * dst.line_len + x * (dst.bpp / 8));
		img = dst.addr + (y * dst.line_len + x * (dst.bpp / 8));
		*(unsigned int *) img = color;
	}
}

void	put_pixel_img_sprites(t_img dst, int x, int y, int color)
{
//	int	*img;
	char	*img;

	if (x >= 0 && y >= 0 && x < dst.w && y < dst.h)
	{
//		dprintf(2, "x = %d\n", x);
//		dprintf(2, "y = %d\n", y);
//		dprintf(2, "dst.line_len = %d\n", dst.line_len);
//		dprintf(2, "dst.bpp / 8) = %d\n", dst.bpp / 8);
//		img = dst.full_buf + (y * dst.line_len + x * (dst.bpp / 8));
		img = dst.addr + (y * dst.line_len + x * (dst.bpp / 8));
		*(unsigned int *) img = color;
	}
}
