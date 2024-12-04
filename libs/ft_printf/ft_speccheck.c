/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_speccheck.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 10:38:58 by jdagoy            #+#    #+#             */
/*   Updated: 2022/11/02 09:15:14 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_speccheck(char c)
{
	char	*allowspec;
	int		i;

	allowspec = "cspdiuxX%";
	i = 0;
	while (allowspec[i])
	{
		if (c == allowspec[i])
			return (1);
		i++;
	}
	return (0);
}
