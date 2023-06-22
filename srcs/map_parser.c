/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:22:46 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/22 11:00:42 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	assign_pointcolor(t_point *map_point, char *point_str)
{
	map_point->color = DEFAULT_COLOR;
	if (check_hexcolor(point_str) != 0)
		map_point->hex_color = check_hexcolor(point_str);
}

static void	load_points(char *line, t_map_data *map, int noline)
{
	char	**split_res;
	int		i;
	int		index;

	i = 0;
	index = 0;
	split_res = ft_split(line, ' ');
	if (!split_res)
		error_split_loadpoint(map);
	while (split_res[i] && split_res[i][0] != '\n')
	{
		if (!valid_point(&split_res[i][0]))
			exit_error("Incorrect map file format. \n");
		map->points[index].axis[Z_AXIS] = ft_atoi(split_res[i]);
		map->points[index].axis[X_AXIS] = i - map->limits.axis[X_AXIS] / 2;
		map->points[index].axis[Y_AXIS] = noline - map->limits.axis[Y_AXIS] / 2;
		assign_pointcolor(&map->points[index], split_res[i]);
		if (map->limits.axis[Z_AXIS] < map->points[index].axis[Z_AXIS])
			map->limits.axis[Z_AXIS] = map->points[index].axis[Z_AXIS];
		if (map->z_min > map->points[index].axis[Z_AXIS])
			map->z_min = map->points[index].axis[Z_AXIS];
		i++;
		index++;
	}
	free_split(split_res, index);
}

static void	get_mappoints(t_map_data *map)
{
	int		i;
	char	*line;
	char	*prev_line;
	int		total_lines;

	i = 0;
	total_lines = 0;
	prev_line = map->mapread;
	line = NULL;
	map->points = ft_calloc(map->dimension, sizeof(t_point));
	while (1)
	{
		if (map->mapread[i] == '\n' || map->mapread[i] == '\0')
		{
			free(line);
			line = ft_substr(prev_line, 0, &map->mapread[i] - prev_line);
			prev_line = &map->mapread[i + 1];
			load_points(line, map, total_lines++);
			if (map->mapread[i] == '\0')
				break ;
		}
		i++;
	}
	ft_printf("Successfully loaded %d points.\n", map->dimension);
	free(line);
}

static char	*read_map(int fd)
{
	char	*gnl_res;
	char	*mapstrings;

	mapstrings = ft_strdup("");
	ft_printf("Loading Map...\n");
	while (1)
	{
		gnl_res = get_next_line(fd);
		if (!gnl_res)
		{
			free(gnl_res);
			break ;
		}
		mapstrings = ft_strjoin(mapstrings, gnl_res);
		free(gnl_res);
	}
	return (mapstrings);
}

void	map_parser(t_map_data *map, char *filename)
{
	int			fd;

	if (!map)
		exit(1);
	init_map(map);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		exit_error("File not found\n");
	map->mapread = read_map(fd);
	close(fd);
	get_mapsize(map);
	ft_printf("====================================\n");
	ft_printf("MAP SIZE: %d x %d\n", map->map_width, map->map_height);
	get_mappoints(map);
	color_points(map);
	print_map(map);
	free_map(map);
}
