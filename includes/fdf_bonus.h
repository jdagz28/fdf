/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:20:40 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/19 15:20:59 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H
# define ON_KEYDOWN 2
# define ON_DESTROY 17

# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "mlx.h"

# ifdef LINUX

enum {
	K_ESC = 65307,
	K_UP = 65362,
	K_DOWN = 65364,
	K_LEFT = 65361,
	K_RIGHT = 65363,
	K_W = 119,
	K_S = 115,
	K_A = 97,
	K_D = 100,
	K_P = 112,
	K_MINUS = 61,
	K_PLUS = 10,
	K_R = 114,
	K_U = 117,
	K_J = 106,
	K_I = 105,
	K_K = 107,
	K_O = 111,
	K_L = 108,
	K_NUM_4 = 65430,
	K_NUM_6 = 65432,
	K_NUM_8 = 65431,
	K_NUM_2 = 65433,
	K_NUM_MINUS = 65453,
	K_NUM_PLUS = 65451
};

# else

enum {
	K_ESC = 53,
	K_UP = 126,
	K_DOWN = 125,
	K_LEFT = 123,
	K_RIGHT = 124,
	K_W = 13,
	K_S = 1,
	K_A = 0,
	K_D = 2,
	K_P = 35,
	K_MINUS = 27,
	K_PLUS = 24,
	K_R = 15,
	K_U = 32,
	K_J = 38,
	K_I = 34,
	K_K = 40,
	K_O = 31,
	K_L = 37,
	K_NUM_4 = 86,
	K_NUM_6 = 88,
	K_NUM_8 = 91,
	K_NUM_2 = 84,
	K_NUM_MINUS = 78,
	K_NUM_PLUS = 69
};

# endif

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}		t_color;

typedef struct s_map_data
{
	int				**map;
	int				size_x;
	int				size_y;
	int				rect_size;
	int				rect_size_x;
	int				rect_size_y;
	int				pos_x;
	int				pos_y;
	int				pos_z;
	int				height_mult;
	int				min_height;
	int				max_height;
}	t_map_data;

typedef enum s_projection
{
	isometric = 0,
	perspective = 1
}	t_projection;

typedef struct s_vector3d
{
	double	x;
	double	y;
	double	z;
}	t_vector3d;

typedef struct s_matrix3d
{
	t_vector3d	*v1;
	t_vector3d	*v2;
	t_vector3d	*v3;
}	t_matrix3d;	

typedef struct s_plane3d
{
	t_vector3d		*p1;
	t_vector3d		*p2;
	t_vector3d		*p3;
	t_vector3d		*v1;
	t_vector3d		*v2;
}	t_plane3d;

typedef struct s_line3d
{
	t_vector3d	*p1;
	t_vector3d	*p2;
	t_vector3d	*v1;
}	t_line3d;

typedef struct s_diplay_info
{
	int				width;
	int				height;
	double			eye_z;
	t_matrix3d		*rotation_matrix;
	t_vector3d		*rotation_center;
	int				rotation_speed;
	int				screen_depth;
	t_plane3d		*screen_plane;
	int				background_color;
	int				pos_x;
	int				pos_y;
	int				pos_z;
	int				mov_speed;
	int				zoom_speed;
	t_projection	projection;
}	t_display_info;

typedef struct s_data_mlx
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data_mlx;

typedef struct s_fdf
{
	t_data_mlx		*mlx_data;
	void			*mlx;
	void			*win;
	char			*display_title;
	t_map_data		*map;
	t_display_info	*display;
}	t_fdf;

typedef enum s_rotation
{
	x_axis = 0,
	y_axis = 1,
	z_axis = 2
}	t_rotation;

//DRAW_LINE.C
void			draw_line_dda(t_fdf *fdf, const int coords[4], int line_color);
void			draw_line(t_fdf *fdf, t_vector3d *v1, t_vector3d *v2, \
							int line_color);

//DRAW_MAP.C
void			draw_y(t_fdf *fdf, t_vector3d ***map_projection);
void			draw_x(t_fdf *fdf, t_vector3d ***map_projection);
void			adapt_size_isometric(t_fdf *fdf);
void			draw_map(t_fdf *fdf);

//DRAW.C
void			my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color);
void			draw_pixels(t_fdf *fdf, int color);

//INIT.C
t_display_info	*screen_display_init(void);
int				init_screen(t_fdf *data);
t_fdf			*init_fdf(char **argv);
int				init_image(t_fdf *fdf);
int				init_display(t_fdf *fdf, char **argv);

