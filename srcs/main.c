/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:20:07 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/24 23:20:57 by jdagoy           ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_fdf	fdf;
	int		arg_check;

	arg_check = arg_handler(argc, argv);
	if (arg_check != 0)
		return (1);
	map_parser(&fdf.map, argv[1]);
	if (!init_fdf(&fdf, argv[1]))
		destroy_fdf(&fdf);
	// print_map(&fdf.map);
	draw_map(&fdf);
	mlx_hook(fdf.win, ON_KEYDOWN, 1L << 0, exit_fdf, &fdf);
	mlx_hook(fdf.win, ON_DESTROY, 1L << 0, clean_exit, &fdf);
	mlx_loop(fdf.mlx);
	free(fdf.map.points);
	free(fdf.map.mapread);

	return (0);
}
