/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 18:35:33 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/04/09 11:00:44 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	i;
	size_t	j;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (!s1 || !s2 ||
		!(joined = (char *)malloc((len_s1 + len_s2 + 1))))
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		joined[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len_s2)
	{
		joined[i + j] = s2[j];
		j++;
	}
	joined[i + j] = '\0';
	return (joined);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == c)
		return ((char *)(s + i));
	return (NULL);
}

int	lettura(char **n_l, char **save, int fd)
{
	int		red;
	char	*buffer;
	char	*temp;

	red = BUFFER_SIZE;
	*n_l = ft_strchr(save[fd], '\n');
	while (!(*n_l) && (red == BUFFER_SIZE))
	{
		buffer = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		if (!buffer)
		{
			free(save[fd]);
			return (-1);
		}
		red = read(fd, buffer, BUFFER_SIZE);
		if (red == -1)
		{
			free(save[fd]);
			free(buffer);
			return (-1);
		}
		temp = ft_strjoin(save[fd], buffer);
		free(save[fd]);
		save[fd] = temp;
		free(buffer);
	}
	return (0);
}

int	get_next_line(const int fd, char **line)
{
	static char	*save[MAX_OPEN];
	char		*n_l;
	char		*temp;

	if (!line || fd < 0 || BUFFER_SIZE < 1 || fd > MAX_OPEN)
		return (-1);
	if (!save[fd])
	{
		save[fd] = (char *)ft_calloc(sizeof(char), 1);
		if (!save[fd])
			return (-1);
	}
	n_l = 0;
	if (lettura(&n_l, save, fd) != 0)
		return (-1);
	if (n_l)
		*n_l = 0;
	*line = ft_strdup(save[fd]);
	if (n_l)
	{
		temp = ft_strdup(n_l + 1);
		free(save[fd]);
		save[fd] = temp;
		return (1);
	}
	free(save[fd]);
	save[fd] = 0;
	return (0);
}
