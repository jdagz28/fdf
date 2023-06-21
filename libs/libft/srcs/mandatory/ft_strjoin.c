/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 14:13:59 by jdagoy            #+#    #+#             */
/*   Updated: 2022/10/14 16:14:01 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	lens1;
	size_t	lens2;

	if (!s1 && !s2)
		return (NULL);
	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	s = (char *)malloc(sizeof(char) * (lens1 + lens2 + 1));
	if (!s)
		return (NULL);
	ft_strlcpy(s, (char *)s1, lens1 + 1);
	ft_strlcat(s, (char *)s2, lens1 + lens2 + 1);
	return (s);
}
