/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 20:43:48 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/07/17 20:43:48 by vbuonvin         ###   ########.fr       */
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

int	all_th_ate(t_philo **philo)
{
	int	i;
	int	nb;

	nb = philo[0]->all->parse_struct->philo_nb;
	i = 0;
	while (i < nb)
	{
		waitpid(philo[0]->all->pid[i], (int *)&philo[0]->all->pid[i], 0);
		i++;
	}
	sem_wait(philo[0]->all->print_sem);
	printf("All the philosophers eat at least %d times\n", nb);
	return (1);
}

void	free_everything(t_philo **philo, t_general *all)
{
	int	i;
	int	nb;

	nb = all->parse_struct->philo_nb;
	i = 0;
	free(all->parse_struct);
	free(all->pid);
	free(all);
	while (i < nb)
	{
		free(philo[i]);
		i++;
	}
	free(philo);
}
