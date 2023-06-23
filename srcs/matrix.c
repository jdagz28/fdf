/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:22:46 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/22 21:46:45 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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