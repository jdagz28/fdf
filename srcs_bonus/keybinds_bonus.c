/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybinds_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:20:07 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/26 15:55:22 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	clean_exit(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx, fdf->win);
	destroy_fdf(fdf);
	return (0);
}

int	exit_fdf(int keycode, t_fdf *fdf)
{
	if (keycode == K_ESC)
		clean_exit(fdf);
	return (0);
}
