/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:06:28 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/27 17:32:38 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include <stdio.h>

static void	number_put(t_fdf *fdf, int x, int y, float num)
{
	char	*str;

	str = ft_itoa(num);
	mlx_string_put(fdf->mlx, fdf->win, x, y, 0xFFFFFF, str);
}

static void	dimensions_put(t_fdf *fdf, int x, int y)
{
	char	*height;
	char	*width;
	char	*str;


	width = ft_itoa(fdf->map.map_width);
	height = ft_itoa(fdf->map.map_height);
	str = malloc(ft_strlen(width) + ft_strlen(height) + 4);
	if (!str)
		exit_error("Malloc Failed");
	ft_strlcpy(str, width, ft_strlen(width) + 1);
	ft_strlcat(str, " X ", ft_strlen(str) + 4);
	ft_strlcat(str, height, ft_strlen(str) + ft_strlen(height) + 1);
	mlx_string_put(fdf->mlx, fdf->win, x, y, 0xFFFFFF, str);
}

static void	draw_mapinfo(t_fdf *fdf)
{
	int	y;

	y = 0;
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 80, 0xFFFFFF, "MAP INFO");
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 25, 0xFFFFFF, "Filename: ");
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 25, 0xFFFFFF, "Dimensions: ");
	dimensions_put(fdf, 1750, y);
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 25, 0xFFFFFF, "Points: ");
	number_put(fdf, 1750, y, fdf->map.dimension);
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 25, 0xFFFFFF, "Z Max: ");
	number_put(fdf, 1750, y, fdf->map.limits.axis[Z_AXIS]);
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 25, 0xFFFFFF, "Z Min: ");
	number_put(fdf, 1750, y, fdf->map.z_min);
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 50, 0xFFFFFF, "RENDER INFO");
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 25, 0xFFFFFF, "Renders: ");
	number_put(fdf, 1750, y, fdf->map.renders);
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 25, 0xFFFFFF, "Scale: ");
	number_put(fdf, 1750, y, fdf->map.scale);
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 25, 0xFFFFFF, "Depth: ");
	number_put(fdf, 1750, y, fdf->map.z_divisor);
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 50, 0xFFFFFF, "VIEW ANGLES");
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 25, 0xFFFFFF, "X: ");
	number_put(fdf, 1750, y, fdf->map.ang[X_AXIS]);
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 25, 0xFFFFFF, "Y: ");
	number_put(fdf, 1750, y, fdf->map.ang[Y_AXIS]);
}

static void	draw_rectangle(t_fdf *fdf, t_point *boundaries)
{
	float	i;
	float	thickness;

	i = 0.0;
	thickness = 5.0;
	while (i < thickness)
	{
		draw_line_dda(fdf, boundaries[0], boundaries[1]);
		draw_line_dda(fdf, boundaries[1], boundaries[2]);
		draw_line_dda(fdf, boundaries[2], boundaries[3]);
		draw_line_dda(fdf, boundaries[3], boundaries[0]);
		boundaries[0].axis[X_AXIS] -= 0.5;
		boundaries[0].axis[Y_AXIS] -= 0.5;
		boundaries[1].axis[X_AXIS] -= 0.5;
		boundaries[1].axis[Y_AXIS] -= 0.5;
		boundaries[2].axis[X_AXIS] -= 0.5;
		boundaries[2].axis[Y_AXIS] -= 0.5;
		boundaries[3].axis[X_AXIS] -= 0.5;
		boundaries[3].axis[Y_AXIS] -= 0.5;
		i += 0.5;
	}
}


void	render_menu_box(t_fdf *fdf)
{
	t_point	boundaries[4];
	int		menu_x;
	int		menu_y;

	menu_x = WINDOW_WIDTH - MENU_WIDTH - 50;
	menu_y = WINDOW_HEIGHT - MENU_HEIGHT - 50;
	boundaries[0].axis[X_AXIS] = menu_x;
	boundaries[0].axis[Y_AXIS] = menu_y;
	boundaries[0].color = 0xFFFFFF;
	boundaries[1].axis[X_AXIS] = menu_x;
	boundaries[1].axis[Y_AXIS] = menu_y + MENU_HEIGHT;
	boundaries[1].color = 0xFFFFFF;
	boundaries[2].axis[X_AXIS] = menu_x + MENU_WIDTH;
	boundaries[2].axis[Y_AXIS] = menu_y + MENU_HEIGHT;
	boundaries[2].color = 0xFFFFFF;
	boundaries[3].axis[X_AXIS] = menu_x + MENU_WIDTH;
	boundaries[3].axis[Y_AXIS] = menu_y;
	boundaries[3].color = 0xFFFFFF;
	draw_rectangle(fdf, boundaries);
}


void	print_menu(t_fdf *fdf)
{
	draw_mapinfo(fdf);
}
