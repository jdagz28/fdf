/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:54:48 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/27 22:15:30 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	numlen(long num)
{
	int	len;

	len = 0;
	if (num < 0)
	{
		num *= -1;
		len++;
	}
	else if (!num)
		return (1);
	while (num)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		i;
	long	num;
	char	*s;

	i = numlen(n);
	s = (char *)malloc(sizeof(char) * (i + 1));
	if (!s)
		return (NULL);
	num = n;
	s[i] = 0;
	if (n < 0)
	{
		s[0] = '-';
		num = -num;
	}
	else if (!num)
		s[0] = '0';
	while (num)
	{
		s[--i] = num % 10 + '0';
		num /= 10;
	}
	return (s);
}
