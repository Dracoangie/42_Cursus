/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:30:20 by angnavar          #+#    #+#             */
/*   Updated: 2025/02/13 18:18:32 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	int	i;
	int	here_doc_mode;

	if (argc < 5)
	{
		write(2, "Usage: ./pipex_bonus infile cmd1 cmd2 ... outfile\n", 50);
		return (1);
	}
	i = 0;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) < 1)
			return (0);
		i++;
	}
	here_doc_mode = !ft_strcmp(argv[1], "here_doc");
	if (here_doc_mode)
		do_here_doc(argc, argv, envp);
	else
		pipex(argv, envp, argc - 3, 0);
	return (0);
}
