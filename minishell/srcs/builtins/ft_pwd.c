/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:19:05 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/07/10 13:19:06 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_pwd(void)
{
	char	*test;

	test = malloc(sizeof(char) * 4096);
	test = getcwd(test, 4096);
	ft_printf_fd(1, "%s\n", test);
	free(test);
}
