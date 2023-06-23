/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrices.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:44:38 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/22 22:01:14 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/* Elemenetal Rotation or Basic Rotation - wiki*/
void	rotate_x(t_point *points, t_point *projection, float ang, int len)
{
	int		i;
	float	rad;
	float	projection_matrix[3][3];

	i = 0;
	rad = ang * M_PI / 180;
	projection_matrix[0] = {1, 0, 0};
	projection_matrix[1] = {0, cos(rad), -sin(rad)};
	while (i < len)
	{
		projection[i] = matrix_multiplier(projection_matrix, points[i]);
		i++;
	}
}

void	rotate_y(t_point *points, t_point *projection, float ang, int len)
{
	int		i;
	float	rad;
	float	projection_matrix[3][3];

	i = 0;
	rad = ang * M_PI / 180;
	projection_matrix[0] = {cos(ang), 0, sin(ang)};
	projection_matrix[1] = {0, 1, 0};
	projection_matrix[2] = {-sin(ang), 0, cos(ang)};
	while (i < len)
	{
		projection[i] = matrix_multiplier(projection_matrix, points[i]);
		i++;
	}
}

void	rotate_z(t_point *points, t_point *projection, float ang, int len)
{
	int		i;
	float	rad;
	float	projection_matrix[3][3];

	i = 0;
	rad = ang * M_PI / 180;
	projection_matrix[0] = {cos(ang), -sin(ang), 0};
	projection_matrix[1] = {sin(ang), cos(ang), 0};
	projection_matrix[2] = {0, 0, 1};
	while (i < len)
	{
		projection[i] = matrix_multiplier(projection_matrix, points[i]);
	}
}
