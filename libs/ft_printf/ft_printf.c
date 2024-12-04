/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:05:33 by jdagoy            #+#    #+#             */
/*   Updated: 2023/05/10 16:56:26 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	argptr;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(argptr, str);
	if (!str)
		return (count);
	while (str[i])
	{
		if (str[i] == '%' && ft_speccheck(str[i + 1]))
			ft_forconversion(str[++i], argptr, &count);
		else if (str[i] == '%' && !ft_speccheck(str[i + 1]))
				i++;
		else
			ft_putchar_printf(str[i], &count);
		i++;
	}
	va_end(argptr);
	return (count);
}
