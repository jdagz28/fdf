/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:22:46 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/18 19:44:44 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*gnl_trim(int fd)
{
	char	*res;
	char	*gnl_res;

	gnl_res = get_next_line(fd);
	if (!gnl_res)
		return (NULL);
	res = ft_strtrim(gnl_res, "\n");
	free(gnl_res);
	return (res);
}

static int	map_parser_cont(t_map_data *res, char *mapstrings)
{
	char	**split_res;
	int		i;

	res->map = ft_realloc_2darr(res->map, res->size_y, res->size_x, \
									res->size_x + 1);
	if (!res->map)
		return (0);
	split_res = ft_split(mapstrings, ' ');
	if (!split_res)
	{
		free_map_parser(res, mapstrings);
		return (0);
	}
	i = 0;
	while (i < count_words(mapstrings, ' '))
	{
		res->map[res->size_x][i] = ft_atoi(split_res[i]);
		i++;
	}
	res->size_x++;
	free_split(split_res, count_words(mapstrings, ' '));
	free(mapstrings);
	mapstrings = 0;
	return (1);
}

static void	map_parser_msg(int type, char *filename, t_map_data *map)
{
	if (type == 0)
	{
		ft_printf("FDF MAP: %s loaded!\n", filename);
		ft_printf("\n\nMAP SIZE: %d x %d\n", map->size_x, map->size_y);
	}
	else
	{
		ft_printf("ERROR: Map dimensions!\n");
		ft_printf("Row size is different from the previous! (row %d)\n", \
			map->size_x + 1);
	}
}

t_map_data	*init_map(char *filename, int *fd)
{
	t_map_data	*res;

	ft_printf("LOADING FDF MAP: %s...\n", filename);
	*fd = open(filename, O_RDONLY);
	if (*fd < 0)
	{
		ft_putstr_fd("ERROR: File not found\n", 1);
		return (NULL);
	}
	res = malloc(sizeof(*res));
	if (!res)
		return (NULL);
	res->map = malloc(1);
	if (!res->map)
		return (NULL);
	res->size_x = 0;
	res->size_y = 0;
	res->height_mult = 10;
	return (res);
}

t_map_data	*map_parser(char *filename)
{
	t_map_data	*res;
	int			fd;
	char		*mapstrings_gnl;

	res = init_map(filename, &fd);
	if (!res)
		return (NULL);
	while (1)
	{
		mapstrings_gnl = gnl_trim(fd);
		if (!mapstrings_gnl)
		{
			map_parser_msg(0, filename, res);
			return (res);
		}
		if (res->size_y == 0)
			res->size_y = count_words(mapstrings_gnl, ' ');
		if (count_words(mapstrings_gnl, ' ') != res->size_y)
		{
			map_parser_msg(1, filename, res);
			return (free_map_parser(res, mapstrings_gnl));
		}
		if (!map_parser_cont(res, mapstrings_gnl))
			return (free_map_parser(res, mapstrings_gnl));
	}
}
