/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 22:09:04 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/22 10:52:25 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	gradient(int startcolor, int endcolor, int len, int pix)
{
	double	increment[3];
	int		new[3];
	int		newcolor;

	increment[0] = (double)((endcolor >> 16) - \
					(startcolor >> 16)) / (double)len;
	increment[1] = (double)(((endcolor >> 8) & 0xFF) - \
					((startcolor >> 8) & 0xFF)) / (double)len;
	increment[2] = (double)((endcolor & 0xFF) - (startcolor & 0xFF)) \
					/ (double)len;
	new[0] = (startcolor >> 16) + round(pix * increment[0]);
	new[1] = ((startcolor >> 8) & 0xFF) + round(pix * increment[1]);
	new[2] = (startcolor & 0xFF) + round(pix * increment[2]);
	newcolor = (new[0] << 16) + (new[1] << 8) + new[2];
	return (newcolor);
}

static void	load_color(int max, int min, t_point *point, t_color	color)
{
	point->color = DEFAULT_COLOR;
	if (point->hex_color > 0)
	{
		point->color = point->hex_color;
		return ;
	}
	if (point->axis[Z_AXIS] == max)
		point->color = color.highest_color;
	else if (point->axis[Z_AXIS] == 0)
		point->color = color.ground_color;
	else if (point->axis[Z_AXIS] == min && min != 0)
		point->color = color.lowest_color;
	else if (point->axis[Z_AXIS] > 0)
		point->color = gradient(color.ground_color, color.highest_color, \
		max, point->axis[Z_AXIS]);
	else
		point->color = gradient(color.lowest_color, color.ground_color, \
		-min, - (min - point->axis[Z_AXIS]));
}

void	color_points(t_map_data *map)
{
	int	i;

	i = 0;
	while (i < map->dimension)
	{
		load_color((int)map->limits.axis[Z_AXIS], map->z_min, \
		&map->points[i], map->color);
		i++;
	}
}
