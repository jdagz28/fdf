/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 10:51:50 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/26 15:54:52 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	my_mlx_pixel_put(t_fdf *fdf, t_point pixel)
{
	int	mypixel;

	if (pixel.axis[X_AXIS] >= WINDOW_WIDTH || pixel.axis[Y_AXIS] \
		>= WINDOW_HEIGHT || pixel.axis[X_AXIS] < 0 || pixel.axis[Y_AXIS] < 0)
		return ;
	mypixel = ((int)pixel.axis[Y_AXIS] * WINDOW_WIDTH * 4)
		+ ((int)pixel.axis[X_AXIS] * 4);
	if (fdf->mlx_data->bits_per_pixel != 32)
		pixel.color = mlx_get_color_value(fdf->mlx, pixel.color);
	set_color(&fdf->mlx_data->addr[mypixel], \
			fdf->mlx_data->endian, pixel.color, 0);
}
