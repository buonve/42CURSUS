/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 15:34:28 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/07/18 15:34:28 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	int_checker(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		j = 0;
		if (av[i][j] == '-' || av[i][j] == '+')
			j++;
		while (av[i][j])
		{
			if (!ft_isdigit((int)av[i][j]))
			{
				printf("One or some arguments are not integers\n");
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_values(t_parse *parse_struct, int flag)
{
	if (parse_struct->philo_nb < 1 || parse_struct->time_die <= 0
		|| parse_struct->time_eat <= 0 || parse_struct->time_sleep <= 0
		|| (parse_struct->nb_to_eat < 1 && flag))
	{
		printf("Wrong argument value\n");
		return (1);
	}
	return (0);
}

int	fill_parse_struct(int ac, char **av, t_parse *parse_struct)
{
	int	flag;

	flag = 0;
	parse_struct->philo_nb = ft_atoi(av[1]);
	parse_struct->time_die = ft_atoi(av[2]);
	parse_struct->time_eat = ft_atoi(av[3]);
	parse_struct->time_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		parse_struct->nb_to_eat = ft_atoi(av[5]);
		flag = 1;
	}
	else
		parse_struct->nb_to_eat = -1;
	if (check_values(parse_struct, flag) == 1)
		return (1);
	return (0);
}

int	start_parse(int ac, char **av, t_parse *parse_struct)
{
	if (ac < 5)
	{
		printf("Wrong number of argument\n");
		return (1);
	}
	else
	{
		if (ac <= 6)
		{
			if (int_checker(ac, av) < 0)
				return (1);
			if (fill_parse_struct(ac, av, parse_struct) == 1)
				return (1);
		}
		else
		{
			printf("Too many arguments\n");
			return (1);
		}
	}
	return (0);
}
