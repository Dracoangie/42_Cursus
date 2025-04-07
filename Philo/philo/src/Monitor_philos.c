/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Monitor_philos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:34:51 by angnavar          #+#    #+#             */
/*   Updated: 2025/03/06 13:55:05 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Philo.h"

int	check_philo_death(t_philos_data *philos)
{
	int		i;
	long	time_since_last_meal;
	t_args	*args;

	args = philos[0].args;
	i = -1;
	while (++i < args->num_philos)
	{
		pthread_mutex_lock(philos[i].act_lock);
		time_since_last_meal = deltatime(&philos[i]) - philos[i].last_meal_time;
		if (time_since_last_meal > args->time_die && philos[i].eat_num != 0)
		{
			if (*philos[i].dead == 0)
			{
				*philos[i].dead = 1;
				pthread_mutex_unlock(philos[i].act_lock);
				return (0);
			}
		}
		pthread_mutex_unlock(philos[i].act_lock);
	}
	return (1);
}

int	check_all_finished(t_philos_data *philos)
{
	int		i;
	int		finished_philos;
	t_args	*args;

	args = philos[0].args;
	i = -1;
	finished_philos = 0;
	pthread_mutex_lock(philos[0].act_lock);
	while (++i < args->num_philos)
	{
		if (philos[i].eat_num == 0)
			finished_philos++;
	}
	if (finished_philos == args->num_philos)
	{
		*philos[0].all_finished = 1;
		pthread_mutex_unlock(philos[0].act_lock);
		return (0);
	}
	pthread_mutex_unlock(philos[0].act_lock);
	return (1);
}

void	*monitor_philos(void *arg)
{
	t_philos_data	*philos;

	philos = (t_philos_data *)arg;
	while (1)
	{
		if (!check_philo_death(philos) || !check_all_finished(philos))
			return (NULL);
		ft_usleep(60, philos);
	}
	return (NULL);
}
