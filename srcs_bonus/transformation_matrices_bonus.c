/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation_matrices_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:20:07 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/26 15:56:04 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	scale(t_point *points, int scale, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		points[i].axis[X_AXIS] = points[i].axis[X_AXIS] * scale;
		points[i].axis[Y_AXIS] = points[i].axis[Y_AXIS] * scale;
		points[i].axis[Z_AXIS] = points[i].axis[Z_AXIS] * scale;
		i++;
	}
}

void	translate(t_point *points, t_point move, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		points[i].axis[X_AXIS] = points[i].axis[X_AXIS] + move.axis[X_AXIS];
		points[i].axis[Y_AXIS] = points[i].axis[Y_AXIS] + move.axis[Y_AXIS];
		points[i].axis[Z_AXIS] = points[i].axis[Z_AXIS];
		i++;
	}
}
