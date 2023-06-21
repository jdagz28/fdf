/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:21:14 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/18 19:52:44 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	destroy_fdf(t_fdf *fdf)
{
	if (!fdf)
		exit(0);
	if (fdf->map)
	{
		free_map_destroy(fdf->map);
		free(fdf->map->map);
		free(fdf->map);
	}
	if (fdf->display->rotation_matrix)
		free_3dmatrix(fdf->display->rotation_matrix);
	if (fdf->display->screen_plane)
		free_3dplane(fdf->display->screen_plane);
	if (fdf->display->rotation_center)
		free(fdf->display->rotation_center);
	if (fdf->display_title)
		free(fdf->display_title);
	if (fdf->display)
		free(fdf->display);
	ft_printf("\n\nExiting FDF...\n");
	exit(0);
}

void	*free_vectors(t_vector3d *v1, t_vector3d *v2, t_vector3d *v3)
{
	if (v1)
		free(v1);
	if (v2)
		free(v2);
	if (v3)
		free(v3);
	return (NULL);
}

void	*free_map(t_map_data *data)
{
	int	i;

	i = 0;
	while (i < data->size_x)
	{	
		free(data->map[i]);
		i++;
	}
	free(data->map);
	free(data);
	return (NULL);
}

int	file_extension_checker(const char *filename, const char *extension)
{
	if (ft_strlen(filename) < ft_strlen(extension))
		return (1);
	if (ft_strncmp(filename + (ft_strlen(filename) - ft_strlen(extension)), \
			extension, ft_strlen(extension)))
		return (1);
	return (0);
}
