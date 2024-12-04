/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:47:45 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/26 12:18:16 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	init_image(t_fdf *fdf)
{
	fdf->mlx_data->img = mlx_new_image(fdf->mlx, WINDOW_WIDTH, \
								WINDOW_HEIGHT);
	if (!fdf->mlx_data->img)
	{
		free_map(&fdf->map);
		return (0);
	}
	fdf->mlx_data->addr = mlx_get_data_addr(fdf->mlx_data->img, \
			&fdf->mlx_data->bits_per_pixel, &fdf->mlx_data->line_length, \
			&fdf->mlx_data->endian);
	if (!fdf->mlx_data->addr)
	{
		free_map(&fdf->map);
		return (0);
	}
	fdf->fit = 1;
	fdf->map.renders = 0;
	fdf->map.proportion = fdf->map.limits.axis[Z_AXIS] \
			/ fdf->map.limits.axis[X_AXIS];
	if (fdf->map.proportion > 0.5)
		fdf->map.z_divisor = fdf->map.proportion * 30;
	return (1);
}

int	init_fdf(t_fdf *fdf, char *filename)
{
	fdf->display_title = ft_strjoin("FDF: ", filename);
	ft_printf("Opening map %s in new window...\n", filename);
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
	{
		free_map(&fdf->map);
		return (0);
	}
	fdf->win = mlx_new_window(fdf->mlx, WINDOW_WIDTH, \
				WINDOW_HEIGHT, fdf->display_title);
	if (!fdf->win)
	{
		free_map(&fdf->map);
		return (0);
	}
	fdf->mlx_data = malloc(sizeof(*fdf->mlx_data));
	if (!fdf->mlx_data)
	{
		free_map(&fdf->map);
		return (0);
	}
	init_image(fdf);
	return (1);
}
