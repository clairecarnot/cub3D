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

# define BONUS 1
# define DIST_MOUSE 20
# define SCREEN_W 640
# define UDIV 7
# define VDIV 7
# define VMOVE 200

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
	char	*addr;
	int		h;
	int		w;
	int		bpp;
	int		line_len;
	int		endian;

	int		*full_buf;
	int		size;
}		t_img;

typedef struct s_anim
{
	t_list	*imgs;
	int		nb_img;
	int		cur_nb;
	int		cur_time;
	int		update_time;
	int		w;
	int		h;
	int		*tex;
}		t_anim;

typedef struct s_sprite
{
	double	x;
	double	y;
	t_anim	*anim;
}		t_sprite;

typedef struct s_game
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			*no;
	t_img			*so;
	t_img			*ea;
	t_img			*we;
	t_img			*door;
	t_img			*spr;
	t_anim			*anim;
	int				anim_flag;
	int				*f;
	int				*c;
	unsigned int	f_color;
	unsigned int	c_color;
	char			**map;
	char			**type;
	int				rows;
	int				cols;
	unsigned int	**buf;
	t_img			*image;

	int				key_w;
	int				key_s;
	int				key_a;
	int				key_d;
	int				key_left;
	int				key_right;
	int				key_q;
	int				key_e;

	int				screen_w;
	int				screen_h;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;

	double			camera_x;
	double			raydir_x;
	double			raydir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;

	int				line_height;
	int				pitch;
	int				draw_start;
	int				draw_end;
	int				tex_num;
	double			wall_x;
	int				tex_x;
	int				tex_y;
	double			step;
	double			tex_pos;

	double			move_speed;

	double			olddir_x;
	double			oldplane_x;

	int				tex_w;
	int				tex_h;
	int				nb_tex;
	unsigned int	**tex;

	t_sprite		*sprite;
	int				num_sprites;
	double			z_buffer[SCREEN_W];
	int				*sprite_order;
	double			*sprite_distance;
	double			sprite_x;
	double			sprite_y;
	double			inv_det;
	double			transform_x;
	double			transform_y;
	int				sprite_screen_x;
	int				sprite_height;
	int				sprite_width;
	int				stripe;
	int				draw_start_y;
	int				draw_start_x;
	int				draw_end_y;
	int				draw_end_x;
	int				vmove_screen;

	double			p_x;
	double			p_y;
	int				col_perso;
	int				col_wall;
	int				col_door;
	int				col_floor;
	int				col_anim;
	int				x_mmap;
	int				y_mmap;
	int				box_size;

	int				m_y;
	int				m_x;
	int				d_y;
	int				d_x;

	int				click;
}		t_game;

/*--------------------------- main.c ---------------------------*/
void			init_loop(t_game *game);
int				main(int argc, char **argv);

/*--------------------------- clear.c ---------------------------*/
int				close_if(int *fd);
void			free_if(char *str);
void			free_img(t_game *game, t_img *img);
void			free_game2(t_game *game);
int				free_game(t_game *game);

/*--------------------------- clear2.c ---------------------------*/
void			free_tab_int(unsigned int **tab, int nb);
void			free_tab(char **tab);
void			ft_lstfree_int(t_list **lst);

/*--------------------------- getcontent1.c ---------------------------*/
int				check_extension(char **argv);
int				check_file_errors(char **argv);
int				get_types(t_game *game, char **argv);
void			is_newline(char *line, int *nl, int *rows);
void			count_rows(t_game *game, int fd, int *rows);

/*--------------------------- getcontent2.c ---------------------------*/
int				cpy_map_from_file(t_game *game, char **argv, int rows);
int				get_map(t_game *game, int fd, char **argv);
void			delete_types_nl(t_game *game);
int				sort_content(t_game *game, char **argv);
int				get_file_content(t_game *game, char **argv);

/*--------------------------- getcontent_bonus1.c ---------------------------*/
int				*get_one_img_data(t_game *game, t_img *img);
t_img			*create_new_img(t_game *game, t_anim *anim);
int				*slice_anim(t_game *game, t_anim *anim, int x, int y);
t_list			*create_imgs_lst(t_game *game, t_anim *anim);
t_anim			*anim_init(t_game *game, int update_time);

/*--------------------------- getcontent_bonus2.c ---------------------------*/
int				sprite_init(t_game *game);
int				create_sprite_utils(t_game *game);
int				bonus_contents(t_game *game);

/*--------------------------- parse_type1.c ---------------------------*/
int				is_wspc_excl_nl(char c);
int				check_types(char **new);
void			swap_ptrs(char **s1, char **s2);
int				ptr_to_swap(char *s);
int				search_type(char *type, char **new);

