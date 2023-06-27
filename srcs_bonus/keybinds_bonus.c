/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybinds_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:20:07 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/27 13:47:40 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	clean_exit(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx, fdf->win);
	destroy_fdf(fdf);
	return (0);
}
void	keybindings_cont_two(int keycode, t_fdf *fdf)
{
	if (keycode == K_NUM_0)
	{
		fdf->fit = 1;
		project_isometric(&fdf->map);
	}
}

void	keybindings_cont(int keycode, t_fdf *fdf)
{
	if (keycode == K_NUM_5)
	{
		fdf->map.ang[X_AXIS] = 0;
		fdf->map.ang[Y_AXIS] = 0;
		fdf->map.ang[Z_AXIS] = 0;
	}
	else if (keycode == K_NUM_8)
		fdf->map.source.axis[Y_AXIS] = fdf->map.source.axis[Y_AXIS] - 5;
	else if (keycode == K_NUM_2)
		fdf->map.source.axis[Y_AXIS] = fdf->map.source.axis[Y_AXIS] + 5;
	else if (keycode == K_NUM_6)
		fdf->map.source.axis[X_AXIS] = fdf->map.source.axis[X_AXIS] + 5;
	else if (keycode == K_NUM_4)
		fdf->map.source.axis[X_AXIS] = fdf->map.source.axis[X_AXIS] - 5;
	else if (keycode == K_NUM_ENTER)
		project_isometric(&fdf->map);
	else if (keycode == K_NUM_PERIOD)
		project_parallel(&fdf->map);
	
}

int	keybindings(int keycode, t_fdf *fdf)
{
	fdf->fit = 0;
	if (keycode == K_ESC)
		clean_exit(fdf);
	else if (keycode == K_D)
		fdf->map.drawtype = (fdf->map.drawtype + 1) % 2;
	else if (keycode == K_NUM_PLUS)
		fdf->map.scale = fdf->map.scale + 1.5;
	else if (keycode == K_NUM_MINUS)
	{	
		if (fdf->map.scale > 2)
			fdf->map.scale = fdf->map.scale - 1.5;
	}
	else if (keycode == K_UP)
		fdf->map.ang[X_AXIS] = fdf->map.ang[X_AXIS] + 2.5;
	else if (keycode == K_DOWN)
		fdf->map.ang[X_AXIS] = fdf->map.ang[X_AXIS] - 2.5;
	else if (keycode == K_RIGHT)
		fdf->map.ang[Y_AXIS] = fdf->map.ang[Y_AXIS] + 2.5;
	else if (keycode == K_LEFT)
		fdf->map.ang[Y_AXIS] = fdf->map.ang[Y_AXIS] - 2.5;
	keybindings_cont(keycode, fdf);
	keybindings_cont_two(keycode, fdf);
	draw_map(fdf);
	return (0);
}
