/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 21:13:02 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/21 12:06:40 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// void	free_split(char **split, size_t len)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < len)
// 	{
// 		free(split[i]);
// 		i++;
// 	}
// 	free(split);
// }

// int	count_words(char *str, char sep)
// {
// 	int	i;
// 	int	same_word;

// 	i = 0;
// 	same_word = 0;
// 	while (*str)
// 	{
// 		if (*str == sep)
// 			same_word = 0;
// 		else
// 		{
// 			if (!same_word)
// 			{
// 				same_word = 1;
// 				i++;
// 			}
// 		}
// 		str++;
// 	}
// 	return (i);
// }

// static int	**ft_realloc_2darr_cont(int **src, int **res, const size_t sizes[3])
// {
// 	size_t	i;
// 	size_t	j;

// 	res = ft_calloc(sizes[2], sizeof(*src));
// 	if (res == NULL)
// 	{
// 		j = 0;
// 		while (j < sizes[0])
// 		{
// 			free(src[j]);
// 			j++;
// 		}
// 		free(src);
// 		return (NULL);
// 	}
// 	i = 0;
// 	while (i < sizes[2])
// 	{
// 		if (i < sizes[1])
// 			res[i] = src[i];
// 		else
// 			res[i] = ft_calloc(sizes[0], sizeof(**src));
// 		i++;
// 	}
// 	return (res);
// }

// int	**ft_realloc_2darr(int **src, size_t elem_size, size_t arr_size, \
// 						size_t new_size)
// {
// 	size_t		j;
// 	int			**res;
// 	size_t		sizes[3];

// 	sizes[0] = elem_size;
// 	sizes[1] = arr_size;
// 	sizes[2] = new_size;
// 	res = 0;
// 	if (new_size <= arr_size)
// 	{
// 		j = 0;
// 		while (j < elem_size)
// 		{
// 			free(src[j]);
// 			j++;
// 		}
// 		free(src);
// 		return (NULL);
// 	}
// 	res = ft_realloc_2darr_cont(src, res, sizes);
// 	free(src);
// 	return (res);
// }
