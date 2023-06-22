/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:21:14 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/22 13:39:38 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


int	destroy_fdf(t_fdf *fdf)
{
	if (!fdf)
		exit(0);
	free_map(&fdf->map);
	free(&fdf->map);
	if (fdf->display_title)
		free(fdf->display_title);
	ft_printf("\n\nExiting FDF...\n");
	exit(0);
}

void	exit_error(char	*str)
{
	ft_putstr_fd("ERROR: ", 1);
	ft_putstr_fd(str, 1);
	exit(1);
}

void	free_split(char **split, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	free_map(t_map_data *map)
{
	free(map->mapread);
	free(map->points);
}