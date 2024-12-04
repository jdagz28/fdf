/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keybinds_2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 00:22:13 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/28 09:43:16 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	color_map(t_map_data *map)
{
	int	i;

	i = 0;
	while (i < map->dimension)
	{
		load_color((int)map->limits.axis[Z_AXIS], map->z_min, \
		&map->points[i], map->color);
		i++;
	}
}

static void	last_pallette(t_fdf *fdf)
{
	fdf->map.color.highest_color = 0x1c6673;
	fdf->map.color.lowest_color = 0xb5aa98;
	fdf->map.color.ground_color = 0xf9c55f;
}

void	keybindings_cont_three(int keycode, t_fdf *fdf)
{
	if (keycode == K_NUM_PERIOD)
	{
		fdf->color = (fdf->color + 1) % 4;
		if (fdf->color == RGB)
		{
			fdf->map.color.highest_color = 0x8b292a;
			fdf->map.color.lowest_color = 0x000bff;
			fdf->map.color.ground_color = 0x165214;
		}
		else if (fdf->color == White)
		{
			fdf->map.color.highest_color = 0xFFFFFF;
			fdf->map.color.lowest_color = 0xFFFFFF;
			fdf->map.color.ground_color = 0xFFFFFF;
		}
		else if (fdf->color == tt_pallette1)
		{
			fdf->map.color.highest_color = 0x630099;
			fdf->map.color.lowest_color = 0xff8305;
			fdf->map.color.ground_color = 0x058d5b;
		}
		else
			last_pallette(fdf);
		color_map(&fdf->map);
	}
}
