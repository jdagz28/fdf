/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_helpers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:12:16 by jwikiera          #+#    #+#             */
/*   Updated: 2023/06/18 18:46:59 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_fdf *fdf, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= fdf->screen_info->width || y < 0
		|| y >= fdf->screen_info->height)
	{
		return ;
	}
	dst = fdf->mlx_data->addr + (y * fdf->mlx_data->line_length
			+ x * (fdf->mlx_data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
