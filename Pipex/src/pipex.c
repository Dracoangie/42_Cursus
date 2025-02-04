/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 02:28:22 by angnavar          #+#    #+#             */
/*   Updated: 2025/02/04 10:48:39 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*get_command_path(char *cmd, char **envp)
{
	char	**paths;
	int		i;

	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		else
			return (NULL);
	}
	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	return (search_executable_in_paths(cmd, paths));
}

void	execute_command(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	path = get_command_path(args[0], envp);
	if (!path || access(path, X_OK) != 0)
	{
		write(2, "zsh: command not found: ", 24);
		write(2, args[0], ft_strlen(args[0]));
		write(2, "\n", 1);
		free_args(args);
		free(path);
		exit(127);
	}
	if (execve(path, args, envp) == -1)
	{
		perror("execve error");
		free_args(args);
		free(path);
		exit(EXIT_FAILURE);
	}
}

void	set_childs(t_pipex *px, char **argv, char **envp)
{
	px->childs[0] = fork();
	if (px->childs[0] == 0)
	{
		dup2(px->file[0], STDIN_FILENO);
		dup2(px->pipe_fd[1], STDOUT_FILENO);
		close(px->pipe_fd[0]);
		execute_command(argv[2], envp);
	}
	px->childs[1] = fork();
	if (px->childs[1] == 0)
	{
		dup2(px->pipe_fd[0], STDIN_FILENO);
		if (px->file[1] >= 0)
			dup2(px->file[1], STDOUT_FILENO);
		else
		{
			perror(argv[4]);
			exit(1);
		}
		close(px->pipe_fd[1]);
		execute_command(argv[3], envp);
	}
}

void	open_files(int file[2], char **argv, int pipe_fd[2])
{
	file[0] = open(argv[1], O_RDONLY);
	if (file[0] < 0)
	{
		perror(argv[1]);
		file[0] = open("/dev/null", O_RDONLY);
		if (file[0] < 0)
			exit(1);
	}
	file[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipe(pipe_fd) == -1)
	{
		perror("pipe error");
		exit(1);
	}
}

void	pipex(char **argv, char **envp)
{
	t_pipex	px;
	int		status[2];

	open_files(px.file, argv, px.pipe_fd);
	set_childs(&px, argv, envp);
	close(px.pipe_fd[0]);
	close(px.pipe_fd[1]);
	close(px.file[0]);
	if (px.file[1] >= 0)
		close(px.file[1]);
	waitpid(px.childs[0], &status[0], 0);
	waitpid(px.childs[1], &status[1], 0);
	if (WIFEXITED(status[1]))
		exit(WEXITSTATUS(status[1]));
	else
		exit(1);
}
