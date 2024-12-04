/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/15 16:59:54 by jdagoy            #+#    #+#             */
/*   Updated: 2022/10/15 18:02:23 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	lstlen;

	lstlen = 0;
	if (!lst)
		return (lstlen);
	while (lst)
	{
		lstlen++;
		lst = lst->next;
	}
	return (lstlen);
}
