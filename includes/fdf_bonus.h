/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:20:40 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/26 16:19:59 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H
# define ON_KEYDOWN 2
# define ON_DESTROY 17
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define X_AXIS 0
# define Y_AXIS 1
# define Z_AXIS 2
# define DEFAULT_COLOR 0x151515

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
};

# else

enum {
	K_ESC = 53,
};

# endif

typedef struct s_point
{
	float	axis[3];
	int		color;
	int		hex_color;
	int		ispoint;
}			t_point;

typedef struct s_color
{
	int		highest_color;
	int		ground_color;
	int		lowest_color;
	int		background;
}			t_color;

typedef enum s_drawtype
{
	line = 0,
	dot = 1
}	t_drawtype;

typedef struct s_map_data
{
	t_point			*points;
	t_point			limits;
	t_point			source;
	t_color			color;
	char			*mapread;
	float			ang[3];
	int				dimension;
	int				map_height;
	int				map_width;
	int				z_min;
	int				z_max;
	float			z_divisor;
	float			scale;
	int				renders;
	float			proportion;
	t_drawtype		drawtype;
}	t_map_data;

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
	t_map_data		map;
	int				fit;
}	t_fdf;

//ARG_HANDLER.C
int			arg_handler(int argc, char **argv);

//DRAW_LINE.C
int			pixel_in_window(t_point pixel);
void		draw_line_dda(t_fdf *fdf, t_point start, t_point end);
void		draw_wireframe(t_fdf *fdf, t_point *point);

//DRAW_MAP_UTILS.C
int			limits(t_point *points, int len);
int			get_color_value(t_fdf *fdf, int color);
void		apply_depth(t_point *proyect, float divisor, int len);
void		set_color(char *buffer, int endian, int color, int alpha);
void		duplicate_map(t_point *src, t_point *dst, int len);

//DRAW_MAP.C
int			draw_map(t_fdf *fdf);

//DRAW.C
void		my_mlx_pixel_put(t_fdf *fdf, t_point pixel);

//DRAW_MENU
void		draw_menu(t_fdf *fdf);

//INIT_MAP.C
void		init_map(t_map_data *map);

//INIT.C
int			init_image(t_fdf *fdf);
int			init_fdf(t_fdf *fdf, char *filename);

//KEYBINDS.C
int			clean_exit(t_fdf *fdf);
int			exit_fdf(int keycode, t_fdf *fdf);

//MAP_COLOR.C
int			gradient(int startcolor, int endcolor, int len, int pix);
void		color_points(t_map_data *map);

//MAP_PARSER_UTILS.C
void		check_z(t_map_data *map, int index);
int			valid_point(char *value);
int			check_hexcolor(char *line);
void		get_mapsize(t_map_data *map);

//MAP_PARSER.C
void		map_parser(t_map_data *map, char *filename);

//MATRIX.C
void		init_matrix(float (*matrix)[3]);
t_point		matrix_multiplier(float matrix[3][3], t_point point);

//PROJECTION.C
void		project_isometric(t_map_data *map);
void		project_ortho(t_point *points, t_point *projection, int len);

//ROTATION_MATRICES.C
void		rotate_x(t_point *points, t_point *projection, float ang, int len);
void		rotate_y(t_point *points, t_point *projection, float ang, int len);
void		rotate_z(t_point *points, t_point *projection, float ang, int len);

//TRANSFORMATION_MATRICES.C
void		scale(t_point *points, int scale, int len);
void		translate(t_point *points, t_point move, int len);

//UTILS.C
void		error_split_loadpoint(t_map_data *map);
int			destroy_fdf(t_fdf *fdf);
void		exit_error(char	*str);
void		free_split(char **ptr);
void		free_map(t_map_data *map);

#endif