/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:22:46 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/26 15:55:41 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	assign_pointcolor(t_point *map_point, char *point_str)
{
	map_point->color = DEFAULT_COLOR;
	if (check_hexcolor(point_str) != 0)
		map_point->hex_color = check_hexcolor(point_str);
}

static int	load_points(char *line, t_map_data *map, int noline)
{
	char			**split_res;
	int				i;
	static int		index = 0;

	i = 0;
	split_res = ft_split(line, ' ');
	if (!split_res)
		error_split_loadpoint(map);
	while (split_res[i] && split_res[i][0] != '\n')
	{
		if (!valid_point(&split_res[i][0]))
			exit_error("Invalid point. Incorrect format.\n");
		map->points[index].axis[Z_AXIS] = ft_atoi(&split_res[i][0]);
		map->points[index].axis[X_AXIS] = i - map->limits.axis[X_AXIS] / 2;
		map->points[index].axis[Y_AXIS] = noline - map->limits.axis[Y_AXIS] / 2;
		map->points[index].ispoint = 1;
		assign_pointcolor(&map->points[index], split_res[i]);
		check_z(map, index);
		i++;
		index++;
	}
	free_split(split_res);
	return (i);
}

static void	get_mappoints(t_map_data *map)
{
	int				i;
	char			*line;
	char			*prev_line;
	static int		total_lines = 0;
	static int		points = 0;

	i = 0;
	prev_line = map->mapread;
	line = NULL;
	map->points = ft_calloc(map->dimension, sizeof(t_point));
	while (++i)
	{
		if (map->mapread[i] == '\n' || map->mapread[i] == '\0')
		{
			free(line);
			line = ft_substr(prev_line, 0, &map->mapread[i] - prev_line);
			prev_line = &map->mapread[i + 1];
			points += load_points(line, map, total_lines++);
			ft_printf("\r Loading pts: %d out of %d.", points, map->dimension);
			if (map->mapread[i] == '\0')
				break ;
		}
	}
	ft_printf("\nMap points succesfully loaded.\n");
	free(line);
}

static char	*read_map(int fd)
{
	char	*gnl_res;
	char	*mapstrings;
	char	*temp;

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
		temp = mapstrings;
		mapstrings = ft_strjoin(mapstrings, gnl_res);
		free(temp);
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
	if (map->map_height == 0 || map->map_width == 0)
		exit_error("Map width and height should be greater than zero.");
	ft_printf("====================================\n");
	ft_printf("Map Size: %d x %d\n", map->map_width, map->map_height);
	get_mappoints(map);
	color_points(map);
}
