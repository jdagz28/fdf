/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 22:09:04 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/19 12:13:27 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	draw_line_dda(t_fdf *fdf, const int coords[4], int line_color)
{
	int		steps;
	float	pos[2];
	float	indices[2];
	int		i;

	if (abs(coords[2] - coords[0]) > abs(coords[3] - coords[1]))
		steps = abs(coords[2] - coords[0]);
	else
		steps = abs(coords[3] - coords[1]);
	indices[0] = (coords[2] - coords[0]) / (float)steps;
	indices[1] = (coords[3] - coords[1]) / (float)steps;
	pos[0] = coords[0];
	pos[1] = coords[1];
	i = 0;
	while (i <= steps)
	{
		my_mlx_pixel_put(fdf, pos[0], pos[1], line_color);
		pos[0] += indices[0];
		pos[1] += indices[1];
		i++;
	}
}

void	draw_line(t_fdf *fdf, t_vector3d *v1, t_vector3d *v2, int line_color)
{	
	int		line_coords[4];

	line_coords[0] = v1->x;
	line_coords[1] = v1->y;
	line_coords[2] = v2->x;
	line_coords[3] = v2->y;
	draw_line_dda(fdf, line_coords, line_color);
}
