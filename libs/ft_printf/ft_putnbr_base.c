/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:29:24 by jdagoy            #+#    #+#             */
/*   Updated: 2023/05/10 16:56:41 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base(int nbr, int sign, char *base_set, int *count)
{
	unsigned int	size;
	unsigned int	num;

	num = nbr;
	size = ft_strlen_printf(base_set);
	if (sign && nbr < 0)
	{
		num = -nbr;
		ft_putchar_printf('-', count);
	}
	if (num > size - 1)
		ft_putnbr_base(num / size, sign, base_set, count);
	ft_putchar_base((num % size), base_set, count);
}
