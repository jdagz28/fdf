/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:48:37 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/19 12:12:18 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

t_vector3d	*vec_add(t_vector3d *v1, t_vector3d *v2)
{
	t_vector3d	*res;

	if (!v1 || !v2)
		return (NULL);
	res = new_3dvector(v1->x + v2->x, v1->y + v2->y, v1->z + v2->z);
	return (res);
}

t_vector3d	*vec_sub(t_vector3d *v1, t_vector3d *v2)
{
	t_vector3d	*res;

	if (!v1 || !v2)
		return (NULL);
	res = new_3dvector(v1->x - v2->x, v1->y - v2->y, v1->z - v2->z);
	return (res);
}

t_vector3d	*cross(t_vector3d *v1, t_vector3d *v2)
{
	t_vector3d	*res;

	res = new_3dvector(v1->y * v2->z - v1->z * v2->y,
			v1->x * v2->z - v1->z * v2->x, v1->x * v2->y - v1->y * v2->x);
	if (!res)
		return (NULL);
	return (res);
}

t_vector3d	*new_3dvector(double x, double y, double z)
{
	t_vector3d	*res;

	res = malloc(sizeof(*res));
	if (!res)
		return (NULL);
	res->x = x;
	res->y = y;
	res->z = z;
	return (res);
}
