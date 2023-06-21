/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdagoy <jdagoy@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 11:55:50 by jdagoy            #+#    #+#             */
/*   Updated: 2023/06/21 13:50:02 by jdagoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 500000
# endif

# include <unistd.h>
# include <stdlib.h>

size_t	ft_strlen_gnl(const char *str);
char	*ft_strjoin_gnl(char const *s1, char const *s2);
char	*ft_strdup_gnl(const char *s1);
char	*ft_strchr_gnl(const char *s, int c);
char	*ft_substr_gnl(char const *s, unsigned int start, size_t len);
char	*get_next_line(int fd);

#endif
