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

/*--------------------------- main.c ---------------------------*/
t_game	*init_game();
int main(int argc, char **argv);

/*--------------------------- getmap.c ---------------------------*/
int	check_extension(char **argv);
int	check_file_errors(char **argv);
char	**get_map(t_game *game, char **argv);

/*--------------------------- clear.c ---------------------------*/
int	close_if(int *fd);
int	free_game(t_game *game);

#endif