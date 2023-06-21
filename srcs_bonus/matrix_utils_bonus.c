/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:44:38 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/19 12:11:40 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	valid_matrix(t_matrix3d *matrix)
{
	if (matrix && matrix->v1 && matrix->v2 && matrix->v3)
		return (1);
	return (0);
}

t_vector3d	*matrix_mult_vector(t_matrix3d *matrix, t_vector3d *vec)
{
	t_vector3d	*res;
	t_vector3d	*v1;
	t_vector3d	*v2;
	t_vector3d	*v3;

	if (!valid_matrix(matrix) || !vec)
		return (NULL);
	v1 = vec_scale(matrix->v1, vec->x);
	if (!v1)
		return (NULL);
	v2 = vec_scale(matrix->v2, vec->y);
	if (!v2)
		return (free_vectors(v1, 0, 0));
	v3 = vec_scale(matrix->v3, vec->z);
	if (!v3)
		return (free_vectors(v1, v2, 0));
	add_vec_inplace(v2, v3);
	res = vec_add(v2, v1);
	free_vectors(v1, v2, v3);
	return (res);
}

t_matrix3d	*matrix_multiplier(t_matrix3d *m1, t_matrix3d *m2)
{
	t_matrix3d	*res;
	t_vector3d	*v1;
	t_vector3d	*v2;
	t_vector3d	*v3;

	v1 = new_3dvector(m1->v1->x * m2->v1->x + m1->v2->x * m2->v1->y + m1->v3->x \
			* m2->v1->z, m1->v1->y * m2->v1->x + m1->v2->y * m2->v1->y \
			+ m1->v3->y * m2->v1->z, m1->v1->z * m2->v1->x + m1->v2->z \
			* m2->v1->y + m1->v3->z * m2->v1->z);
	v2 = new_3dvector(m1->v1->x * m2->v2->x + m1->v2->x * m2->v2->y + m1->v3->x \
			* m2->v2->z, m1->v1->y * m2->v2->x + m1->v2->y * m2->v2->y \
			+ m1->v3->y * m2->v2->z, m1->v1->z * m2->v2->x + m1->v2->z \
			* m2->v2->y + m1->v3->z * m2->v2->z);
	v3 = new_3dvector(m1->v1->x * m2->v3->x + m1->v2->x * m2->v3->y + m1->v3->x \
			* m2->v3->z, m1->v1->y * m2->v3->x + m1->v2->y * m2->v3->y \
			+ m1->v3->y * m2->v3->z, m1->v1->z * m2->v3->x + m1->v2->z \
			* m2->v3->y + m1->v3->z * m2->v3->z);
	res = new_3dmatrix(v1, v2, v3);
	if (!res)
		return (free_vectors(v1, v2, v3));
	if (!valid_matrix(res))
		return (free_3dmatrix(res));
	return (res);
}

t_matrix3d	*new_3dmatrix(t_vector3d *v1, t_vector3d *v2, t_vector3d *v3)
{
	t_matrix3d	*res;

	res = malloc(sizeof(*res));
	if (!res)
		return (NULL);
	res->v1 = v1;
	res->v2 = v2;
	res->v3 = v3;
	return (res);
}
