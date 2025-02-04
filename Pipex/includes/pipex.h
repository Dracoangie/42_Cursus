/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:56:31 by angnavar          #+#    #+#             */
/*   Updated: 2025/02/04 11:13:26 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../includes/ft_printf/ft_printf.h"
# include "../includes/libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

typedef struct s_pipex
{
	pid_t	childs[2];
	int		file[2];
	int		pipe_fd[2];
}			t_pipex;

void		free_args(char **args);
char		*search_executable_in_paths(char *cmd, char **paths);
void		pipex(char **argv, char **envp);

#endif
