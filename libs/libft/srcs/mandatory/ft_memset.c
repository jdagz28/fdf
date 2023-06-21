/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 09:51:49 by jdagoy            #+#    #+#             */
/*   Updated: 2022/10/21 11:40:55 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	unsigned int	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)str)[i] = (unsigned char)c;
		i++;
	}
	return (str);
}
