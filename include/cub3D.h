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
 * type[0] = NO
 * type[1] = SO
 * type[2] = WE
 * type[3] = EA
 * type[4] = floor
 * type[5] = ceiling
 * type[6] = NULL
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

/*--------------------------- clear.c ---------------------------*/
int	close_if(int *fd);
void	free_if(char *str);
void	free_tab(char **tab);
int	free_game(t_game *game);

/*--------------------------- getcontent1.c ---------------------------*/
int	check_extension(char **argv);
int	check_file_errors(char **argv);
int	get_types(t_game *game, char **argv);
void	is_newline(char *line, int *nl, int *rows);
void	count_rows(t_game *game, int fd, int *rows);

/*--------------------------- getcontent2.c ---------------------------*/
int	cpy_map_from_file(t_game *game, char **argv, int rows);
int	get_map(t_game *game, int fd, char **argv);
int	sort_content(t_game *game, char **argv);
int	get_file_content(t_game *game, char **argv);

/*--------------------------- parse_type1.c ---------------------------*/
int	is_wspc_excl_nl(char c);
int	check_types(char **new);
void	swap_ptrs(char **s1, char **s2);
int	ptr_to_swap(char *s);
int	search_type(char *type, char **new);

/*--------------------------- parse_type2.c ---------------------------*/
int	check_alltypes(char **new);
int	reorder_new(char **new);
int	clean_types(char **new);
char	*init_set(void);
int	redef_types(t_game *game);

/*--------------------------- parse_map1.c ---------------------------*/
char	repl_char(t_game *game, int i, int j);
int	replace_empty_chars(t_game *game);

/*--------------------------- parse_map2.c ---------------------------*/
int	len_max(char **tab);
char	*redef_rows_bis(char *map, int lmax);
char	*redef_rows(char *map, int lmax);
int	rmv_end_nl(t_game *game);
int	redef_map(t_game *game);

/*--------------------------- parse_err_map.c ---------------------------*/
int	check_err_map(t_game *game);

/*--------------------------- parsing.c ---------------------------*/
int	parse_content(t_game *game);

#endif