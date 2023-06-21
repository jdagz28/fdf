/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:20:07 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/18 20:22:43 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	clean_exit(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx, fdf->win);
	destroy_fdf(fdf);
	return (0);
}

static int	exit_fdf(int keycode, t_fdf *fdf)
{
	if (keycode == K_ESC)
		clean_exit(fdf);
	return (0);
}

static int	arg_handler(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Usage: ./fdf {file in .fdf format} \n");
		return (1);
	}
	if (file_extension_checker(argv[1], ".fdf") != 0)
	{
		ft_printf("Error: Invalid map format. Must be in `.fdf` format\n");
		return (1);
	}
	ft_printf("File: %s\n", argv[1]);
	return (0);
}

int	main(int argc, char **argv)
{
	t_fdf	*fdf;
	int		arg_check;

	arg_check = arg_handler(argc, argv);
	if (arg_check != 0)
		return (1);
	fdf = init_fdf(argv);
	if (!fdf)
		return (1);
	if (!init_display(fdf, argv) || !init_image(fdf))
		destroy_fdf(fdf);
	add_angle_to_rotation_matrix(fdf->display->rotation_matrix, -30, \
		x_axis, 0);
	add_angle_to_rotation_matrix(fdf->display->rotation_matrix, 40, \
		z_axis, 0);
	draw_map(fdf);
	mlx_hook(fdf->win, ON_KEYDOWN, 1L << 0, exit_fdf, fdf);
	mlx_hook(fdf->win, ON_DESTROY, 1L << 0, clean_exit, fdf);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->mlx_data->img, 0, 0);
	mlx_loop(fdf->mlx);
	return (0);
}
