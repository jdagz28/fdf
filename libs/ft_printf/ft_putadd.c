/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:55:17 by jdagoy            #+#    #+#             */
/*   Updated: 2023/05/10 16:55:11 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putmemchar(int nbr, char *hexbase, int *count)
{
	write(1, &hexbase[nbr], 1);
	*count += 1;
}

static void	ft_putmem(unsigned long nbr, int *count)
{
	if (nbr > 15)
		ft_putmem(nbr / 16, count);
	ft_putmemchar((nbr % 16), LOW_HEX, count);
}

void	ft_putadd(void *add, int *count)
{
	unsigned long	hex;

	hex = (unsigned long)add;
	ft_putstr_printf("0x", count);
	ft_putmem(hex, count);
}
