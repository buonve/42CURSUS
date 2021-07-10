/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:21:16 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/07/10 13:21:17 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_print_env(t_env *env)
{
	while (env)
	{
		printf("%s", env->env_name);
		printf("=");
		printf("%s\n", env->env_value);
		env = env->next_env;
	}
}

int	only_spaces(char *str)
{
	while (*str)
	{
		if (*str != ' ')
			return (0);
		str++;
	}
	return (1);
}
