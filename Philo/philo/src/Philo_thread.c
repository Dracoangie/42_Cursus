/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philo_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:44:00 by angnavar          #+#    #+#             */
/*   Updated: 2025/03/06 13:53:57 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Philo.h"

int	check_dead(t_philos_data *data)
{
	long	time_since_last_meal;

	pthread_mutex_lock(data->act_lock);
	time_since_last_meal = deltatime(data) - data->last_meal_time;
	if (*data->dead == 1)
	{
		if (!*data->die_printed)
		{
			*data->die_printed = 1;
			philo_die(data->num, deltatime(data), data);
		}
		pthread_mutex_unlock(data->act_lock);
		return (0);
	}
	pthread_mutex_unlock(data->act_lock);
	return (1);
}

int	lock_second_fork(t_philos_data *data, int first, int second)
{
	if (pthread_mutex_lock(&data->forks[second]) != 0)
	{
		pthread_mutex_unlock(&data->forks[first]);
		return (1);
	}
	philo_take_fork(data->num, deltatime(data), data);
	return (0);
}

int	take_forks(t_philos_data *data)
{
	int	left;
	int	right;

	left = data->num - 1;
	right = data->num % data->args->num_philos;
	if (data->args->num_philos == 1)
	{
		pthread_mutex_lock(&data->forks[left]);
		philo_take_fork(data->num, deltatime(data), data);
		ft_usleep(data->args->time_die, data);
		philo_die(data->num, deltatime(data), data);
		pthread_mutex_unlock(&data->forks[left]);
		return (1);
	}
	if (data->num % 2 == 0)
		pthread_mutex_lock(&data->forks[left]);
	else
		pthread_mutex_lock(&data->forks[right]);
	philo_take_fork(data->num, deltatime(data), data);
	if (data->num % 2 == 0)
		return (lock_second_fork(data, left, right));
	else
		return (lock_second_fork(data, right, left));
}

int	meal_time(t_philos_data *data)
{
	if (!take_forks(data))
	{
		philo_eat(data->num, deltatime(data), data);
		pthread_mutex_lock(data->act_lock);
		data->last_meal_time = deltatime(data);
		data->eat_num--;
		pthread_mutex_unlock(data->act_lock);
		ft_usleep(data->args->time_eat, data);
		pthread_mutex_unlock(&data->forks[data->num - 1]);
		pthread_mutex_unlock(&data->forks[data->num % data->args->num_philos]);
		return (0);
	}
	return (1);
}

void	*philo_thread(void *arg)
{
	t_philos_data	*data;

	data = (t_philos_data *)arg;
	if (!check_one_filo(data))
		return (NULL);
	while (check_dead(data))
	{
		pthread_mutex_lock(data->act_lock);
		if (data->eat_num == 0)
		{
			pthread_mutex_unlock(data->act_lock);
			return (NULL);
		}
		pthread_mutex_unlock(data->act_lock);
		meal_time(data);
		philo_sleep(data->num, deltatime(data), data);
		ft_usleep(data->args->time_sleep, data);
		philo_think(data->num, deltatime(data), data);
	}
	return (NULL);
}
