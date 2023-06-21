/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 10:45:45 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/19 12:11:03 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	draw_y(t_fdf *fdf, t_vector3d ***map_projection)
{
	t_vector3d	*previous_px;
	int			i;
	int			j;

	i = 0;
	while (i < fdf->map->size_x)
	{
		previous_px = NULL;
		j = 0;
		while (j < fdf->map->size_y)
		{
			if (map_projection[i][j] && previous_px)
				draw_line(fdf, previous_px, map_projection[i][j], 0x00000000);
			previous_px = map_projection[i][j];
			j++;
		}
		i++;
	}
}

void	draw_x(t_fdf *fdf, t_vector3d ***map_projection)
{
	t_vector3d	*previous_px;
	int			i;
	int			j;

	i = 0;
	while (i < fdf->map->size_y)
	{
		previous_px = NULL;
		j = 0;
		while (j < fdf->map->size_x)
		{
			if (map_projection[j][i] && previous_px)
				draw_line(fdf, previous_px, map_projection[j][i], 0x00000000);
			previous_px = map_projection[j][i];
			j++;
		}
		i++;
	}
}

void	adapt_size_isometric(t_fdf *fdf)
{
	fdf->map->rect_size = add_padding(min_scale((fdf->display->height - 600)
				/ fdf->map->size_x, (fdf->display->width - 600)
				/ fdf->map->size_y), 1);
	if (fdf->display->projection == isometric)
		fdf->map->rect_size = add_padding(1, fdf->map->rect_size
				- fdf->display->pos_z);
	fdf->map->pos_x = fdf->display->width / 2 - fdf->map->size_y \
						* fdf->map->rect_size / 2 + fdf->display->pos_x;
	fdf->map->pos_y = fdf->display->height / 2 - fdf->map->size_x \
						* fdf->map->rect_size / 2 + fdf->display->pos_y;
	fdf->map->pos_z = fdf->display->screen_depth + 150;
}

void	draw_map(t_fdf *fdf)
{
	t_vector3d	*rotation_center;
	t_vector3d	***map_projection;

	adapt_size_isometric(fdf);
	draw_pixels(fdf, fdf->display->background_color);
	rotation_center = new_3dvector(fdf->display->rotation_center->x, \
		fdf->display->rotation_center->y, fdf->display->rotation_center->z);
	free(fdf->display->rotation_center);
	fdf->display->rotation_center = new_3dvector(fdf->map->pos_x
			+ fdf->map->size_y * fdf->map->rect_size / 2.0 - fdf->map->rect_size
			/ 2.0, (float)fdf->map->pos_y + (float)fdf->map->size_x
			* (float)fdf->map->rect_size / 2.0 - fdf->map->rect_size
			/ 2.0, fdf->map->pos_z + fdf->display->pos_z);
	map_projection = get_map_projection(fdf);
	if (!map_projection)
		return ;
	draw_x(fdf, map_projection);
	draw_y(fdf, map_projection);
	free_map_projection(map_projection, fdf->map->size_x, fdf->map->size_y, \
							fdf->map->size_y);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->mlx_data->img, 0, 0);
	free(fdf->display->rotation_center);
	fdf->display->rotation_center = rotation_center;
}
