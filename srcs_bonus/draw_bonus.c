/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:51:50 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/19 12:10:53 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= fdf->display->width || y < 0
		|| y >= fdf->display->height)
	{
		return ;
	}
	dst = fdf->mlx_data->addr + (y * fdf->mlx_data->line_length
			+ x * (fdf->mlx_data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_pixels(t_fdf *fdf, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < fdf->display->width)
	{
		j = 0;
		while (j < fdf->display->height)
		{
			my_mlx_pixel_put(fdf, i, j, color);
			j ++;
		}
		i ++;
	}
}
