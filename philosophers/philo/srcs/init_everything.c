/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_everything.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 10:38:13 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/07/18 10:38:14 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_philos(t_philo **philo, t_general *all)
{
	int	i;

	i = 0;
	while (i < all->parse_struct->philo_nb)
	{
		philo[i] = malloc(sizeof(t_philo));
		philo[i]->eating_count = 0;
		philo[i]->finish = 0;
		philo[i]->sx_hand = NOT_TAKEN;
		philo[i]->dx_hand = NOT_TAKEN;
		philo[i]->last_change = 0;
		philo[i]->last_eat = ft_get_time();
		philo[i]->philo_id = i + 1;
		philo[i]->stage = EATING;
		philo[i]->status = ALIVE;
		philo[i]->all = all;
		i++;
	}
}

void	init_forks(t_general *all)
{
	int	i;

	i = 0;
	all->forks = malloc(sizeof(int *) * (all->parse_struct->philo_nb + 1));
	while (i < all->parse_struct->philo_nb)
	{
		all->forks[i] = malloc(sizeof(int));
		all->forks[i][0] = 1;
		i++;
	}
	all->forks[i] = all->forks[0];
}

void	init_mutex(t_general *all)
{
	int	i;

	i = 0;
	all->forks_mutex = malloc(sizeof(pthread_mutex_t *)
			* (all->parse_struct->philo_nb + 1));
	while (i < all->parse_struct->philo_nb)
	{
		all->forks_mutex[i] = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(all->forks_mutex[i], NULL);
		i++;
	}
	all->forks_mutex[i] = all->forks_mutex[0];
	all->print_mutex = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(all->print_mutex, NULL);
	all->kill_mutex = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(all->kill_mutex, NULL);
}

void	init_threads(t_general *all)
{
	int	i;

	i = 0;
	all->philo_threads = malloc(sizeof(pthread_t *)
			* all->parse_struct->philo_nb);
	while (i < all->parse_struct->philo_nb)
	{
		all->philo_threads[i] = malloc(sizeof(pthread_t));
		i++;
	}
}

void	run_life(t_philo **philo)
{
	int	i;
	int	nb;

	nb = philo[0]->all->parse_struct->philo_nb;
	i = 0;
	philo[0]->all->run_time = ft_get_time();
	while (i < nb)
	{
		pthread_create(philo[i]->all->philo_threads[i],
			NULL, &sit_at_table, (void *)philo[i]);
		i++;
	}
}
