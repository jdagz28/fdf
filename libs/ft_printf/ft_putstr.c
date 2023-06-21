/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:46:23 by jdagoy            #+#    #+#             */
/*   Updated: 2023/05/10 16:54:21 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_printf(char *str, int *count)
{
	int	i;

	i = 0;
	if (!str)
		ft_putstr_printf("(null)", count);
	while (str && str[i])
		ft_putchar_printf(str[i++], count);
}
