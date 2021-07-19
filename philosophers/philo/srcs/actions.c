/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 14:56:45 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/07/18 14:56:45 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	get_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->all->forks_mutex[philo->philo_id - 1]);
	if (*philo->all->forks[philo->philo_id - 1] == 1)
	{
		philo->sx_hand = 1;
		*philo->all->forks[philo->philo_id - 1] = 0;
		write_correct_info(philo->philo_id,
			"\033[0;34mhas taken a fork (left)\e[0m", philo);
	}
	pthread_mutex_lock(philo->all->forks_mutex[philo->philo_id]);
	if (*philo->all->forks[philo->philo_id] == 1)
	{
		philo->dx_hand = 1;
		*philo->all->forks[philo->philo_id] = 0;
		write_correct_info(philo->philo_id,
			"\033[0;34mhas taken a fork (right)\e[0m", philo);
	}
}

void	give_forks(t_philo *philo)
{
	if (*philo->all->forks[philo->philo_id - 1] == 0)
	{
		philo->sx_hand = 0;
		*philo->all->forks[philo->philo_id - 1] = 1;
	}
	pthread_mutex_unlock(philo->all->forks_mutex[philo->philo_id - 1]);
	if (*philo->all->forks[philo->philo_id] == 0)
	{
		philo->dx_hand = 0;
		*philo->all->forks[philo->philo_id] = 1;
	}
	pthread_mutex_unlock(philo->all->forks_mutex[philo->philo_id]);
}

void	go_eat(t_philo *philo)
{
	if (philo->dx_hand == 1 && philo->sx_hand == 1)
	{
		philo->last_eat = ft_get_time();
		write_correct_info(philo->philo_id, "\033[0;32mis eating\e[0m", philo);
		ft_usleep(philo->all->parse_struct->time_eat, philo);
		give_forks(philo);
		philo->eating_count += 1;
		philo->stage = SLEEPING;
	}
}

void	go_sleep(t_philo *philo)
{
	write_correct_info(philo->philo_id, "\033[0;33mis sleeping\e[0m", philo);
	ft_usleep(philo->all->parse_struct->time_sleep, philo);
	philo->last_change = ft_get_time() - philo->all->run_time;
	philo->stage = EATING;
}
