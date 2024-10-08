/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: angnavar <angnavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 14:16:53 by angnavar          #+#    #+#             */
/*   Updated: 2024/10/08 19:17:41 by angnavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

char	*is_line_break(int fd, char **buffer)
{
    char *line;
    char i = 0;

    if (!ft_strchr(*buffer, '\n'))
        return (NULL);
    while ((*buffer)[i] && (*buffer)[i] != '\n')
        i++;
    line = ft_substr(*buffer, 0, i);
    if (!line)
        return (NULL);
    return (line);
}

char	*set_buffer(int fd, char **buffer)
{
    ssize_t i_readed;
    char buffer_read[BUFFER_SIZE + 1];
    char *aux;

    i_readed = read(fd, buffer_read, BUFFER_SIZE);
    if (i_readed <= 0) 
	{
        if (*buffer && (*buffer)[0])
            return (*buffer);
        return (NULL);
    }
    buffer_read[i_readed] = '\0';
    aux = ft_strjoin(*buffer, buffer_read);
    if (!aux)
        return (NULL);
    free(*buffer);
    *buffer = aux;
	aux = is_line_break (fd, buffer);
	if(aux)
	{
    	free(*buffer);
    	*buffer = aux;
	}
    return set_buffer (fd, buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if(!buffer)
		buffer = ft_strdup ("");
	buffer = set_buffer(fd, &buffer);
	if(!buffer)
		return (NULL);
	return (buffer);
}

int main()
{
	int	fd;
	int	i = 0;

	fd = open("../prueba.txt", O_RDONLY);
	while (get_next_line (fd))
	{
		printf ("%s\n", get_next_line (fd));
		
	}
}
