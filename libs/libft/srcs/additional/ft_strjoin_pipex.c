/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_pipex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 21:53:47 by jdagoy            #+#    #+#             */
/*   Updated: 2023/05/11 11:17:58 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_pipex(const char *s1, const char *s2, const char *s3)
{
	char	*result;
	size_t	s1_len;
	size_t	s2_len;
	size_t	s3_len;

	if (!s1 || !s2 || !s3)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s3_len = ft_strlen(s3);
	result = (char *)malloc(sizeof(char) * (s1_len + s2_len + s3_len + 1));
	if (!result)
		return (NULL);
	while (*s1)
		*result++ = *s1++;
	while (*s2)
		*result++ = *s2++;
	while (*s3)
		*result++ = *s3++;
	*result = '\0';
	return (result - s1_len - s2_len - s3_len);
}
