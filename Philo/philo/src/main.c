/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 18:40:13 by angnavar          #+#    #+#             */
/*   Updated: 2025/03/06 13:47:57 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Philo.h"

int	main(int argc, char **argv)
{
	t_args	args;

	if (argc != 5 && argc != 6)
		custom_error("invalid num of arguments\n", 2);
	checker(argv, &args);
	if (args.num_philos == 0)
		return (0);
	philos(&args);
}
