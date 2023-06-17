/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 22:30:37 by zelhajou          #+#    #+#             */
/*   Updated: 2023/06/17 19:24:26 by zelhajou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*read_line(int fd, char *buffer, char *saved)
{
	int		bytes_read;
	char	*temp;
	char	*newline_ptr;

	bytes_read = 1;
	newline_ptr = ft_strchr(saved, '\n');
	while (newline_ptr == NULL && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			break ;
		buffer[bytes_read] = '\0';
		temp = saved;
		saved = ft_strjoin(saved, buffer);
		free(temp);
		newline_ptr = ft_strchr(saved, '\n');
	}
	if (bytes_read == -1 || (bytes_read <= 0 && saved && saved[0] == '\0'))
	{
		free(saved);
		saved = NULL;
		return (NULL);
	}
	return (saved);
}

static char	*extract_line(char **saved, int i)
{
	char	*line;
	char	*temp;

	while ((*saved)[i] != '\n' && (*saved)[i] != '\0')
		i++;
	if ((*saved)[i] == '\n')
	{
		line = ft_substr(*saved, 0, i + 1);
		temp = *saved;
		*saved = ft_strdup(*saved + i + 1);
		free(temp);
		if ((*saved)[0] == '\0')
		{
			free(*saved);
			*saved = NULL;
		}
	}
	else
	{
		line = ft_strdup(*saved);
		free(*saved);
		*saved = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*saved[1024];
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (!saved[fd])
		saved[fd] = ft_strdup("");
	saved[fd] = read_line(fd, buffer, saved[fd]);
	free(buffer);
	if (!saved[fd])
		return (NULL);
	line = extract_line(&saved[fd], 0);
	if (!line)
	{
		free(saved[fd]);
		saved[fd] = NULL;
	}
	return (line);
}
