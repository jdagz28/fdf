/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:22:46 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/21 16:18:57 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	free_map(t_map_data *map)
{
	int	i;

	i = 0;
	while (i < map->dimension)
		free(map->points[i]);
}
int	check_hexcolor(char *str)
{
	char	**color;
	int		get_color;
	char	*temp;
	char	*color_substr;
	int		i;

	i = 0;
	temp = ft_strdup("");
	if (ft_strchr(str, ',') != 0)
	{
		color = ft_split(str, ',');
		color_substr = color[1] + 2;
		while (i < 8 && color_substr[i] != '\0')
		{
			temp[i] = color_substr[i];
			i++;
		}
		temp[i] = '\0';
	}
	get_color = ft_atoi(temp);
	printf("%d", get_color);
	return (get_color);
}

void	error_split_loadpoint(t_map_data *map)
{
	free_map(map);
	exit_error("Parsing error while loading each point.\n");
}


static void	assign_pointcolor(t_point *map_point, char *point_str)
{
	map_point->color = DEFAULT_COLOR;
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
		map->points[index].axis[Z_AXIS] = ft_atoi(&split_res[i][0]);
		map->points[index].axis[X_AXIS] = i - map->limits[X_AXIS] / 2;
		map->points[index].axis[Y_AXIS] = noline - map->limits.axis[Y_AXIS] / 2;
		assign_pointcolor(map->points[index], split_res[i]);
		if (map->limits.axis[Z_AXIS] < map->points[index].axis[Z_AXIS])
			map->limits.axis[Z_AXIS] = map->points[index].axis[Z_AXIS];
		if (map->z_min > map->points[index].axis[Z_AXIS])
			map->z_min = map->points[index].axis[Z_AXIS];
		i++;
		index++;
	}
	free_split(split_res);
}

static void	get_mappoints(t_map_data *map)
{
	int		i;
	char	*line;
	char	*prev_line;
	int		total_lines;

	i = 0;
	total_lines = 0;
	map->points = ft_calloc(sizeof(t_point), map->dimension);
	while (++i)
	{
		if (map->mapread[i] == '\n' || map->mapread[i] == '\0')
		{
			if (line)
				free(line);
			line = ft_substr(prev_line, 0, &map->mapread[i] - prev_line);
			prev_line = &map->mapread[i + 1];
			load_points(line, map, total_lines++);
			if (map->mapread == '\0')
				break
		}
	}
	ft_printf("Successfully loaded %d points.\n", map->dimension);
	free(line);

}



static char	*gnl_trim(int fd)
{
	char	*gnl_res;

	gnl_res = get_next_line(fd);
	if (!gnl_res)
		return (NULL);
	return (gnl_res);
}

void	exit_error(char	*str)
{
	ft_putstr_fd("ERROR: ", 1);
	ft_putstr_fd(str, 1);
	exit(1);
}

void	get_mapsize_cont(t_map_data *map, int elem_count)
{
	if (elem_count && (map->limits.axis[X_AXIS] != elem_count))
	{
		ft_printf("Row size is different from the previous! (row %d)\n", \
					map->limits.axis[X_AXIS]);
		exit_error("Map row elements are different.\n");
	}
	map->limits.axis[Y_AXIS]++;
	map->map_height = map->limits.axis[Y_AXIS];
	map->map_width = map->limits.axis[X_AXIS];
	map->dimension = map->map_height * map->map_width;
}

void	get_mapsize(t_map_data *map)
{
	int i;
	int elem_count;

	i = 0;
	elem_count = 0;
	while (map->mapread[i])
	{
		if (map->mapread[i] == '\n' && map->mapread[i + 1] == '\0')
			break ;
		if (ft_isalnum(map->mapread[i]) && (map->mapread[i + 1] == ' ' \
				|| map->mapread[i + 1] == '\n' || map->mapread[i + 1] == '\0'))
				elem_count++;
		if (map->mapread[i] == '\n')
		{
			map->limits.axis[Y_AXIS]++;
			if (map->limits.axis[X_AXIS] != 0 && \
					(map->limits.axis[X_AXIS] != elem_count))
				exit_error("Map row elements are different.\n");
			else
				map->limits.axis[X_AXIS] = elem_count;
			elem_count = 0;
		}
		i++;
	}
	get_mapsize_cont(map, elem_count);
}

static char	*read_map(int fd)
{
	char	*gnl_res;
	char	*mapstrings;

	mapstrings = ft_strdup("");
	ft_printf("Loading Map...\n");
	while (1)
	{
		gnl_res = gnl_trim(fd);
		if (!gnl_res)
			break ;
		mapstrings = ft_strjoin(mapstrings, gnl_res);
		free(gnl_res);
	}
	return (mapstrings);
}

void	initialize_colors(t_map_data *map)
{
	map->color.background = 0x151515; //BLACK
	map->color.highest_color = 0x8b292a; //RED
	map->color.lowest_color = 0x000bff; //BLUE
	map->color.ground_color = 0x165214; //GREEN
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
	// printf("%s", map->mapread);
	close(fd);
	get_mapsize(map);
	ft_printf("====================================\n");
	ft_printf("MAP SIZE: %d x %d\n", map->map_width, map->map_height);
	get_mappoints(map);
}
