/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 20:43:37 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/07/17 20:43:37 by vbuonvin         ###   ########.fr       */
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

void	*control_room(void *all)
{
	t_general	*a_cast;
	int			i;

	i = 0;
	a_cast = all;
	sem_wait(a_cast->kill_sem);
	while (i < a_cast->parse_struct->philo_nb)
	{
		if (a_cast->pid[i] != 0)
			kill(a_cast->pid[i], 1);
		i++;
	}
	a_cast->kill = 1;
	return (0);
}

void	control_process_status(t_philo **philo, t_general *all)
{
	pthread_t	*controller;
	int			i;

	controller = malloc(sizeof(pthread_t));
	pthread_create(controller, NULL, (void *)&control_room, (void *)all);
	i = 0;
	while (i < philo[0]->all->parse_struct->philo_nb)
	{
		waitpid(philo[0]->all->pid[i], (int *)&philo[0]->all->pid[i], 0);
		i++;
	}
	sem_post(all->kill_sem);
	pthread_join(*controller, NULL);
	free(controller);
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
	init_sems(all);
	all->kill = 0;
	all->pid = malloc(sizeof(int) * all->parse_struct->philo_nb);
	philo = malloc(sizeof(t_philo) * all->parse_struct->philo_nb);
	init_philos(philo, all);
	run_life(philo);
	control_process_status(philo, all);
	free_everything(philo, all);
	return (0);
}
