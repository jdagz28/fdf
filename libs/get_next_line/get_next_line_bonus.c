/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:21:27 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/21 13:50:51 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_get_line(char *saved)
{
	int	size;

	size = 0;
	if (ft_strlen_gnl(saved) == 0 && !ft_strchr_gnl(saved, '\n'))
		return (NULL);
	if (!ft_strchr_gnl(saved, '\n'))
		return (ft_strdup_gnl(saved));
	while (saved[size] && saved[size] != '\n')
		size++;
	return (ft_substr_gnl(saved, 0, size + 1));
}

static char	*ft_clean(char *saved)
{
	char	*clear;

	if (!ft_strchr_gnl(saved, '\n'))
		return (free(saved), NULL);
	clear = ft_strdup_gnl(ft_strchr_gnl(saved, '\n') + 1);
	free(saved);
	return (clear);
}

static char	*ft_read(int fd, char **saved)
{
	char	*buffer;
	int		readbytes;
	char	*temp;

	buffer = (char *)malloc(sizeof(*buffer) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	readbytes = 1;
	while (readbytes && !ft_strchr_gnl(*saved, '\n'))
	{
		readbytes = read(fd, buffer, BUFFER_SIZE);
		if (readbytes == -1 || (readbytes == 0 && !*saved))
			return (free(*saved), free(buffer), NULL);
		buffer[readbytes] = 0;
		if (readbytes == 0 && !*saved)
			return (free(buffer), *saved);
		temp = *saved;
		*saved = ft_strjoin_gnl(temp, buffer);
		free(temp);
	}
	free(buffer);
	return (*saved);
}

char	*get_next_line(int fd)
{
	static char		*saved[OPEN_MAX];
	char			*line;

	if (fd < 0 || fd > OPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	if (!saved[fd])
		saved[fd] = ft_strdup_gnl("");
	if (!saved[fd])
		return (NULL);
	if (!ft_strchr_gnl(saved[fd], '\n'))
		saved[fd] = ft_read(fd, &saved[fd]);
	if (!saved[fd])
		return (free(saved[fd]), NULL);
	line = ft_get_line(saved[fd]);
	saved[fd] = ft_clean(saved[fd]);
	return (line);
}
