/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 10:38:06 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/07/18 10:38:06 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_struct(t_parse *parse_struct)
{
	parse_struct->philo_nb = -1;
	parse_struct->time_die = -1;
	parse_struct->time_eat = -1;
	parse_struct->time_sleep = -1;
	parse_struct->nb_to_eat = -1;
}

void	loop_checks(t_general *all, t_philo **philo)
{
	int	i;

	i = 0;
	while (!all->kill)
	{
		if (all->parse_struct->nb_to_eat > 0)
			all_th_ate(philo);
	}
	i = 0;
	while (i < all->parse_struct->philo_nb && all->kill == 1)
	{
		pthread_join(*all->philo_threads[i], NULL);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_philo		**philo;
	t_general	*all;

	all = malloc(sizeof(t_general));
	all->parse_struct = malloc(sizeof(t_parse));
	init_struct(all->parse_struct);
	if (start_parse(ac, av, all->parse_struct) == 1)
	{
		free(all->parse_struct);
		free(all);
		return (1);
	}
	init_forks(all);
	init_mutex(all);
	init_threads(all);
	all->kill = 0;
	philo = malloc(sizeof(t_philo) * all->parse_struct->philo_nb);
	init_philos(philo, all);
	run_life(philo);
	loop_checks(all, philo);
	free_everything(philo, all);
	return (0);
}
