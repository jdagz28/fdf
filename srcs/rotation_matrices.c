/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_matrices.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:44:38 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/23 12:29:10 by jdagoy           ###   ########.fr       */
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
	init_matrix(projection_matrix);
	projection_matrix[0][0] = 1;
	projection_matrix[1][1] = cos(rad);
	projection_matrix[1][2] = -sin(rad);
	projection_matrix[2][1] = sin(rad);
	projection_matrix[2][2] = cos(rad);
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
	init_matrix(projection_matrix);
	projection_matrix[0][0] = cos(rad);
	projection_matrix[0][2] = sin(rad);
	projection_matrix[1][1] = 1;
	projection_matrix[2][0] = -sin(rad);
	projection_matrix[2][2] = cos(rad);
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
	init_matrix(projection_matrix);
	projection_matrix[0][0] = cos(rad);
	projection_matrix[0][1] = -sin(rad);
	projection_matrix[1][0] = sin(rad);
	projection_matrix[1][1] = cos(rad);
	projection_matrix[2][2] = 1;
	while (i < len)
	{
		projection[i] = matrix_multiplier(projection_matrix, points[i]);
	}
}
