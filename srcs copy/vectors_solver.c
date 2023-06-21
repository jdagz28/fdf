/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_solver.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:26:23 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/18 20:00:47 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	determinant(t_vector3d *v1, t_vector3d *v2, t_vector3d *v3)
{
	double	a[12];

	a[0] = v1->x;
	a[1] = v1->y;
	a[2] = v1->z;
	a[3] = v2->x;
	a[4] = v2->y;
	a[5] = v2->z;
	a[6] = v3->x;
	a[7] = v3->y;
	a[8] = v3->z;
	return (a[0] * (a[4] * a[8] - a[5] * a[7]) - a[3] \
		* (a[1] * a[8] - a[2] * a[7]) + a[6] * (a[1] * a[5] - a[2] * a[4]));
}

static double	*assign_a(t_vector3d *v1, t_vector3d *v2, t_vector3d *v3, \
					t_vector3d *v_sol)
{
	double	*a;

	a = malloc(12 * sizeof(double));
	if (!a)
		return (NULL);
	a[0] = v1->x;
	a[1] = v1->y;
	a[2] = v1->z;
	a[3] = v2->x;
	a[4] = v2->y;
	a[5] = v2->z;
	a[6] = v3->x;
	a[7] = v3->y;
	a[8] = v3->z;
	a[9] = v_sol->x;
	a[10] = v_sol->y;
	a[11] = v_sol->z;
	return (a);
}

t_vector3d	*solve_general(t_vector3d *v1, t_vector3d *v2, t_vector3d *v3, \
							t_vector3d *v_sol)
{
	double	x;
	double	y;
	double	z;
	double	det;
	double	a[12];

	ft_memcpy(a, assign_a(v1, v2, v3, v_sol), 12 * sizeof(double));
	det = determinant(v1, v2, v3);
	if (det == 0)
		return (new_3dvector(0, 0, 0));
	x = (a[9] * (a[4] * a[8] - a[5] * a[7]) + a[10]
			* (a[5] * a[6] - a[3] * a[8])
			+ a[11] * (a[3] * a[7] - a[6] * a[4])) / det;
	y = (a[9] * (a[7] * a[2] - a[1] * a[8]) + a[10]
			* (a[0] * a[8] - a[2] * a[6])
			+ a[11] * (a[1] * a[6] - a[7] * a[0])) / det;
	z = (a[9] * (a[1] * a[5] - a[2] * a[4]) + a[10]
			* (a[0] * a[5] - a[2] * a[3])
			+ a[11] * (a[0] * a[4] - a[1] * a[3])) / det;
	return (new_3dvector(x, y, z));
}
