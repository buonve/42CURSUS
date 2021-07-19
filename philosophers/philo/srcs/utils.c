/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 10:37:55 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/07/18 10:37:55 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

uint64_t	ft_get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

void	ft_usleep(int time, t_philo *philo)
{
	unsigned long	end;

	end = ft_get_time() + time;
	while (ft_get_time() < end && !philo->all->kill)
		usleep(time);
}

int	ft_finished(t_philo **philo)
{
	pthread_mutex_lock(philo[0]->all->kill_mutex);
	philo[0]->all->kill = 1;
	pthread_mutex_unlock(philo[0]->all->kill_mutex);
	pthread_mutex_lock(philo[0]->all->print_mutex);
	printf("\033[0;31mAll philosophers ate at least %d times\n\e[0m",
		philo[0]->all->parse_struct->nb_to_eat);
	pthread_mutex_unlock(philo[0]->all->print_mutex);
	return (1);
}

int	all_th_ate(t_philo **philo)
{
	int	i;
	int	finished;

	i = 0;
	finished = 0;
	while (i < philo[0]->all->parse_struct->philo_nb)
	{
		if (philo[i]->finish == 1)
		{
			finished += 1;
			i++;
		}
		else
			return (0);
	}
	if (finished == philo[0]->all->parse_struct->philo_nb)
	{
		if (ft_finished(philo) == 1)
			return (1);
	}
	return (0);
}
