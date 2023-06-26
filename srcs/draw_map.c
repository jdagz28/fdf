/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:45:45 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/25 01:28:17 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>


void	project_ortho(t_point *points, t_point *projection, int len)
{
	int		i;
	float	projection_matrix[3][3];

	init_matrix(projection_matrix);
	projection_matrix[0][0] = 1;
	projection_matrix[1][1] = 1;
	i = 0;
	while (i < len)
	{
		projection[i] = matrix_multiplier(projection_matrix, points[i]);
		i++;
	}
}

static void	apply_3d_to_points(t_fdf *fdf, t_point *points)
{
	apply_depth(points, fdf->map.z_divisor, fdf->map.dimension);
	rotate_x(points, points, fdf->map.ang[X_AXIS], fdf->map.dimension);
	rotate_y(points, points, fdf->map.ang[Y_AXIS], fdf->map.dimension);
	rotate_z(points, points, fdf->map.ang[Z_AXIS], fdf->map.dimension);
	project_ortho(points, points, fdf->map.dimension);
	scale(points, fdf->map.scale, fdf->map.dimension);
	translate(points, fdf->map.source, fdf->map.dimension);
}

static int	get_color_value(t_fdf *fdf, int color)
{
	if (fdf->mlx_data->bits_per_pixel != 32)
		color = mlx_get_color_value(fdf->mlx, color);
	return (color);
}

static void	draw_background(t_fdf *fdf, int background)
{
	int	axis[2];
	int	pixel;
	int	color;

	background = get_color_value(fdf, background);
	axis[X_AXIS] = 0;
	axis[Y_AXIS] = 0;
	color = background;
	while (axis[Y_AXIS] < WINDOW_HEIGHT)
	{
		while (axis[X_AXIS] < WINDOW_WIDTH)
		{
			pixel = (axis[Y_AXIS] * fdf->mlx_data->line_length) \
					+ (axis[X_AXIS] * 4);
			set_color(&fdf->mlx_data->addr[pixel], \
					fdf->mlx_data->endian, color, 1);
			axis[X_AXIS]++;
		}
		axis[Y_AXIS]++;
		axis[X_AXIS] = 0;
	}
}

void	draw_type(t_fdf *fdf, t_point *projection)
{
	printf("print line\n");
	if (fdf->map.drawtype == line)
	{	
		printf("draw type identified as line\n");
		draw_wireframe(fdf, projection);
	}
}

int	draw_map(t_fdf *fdf)
{
	t_point	*projection;

	projection = malloc(sizeof(t_point) * fdf->map.dimension);
	if (!projection)
		exit(1);
	fdf->map.renders = fdf->map.renders + 1;
	draw_background(fdf, fdf->map.color.background);
	printf("Background drawn\n");
	print_map(&fdf->map);
	duplicate_map(fdf->map.points, projection, fdf->map.dimension);
	printf("Map duplicated\n");
	apply_3d_to_points(fdf, projection);
	printf("Elemental Rotation applied to points\n");
	draw_type(fdf, projection);
	//mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->mlx_data->img, 0, 0);
	free(projection);
	return (1);
}
