/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:50:49 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/18 19:51:43 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*free_map_projection(t_vector3d ***res, int size_y, int size_x, \
								int size_last)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	while (i < size_y)
	{
		if (i == size_y - 1)
			max = size_last;
		else
			max = size_x;
		j = 0;
		while (j < max)
		{
			free(res[i][j]);
			j++;
		}
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

void	free_3dplane(t_plane3d *plane)
{
	free(plane->p1);
	free(plane->p2);
	free(plane->p3);
	free(plane->v1);
	free(plane->v2);
	free(plane);
}

void	*free_3dmatrix(t_matrix3d *matrix)
{
	free_vectors(matrix->v1, matrix->v2, matrix->v3);
	free(matrix);
	return (NULL);
}
