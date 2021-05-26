/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/25 15:42:56 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/05/25 15:42:58 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char**av)
{
	int	*stack_a;
	int	len;

	len = 0;
	if (ac <= 2)
	{
		if (ac == 2)
			stack_a = check_single_arg(av, &len);
		else
			exit(0);
	}
	else
	{
		stack_a = check_more_args(ac, av, &len);
	}
	start_checker(stack_a, len);
	free(stack_a);
	return (0);
}
