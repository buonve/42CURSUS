/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 20:43:41 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/07/19 15:14:44 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	write_correct_info(int philo_id, char *status, t_philo *philo)
{
	uint64_t	i;

	i = ft_get_time();
	i = i - philo->all->run_time;
	sem_wait(philo->all->print_sem);
	if (!philo->all->kill)
		printf("%llu \033[0;35mPhilo %d\e[0m %s\n", i, philo_id, status);
	sem_post(philo->all->print_sem);
}

void	enact_death(t_philo *cast)
{
	give_forks(cast);
	sem_wait(cast->all->print_sem);
	printf("%llu \033[0;31mPhilo[%d] died.\n\e[0m",
		ft_get_time() - cast->all->run_time, cast->philo_id);
	if (!cast->all->kill)
		cast->all->kill = 1;
	sem_post(cast->all->kill_sem);
	cast->status = DIED;
}

void	*ft_check_death(void *philo)
{
	t_philo	*cast;

	cast = (t_philo *)philo;
	while (!cast->all->kill)
	{
		if (cast->eating_count == cast->all->parse_struct->nb_to_eat)
		{
			cast->finish = 1;
			cast->status = FINISH;
			give_forks(cast);
			sem_wait(cast->all->print_sem);
			printf("%llu \033[0;35mPhilo[%d] finished eating.\e[0m\n",
				ft_get_time() - cast->all->run_time, cast->philo_id);
			sem_post(cast->all->print_sem);
			break ;
		}
		if ((ft_get_time() - cast->last_eat)
			> (uint64_t)cast->all->parse_struct->time_die)
		{
			enact_death(cast);
			break ;
		}
		usleep(50);
	}
	return (0);
}

int	loop_table(t_philo *casted)
{
	if (casted->stage == EATING && !casted->all->kill)
	{
		if (casted->status == DIED)
			return (1);
		get_forks(casted);
		go_eat(casted);
		casted->stage = SLEEPING;
	}
	if (casted->stage == SLEEPING && !casted->all->kill)
	{
		if (casted->status == DIED)
			return (1);
		go_sleep(casted);
		casted->stage = EATING;
	}
	if (!casted->all->kill && casted->status == EATING)
		write_correct_info(casted->philo_id,
			"\033[0;33mis thinking...\e[0m", casted);
	return (0);
}

void	*sit_at_table(void *philo)
{
	t_philo		*casted;
	pthread_t	*check_death;

	casted = philo;
	check_death = malloc(sizeof(pthread_t));
	pthread_create(check_death, NULL, &ft_check_death, (void *)casted);
	if ((casted->philo_id) % 2 == 0)
		usleep(10);
	while (casted->status == ALIVE && !casted->all->kill)
	{
		if (loop_table(casted) == 1)
			break ;
	}
	pthread_join(check_death[0], NULL);
	free(check_death);
	return (0);
}
