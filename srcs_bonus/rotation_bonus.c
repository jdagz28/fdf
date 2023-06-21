/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 22:14:44 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/19 12:11:52 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

t_matrix3d	*get_rot_z(double angle)
{
	t_matrix3d	*res;
	t_vector3d	*v1;
	t_vector3d	*v2;
	t_vector3d	*v3;

	v1 = new_3dvector(cos(angle), sin(angle), 0);
	v2 = new_3dvector(-sin(angle), cos(angle), 0);
	v3 = new_3dvector(0, 0, 1);
	if (!v1 || !v2 || !v3)
		return (free_vectors(v1, v2, v3));
	res = new_3dmatrix(v1, v2, v3);
	if (!res)
		return (free_vectors(v1, v2, v3));
	return (res);
}

t_matrix3d	*get_rot_y(double angle)
{
	t_matrix3d	*res;
	t_vector3d	*v1;
	t_vector3d	*v2;
	t_vector3d	*v3;

	v1 = new_3dvector(cos(angle), 0, -sin(angle));
	v2 = new_3dvector(0, 1, 0);
	v3 = new_3dvector(sin(angle), 0, cos(angle));
	if (!v1 || !v2 || !v3)
		return (free_vectors(v1, v2, v3));
	res = new_3dmatrix(v1, v2, v3);
	if (!res)
		return (free_vectors(v1, v2, v3));
	return (res);
}

t_matrix3d	*get_rot_x(double angle)
{
	t_matrix3d	*res;
	t_vector3d	*v1;
	t_vector3d	*v2;
	t_vector3d	*v3;

	v1 = new_3dvector(1, 0, 0);
	v2 = new_3dvector(0, cos(angle), sin(angle));
	v3 = new_3dvector(0, -sin(angle), cos(angle));
	if (!v1 || !v2 || !v3)
		return (free_vectors(v1, v2, v3));
	res = new_3dmatrix(v1, v2, v3);
	if (!res)
		return (free_vectors(v1, v2, v3));
	return (res);
}

t_matrix3d	*get_rotation_matrix(double angle, t_rotation axis, int is_rad)
{
	if (!is_rad)
		angle = (angle * M_PI) / 180;
	if (axis == x_axis)
		return (get_rot_x(angle));
	else if (axis == y_axis)
		return (get_rot_y(angle));
	else
		return (get_rot_z(angle));
}

void	add_angle_to_rotation_matrix(t_matrix3d *rotation_matrix, double angle, \
					t_rotation axis, int is_rad)
{
	t_matrix3d	*new_matrix;
	t_matrix3d	*rot_matrix;

	rot_matrix = get_rotation_matrix(angle, axis, is_rad);
	if (!rot_matrix)
		return ;
	new_matrix = matrix_multiplier(rotation_matrix, rot_matrix);
	free_3dmatrix(rot_matrix);
	if (!new_matrix)
		return ;
	free_vectors(rotation_matrix->v1, rotation_matrix->v2, rotation_matrix->v3);
	rotation_matrix->v1 = new_matrix->v1;
	rotation_matrix->v2 = new_matrix->v2;
	rotation_matrix->v3 = new_matrix->v3;
	free(new_matrix);
}
