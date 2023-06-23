/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:20:07 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/23 12:30:42 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	draw_map(&fdf);
	mlx_loop(&fdf.mlx);


	return (0);
}
