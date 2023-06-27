/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_dotpoint_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 05:11:14 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/27 05:42:25 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	draw_eachpoint(t_fdf *fdf, t_point pixel, t_point point, \
							int coord)
{
	int	i;
	
	i = point.axis[X_AXIS];
	while (i <= point.axis[X_AXIS] + coord)
	{
		pixel.axis[X_AXIS] = i;
		pixel.axis[Y_AXIS] = (int)point.axis[Y_AXIS] + coord;
		my_mlx_pixel_put(fdf, pixel);
		pixel.axis[X_AXIS] = i;
		pixel.axis[Y_AXIS] = (int)point.axis[Y_AXIS] - coord;
		my_mlx_pixel_put(fdf, pixel);
		i++;
	}
}

void	draw_point(t_fdf *fdf, t_point point, int radius)
{
	int		axis[2];
	int		change[2];
	int		error;
	t_point	pixel;

	axis[X_AXIS] = radius;
	axis[Y_AXIS] = 0;
	change[X_AXIS] = 1 - (radius << 1);
	change[Y_AXIS] = 0;
	pixel.color = point.color;
	while (axis[X] >= axis[Y])
	{
		draw_eachpoint(fdf, pixel, point, axis[Y_AXIS]);
		draw_eachpoint(fdf, pixel, point, axis[X_AXIS]);
		axis[Y]++;
		error += change[Y_AXIS];
		change[Y] += 2;
		if (((error << 1) + change[X_AXIS]) > 0)
		{
			axis[X_AXIS]--;
			error += change[X_AXIS];
			change[X_AXIS] += 2;
		}
	}
}

void	draw_dotpoint(t_fdf *fdf, t_point *projection)
{
	int	i;

	i = 0;
	while (i < fdf->map.dimension)
	{
		if (projection[i].ispoint)
			draw_point(fdf, projection[i], 1);
		i++;
	}
}