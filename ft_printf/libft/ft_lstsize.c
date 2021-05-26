/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 10:56:16 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/01/19 11:20:54 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	size_t i;
	t_list *tmp;

	tmp = lst;
	i = 0;
	if (!tmp)
		return (0);
	while (tmp->next != NULL)
	{
		i++;
		tmp = tmp->next;
	}
	if (tmp->next == NULL)
		i++;
	return (i);
}
