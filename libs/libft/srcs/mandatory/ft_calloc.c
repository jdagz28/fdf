/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:51:48 by jdagoy            #+#    #+#             */
/*   Updated: 2023/04/14 09:27:31 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	size_t	total;

	total = count * size;
	mem = malloc(count * size);
	if (!mem)
		return (NULL);
	if (count != 0 && (total / count != size || total % count != 0))
		return (NULL);
	ft_bzero(mem, count * size);
	return (mem);
}
