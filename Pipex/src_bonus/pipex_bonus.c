/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 02:28:22 by angnavar          #+#    #+#             */
/*   Updated: 2025/02/13 19:48:28 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	close_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->cmd_len - 1)
	{
		close(pipex->pipes[i][0]);
		close(pipex->pipes[i][1]);
		free(pipex->pipes[i]);
		i++;
	}
	free(pipex->pipes);
}

void	create_pipes(t_pipex *pipex)
{
	int	i;

	pipex->pipes = malloc(sizeof(int *) * (pipex->cmd_len - 1));
	if (!pipex->pipes)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < pipex->cmd_len - 1)
	{
		pipex->pipes[i] = malloc(sizeof(int) * 2);
		if (!pipex->pipes[i] || pipe(pipex->pipes[i]) == -1)
		{
			perror("pipe error");
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

static void	set_dups_close(t_pipex *pipex, int i)
{
	int	j ;

	j = 0;
	if (i == 0)
	{
		dup2(pipex->file[0], STDIN_FILENO);
		dup2(pipex->pipes[i][1], STDOUT_FILENO);
	}
	else if (i == pipex->cmd_len - 1)
	{
		dup2(pipex->pipes[i - 1][0], STDIN_FILENO);
		dup2(pipex->file[1], STDOUT_FILENO);
	}
	else
	{
		dup2(pipex->pipes[i - 1][0], STDIN_FILENO);
		dup2(pipex->pipes[i][1], STDOUT_FILENO);
	}
	while (j < pipex->cmd_len - 1)
	{
		close(pipex->pipes[j][0]);
		close(pipex->pipes[j][1]);
		j++;
	}
}

void	set_childs(t_pipex *pipex, char **argv, char **envp)
{
	int	i;

	i = 0;
	pipex->childs = malloc(sizeof(pid_t) * pipex->cmd_len);
	if (!pipex->childs)
		exit(EXIT_FAILURE);
	while (i < pipex->cmd_len)
	{
		pipex->childs[i] = fork();
		if (pipex->childs[i] == 0)
		{
			set_dups_close(pipex, i);
			execute_command(argv[2 + i + pipex->here_doc_mode], envp, pipex);
		}
		i++;
	}
}

void	pipex(char **argv, char **envp, int cmd_len, int here_doc_mode)
{
	t_pipex	pipex;
	int		status;
	int		i;

	pipex.cmd_len = cmd_len;
	pipex.here_doc_mode = here_doc_mode;
	here_doc_open_files(&pipex, argv);
	create_pipes(&pipex);
	if (!here_doc_mode)
		dup2(pipex.file[0], STDIN_FILENO);
	set_childs(&pipex, argv, envp);
	close_pipes(&pipex);
	if (!here_doc_mode)
		close(pipex.file[0]);
	close(pipex.file[1]);
	i = 0;
	while (i < pipex.cmd_len)
	{
		waitpid(pipex.childs[i], &status, 0);
		i++;
	}
	free(pipex.childs);
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
	exit(EXIT_FAILURE);
}