/*--------------------------- parse_type2.c ---------------------------*/
int				check_alltypes(char **new);
int				reorder_new(char **new);
int				clean_types(char **new);
char			*init_set(void);
int				redef_types(t_game *game);

/*--------------------------- parse_map1.c ---------------------------*/
char			repl_char(t_game *game, int i, int j);
int				replace_empty_chars(t_game *game);

/*--------------------------- parse_map2.c ---------------------------*/
int				len_max(char **tab);
char			*redef_rows_bis(char *map, int lmax);
char			*redef_rows(char *map, int lmax);
int				rmv_end_nl(t_game *game);
int				redef_map(t_game *game);

/*--------------------------- parse_err_map.c ---------------------------*/
int				valid_char(char c);
int				valid_char_bonus(t_game *game, char c);

/*--------------------------- parse_err_map.c ---------------------------*/
int				contains_empty_nl(t_game *game);
int				contains_forbid_chars(t_game *game);
int				wrong_nb_player(t_game *game);
int				map_not_closed(t_game *game);
int				check_err_map(t_game *game);

/*--------------------------- parse_err_types.c ---------------------------*/
int				check_chars(char *s, char c);
t_img			*xpm_img(t_game *game, char *img_path, int w, int h);
int				get_nb(char *color);
int				*parse_colors(char *identifier);
int				check_err_types(t_game *game);

/*--------------------------- parse_err_types2.c ---------------------------*/
int				get_each_img_data(t_game *game, t_img *img, int i);
int				get_imgs_data(t_game *game);

/*--------------------------- parsing.c ---------------------------*/
int				tab_size(char **tab);
int				parse_content(t_game *game);

//--------------------------- init.c ---------------------------//
void			get_dir2(t_game *game, char c);
void			get_dir(t_game *game, char c);
void			get_pos(t_game *game);
void			init_mlx(t_game *game);
t_game			*init_game(void);

//--------------------------- handle.c ---------------------------//
int				handle_no_event(t_game *game);
int				handle_keypress(int keysym, t_game *game);
int				handle_keyrelease(int keysym, t_game *game);

//--------------------------- display.c ---------------------------//
int				init_buf(t_game *game);
void			wall_size(t_game *game);
void			dda_algo(t_game *game);
void			init_side(t_game *game);
int				display(t_game *game, int x);

//--------------------------- draw.c ---------------------------//
void			draw(t_game *game);

//--------------------------- sprites.c ---------------------------//
void			swap_dist(double *a, double *b);
void			swap_sprite(t_sprite *a, t_sprite *b);
void			sort_sprites(t_sprite *sprite, double *dist, int numspr);
t_list			*ft_lstget(t_list *lst, int index);
void			update_sprite(t_game *game);

//--------------------------- texture.c ---------------------------//
int				get_color(int *tab_c);
void			pixel_color_ceiling_floor(t_game *game, int x);
void			pixel_color_walls(t_game *game, int x);
void			texture_wall_orientation(t_game *game);
void			texture(t_game *game, int x);

void			draw_box(t_game *game, int color, int x, int y);
void			minimap(t_game *game);

//--------------------------- texture2.c ---------------------------//
void			project_sprites_ter(t_game *game);
void			project_sprites_bis(t_game *game);
void			project_sprites(t_game *game, int i);
void			pixel_color_sprites(t_game *game);

//--------------------------- pixels.c ---------------------------//
unsigned int	get_pixel_img(t_img src, int x, int y);
void			put_pixel_img(t_img dst, int x, int y, int color);
void			put_pixel_img_anims(t_img dst, int x, int y, int color);

//------------------------- move.c --------------------------//
void			move_up(t_game *game);
void			move_down(t_game *game);
void			move_right(t_game *game);
void			move_left(t_game *game);

//------------------------- move_mouse.c --------------------------//
void			mouse_pos(t_game *game, int x, int y);
int				mouse_mv(int x, int y, t_game *game);
int				mouse_click(int button, int x, int y, t_game *game);

//------------------------- minimap.c --------------------------//
void			perso(t_game *game);
void			minimap(t_game *game);

//------------------------- minimap2.c --------------------------//
void			right_down(t_game *game, int y, int x);
void			left_down(t_game *game, int y, int x);
void			left_up(t_game *game, int y, int x);
void			right_up(t_game *game, int y, int x);

//------------------------- rotate.c --------------------------//
void			rotate_right(t_game *game, double mult);
void			rotate_left(t_game *game, double mult);

//-------------------------- free_exit.c -------------------------//
void			free_buffer(t_game *game);
int				ft_exit(t_game *game);

#endif