/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:30:20 by angnavar          #+#    #+#             */
/*   Updated: 2025/02/04 10:49:35 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	i;

	if (argc != 5)
	{
		write(2, "Usage: ./pipex infile cmd1 cmd2 outfile\n", 40);
		return (1);
	}
	i = 0;
	while (i < 5)
	{
		if (ft_strlen(argv[i]) < 1)
			return (0);
		i++;
	}
	pipex(argv, envp);
	return (0);
}
