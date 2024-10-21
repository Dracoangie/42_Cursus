/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:16:53 by angnavar          #+#    #+#             */
/*   Updated: 2024/10/21 12:51:24 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>

char	*is_line_break(char **buffer)
{
	char	*newline;
	size_t	line_length;
	char	*line;
	char	*aux;

	if (!buffer || !*buffer)
		return (NULL);
	newline = ft_strchr (*buffer, '\n');
	if (!newline)
		return (NULL);
	line_length = newline - *buffer + 1;
	line = ft_substr (*buffer, 0, line_length);
	if (!line)
		return (NULL);
	aux = ft_strdup (newline + 1);
	if (!aux)
	{
		free (line);
		return (NULL);
	}
	free (*buffer);
	*buffer = aux;
	line[ft_strlen (line)] = '\0';
	return (line);
}

char	*check_readed(ssize_t i_readed, char **buffer, char *buffer_read)
{
	char	*aux;

	free(buffer_read);
	if (i_readed == 0 && *buffer && ft_strlen(*buffer) > 0)
	{
		aux = *buffer;
		*buffer = NULL;
		return (aux);
	}
	if (*buffer)
		free(*buffer);
	*buffer = NULL;
	return (NULL);
}

char	*set_buffer(int fd, char **buffer, char *buffer_read)
{
	ssize_t	i_readed;
	char	*aux;

	while (1)
	{
		aux = is_line_break(buffer);
		if (aux)
			free(buffer_read);
		if (aux)
			return (aux);
		i_readed = read(fd, buffer_read, BUFFER_SIZE);
		if (i_readed <= 0)
			return (check_readed(i_readed, buffer, buffer_read));
		buffer_read[i_readed] = '\0';
		aux = ft_strjoin(*buffer, buffer_read);
		if (!aux)
		{
			free(buffer_read);
			free(*buffer);
			*buffer = NULL;
			return (NULL);
		}
		free(*buffer);
		*buffer = aux;
	}
}

char	*get_next_line(int fd)
{
	static char	*buffers[1024] = {NULL};
	char		*buffer_read;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffers[fd])
		buffers[fd] = ft_strdup("");
	if (!buffers[fd])
		return (NULL);
	buffer_read = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer_read)
		return (NULL);
	return (set_buffer(fd, &buffers[fd], buffer_read));
}

/*
int main()
{
    int fd;
    int fd1;
    int fd2;
    //int fd1;
    char *line;

    fd = open("../pruebas/empty.txt", O_RDONLY);
    //fd = open("../pruebas/variable_nls.txt", O_RDONLY);
    //fd = open("../pruebas/read_error.txt", O_RDONLY);
    //fd = open("../pruebas/only_nl.txt", O_RDONLY);
    //fd = open("../pruebas/one_line_no_nl.txt", O_RDONLY);
    //fd = open("../pruebas/multiple_nl.txt", O_RDONLY);
    //fd = open("../pruebas/giant_line_nl.txt", O_RDONLY);
    //fd = open("../pruebas/prueba.txt", O_RDONLY);
    fd1 = open("../pruebas/variable_nls.txt", O_RDONLY);
    fd2 = open("../pruebas/lines_around_10.txt", O_RDONLY);
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd1);
        printf("%s", line);
        free(line);
		line = get_next_line(fd2);
        printf("%s", line);
        free(line);
    }
    close(fd);
    close(fd1);
    close(fd2);
    return 0;
}*/
