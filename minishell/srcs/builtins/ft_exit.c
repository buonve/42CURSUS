/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 13:18:53 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/07/10 13:22:02 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_exit(t_shell *g_shell)
{
	if (!ft_strcmp(g_shell->prompt, "peppere> "))
		ctrl_c();
	else
	{
		ft_free_env(g_shell->env);
		free_old(g_shell->current);
		free_history(g_shell->current);
		printf("exit\n");
		exit(0);
	}
}
