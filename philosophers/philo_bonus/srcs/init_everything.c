/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_everything.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 20:43:31 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/07/19 14:25:45 by vbuonvin         ###   ########.fr       */
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

void	init_sems(t_general *all)
{
	char	*sem_name;
	int		nb;

	nb = all->parse_struct->philo_nb;
	sem_name = ft_strdup("forchette");
	sem_unlink(sem_name);
	all->forks_sem = sem_open(sem_name, O_CREAT | O_EXCL, 0644, nb);
	free(sem_name);
	sem_name = ft_strdup("stampa");
	sem_unlink(sem_name);
	all->print_sem = sem_open(sem_name, O_CREAT | O_EXCL, 0644, 1);
	free(sem_name);
	sem_name = ft_strdup("uccidi");
	sem_unlink(sem_name);
	all->kill_sem = sem_open(sem_name, O_CREAT | O_EXCL, 0644, 0);
	free(sem_name);
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
		philo[0]->all->pid[i] = fork();
		if (!philo[0]->all->pid[i])
		{
			sit_at_table(philo[i]);
			exit(0);
		}
		i++;
	}
	i = 0;
}
