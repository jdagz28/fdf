/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_menu_2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 22:36:55 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/28 01:37:47 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	filename_put(t_fdf *fdf, int x, int y)
{
	char	*str;

	str = ft_strrchr(fdf->display_title, '/') + 1;
	mlx_string_put(fdf->mlx, fdf->win, x, y, 0xFFFFFF, str);
}

void	draw_projectioninfo(t_fdf *fdf)
{
	int	y;

	y = 495;
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 30, 0xFFFFFF, \
														"PROJECTIONS / VIEWS");
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 25, 0xFFFFFF, \
												"[ ] - Isometric (Default)");
	if (fdf->projection == isometric)
		mlx_string_put(fdf->mlx, fdf->win, 1595, y, 0xFFFFFF, "X");
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 25, 0xFFFFFF, \
														"[ ] - Parallel");
	if (fdf->projection == parallel)
		mlx_string_put(fdf->mlx, fdf->win, 1595, y, 0xFFFFFF, "X");
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 25, 0xFFFFFF, \
														"[ ] - Top View");
	if (fdf->projection == top_view)
		mlx_string_put(fdf->mlx, fdf->win, 1595, y, 0xFFFFFF, "X");
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 25, 0xFFFFFF, \
											"Numpad 0 - Reset view and angles");
}

void	draw_colorinfo(t_fdf *fdf)
{
	int	y;

	y = 625;
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 30, 0xFFFFFF, "COLOR");
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 25, 0xFFFFFF, \
												"[ ] - RGB (Default)");
	if (fdf->color == RGB)
		mlx_string_put(fdf->mlx, fdf->win, 1595, y, 0xFFFFFF, "X");
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 25, 0xFFFFFF, \
												"[ ] - White Only");
	if (fdf->color == White)
		mlx_string_put(fdf->mlx, fdf->win, 1595, y, 0xFFFFFF, "X");
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 25, 0xFFFFFF, \
												"[ ] - Custom Pallette 1");
	if (fdf->color == tt_pallette1)
		mlx_string_put(fdf->mlx, fdf->win, 1595, y, 0xFFFFFF, "X");
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 25, 0xFFFFFF, \
												"[ ] - Custom Pallette 2");
	if (fdf->color == tt_pallette2)
		mlx_string_put(fdf->mlx, fdf->win, 1595, y, 0xFFFFFF, "X");
}

void	draw_controlsinfo(t_fdf *fdf)
{
	int	y;

	y = 755;
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 30, 0xFFFFFF, "CONTROLS");
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 25, 0xFFFFFF, \
												"ARROWS: Rotation");
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 25, 0xFFFFFF, \
											"Numpad 7,9: Rotation (Z-axis)");
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 25, 0xFFFFFF, \
											"Numpad 8,2,4,6: Translation");
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 25, 0xFFFFFF, \
											"Numpad +,-: Scale");
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 25, 0xFFFFFF, \
										"Numpad Enter: Change Projection/View");
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 25, 0xFFFFFF, \
										"Numpad Period: Change Color");
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 25, 0xFFFFFF, \
										"Numpad 5: Change Draw Type");
	mlx_string_put(fdf->mlx, fdf->win, 1590, y += 25, 0xFFFFFF, \
										"Numpad 0: Reset Angles and Projection");
									
}
