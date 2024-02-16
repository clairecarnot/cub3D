#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <unistd.h>

/*
 * char	**type
 * type[1] = NO
 * type[2] = SO
 * type[3] = WE
 * type[4] = EA
 * type[5] = floor
 * type[6] = ceiling
 * type[7] = NULL
 */

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	char		**type;
	int			rows;
	int			cols;
}		t_game;

/*--------------------------- main.c ---------------------------*/
t_game	*init_game(void);
int main(int argc, char **argv);

/*--------------------------- getcontent1.c ---------------------------*/
int	check_extension(char **argv);
int	check_file_errors(char **argv);
int	get_types(t_game *game, char **argv);
void	is_newline(char *line, int *nl, int *rows);
void	count_rows(t_game *game, int fd, int *rows);

/*--------------------------- getcontent2.c ---------------------------*/
//int	is_wspc(char c);
int	cpy_map_from_file(t_game *game, char **argv, int rows);
int	get_map(t_game *game, int fd, char **argv);
int	sort_content(t_game *game, char **argv);
int	get_file_content(t_game *game, char **argv);

/*--------------------------- clear.c ---------------------------*/
int	close_if(int *fd);
void	free_if(char *str);
void	free_tab(char **tab);
int	free_game(t_game *game);

#endif