//INIT_UTILS.C
t_plane3d		*plane_from_points(t_vector3d *p1, t_vector3d *p2, \
									t_vector3d *p3);
t_plane3d		*get_screen_plane(int width, int height, int viewer_distance);

// MAP_PARSER_UTILS.C
void			free_split(char **split, size_t len);
int				count_words(char *str, char sep);
int				**ft_realloc_2darr(int **src, size_t elem_size, \
					size_t arr_size, size_t new_size);

// MAP_PARSER.C
t_map_data		*init_map(char *filename, int *fd);
t_map_data		*map_parser(char *filename);

//PROJECTIONS_GET.C
int				free_map_projection_pt(t_vector3d ***res, int size_y, \
					int size_x, int size_last);
t_vector3d		***get_map_projection(t_fdf *fdf);

// PROJECTIONS_LINE.C
void			free_line3d(t_line3d *line3d);
t_line3d		*line_from_points(t_vector3d *p1, t_vector3d *p2);
t_line3d		*line_from_point_and_vector(t_vector3d *p, t_vector3d *d);

// PROJECTIONS.C
t_vector3d		*apply_rotation_matrix_to_point(t_vector3d *point, \
											t_display_info *display_info);
t_vector3d		*project_perspective(t_vector3d *pt, t_plane3d *plane, \
								t_display_info *display_info);
t_vector3d		*project_isometric(t_vector3d *pt, t_plane3d *plane, \
								t_display_info *display_info);

//MAP_PARSER.C
t_map_data		*map_parser(char *filename);

//MATRIX_UTILS.C
int				valid_matrix(t_matrix3d *matrix);
t_vector3d		*matrix_mult_vector(t_matrix3d *matrix, t_vector3d *vec);
t_matrix3d		*matrix_multiplier(t_matrix3d *m1, t_matrix3d *m2);
t_matrix3d		*new_3dmatrix(t_vector3d *v1, t_vector3d *v2, t_vector3d *v3);

//ROTATION.C
t_matrix3d		*get_rot_z(double angle);
t_matrix3d		*get_rot_y(double angle);
t_matrix3d		*get_rot_x(double angle);
t_matrix3d		*get_rotation_matrix(double angle, t_rotation axis, int is_rad);
void			add_angle_to_rotation_matrix(t_matrix3d *rotation_matrix, \
					double angle, t_rotation axis, int is_rad);

//UTILS.C
int				destroy_fdf(t_fdf *fdf);
void			*free_vectors(t_vector3d *v1, t_vector3d *v2, t_vector3d *v3);
void			*free_map(t_map_data *data);
int				file_extension_checker(const char *filename, \
						const char *extension);

//UTILS_2.C
void			free_map_destroy(t_map_data *map);
void			free_points(t_vector3d *p1, t_vector3d *p2, t_vector3d *p3);
void			*free_map_parser(t_map_data *data, char *mapstring);
int				min_scale(int a, int b);
int				add_padding(int a, int b);
// void			print_matrix(t_matrix3d *matrix);
// void			print_map(t_map_data *map);

//UTILS_3.C
void			*free_map_projection(t_vector3d ***res, int size_x, int size_y, \
								int size_last);
void			free_3dplane(t_plane3d *plane);
void			*free_3dmatrix(t_matrix3d *matrix);

//VECTORS.C
t_vector3d		*vec_add(t_vector3d *v1, t_vector3d *v2);
t_vector3d		*vec_sub(t_vector3d *v1, t_vector3d *v2);
t_vector3d		*cross(t_vector3d *v1, t_vector3d *v2);
t_vector3d		*new_3dvector(double x, double y, double z);

//VECTORS_2.C
t_vector3d		*vec_invert(t_vector3d *v);
void			add_vec_inplace(t_vector3d *addee, t_vector3d *added);
t_vector3d		*vec_scale(t_vector3d *v, double scalar);

//VECTORS_INTERSECT.C
t_vector3d		*line_plane_intersect3d(t_line3d *line, t_plane3d *plane);

//VECOTRS_SOLVER.C
t_vector3d		*solve_general(t_vector3d *v1, t_vector3d *v2, t_vector3d *v3, \
							t_vector3d *v_sol);

//CONTROLS.C
int				clean_exit(t_fdf *fdf);
int				keybindings(int keycode, t_fdf *fdf);

#endif