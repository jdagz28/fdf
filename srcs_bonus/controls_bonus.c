/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 15:38:51 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/19 15:58:08 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

//TODO
//! Key bindings
//! HOOKS

int	clean_exit(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx, fdf->win);
	destroy_fdf(fdf);
	return (0);
}


static void	keybindings_cont(int keycode, t_fdf *fdf)
{

	if (keycode == K_P)
	{
		fdf->display->projection = (fdf->display->projection + 1) % 2;
		if (fdf->display->projection == perspective)
			fdf->display->pos_z = 110;
		else if (fdf->display->projection == isometric)
			fdf->display->pos_z = 0;
	}
	else if (keycode == K_A)
		add_angle_to_rotation_matrix(fdf->display->rotation_matrix, \
			- fdf->display->rotation_speed, z_axis, 0);
	else if (keycode == K_D)
		add_angle_to_rotation_matrix(fdf->display->rotation_matrix, \
			fdf->display->rotation_speed, z_axis, 0);
	else if (keycode == K_W)
		// fdf->display->pos_z -= fdf->display->zoom_speed;
		fdf->display->eye_z += 10;
	else if (keycode == K_S)
		// fdf->display->pos_z += fdf->display->zoom_speed;
		fdf->display->eye_z -= 10;
}

int	keybindings(int keycode, t_fdf *fdf)
{
	if (keycode == K_ESC)
		clean_exit(fdf);
	else if (keycode == K_UP)
		add_angle_to_rotation_matrix(fdf->display->rotation_matrix, \
			- fdf->display->rotation_speed, x_axis, 0);
	else if (keycode == K_DOWN)
		add_angle_to_rotation_matrix(fdf->display->rotation_matrix, \
			fdf->display->rotation_speed, x_axis, 0);
	else if (keycode == K_RIGHT)
		add_angle_to_rotation_matrix(fdf->display->rotation_matrix, \
			- fdf->display->rotation_speed, y_axis, 0);
	else if (keycode == K_LEFT)
		add_angle_to_rotation_matrix(fdf->display->rotation_matrix, \
			fdf->display->rotation_speed, y_axis, 0);
	else if (keycode == K_NUM_8)
		fdf->display->pos_y += fdf->display->mov_speed;
	else if (keycode == K_NUM_2)
		fdf->display->pos_y -= fdf->display->mov_speed;
	else if (keycode == K_NUM_4)
		fdf->display->pos_x -= fdf->display->mov_speed;
	else if (keycode == K_NUM_6)
		fdf->display->pos_x += fdf->display->mov_speed;
	keybindings_cont(keycode, fdf);
	draw_map(fdf);
	return (0);
}
