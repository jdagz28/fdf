/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:45:45 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/27 12:17:13 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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

static void	fit_window(t_fdf *fdf, t_point *projection)
{
	fdf->map.source.axis[X_AXIS] = ((WINDOW_WIDTH - MENU_WIDTH - 100) / 2);
	fdf->map.source.axis[Y_AXIS] = WINDOW_HEIGHT / 2;
	fdf->map.source.axis[Z_AXIS] = 0;
	fdf->map.scale = 1;
	duplicate_map(fdf->map.points, projection, fdf->map.dimension);
	apply_3d_to_points(fdf, projection);
	while (!(limits(projection, fdf->map.dimension)))
	{
		duplicate_map(fdf->map.points, projection, fdf->map.dimension);
		apply_3d_to_points(fdf, projection);
		fdf->map.scale = fdf->map.scale + 0.2;
	}
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

static void	draw_type(t_fdf *fdf, t_point *projection)
{
	if (fdf->fit == 1)
	{
		fit_window(fdf, projection);
	}
	if (fdf->map.drawtype == line)
	{	
		draw_wireframe(fdf, projection);
	}
	else if (fdf->map.drawtype == dot)
	{
		draw_dotpoint(fdf, projection);
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
	duplicate_map(fdf->map.points, projection, fdf->map.dimension);
	apply_3d_to_points(fdf, projection);
	draw_type(fdf, projection);
	draw_menu(fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->mlx_data->img, 0, 0);
	free(projection);
	return (1);
}
