/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:56:31 by angnavar          #+#    #+#             */
/*   Updated: 2025/02/13 19:52:18 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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
	pid_t	*childs;
	int		file[2];
	int		**pipes;
	int		cmd_len;
	int		here_doc_mode;
}			t_pipex;

typedef struct s_heredoc
{
	int		pipe_fd[2];
	char	*line;
	size_t	len;
	size_t	size;
}			t_heredoc;

void		free_args(char **args);
void		execute_command(char *cmd, char **envp, t_pipex *pipex);
void		pipex(char **argv, char **envp, int cmd_len, int here_doc_mode);
int			ft_strcmp(const char *s1, const char *s2);
void		here_doc(char *delimiter);
int			ft_getline(char **line, size_t *len, int fd);
void		do_here_doc(int argc, char **argv, char **envp);
void		here_doc_open_files(t_pipex *pipex, char **argv);
void		open_files(t_pipex *pipex, char **argv);
void		close_pipes(t_pipex *pipex);

#endif
