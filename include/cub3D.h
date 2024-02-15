#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"

# include <stdio.h>

# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
}		t_game;

int main(int argc, char **argv);

#endif