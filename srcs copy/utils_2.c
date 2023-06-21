/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:48:42 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/18 19:53:03 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_map_destroy(t_map_data *map)
{
	int	i;

	i = 0;
	while (i < map->size_x)
	{
		free(map->map[i]);
		i ++;
	}
}

void	free_points(t_vector3d *p1, t_vector3d *p2, t_vector3d *p3)
{
	free(p1);
	free(p2);
	free(p3);
}

void	*free_map_parser(t_map_data *data, char *mapstring)
{
	int	i;

	if (mapstring)
		free(mapstring);
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

int	min_scale(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	add_padding(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

// void	print_matrix(t_matrix3d *matrix)
// {
// 	printf("Matrix\n");
// 	printf("%f ", matrix->v1->x);
// 	printf("%f ", matrix->v1->y);
// 	printf("%f\n", matrix->v1->z);
// 	printf("%f ", matrix->v2->x);
// 	printf("%f ", matrix->v2->y);
// 	printf("%f\n", matrix->v2->z);
// 	printf("%f ", matrix->v3->x);
// 	printf("%f ", matrix->v3->y);
// 	printf("%f\n", matrix->v3->z);
// }

// void	print_map(t_map_data *map)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < map->size_x)
// 	{
// 		j = 0;
// 		while (j < map->size_y)
// 		{
// 			ft_printf("%d ", map->map[i][j]);
// 			j ++;
// 		}
// 		ft_printf("\n");
// 		i ++;
// 	}
// 	ft_printf("\n");
// }