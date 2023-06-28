/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 16:06:28 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/28 10:00:39 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	number_put(t_fdf *fdf, int x, int y, float num)
{
	char	*str;

	str = ft_itoa(num);
	mlx_string_put(fdf->mlx, fdf->win, x, y, 0xFFFFFF, str);
	free(str);
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
	free(str);
	free(width);
	free(height);
}

static void	draw_mapinfo(t_fdf *fdf)
{
	int	y;

	y = 0;
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 80, 0xFFFFFF, "MAP INFO");
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 25, 0xFFFFFF, "Filename: ");
	filename_put(fdf, 1750, y);
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 25, 0xFFFFFF, "Dimensions: ");
	dimensions_put(fdf, 1750, y);
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 25, 0xFFFFFF, "Points: ");
	number_put(fdf, 1750, y, fdf->map.dimension);
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 25, 0xFFFFFF, "Z Max: ");
	number_put(fdf, 1750, y, fdf->map.limits.axis[Z_AXIS]);
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 25, 0xFFFFFF, "Z Min: ");
	number_put(fdf, 1750, y, fdf->map.z_min);
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 30, 0xFFFFFF, "RENDER INFO");
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 25, 0xFFFFFF, "Renders: ");
	number_put(fdf, 1750, y, fdf->map.renders);
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 25, 0xFFFFFF, "Scale: ");
	number_put(fdf, 1750, y, fdf->map.scale);
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 25, 0xFFFFFF, "Depth: ");
	number_put(fdf, 1750, y, fdf->map.z_divisor);
}

static void	draw_angleinfo(t_fdf *fdf)
{
	int	y;

	y = 310;
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 30, 0xFFFFFF, "VIEW ANGLES");
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 25, 0xFFFFFF, "X: ");
	number_put(fdf, 1750, y, fdf->map.ang[X_AXIS]);
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 25, 0xFFFFFF, "Y: ");
	number_put(fdf, 1750, y, fdf->map.ang[Y_AXIS]);
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 25, 0xFFFFFF, "Z: ");
	number_put(fdf, 1750, y, fdf->map.ang[Z_AXIS]);
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 30, 0xFFFFFF, "DRAW TYPE");
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 25, 0xFFFFFF, \
													"[ ] - Lines/Wireframe");
	if (fdf->map.drawtype == line)
		mlx_string_put(fdf->mlx, fdf->win, 1595, y, 0xFFFFFF, "X");
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 25, 0xFFFFFF, "[ ] - Points");
	if (fdf->map.drawtype == dot)
		mlx_string_put(fdf->mlx, fdf->win, 1595, y, 0xFFFFFF, "X");
}

void	print_menu(t_fdf *fdf)
{
	draw_mapinfo(fdf);
	draw_angleinfo(fdf);
	draw_projectioninfo(fdf);
	draw_colorinfo(fdf);
	draw_controlsinfo(fdf);
}
