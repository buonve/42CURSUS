/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 15:16:51 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/07/18 15:16:51 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	get_forks(t_philo *philo)
{
	sem_wait(philo->all->forks_sem);
	philo->sx_hand = 1;
	write_correct_info(philo->philo_id,
		"\033[0;34mhas taken a fork (left)\e[0m", philo);
	sem_wait(philo->all->forks_sem);
	philo->dx_hand = 1;
	write_correct_info(philo->philo_id,
		"\033[0;34mhas taken a fork (right)\e[0m", philo);
}

void	give_forks(t_philo *philo)
{
	philo->sx_hand = 0;
	sem_post(philo->all->forks_sem);
	philo->dx_hand = 0;
	sem_post(philo->all->forks_sem);
}

void	go_eat(t_philo *philo)
{
	if (philo->dx_hand == 1 && philo->sx_hand == 1)
	{
		philo->last_eat = ft_get_time();
		write_correct_info(philo->philo_id,
			"\033[0;32mis eating\e[0m", philo);
		ft_usleep(philo->all->parse_struct->time_eat, philo);
		give_forks(philo);
		philo->eating_count += 1;
		philo->stage = SLEEPING;
	}
}

void	go_sleep(t_philo *philo)
{
	write_correct_info(philo->philo_id,
		"\033[0;33mis sleeping\e[0m", philo);
	ft_usleep(philo->all->parse_struct->time_sleep, philo);
	philo->last_change = ft_get_time() - philo->all->run_time;
	philo->stage = EATING;
}
