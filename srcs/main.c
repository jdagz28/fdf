/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 14:20:07 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/21 12:37:26 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	file_extension_checker(const char *filename, const char *extension)
{
	if (ft_strlen(filename) < ft_strlen(extension))
		return (1);
	if (ft_strncmp(filename + (ft_strlen(filename) - ft_strlen(extension)), \
			extension, ft_strlen(extension)))
		return (1);
	return (0);
}

static int	arg_handler(int argc, char **argv)
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

int	main(int argc, char **argv)
{
	t_fdf	fdf;
	int		arg_check;

	arg_check = arg_handler(argc, argv);
	if (arg_check != 0)
		return (1);
	map_parser(&fdf.map, argv[1]);


	return (0);
}
