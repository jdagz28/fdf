/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:47:45 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/26 15:55:18 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	initialize_colors(t_map_data *map)
{
	map->color.background = 0x151515;
	map->color.highest_color = 0x8b292a;
	map->color.lowest_color = 0x000bff;
	map->color.ground_color = 0x165214;
}

void	init_map(t_map_data *map)
{
	map->drawtype = line;
	map->limits.axis[X_AXIS] = 0;
	map->limits.axis[Y_AXIS] = 0;
	map->limits.axis[Z_AXIS] = 0;
	map->ang[X_AXIS] = 0;
	map->ang[Y_AXIS] = 0;
	map->ang[Z_AXIS] = 0;
	map->z_divisor = 1;
	map->scale = 1;
	map->map_height = 0;
	map->map_width = 0;
	map->source.axis[X_AXIS] = (WINDOW_WIDTH / 2) + WINDOW_WIDTH;
	map->source.axis[Y_AXIS] = WINDOW_HEIGHT / 2;
	map->source.axis[Z_AXIS] = 0;
	initialize_colors(map);
}
