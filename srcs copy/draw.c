/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:51:50 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/22 23:47:46 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= fdf->map->map_width || y < 0
		|| y >= fdf->map->map_height)
	{
		return ;
	}
	dst = fdf->mlx_data->addr + (y * fdf->mlx_data->line_length
			+ x * (fdf->mlx_data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
