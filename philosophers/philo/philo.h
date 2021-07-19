/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbuonvin <vbuonvin@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 10:37:44 by vbuonvin          #+#    #+#             */
/*   Updated: 2021/07/18 10:37:44 by vbuonvin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/time.h>

enum e_status
{
	ALIVE,
	DIED,
};

enum e_fork
{
	TAKEN,
	NOT_TAKEN,
};

enum e_stage
{
	EATING,
	SLEEPING,
	FINISH,
};

typedef struct s_parse
{
	int	philo_nb;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	nb_to_eat;
}		t_parse;

typedef struct s_general
{
	t_parse			*parse_struct;
	pthread_mutex_t	**forks_mutex;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*kill_mutex;
	pthread_t		**philo_threads;
	uint64_t		run_time;
	int				kill;
	int				**forks;
}					t_general;

typedef struct s_philo
{
	int				philo_id;
	int				dx_hand;
	int				sx_hand;
	int				stage;
	int				status;
	int				eating_count;
	int				finish;
	uint64_t		last_eat;
	uint64_t		last_change;
	t_general		*all;
}					t_philo;

/*
** UTILS
*/

int			ft_atoi(const char *str);
void		ft_usleep(int time, t_philo *philo);
uint64_t	ft_get_time(void);
void		write_correct_info(int philo_id, char *status, t_philo *philo);
int			check_still_alive(t_philo *philo);
int			all_th_ate(t_philo **philo);
void		free_everything(t_philo **philo, t_general *all);
int			ft_isdigit(int c);

/*
** INITS
*/

int			start_parse(int ac, char **av, t_parse *parse_struct);
void		init_philos(t_philo **philo, t_general *all);
void		init_forks(t_general *all);
void		init_mutex(t_general *all);
void		init_threads(t_general *all);
void		run_life(t_philo **philo);

/*
** TABLE
*/

void		*sit_at_table(void *philo);

/*
** ACTIONS
*/

void		get_forks(t_philo *philo);
void		give_forks(t_philo *philo);
void		go_eat(t_philo *philo);
void		go_sleep(t_philo *philo);

#endif