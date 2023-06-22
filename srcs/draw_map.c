/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:45:45 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/22 13:53:28 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


static void	apply_3d_to_points(t_fdf *fdf, t_point *points)
{
	apply_depth(points, fdf->map.z_divisor, fdf->map.dimension);
	rotate_x(points, points, fdf->map.ang[X_AXIS], fdf->map.dimension);
	rotate_y(points, points, fdf->map.ang[Y_AXIS], fdf->map.dimension);
	rotate_z(points, points, fdf->map.ang[Z_AXIS], fdf->map.dimension);
	//!ortho projection
	scale(points, fdf->map.scale, fdf->map.dimension);
	translate(points, fdf->map.source, fdf->map.len);
}

static int	get_color_value(t_fdf *fdf, int color)
{
	if (fdf->mlx_data->bits_per_pixel != 32)
		color = mlx_get_color_value(fdf->mlx, color);
	return (color);
}


static void	draw_bakground(t_fdf *fdf. int background)
{
	int	axis[2];
	int	pixel;
	int	color;

	bakground = get_color_value(fdf, bakground);
	axis[X_AXIS] = 0;
	axis[Y_AXIS] = 0;
	while (axis[Y_AXIS] < WINDOW_WIDTH)
	{
		while (axis[X_AXIS] < WINDOW_HEIGHT)
		{
			pixel = (axis[Y_AXIS] * fdf->mlx_data->line_length) \
					+ (axis[X_AXIS] * 4);
			set_color(&fdf->mlx_data->addr[pixel], \
					fdf->mlx_data.endian, color, 1);
			axis[X_AXIS]++;
		}
		axis[Y_AXIS]++;
		axis[X_AXIS] = 0;
	}
}


int	draw_map(t_fdf *fdf)
{
	t_point	*map_points;

	projection = malloc(sizeof(t_point) * fdf->map.dimension);
	if (!projection)
		return (NULL);
	fdf->map.renders++;
	draw_background(fdf, fdf->map.color.background);
	duplicate_map(fdf->map.points, map_points, fdf->map.dimension);
	apply_3d_to_points(fdf, map_points);
}
