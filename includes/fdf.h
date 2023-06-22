/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:20:40 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/22 11:14:23 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
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
	t_drawtype		drawtype;
}	t_map_data;

typedef enum s_projection
{
	isometric = 0,
	perspective = 1
}	t_projection;

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
	t_projection	projection;
}	t_fdf;

//ARG_HANDLER.C
int	arg_handler(int argc, char **argv);

//INIT.C
int	init_fdf(t_fdf *fdf, char *filename);
int	init_image(t_fdf *fdf);

//MAP_COLOR.C
void	color_points(t_map_data *map);

//MAP PARSER.C
void	map_parser(t_map_data *map, char *filename);

//MAP PARSER_UTILS.C
int	valid_point(char *value);
int	check_hexcolor(char *line);
void	error_split_loadpoint(t_map_data *map);
void	get_mapsize(t_map_data *map);

//INIT_MAP.C
void	initialize_colors(t_map_data *map);
void	init_map(t_map_data *map);

//UTILS.C
int	destroy_fdf(t_fdf *fdf);
void	exit_error(char	*str);
void	free_split(char **split, size_t len);
void	free_map(t_map_data *map);

//DEBUG.C
void	print_map(t_map_data *map);

#endif