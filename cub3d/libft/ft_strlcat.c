/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 11:45:27 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/01/18 12:52:51 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t len_d;
	size_t len_s;
	size_t i;
	size_t j;

	len_d = ft_strlen(dst);
	len_s = ft_strlen(src);
	j = 0;
	if (dstsize <= len_d)
		return (len_s + dstsize);
	i = ft_strlen(dst);
	if (i < dstsize - 1)
	{
		while (src[j] != '\0' && i < dstsize - 1)
			dst[i++] = src[j++];
	}
	dst[i] = '\0';
	return (len_d + len_s);
}
