/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 22:09:04 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/23 03:02:11 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int	pixel_in_window(t_point pixel)
{
	if (pixel.axis[X] < 0 || pixel.axis[X] > WINX)
		return (0);
	if (pixel.axis[Y] < 0 || pixel.axis[Y] > WINY)
		return (0);
	return (1);
}

void	draw_line_dda(t_fdf *fdf, t_point start, t_point end)
{
	int		steps;
	float	pos[2];
	float	indices[2];
	int		i;

	if (!pixel_in_window(start) && pixel_in_window(end) == 0)
		return ;
	if (abs(end.axis[X_AXIS] - start.axis[X_AXIS]) \
			> abs(end.axis[Y_AXIS] - start.axis[Y_AXIS]))
		steps = abs(end.axis[X_AXIS] - start.axis[X_AXIS]);
	else
		steps = abs(end.axis[Y_AXIS] - start.axis[Y_AXIS]);
	indices[X_AXIS] = (end.axis[X_AXIS] - start.axis[X_AXIS]) / (float)steps;
	indices[Y_AXIS] = (end.axis[Y_AXIS] - start.axis[Y_AXIS]) / (float)steps;
	pos[X_AXIS] = start.axis[X_AXIS];
	pos[Y_AXIS] = start.axis[Y_AXIS];
	i = 0;
	while (i <= steps)
	{
		my_mlx_pixel_put(fdf, pos[X_AXIS], pos[Y_AXIS], line_color);
		pos[X_AXIS] += indices[X_AXIS];
		pos[Y_AXIS] += indices[Y_AXIS];
		i++;
	}
}

void	connect_points(t_point *point, t_fdf *fdf, int density, int line)
{
	int	i;
	int	x_end;
	int	y_end;

	i = 0;
	while (i < (int)fdf->map.limits.axis[X_AXIS])
	{
		x_end = i + density;
		if (x_end >= (int)fdf->map.limits.axis[X_AXIS])
			x_end = (int)fdf->map.limits.axis[X_AXIS] - 1;
		y_end = i + (int)fdf->map.limits.axis[X_AXIS] * density;
		draw_line_dda(fdf, point[i], point[x_end]);
		if (line + density < (int)fdf->map.limits.axis[Y_AXIS])
			draw_line_dda(fdf, point[i], point[y_end]);
		i += density;
	}
}

void	draw_wireframe(t_fdf *fdf, t_point point)
{
	int	i;
	int	density;

	density = 8 / fdf->map.scale;
	if (density == 0)
		density == 1;
	i = 0;
	while (i < fdf->map.dimension)
	{
		connect_points(&point[i], fdf, density, i \
							/ fdf->map.limits.axis[X_AXIS]);
		i = i + fdf->map.limits.axis[X_AXIS] * density;

	}
}
