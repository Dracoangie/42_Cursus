/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:40:38 by angnavar          #+#    #+#             */
/*   Updated: 2025/03/06 14:12:20 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Philo.h"

int	to_num(const char *nptr)
{
	long	temp_result;
	int		has_num;

	temp_result = 0;
	while (*nptr >= '0' && *nptr <= '9')
	{
		temp_result = temp_result * 10 + (*nptr - '0');
		nptr++;
		has_num = 1;
	}
	if (*nptr != '\0' || has_num != 1)
		custom_error("invalid arguments\n", 2);
	if (temp_result > 2147483647)
		custom_error("invalid arguments\n", 2);
	return (temp_result);
}

void	checker(char **argv, t_args *args)
{
	args->num_philos = to_num(argv[1]);
	if (to_num (argv[1]) > 200)
		args->num_philos = 200;
	args->time_die = to_num(argv[2]);
	args->time_eat = to_num(argv[3]);
	args->time_sleep = to_num(argv[4]);
	if (argv[5])
		args->num_time_philos_eat = to_num(argv[5]);
	else
		args->num_time_philos_eat = -1;
}

int	check_one_filo(t_philos_data *data)
{
	if (data->args->num_philos == 1)
	{
		pthread_mutex_lock(&data->forks[0]);
		philo_take_fork(data->num, deltatime(data), data);
		pthread_mutex_unlock(&data->forks[0]);
		ft_usleep(data->args->time_die, data);
		philo_die(data->num, deltatime(data), data);
		return (0);
	}
	return (1);
}
