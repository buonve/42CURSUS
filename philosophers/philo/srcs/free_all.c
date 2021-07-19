/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 14:36:50 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/07/18 14:36:50 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	free_mutex(pthread_mutex_t **matrix, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	free_forks(int **forks, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		free(forks[i]);
		i++;
	}
	free(forks);
}

void	free_threads(pthread_t **th, int nb)
{
	int	i;

	i = 0;
	while (i < nb)
	{
		free(th[i]);
		i++;
	}
	free(th);
}

void	free_everything(t_philo **philo, t_general *all)
{
	int	i;
	int	nb;

	nb = philo[0]->all->parse_struct->philo_nb;
	i = 0;
	free(all->print_mutex);
	free(all->kill_mutex);
	free_mutex(all->forks_mutex, nb);
	free_forks(all->forks, nb);
	free_threads(all->philo_threads, nb);
	free(all->parse_struct);
	free(all);
	while (i < nb)
	{
		free(philo[i]);
		i++;
	}
	free(philo);
}
