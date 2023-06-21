/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 11:51:48 by jdagoy            #+#    #+#             */
/*   Updated: 2023/05/11 10:04:28 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*mem;

	len = ft_strlen(s1);
	mem = (char *)malloc(sizeof(char) * (len + 1));
	if (!mem)
		return (NULL);
	ft_memcpy(mem, s1, len + 1);
	return (mem);
}
