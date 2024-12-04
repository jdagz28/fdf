/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:51:48 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/25 01:40:00 by jdagoy           ###   ########.fr       */
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
