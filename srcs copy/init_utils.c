/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:39:54 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/18 20:15:32 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_plane3d	*plane_from_points(t_vector3d *p1, t_vector3d *p2, t_vector3d *p3)
{
	t_plane3d	*res;

	if (!p1 || !p2 || !p3)
		return (NULL);
	res = malloc(sizeof(*res));
	if (!res)
		return (NULL);
	res->p1 = p1;
	res->p2 = p2;
	res->p3 = p3;
	res->v1 = vec_sub(p2, p1);
	if (!res->v1)
	{	
		free_points(p1, p2, p3);
		return (NULL);
	}
	res->v2 = vec_sub(p3, p1);
	if (!res->v2)
	{
		free_points(p1, p2, p3);
		return (NULL);
	}
	return (res);
}

t_plane3d	*get_screen_plane(int width, int height, int viewer_distance)
{
	t_vector3d	*p1;
	t_vector3d	*p2;
	t_vector3d	*p3;
	t_plane3d	*res;

	p1 = new_3dvector(0, 0, viewer_distance);
	p2 = new_3dvector(0, -height / 2, viewer_distance);
	p3 = new_3dvector(-width / 2, -height / 2, viewer_distance);
	if (!p1 || !p2 || !p3)
		return (free_vectors(p1, p2, p3));
	res = plane_from_points(p1, p2, p3);
	return (res);
}
