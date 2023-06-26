/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_handler_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 10:47:45 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/26 15:54:46 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	file_extension_checker(const char *filename, const char *extension)
{
	if (ft_strlen(filename) < ft_strlen(extension))
		return (1);
	if (ft_strncmp(filename + (ft_strlen(filename) - ft_strlen(extension)), \
			extension, ft_strlen(extension)))
		return (1);
	return (0);
}

int	arg_handler(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("Usage: ./fdf {file in .fdf format} \n");
		return (1);
	}
	if (file_extension_checker(argv[1], ".fdf") != 0)
	{
		ft_printf("Error: Invalid map format. Must be in `.fdf` format\n");
		return (1);
	}
	ft_printf("File: %s\n", argv[1]);
	return (0);
}
