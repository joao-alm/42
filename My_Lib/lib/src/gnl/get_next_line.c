/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-alm <support@toujoustudios.net>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:02:20 by joao-alm          #+#    #+#             */
/*   Updated: 2024/11/08 17:02:20 by joao-alm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_gnl.h"
#include <unistd.h>

char	*ft_join_free(char *s1, char *s2)
{
	char	*temp_buffer;

	temp_buffer = ft_gnl_strjoin(s1, s2);
	free(s1);
	return (temp_buffer);
}

char	*ft_fill_line(char *buffer)
{
	char	*line;
	size_t	line_len;
	size_t	i;

	line_len = 0;
	while (buffer[line_len] && buffer[line_len] != '\n')
		line_len++;
	if (buffer[line_len] == '\n')
		line_len++;
	line = ft_gnl_calloc(line_len + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = -1;
	while (++i < line_len)
		line[i] = buffer[i];
	return (line);
}

char	*ft_update_buffer(char *buffer, char *line)
{
	char	*new_buffer;
	size_t	buffer_len;
	size_t	line_len;
	size_t	i;

	buffer_len = ft_gnl_strlen(buffer);
	line_len = ft_gnl_strlen(line);
	if (line_len == buffer_len)
		return (free(buffer), NULL);
	new_buffer = ft_gnl_calloc(buffer_len - line_len + 1, sizeof(char));
	if (!new_buffer)
		return (free(buffer), NULL);
	i = -1;
	while (buffer[line_len + ++i])
		new_buffer[i] = buffer[line_len + i];
	return (free(buffer), new_buffer);
}

char	*ft_fill_buffer(char *buffer, int fd)
{
	char	*temp_buffer;
	ssize_t	bytes_read;

	if (!buffer)
		buffer = ft_gnl_calloc(1, 1);
	if (!buffer)
		return (NULL);
	temp_buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!temp_buffer)
		return (free(buffer), NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free(buffer), free(temp_buffer), NULL);
		temp_buffer[bytes_read] = '\0';
		buffer = ft_join_free(buffer, temp_buffer);
		if (!buffer)
			return (free(temp_buffer), NULL);
		if (ft_gnl_strchr(temp_buffer, '\n'))
			break ;
	}
	return (free(temp_buffer), buffer);
}

char	*get_next_line(int fd)
{
	static char	*static_array[FD_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || FD_MAX <= 0 || fd >= FD_MAX)
		return (NULL);
	static_array[fd] = ft_fill_buffer(static_array[fd], fd);
	if (!static_array[fd])
		return (NULL);
	line = ft_fill_line(static_array[fd]);
	if (!line || line[0] == '\0')
	{
		free(static_array[fd]);
		static_array[fd] = NULL;
		return (free(line), NULL);
	}
	static_array[fd] = ft_update_buffer(static_array[fd], line);
	return (line);
}
