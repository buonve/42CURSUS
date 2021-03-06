/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 16:53:17 by scilla            #+#    #+#             */
/*   Updated: 2021/07/10 13:20:20 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	elab_pipe(t_cv *cv, int *i)
{
	if (!cv->arr || !cv->arr[0] || !*cv->arr[0])
	{
		free(cv->buff);
		ft_error(errno, 0, 258);
		return (1);
	}
	cv->tmp_comm = malloc(sizeof(t_cmd));
	cv->comm->next = cv->tmp_comm;
	cv->comm->arr = cv->arr;
	cv->tmp_comm->next = 0;
	cv->comm = cv->comm->next;
	init_cmd(cv->comm);
	cv->comm->has_previous = 1;
	(*i)++;
	cv->arr = malloc(sizeof(char *));
	*cv->arr = NULL;
	cv->stage = 0;
	free(cv->buff);
	return (1);
}

void	check_stage2(t_cv *cv)
{
	if (cv->stage == 7 && ft_strlen(cv->buff))
	{
		free(cv->comm->eof);
		cv->comm->eof = cv->buff;
		cv->comm->has_dred = 1;
		cv->stage = 0;
	}
	else
		free(cv->buff);
}

void	file_in(t_cv *cv)
{
	if (cv->comm->file_in != 0)
		close(cv->comm->file_in);
	cv->comm->file_in = open(cv->buff, O_RDONLY);
	cv->stage = 0;
	if (cv->comm->file_in == -1)
	{
		ft_error(errno, 0, 0);
		cv->comm->ignore = 1;
		g_shell->exit_code = 1;
	}
}

void	check_stage(t_cv *cv)
{
	if ((cv->stage == 3 || cv->stage == 4) && ft_strlen(cv->buff))
	{
		if (cv->comm->file_out != 1)
			close(cv->comm->file_out);
		if (cv->stage == 3)
			cv->comm->file_out = open(cv->buff, O_CREAT | O_RDWR | O_TRUNC,
					S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
		else
		{
			cv->comm->file_out = open(cv->buff, O_CREAT | O_RDWR | O_APPEND,
					S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
			cv->comm->is_append = 1;
		}
		cv->stage = 0;
	}
	else if (cv->stage == 5 && ft_strlen(cv->buff))
	{
		file_in(cv);
	}
	check_stage2(cv);
}

t_cmd	**start_parsing(const char *cmd)
{
	t_cv	*cv;
	t_cmd	**res;
	int		i;

	cv = alloc_cv(&i);
	while ((*(cmd + i) || !i) && !g_shell->abort)
	{
		cv = set_cv(cv);
		while (*(cmd + i) && !g_shell->abort)
		{
			new_buff(cv, cmd, &i);
			if (cv->isb == 2 && elab_pipe(cv, &i))
			{
				if (cv->stage)
					ft_error(errno, 0, 258);
				continue ;
			}
			check_stage(cv);
			if (check_isb(cv, cmd, &i))
				break ;
		}
		move_arr(cv);
	}
	res = get_res(cv);
	return (res);
}
