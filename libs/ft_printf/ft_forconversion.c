/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forconversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:39:16 by jdagoy            #+#    #+#             */
/*   Updated: 2023/05/10 16:56:33 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_forconversion(char c, va_list argptr, int *count)
{
	if (c == 'c')
		ft_putchar_printf(va_arg(argptr, int), count);
	else if (c == 's')
		ft_putstr_printf(va_arg(argptr, void *), count);
	else if (c == 'p')
		ft_putadd(va_arg(argptr, void *), count);
	else if (c == 'd' || c == 'i')
		ft_putnbr_base(va_arg(argptr, int), SIGNED, DECIMAL, count);
	else if (c == 'u')
		ft_putnbr_base(va_arg(argptr, int), UNSIGNED, DECIMAL, count);
	else if (c == 'x')
		ft_putnbr_base(va_arg(argptr, int), UNSIGNED, LOW_HEX, count);
	else if (c == 'X')
		ft_putnbr_base(va_arg(argptr, int), UNSIGNED, UP_HEX, count);
	else if (c == '%')
		ft_putchar_printf('%', count);
}
