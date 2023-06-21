/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projections_line_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:27:04 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/19 12:11:49 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	free_line3d(t_line3d *line3d)
{
	free(line3d->p1);
	free(line3d->p2);
	free(line3d->v1);
	free(line3d);
}

t_line3d	*line_from_points(t_vector3d *p1, t_vector3d *p2)
{
	t_line3d	*res;

	if (!p1 || !p2)
		return (NULL);
	res = malloc(sizeof(*res));
	if (!res)
		return (NULL);
	res->p1 = p1;
	res->p2 = p2;
	res->v1 = vec_sub(p2, p1);
	if (!res->v1)
	{
		free(res->p1);
		free(res->p2);
		return (NULL);
	}
	return (res);
}

t_line3d	*line_from_point_and_vector(t_vector3d *p, t_vector3d *d)
{
	t_line3d	*res;

	if (!p || !d)
		return (NULL);
	res = malloc(sizeof(*res));
	if (!res)
		return (NULL);
	res->p1 = p;
	res->p2 = vec_add(p, d);
	res->v1 = d;
	if (!res->p2)
	{
		free(res->p1);
		free(res->v1);
		return (NULL);
	}
	return (res);
}
