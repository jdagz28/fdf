/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:55:51 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/21 13:50:13 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_get_line(char *saved)
{
	int	size;

	size = 0;
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

static char	*ft_read(int fd, char *saved)
{
	char	*buffer;
	int		readbytes;
	char	*temp;

	buffer = (char *)malloc(sizeof(*buffer) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free(saved), NULL);
	readbytes = 1;
	while (readbytes && !ft_strchr_gnl(saved, '\n'))
	{
		readbytes = read(fd, buffer, BUFFER_SIZE);
		if (readbytes == -1 || (readbytes == 0 && !saved[0]))
			return (free(buffer), free(saved), NULL);
		buffer[readbytes] = 0;
		if (readbytes == 0 && saved[0])
			return (free(buffer), saved);
		temp = saved;
		saved = ft_strjoin_gnl(temp, buffer);
		free (temp);
	}
	free(buffer);
	return (saved);
}

char	*get_next_line(int fd)
{
	static char		*saved;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!saved)
		saved = ft_strdup_gnl("");
	if (!saved)
		return (NULL);
	if (!ft_strchr_gnl(saved, '\n'))
		saved = ft_read(fd, saved);
	if (!saved)
		return (NULL);
	line = ft_get_line(saved);
	saved = ft_clean(saved);
	return (line);
}
