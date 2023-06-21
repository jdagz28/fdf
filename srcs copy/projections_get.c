/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections_get.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 21:48:34 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/18 20:31:52 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	free_map_projection_pt(t_vector3d ***res, int size_y, int size_x, \
							int size_last)
{
	free_map_projection(res, size_y, size_x, size_last);
	return (0);
}

t_vector3d	*get_pt(t_fdf *fdf, int i, int j)
{
	t_vector3d	*res;

	res = new_3dvector(fdf->map->pos_x + i * fdf->map->rect_size, \
			fdf->map->pos_y + j * fdf->map->rect_size, fdf->map->pos_z \
			- fdf->map->map[j][i] * fdf->map->height_mult \
			+ fdf->display->pos_z);
	return (res);
}

/* The res[i][*j] malloc is not protected directly here, because some vects
 * can be empty. The not null check happens in the main draw function */
static int	get_map_projection_cont(int i, int *j, t_vector3d ***res, \
										t_fdf *fdf)
{
	t_vector3d	*pt;

	while (*j < fdf->map->size_y)
	{
		pt = get_pt(fdf, *j, i);
		if (!pt)
			return (free_map_projection_pt(res, i, fdf->map->size_y, *j));
		res[i][*j] = project_isometric(pt, fdf->display->screen_plane, \
											fdf->display);
		free(pt);
		(*j)++;
	}
	return (1);
}

t_vector3d	***get_map_projection(t_fdf *fdf)
{
	t_vector3d	***res;
	int			i;
	int			j;

	res = malloc(sizeof(*res) * fdf->map->size_x);
	if (!res)
		return (NULL);
	i = 0;
	while (i < fdf->map->size_x)
	{
		j = 0;
		res[i] = malloc(sizeof(**res) * fdf->map->size_y);
		if (!res[i])
			return (free_map_projection(res, i, fdf->map->size_y, j));
		get_map_projection_cont(i, &j, res, fdf);
		i++;
	}
	return (res);
}
