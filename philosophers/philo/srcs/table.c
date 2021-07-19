/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 10:38:02 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/07/19 15:32:50 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	write_correct_info(int philo_id, char *status, t_philo *philo)
{
	uint64_t	i;

	i = ft_get_time();
	i = i - philo->all->run_time;
	pthread_mutex_lock(philo->all->print_mutex);
	if (!philo->all->kill)
		printf("%llu \033[0;35mPhilo %d\e[0m %s\n", i, philo_id, status);
	pthread_mutex_unlock(philo->all->print_mutex);
}

void	enact_death(t_philo *cast)
{
	give_forks(cast);
	pthread_mutex_lock(cast->all->kill_mutex);
	if (!cast->all->kill)
	{
		cast->status = DIED;
		pthread_mutex_lock(cast->all->print_mutex);
		if (!cast->all->kill)
			printf("%llu \033[0;31mPhilo[%d] died.\n\e[0m",
				ft_get_time() - cast->all->run_time, cast->philo_id);
		cast->all->kill = 1;
		pthread_mutex_unlock(cast->all->print_mutex);
	}
	pthread_mutex_unlock(cast->all->kill_mutex);
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
			pthread_mutex_lock(cast->all->print_mutex);
			printf("%llu \033[0;35mPhilo[%d] finished eating.\e[0m\n",
				ft_get_time() - cast->all->run_time, cast->philo_id);
			pthread_mutex_unlock(cast->all->print_mutex);
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
	if (!casted->all->kill && casted->stage == EATING)
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
		ft_usleep(casted->all->parse_struct->time_eat, casted);
	while (casted->status == ALIVE && !casted->all->kill)
	{
		if (loop_table(casted) == 1)
			break ;
	}
	pthread_join(check_death[0], NULL);
	free(check_death);
	return (0);
}
