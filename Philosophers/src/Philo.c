/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 16:44:00 by angnavar          #+#    #+#             */
/*   Updated: 2025/03/06 15:22:22 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Philo.h"

void	set_philo_data(t_data *data, t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->num_philos)
	{
		data->filos_data[i].num = i + 1;
		data->filos_data[i].eat_num = args->num_time_philos_eat;
		data->filos_data[i].args = args;
		data->filos_data[i].forks = data->forks;
		data->filos_data[i].act_lock = &data->act_lock;
		data->filos_data[i].write_lock = &data->write_lock;
		data->filos_data[i].start_time = timestamp();
		data->filos_data[i].last_meal_time = deltatime(&data->filos_data[i]);
		data->filos_data[i].dead = &data->dead;
		data->filos_data[i].die_printed = &data->die_printed;
		data->filos_data[i].all_finished = &data->all_finished;
		pthread_create(&data->threads[i], NULL, philo_thread,
			&data->filos_data[i]);
	}
}

void	ft_free_data(t_data *data, t_args *args)
{
	int	i;

	i = -1;
	while (++i < args->num_philos)
		pthread_mutex_destroy(&data->forks[i]);
	pthread_mutex_destroy(&data->act_lock);
	pthread_mutex_destroy(&data->write_lock);
	free(data->forks);
	free(data->threads);
	free(data->filos_data);
}

void	philos(t_args *args)
{
	t_data	data;
	int		i;

	i = -1;
	data.dead = 0;
	data.die_printed = 0;
	data.all_finished = 0;
	data.threads = malloc(sizeof(pthread_t) * args->num_philos);
	data.filos_data = malloc(sizeof(t_philos_data) * args->num_philos);
	data.forks = malloc(sizeof(pthread_mutex_t) * args->num_philos);
	pthread_mutex_init(&data.act_lock, NULL);
	pthread_mutex_init(&data.write_lock, NULL);
	while (++i < args->num_philos)
	{
		pthread_mutex_init(&data.forks[i], NULL);
	}
	set_philo_data(&data, args);
	pthread_create(&data.monitor_thread, NULL, monitor_philos, data.filos_data);
	pthread_join(data.monitor_thread, NULL);
	i = -1;
	while (++i < args->num_philos)
	{
		pthread_join(data.threads[i], NULL);
	}
	ft_free_data(&data, args);
}
