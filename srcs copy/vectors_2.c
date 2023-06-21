/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:59:09 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/18 20:00:18 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector3d	*vec_invert(t_vector3d *v)
{
	return (vec_scale(v, -1));
}

void	add_vec_inplace(t_vector3d *addee, t_vector3d *added)
{
	addee->x += added->x;
	addee->y += added->y;
	addee->z += added->z;
}

t_vector3d	*vec_scale(t_vector3d *v, double scalar)
{
	t_vector3d	*res;

	res = new_3dvector(v->x * scalar, v->y * scalar, v->z * scalar);
	return (res);
}
