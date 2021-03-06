/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:42:12 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/05/25 15:42:15 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_stack(t_list **stack)
{
	t_list	*curr;
	t_list	*tmp;

	curr = *stack;
	while (curr)
	{
		tmp = curr->next;
		free(curr);
		curr = tmp;
	}
}

void	adjust_index(t_list **stack)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	if (*stack)
	{
		while (tmp)
		{
			tmp->index = i;
			i++;
			tmp = tmp->next;
		}
	}
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
	matrix = NULL;
}

void	ft_error(int *stack_a)
{
	write(1, "Error\n", 6);
	free(stack_a);
	stack_a = NULL;
	exit(0);
}
