/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:06:28 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/26 17:26:23 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include <stdio.h>

static void draw_thicker_line_dda(t_fdf *fdf, t_point start, t_point end, int thickness)
{
    // Calculate the line slope
    float dxend.axis[X_AXIS] - start.axis[X_AXIS];
    float dy = end.axis[Y_AXIS] - start.axis[Y_AXIS];

    // Calculate the line length
    int line_length = (int)(sqrt(dx * dx + dy * dy));

    // Calculate the step increments
    float x_step = dx / line_length;
    float y_step = dy / line_length;

    // Calculate the perpendicular offsets for thickness
    float x_offset = thickness * y_step;
    float y_offset = thickness * x_step;

    // Calculate the initial coordinates
    float x = start.axis[X_AXIS] - 0.5;
    float y = start.axis[Y_AXIS] - 0.5;

    // Draw the thicker line
    for (int i = 0; i < line_length; i++)
    {
        for (int j = 0; j < thickness; j++)
        {
            t_point pixel;
            pixel.axis[X_AXIS] = x + j * x_offset;
            pixel.axis[Y_AXIS] = y + j * y_offset;
            pixel.color = start.color;
            my_mlx_pixel_put(fdf, pixel);
        }

        x += x_step;
        y += y_step;
    }
}

static void	render_menu_box(t_fdf *fdf)
{
	t_point	boundaries[4];
	int	density;
	density = 8 / fdf->map.scale;
	if (density == 0)
        density = 1;
	int menu_width = 500 * density;
	int menu_height = 500 * density;
	int menu_x = WINDOW_WIDTH - menu_width - 50;
	int menu_y = WINDOW_HEIGHT - menu_height - 50;
	boundaries[0].axis[X_AXIS] = menu_x;
	boundaries[0].axis[Y_AXIS] = menu_y;
	boundaries[0].color = 0xFFFFFF;
	boundaries[1].axis[X_AXIS] = menu_x;
	boundaries[1].axis[Y_AXIS] = menu_y + menu_height;
	boundaries[1].color = 0xFFFFFF;
	boundaries[2].axis[X_AXIS] = menu_x + menu_width;
	boundaries[2].axis[Y_AXIS] = menu_y + menu_height;
	boundaries[2].color = 0xFFFFFF;
	boundaries[3].axis[X_AXIS] = menu_x + menu_width;
	boundaries[3].axis[Y_AXIS] = menu_y;
	boundaries[3].color = 0xFFFFFF;

	int line_thickness = 5 * density; // Adjust the thickness as needed

    draw_thicker_line_dda(fdf, boundaries[0], boundaries[1], line_thickness);
    draw_thicker_line_dda(fdf, boundaries[1], boundaries[2], line_thickness);
    draw_thicker_line_dda(fdf, boundaries[2], boundaries[3], line_thickness);
    draw_thicker_line_dda(fdf, boundaries[3], boundaries[0], line_thickness);
}


void	draw_menu(t_fdf *fdf)
{
	render_menu_box(fdf);
}
