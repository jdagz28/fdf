/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:55:13 by jdagoy            #+#    #+#             */
/*   Updated: 2022/10/12 23:59:47 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned char	*str;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	str = (unsigned char *)ft_strdup(s);
	if (!str)
		return (NULL);
	i = 0;
	while (str && str[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return ((char *) str);
}
