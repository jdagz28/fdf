/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:21:14 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/26 15:20:15 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_split_loadpoint(t_map_data *map)
{
	free_map(map);
	(void)map;
	exit_error("Parsing error while loading each point.\n");
}

int	destroy_fdf(t_fdf *fdf)
{
	if (!fdf)
		exit(0);
	free_map(&fdf->map);
	if (fdf->display_title)
		free(fdf->display_title);
	ft_printf("\n\nExiting FDF...\n");
	exit(0);
}

void	exit_error(char	*str)
{
	ft_printf("\n");
	ft_putstr_fd("ERROR: ", 1);
	ft_putstr_fd(str, 1);
	exit(1);
}

void	free_split(char **ptr)
{
	int	i;

	if (!ptr)
		return ;
	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free (ptr);
}

void	free_map(t_map_data *map)
{
	free(map->mapread);
	free(map->points);
}
