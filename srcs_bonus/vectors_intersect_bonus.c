/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors_intersect_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 22:47:49 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/19 12:12:22 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	calculate_1(t_vector3d **tab, t_line3d *line, t_plane3d *plane)
{
	tab[0] = vec_invert(plane->v1);
	tab[1] = vec_invert(plane->v2);
	tab[2] = vec_sub(plane->p1, line->p1);
}

static void	calculate_2(t_vector3d **tab, t_plane3d *plane, t_vector3d *sol)
{
	tab[0] = vec_scale(plane->v1, sol->y);
	tab[1] = vec_scale(plane->v2, sol->z);
	free(sol);
}

t_vector3d	*line_plane_intersect3d(t_line3d *line, t_plane3d *plane)
{
	t_vector3d	*res;
	t_vector3d	*sol;
	t_vector3d	*calc_vectors[3];

	if (!line || !plane)
		return (NULL);
	calculate_1(calc_vectors, line, plane);
	if (!calc_vectors[0] || !calc_vectors[1] || !calc_vectors[2])
		return (free_vectors(calc_vectors[0], calc_vectors[1], \
					calc_vectors[2]));
	sol = solve_general(line->v1, calc_vectors[0], calc_vectors[1], \
								calc_vectors[2]);
	if (!sol)
		return (free_vectors(sol, 0, 0));
	calculate_2(calc_vectors, plane, sol);
	if (!calc_vectors[0] || !calc_vectors[1])
		return (free_vectors(calc_vectors[0], calc_vectors[1], 0));
	calc_vectors[2] = vec_add(calc_vectors[0], calc_vectors[1]);
	free_vectors(calc_vectors[0], calc_vectors[1], 0);
	if (!calc_vectors[2])
		free_vectors(calc_vectors[0], calc_vectors[1], calc_vectors[2]);
	res = vec_add(plane->p1, calc_vectors[2]);
	free(calc_vectors[2]);
	return (res);
}
