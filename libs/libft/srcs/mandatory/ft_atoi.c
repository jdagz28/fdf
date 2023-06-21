/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 14:21:47 by jdagoy            #+#    #+#             */
/*   Updated: 2023/02/02 11:33:14 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	atoi;

	i = 0;
	sign = 1;
	atoi = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign *= -1;
	while (ft_isdigit(str[i]))
	{	
		atoi = atoi * 10 + (str[i++] - '0');
		if (atoi > LLONG_MAX && sign > 0)
			return (-1);
		if (atoi > LLONG_MAX && sign < 0)
			return (0);
	}	
	return (atoi * sign);
}
