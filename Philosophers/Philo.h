/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:44:02 by angnavar          #+#    #+#             */
/*   Updated: 2025/03/06 15:22:12 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_args
{
	int				num_philos;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				num_time_philos_eat;
}					t_args;

typedef struct s_philos_data
{
	int				num;
	int				eat_num;
	t_args			*args;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*act_lock;
	pthread_mutex_t	*write_lock;
	long			last_meal_time;
	int				*dead;
	int				*all_finished;
	long long		start_time;
	int				*die_printed;
}					t_philos_data;

typedef struct s_data
{
	pthread_t		*threads;
	pthread_t		monitor_thread;
	t_philos_data	*filos_data;
	pthread_mutex_t	*forks;
	pthread_mutex_t	act_lock;
	pthread_mutex_t	write_lock;
	int				dead;
	int				die_printed;
	int				all_finished;
}					t_data;

// HELPER
void		checker(char **argv, t_args *args);
void		custom_error(char *strError, int error);
int			to_num(const char *nptr);
long long	deltatime(t_philos_data *data);
long long	timestamp(void);
void		ft_usleep(int time, t_philos_data *data);

// PROGRAM
void		*monitor_philos(void *arg);
void		*philo_thread(void *arg);
void		philos(t_args *args);
void		*check_philos_dead(void *arg);
int			check_one_filo(t_philos_data *data);

// PRINTS
void		philo_take_fork(int num_philo, int timestamp_in_ms,
				t_philos_data *data);
void		philo_eat(int num_philo, int timestamp_in_ms,
				t_philos_data *data);
int			philo_sleep(int num_philo, int timestamp_in_ms,
				t_philos_data *data);
void		philo_think(int num_philo, int timestamp_in_ms,
				t_philos_data *data);
void		philo_die(int num_philo, int timestamp_in_ms,
				t_philos_data *data);

#endif