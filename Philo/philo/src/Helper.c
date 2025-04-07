/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:43:15 by angnavar          #+#    #+#             */
/*   Updated: 2025/03/06 13:51:51 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Philo.h"

void	ft_usleep(int time, t_philos_data *data)
{
	long long	start;
	long long	current;

	start = deltatime(data);
	current = deltatime(data);
	while (current - start < time)
	{
		current = deltatime(data);
		pthread_mutex_lock(data->act_lock);
		if (*data->dead || *data->all_finished)
		{
			pthread_mutex_unlock(data->act_lock);
			return ;
		}
		pthread_mutex_unlock(data->act_lock);
		usleep(20);
	}
}

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

void	custom_error(char *strError, int error)
{
	write(error, strError, ft_strlen(strError));
	exit(error);
}

long long	timestamp(void)
{
	struct timeval	t_val;

	gettimeofday(&t_val, NULL);
	return ((t_val.tv_sec * 1000) + (t_val.tv_usec / 1000));
}

long long	deltatime(t_philos_data *data)
{
	long long int	time;

	time = timestamp();
	return (time - data->start_time);
}
