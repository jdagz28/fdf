/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:47:45 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/19 12:11:19 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

t_display_info	*screen_display_init(void)
{
	t_display_info	*display;

	display = malloc(sizeof(*display));
	if (!display)
		return (NULL);
	display->width = 1920;
	display->height = 1080;
	display->pos_x = 0;
	display->pos_y = 0;
	display->pos_z = 0;
	display->mov_speed = 5;
	display->zoom_speed = 5;
	display->rotation_matrix = new_3dmatrix(new_3dvector(1, 0, 0), \
								new_3dvector(0, 1, 0), new_3dvector(0, 0, 1));
	display->rotation_center = new_3dvector(0, 0, 0);
	display->rotation_speed = 5;
	display->eye_z = 0;
	display->screen_depth = 200;
	display->screen_plane = get_screen_plane(display->width, display->height, \
								display->screen_depth);
	display->background_color = 0x00FFFFFF;
	display->projection = isometric;
	return (display);
}

int	init_screen(t_fdf *data)
{
	data->display = screen_display_init();
	if (!data->display)
	{
		free_map(data->map);
		ft_putstr_fd("ERROR: Failed to initialized display.\n", 1);
		return (0);
	}
	return (1);
}

t_fdf	*init_fdf(char **argv)
{
	t_fdf	*data;

	data = malloc(sizeof(*data));
	if (!data)
		return (ft_putstr_fd("ERROR: Malloc failure on fdf struct\n", 1), NULL);
	data->map = map_parser(argv[1]);
	if (!data->map)
	{
		free(data);
		return (NULL);
	}
	if (data->map->size_x == 0 || data->map->size_y == 0)
	{
		free_map(data->map);
		free(data);
		return (ft_putstr_fd("ERROR: Invalid dimensions.\n", 1), NULL);
	}
	if (!init_screen(data))
		return (NULL);
	return (data);
}

int	init_image(t_fdf *fdf)
{
	fdf->mlx_data->img = mlx_new_image(fdf->mlx, fdf->display->width, \
								fdf->display->height);
	if (!fdf->mlx_data->img)
	{
		free_map(fdf->map);
		return (0);
	}
	fdf->mlx_data->addr = mlx_get_data_addr(fdf->mlx_data->img, \
			&fdf->mlx_data->bits_per_pixel, &fdf->mlx_data->line_length, \
			&fdf->mlx_data->endian);
	if (!fdf->mlx_data->addr)
	{
		free_map(fdf->map);
		return (0);
	}
	return (1);
}

int	init_display(t_fdf *fdf, char **argv)
{
	fdf->display_title = ft_strjoin("FDF: ", argv[1]);
	if (!fdf->display_title)
		destroy_fdf(fdf);
	ft_printf("Opening map %s in new window\n", argv[1]);
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
	{
		free_map(fdf->map);
		return (0);
	}
	fdf->win = mlx_new_window(fdf->mlx, fdf->display->width, \
				fdf->display->height, fdf->display_title);
	if (!fdf->win)
	{
		free_map(fdf->map);
		return (0);
	}
	fdf->mlx_data = malloc(sizeof(*fdf->mlx_data));
	if (!fdf->mlx_data)
	{
		free_map(fdf->map);
		return (0);
	}
	return (1);
}
