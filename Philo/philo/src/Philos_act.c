/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philos_act.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:10:26 by angnavar          #+#    #+#             */
/*   Updated: 2025/03/06 13:52:36 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Philo.h"

void	philo_take_fork(int num_philo, int timestamp_in_ms, t_philos_data *data)
{
	pthread_mutex_lock(data->act_lock);
	if (*data->dead)
	{
		pthread_mutex_unlock(data->act_lock);
		return ;
	}
	pthread_mutex_lock(data->write_lock);
	printf("\033[1;33m%d %d has taken a fork\n\033[0m", timestamp_in_ms,
		num_philo);
	pthread_mutex_unlock(data->write_lock);
	pthread_mutex_unlock(data->act_lock);
}

void	philo_eat(int num_philo, int timestamp_in_ms, t_philos_data *data)
{
	pthread_mutex_lock(data->act_lock);
	if (*data->dead)
	{
		pthread_mutex_unlock(data->act_lock);
		return ;
	}
	pthread_mutex_lock(data->write_lock);
	printf("\033[1;32m%d %d is eating\n\033[0m", timestamp_in_ms, num_philo);
	pthread_mutex_unlock(data->write_lock);
	pthread_mutex_unlock(data->act_lock);
}

int	philo_sleep(int num_philo, int timestamp_in_ms, t_philos_data *data)
{
	pthread_mutex_lock(data->act_lock);
	if (*data->dead)
	{
		pthread_mutex_unlock(data->act_lock);
		return (0);
	}
	pthread_mutex_lock(data->write_lock);
	printf("\033[1;34m%d %d is sleeping\n\033[0m", timestamp_in_ms, num_philo);
	pthread_mutex_unlock(data->write_lock);
	pthread_mutex_unlock(data->act_lock);
	return (1);
}

void	philo_think(int num_philo, int timestamp_in_ms, t_philos_data *data)
{
	pthread_mutex_lock(data->act_lock);
	if (*data->dead)
	{
		pthread_mutex_unlock(data->act_lock);
		return ;
	}
	pthread_mutex_lock(data->write_lock);
	printf("\033[1;36m%d %d is thinking\n\033[0m", timestamp_in_ms, num_philo);
	pthread_mutex_unlock(data->write_lock);
	pthread_mutex_unlock(data->act_lock);
}

void	philo_die(int num_philo, int timestamp_in_ms, t_philos_data *data)
{
	pthread_mutex_lock(data->write_lock);
	printf("\033[1;31m%d %d died\n\033[0m", timestamp_in_ms, num_philo);
	pthread_mutex_unlock(data->write_lock);
}
