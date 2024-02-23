#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"

# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>
# include <X11/X.h>
# include <X11/keysym.h>


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

typedef struct s_img
{
	void	*img_ptr;
	// char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		line_len;
	int		endian;

	int		*full_buf;
	int 	size;
}		t_img;

typedef struct s_game
{

	void			*mlx_ptr;
	void			*win_ptr;
	// t_img			image_base;
	t_img		*no;
	t_img		*so;
	t_img		*ea;
	t_img		*we;
	int		*f;
	int		*c;
	char			**map;
	char			**type;
	int				rows;
	int				cols;
	unsigned int	**buf;
	// char		*full_buf;
	t_img			*image;

	int				screen_w;
	int				screen_h;
	double			posX;
	double			posY;
	double			dirX;
	double			dirY;
	double			planeX;
	double			planeY;
	double			time;//
	double			oldtime;//

	double			cameraX;
	double			rayDirX;
	double			rayDirY;
	int				mapX;
	int				mapY;
	double			sideDistX;
	double			sideDistY;
	double			deltaDistX;
	double			deltaDistY;
	double			perpWallDist;
	int				stepX;
	int				stepY;
	int				hit;
	int				side;

	int				lineHeight;
	int				drawStart;
	int				drawEnd;
	
	// double			frameTime;
	double			moveSpeed;
	double			rotSpeed;

	double			oldDirX;
	double			oldPlaneX;

	int				tex_w;
	int				tex_h;
	int				nb_tex;
	unsigned int	**tex;
}		t_game;

/*--------------------------- main.c ---------------------------*/
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
void	delete_types_nl(t_game *game);
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
int	contains_empty_nl(t_game *game);
int	contains_forbid_chars(t_game *game);
int	wrong_nb_player(t_game *game);
int	map_not_closed(t_game *game);
int	check_err_map(t_game *game);

/*--------------------------- parse_err_types.c ---------------------------*/
int	check_chars(char *s, char c);
t_img	*xpm_img(t_game *game, char *img_path);
int	get_nb(char *color);
int	*parse_colors(char *identifier);
int	check_err_types(t_game *game);

/*--------------------------- parsing.c ---------------------------*/
int	tab_size(char **tab);
int	parse_content(t_game *game);

//--------------------------- init.c ---------------------------//
int		init_buf(t_game *game);
void	get_dir(t_game *game, char c);
void	get_pos(t_game *game);
void	init_info(t_game *game);
void	init_mlx(t_game *game);
t_game	*init_game(void);

//--------------------------- handle.c ---------------------------//
int		handle_no_event(t_game *game);
int		handle_keypress(int keysym, t_game *game);

//--------------------------- display.c ---------------------------//
void	draw(t_game *game);
void	save_pixel(t_game *game, int x, int color);
int		display(t_game *game);

//------------------------- move.c --------------------------//
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_right(t_game *game);
void	move_left(t_game *game);

//------------------------- rotate.c --------------------------//
void	rotate_right(t_game *game);
void	rotate_left(t_game *game);

//------------------------- img_utils.c --------------------------//
// t_img	new_img(int w, int h, t_game *game);

//-------------------------- free_exit.c -------------------------//
void	free_buffer(t_game *game);
int	ft_exit(t_game *game);

#endif