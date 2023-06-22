/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 09:59:50 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/22 10:54:37 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	print_map(t_map_data *map)
{
	int	i;

	i = 0;
	while (map->points && i < map->dimension)
	{
		printf("Point %d\n", i);
		printf("Point X: %f\n", map->points[i].axis[X_AXIS]);
		printf("Point Y: %f\n", map->points[i].axis[Y_AXIS]);
		printf("Point Z: %f\n", map->points[i].axis[Z_AXIS]);
		printf("Point color: %d\n", map->points[i].color);
		printf("Point hex_color: %d\n\n\n", map->points[i].hex_color);
		i++;
	}
}