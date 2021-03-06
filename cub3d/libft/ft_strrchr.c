/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 16:47:27 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/01/14 17:19:20 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == (char)c)
			return (char *)(s + i);
		i--;
	}
	if (s[i] == (char)c)
		return ((char *)s);
	return (NULL);
}
