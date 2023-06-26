/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:22:46 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/26 15:55:51 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	init_matrix(float (*matrix)[3])
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			matrix[i][j] = 0;
			j++;
		}
		i++;
	}
}

t_point	matrix_multiplier(float matrix[3][3], t_point point)
{
	int		i;
	int		k;
	t_point	res;

	res = point;
	i = 0;
	while (i < 3)
	{
		res.axis[i] = 0;
		res.color = point.color;
		k = 0;
		while (k < 3)
		{
			res.axis[i] += matrix[i][k] * point.axis[k];
			k++;
		}
		i++;
	}
	return (res);
}
