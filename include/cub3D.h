#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"

# include <stdio.h>

# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_img
{
	void	*img_ptr;
	// char	*addr;
	int		height;
	int		width;
	// int		bpp;
	// int		line_len;
	// int		endian;
}		t_img;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		image_base;
	char		**map;
	double		posX;
	double
}		t_game;

int main(int argc, char **argv);

//--------------------------- handle.c ---------------------------//
int	handle_no_event(t_game *game);
int	handle_input(int keysym, t_game *game);

//------------------------- img_utils.c --------------------------//
t_img	new_img(int w, int h, t_game *game);

//-------------------------- free_exit.c -------------------------//
int	ft_exit(t_game *game);

#endif