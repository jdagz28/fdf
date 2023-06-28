/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:47:45 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/28 10:01:14 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	project_isometric(t_map_data *map)
{
	map->ang[X_AXIS] = 30;
	map->ang[Y_AXIS] = 330;
	map->ang[Z_AXIS] = 30;
	if (map->source.axis[X_AXIS] > 0 || map->source.axis[Y_AXIS] > 0)
		return ;
	map->source.axis[X_AXIS] = WINDOW_WIDTH / 2;
	map->source.axis[Y_AXIS] = WINDOW_HEIGHT / 2;
}

void	project_perspective(t_map_data *map)
{
	map->ang[X_AXIS] = 90;
	map->ang[Y_AXIS] = 0;
	map->ang[Z_AXIS] = 0;
	if (map->source.axis[X_AXIS] > 0 || map->source.axis[Y_AXIS] > 0)
		return ;
	map->source.axis[X_AXIS] = WINDOW_WIDTH / 2;
	map->source.axis[Y_AXIS] = WINDOW_HEIGHT / 2;
}

void	project_ortho(t_point *points, t_point *projection, int len)
{
	int		i;
	float	projection_matrix[3][3];

	init_matrix(projection_matrix);
	projection_matrix[0][0] = 1;
	projection_matrix[1][1] = 1;
	i = 0;
	while (i < len)
	{
		projection[i] = matrix_multiplier(projection_matrix, points[i]);
		i++;
	}
}
