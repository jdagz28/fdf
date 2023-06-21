/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:11:30 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/18 20:30:10 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vector3d	*apply_rotation_matrix_to_point(t_vector3d *point, \
											t_display_info *display_info)
{
	t_vector3d	*pt;
	t_vector3d	*pt2;

	pt = vec_sub(point, display_info->rotation_center);
	if (!pt)
		return (NULL);
	pt2 = matrix_mult_vector(display_info->rotation_matrix, pt);
	free(pt);
	if (!pt)
		return (NULL);
	add_vec_inplace(pt2, display_info->rotation_center);
	return (pt2);
}

t_vector3d	*project_isometric(t_vector3d *pt, t_plane3d *plane, \
								t_display_info *display_info)
{
	t_vector3d	*pt2;
	t_vector3d	*cross_res;
	t_line3d	*line;
	t_vector3d	*intersection;

	pt2 = apply_rotation_matrix_to_point(pt, display_info);
	if (!pt2)
		return (NULL);
	cross_res = cross(plane->v1, plane->v2);
	if (!cross_res)
		return (free_vectors(pt2, 0, 0));
	line = line_from_point_and_vector(pt2, cross_res);
	if (!line)
		return (free_vectors(pt2, cross_res, 0));
	intersection = line_plane_intersect3d(line, plane);
	free_line3d(line);
	return (intersection);
}
